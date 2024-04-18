#include "world.h"

//returns 0 if free, -1 if out of bounds
int isTaken(std::vector<Organism*> organisms, int numberOfOrganisms, int x, int y, int width, int height) {
    if (x > width || y > width || x < 1 || y < 1)
        return -1;
    int counter = 0;
    for (int i = 0; i < numberOfOrganisms; i++) {
        if (x == organisms[i]->getX() && y == organisms[i]->getY())
            counter += 1;
    }
    return counter;
};

World::World(int width, int height) : width(width), height(height) {}

World::~World() {
    for (auto& organism : organisms) {
        delete organism;
    }
}

void World::addOrganism(Organism* organism) {
    organisms.push_back(organism);
}

void World::removeOrganism(int i) {
    Organism* organism = organisms[i];
    organisms.erase(organisms.begin() + i);

    delete organism;
}

Organism* World::getOrganism(int i) {
    return organisms[i];
}

void World::sortOrganisms() {
    std::sort(organisms.begin(), organisms.end(), [](Organism* a, Organism* b) {
        if (a->getInitiative() != b->getInitiative()) {
            return a->getInitiative() > b->getInitiative(); 
        }
        else {
            return a->getAge() > b->getAge();
        }
        });
}

void World::drawWorld() {
    clrscr();
    gotoxy(1, 1);
    std::cout << "Y\\X|";
    for (int x = 1; x <= width; x++) {
        if (x < 10) {
            std::cout << "  ";
        }
        else if (x < 100) {
            std::cout << " ";
        }
        std::cout << x << "|";
    }
    std::cout << '\n';
    for (int y = 1; y <= height; y++) {
        if (y < 10) {
            std::cout << "  ";
        }
        else if (y < 100) {
            std::cout << " ";
        }
        std::cout << y << "|";

        for (int x = 0; x < width; x++) {
            std::cout << "   |";
        }
        std::cout << '\n';
    }

    for (int i = (int)organisms.size()-1; i >= 0; i--) {
        organisms[i]->draw();
    }

    gotoxy(1, height + 3);
    std::cout << "Mateusz Grzonka s198023\n";
    std::cout << "WASD  - Walking\n";
    std::cout << "E     - Special (Alzur's Shield)\n";
    std::cout << "SPACE - Next turn\n";
    std::cout << "P     - Save game\n";
    std::cout << "Q     - Quit\n\n";
    std::cout << "Turn: " << turn << "\n";
    std::cout << "Activity Log:\n";
    std::cout << activitylog;
}

void World::executeTurn() {
    activitylog = "";
    sortOrganisms();
    int result ,preX, preY;
    int numberOfOrganisms = (int)organisms.size();

    //Each organism makes their move
    for (int i = 0; i < numberOfOrganisms; i++) {
        this->drawWorld();
        if (!organisms[i]->alive())
            break;
        preX = organisms[i]->getX();
        preY = organisms[i]->getY();
        result = organisms[i]->action(width, height);
        if (result == BREED) {
            //if an organism exists in the new spot dont make it
            Organism* newOrganism = organisms[i]->clone();
            newOrganism->setAge(0);
            newOrganism->action(width, height);
            for (int j = 0; j < numberOfOrganisms; j++) {
                if (newOrganism->getX() == organisms[j]->getX() && newOrganism->getY() == organisms[j]->getY()) {
                    delete newOrganism;
                    newOrganism = nullptr;
                    break;
                }
            }
            if(newOrganism!=nullptr)
                addOrganism(newOrganism);
        }

        //Checking for collision
        for (int j = 0; j < numberOfOrganisms; j++) {
            if (i != j && organisms[i]->getX() == organisms[j]->getX() && organisms[i]->getY() == organisms[j]->getY()) {
                result = organisms[i]->collision(organisms[j]);
                if (result == KILL) {
                    result = organisms[j]->collision(organisms[i]);
                    if (result == DIES) {
                        organisms[j]->die();
                        activitylog = activitylog + organisms[i]->getName() + " killed " + organisms[j]->getName() + "\n";
                    }
                    else if (result == DODGE) {
                        organisms[j]->action(width, height);
                        activitylog = activitylog + organisms[j]->getName() + " dodged attack from " + organisms[i]->getName() + "\n";
                    }
                }
                else if (result == DIES) {
                    organisms[i]->die();
                    activitylog = activitylog + organisms[j]->getName() + " killed " + organisms[i]->getName() + "\n";
                }
                else if (result == BREED) {
                    organisms[i]->setX(preX);
                    organisms[i]->setY(preY);
                    if (organisms[i]->getAge() < 10 || organisms[j]->getAge() < 10)
                        break;
                    if (!isTaken(organisms, numberOfOrganisms, organisms[i]->getX(), organisms[i]->getY() - 1, width, height)) {
                        Organism* newOrganism = organisms[i]->clone();
                        newOrganism->setAge(0);
                        newOrganism->setY(organisms[i]->getY() - 1);
                        addOrganism(newOrganism);
                        activitylog = activitylog + newOrganism->getName() + " is born \n";
                        break;
                    }
                    else if (!isTaken(organisms, numberOfOrganisms, organisms[i]->getX(), organisms[i]->getY() + 1, width, height)) {
                        Organism* newOrganism = organisms[i]->clone();
                        newOrganism->setAge(0);
                        newOrganism->setY(organisms[i]->getY() + 1);
                        addOrganism(newOrganism);
                        activitylog = activitylog + newOrganism->getName() + " is born \n";
                        break;
                    }
                    else if (!isTaken(organisms, numberOfOrganisms, organisms[i]->getX() - 1, organisms[i]->getY(), width, height)) {
                        Organism* newOrganism = organisms[i]->clone();
                        newOrganism->setAge(0);
                        newOrganism->setX(organisms[i]->getX() - 1);
                        addOrganism(newOrganism);
                        activitylog = activitylog + newOrganism->getName() + " is born \n";
                        break;
                    }
                    else if (!isTaken(organisms, numberOfOrganisms, organisms[i]->getX() + 1, organisms[i]->getY(), width, height)) {
                        Organism* newOrganism = organisms[i]->clone();
                        newOrganism->setAge(0);
                        newOrganism->setX(organisms[i]->getX() + 1);
                        addOrganism(newOrganism);
                        activitylog = activitylog + newOrganism->getName() + " is born \n";
                        break;
                    }
                    break;
                }
                else if (result == NOTHING) {
                    organisms[i]->setX(preX);
                    organisms[i]->setY(preY);
                }
            }
        }
    }

    //Removing dead organisms from vector
    for (int i = 0; i < (int)organisms.size(); i++)
        if (!organisms[i]->alive())
            removeOrganism(i);

    sortOrganisms();
    turn++;
}

void World::saveFile() {
    system("cls");
    gotoxy(1, 1);
    std::string filepath = "savefile.txt";

    std::cout << "Filename: ";
    std::cin >> filepath;

    std::ofstream file(filepath, std::ios::out);

    if (file.is_open()) {
        file << this->width << ';' << this->height << ';' << this->turn << '\n';
        for (int i = 0; i < organisms.size(); i++) {
            file << organisms[i]->getName() << ';';
            file << organisms[i]->getStrength() << ';' << organisms[i]->getInitiative() << ';';
            file << organisms[i]->getX() << ';' << organisms[i]->getY() << ';';
            file << organisms[i]->getAge() << '\n';
        }
        file.close();
        std::cout << "Game saved to " << filepath << '\n';
        std::cout << "Press SPACE to continue";
    }
};