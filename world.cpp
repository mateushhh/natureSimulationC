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
    std::string filename = "savefile.txt";

    std::cout << "Filename: ";
    std::cin >> filename;

    std::ofstream file(filename, std::ios::out);

    if (file.is_open()) {
        file << this->width << ';' << this->height << ';' << this->turn << '\n';
        for (int i = 0; i < organisms.size(); i++) {
            file << organisms[i]->getName() << ';';
            file << organisms[i]->getStrength() << ';' << organisms[i]->getInitiative() << ';';
            file << organisms[i]->getX() << ';' << organisms[i]->getY() << ';';
            file << organisms[i]->getAge() << '\n';
        }
        file.close();
        std::cout << "Game saved to " << filename << '\n';
        std::cout << "Press SPACE to continue";
    }
}

/*
width; height; turn
name; strength; initiative; x; y; age\n

20;25;2
Fox;3;7;5;17;2
Fox;3;7;18;4;2
Wolf;9;5;4;13;2
Wolf;9;5;13;2;2
Sheep;4;4;7;6;2
Sheep;4;4;3;6;2
Antilope;4;4;15;7;2
Antilope;4;4;12;7;2
Human;5;4;1;1;2
Turtle;2;1;12;21;2
Turtle;2;1;16;15;2
Grass;0;0;2;2;2
Dandelion;0;0;8;10;2
Guarana;0;0;11;16;2
Wolfberries;99;0;18;19;2
Borscht;10;0;20;20;2

*/


int World::loadFile(std::string filepath) {
    std::ifstream file(filepath);
    if (!file.is_open()) {
        std::cerr << "Cannot open file." << std::endl;
        return 0;
    }

    //std::vector<Organism*> organisms;
    std::string line;

    std::getline(file, line);
    std::istringstream iss(line);
    std::string token;
    int width, height, turn;
    std::getline(iss, token, ';');
    this->width = std::stoi(token);
    std::getline(iss, token, ';');
    this->height = std::stoi(token);
    std::getline(iss, token, ';');
    this->turn = std::stoi(token);


    while (std::getline(file, line)) {
        std::istringstream iss(line);
        std::string token;
        std::string name;
        int strength, initiative, x, y, age;
        
        //Reading organism data from file
        std::getline(iss, token, ';');
        name = token;
        std::getline(iss, token, ';');
        strength = std::stoi(token);
        std::getline(iss, token, ';');
        initiative = std::stoi(token);
        std::getline(iss, token, ';');
        x = std::stoi(token);
        std::getline(iss, token, ';');
        y = std::stoi(token);
        std::getline(iss, token, ';');
        age = std::stoi(token);


        Organism* organism = nullptr;
        if (name == "Antilope") {
            delete organism;
            Antilope* organism = new Antilope(x,y, this->organisms);
            organism->setStrength(strength);
            organism->setAge(age);
            this->organisms.push_back(organism);
        }
        else if (name == "Fox") {
            delete organism;
            Fox* organism = new Fox(x, y, this->organisms);
            organism->setStrength(strength);
            organism->setAge(age);
            this->organisms.push_back(organism);
        }
        else if (name == "Human") {
            delete organism;
            Human* organism = new Human(x, y, this->organisms);
            organism->setStrength(strength);
            organism->setAge(age);
            this->organisms.push_back(organism);
        }
        else if (name == "Sheep") {
            delete organism;
            Sheep* organism = new Sheep(x, y, this->organisms);
            organism->setStrength(strength);
            organism->setAge(age);
            this->organisms.push_back(organism);
        }
        else if (name == "Turtle") {
            delete organism;
            Turtle* organism = new Turtle(x, y, this->organisms);
            organism->setStrength(strength);
            organism->setAge(age);
            this->organisms.push_back(organism);
        }
        else if (name == "Wolf") {
            delete organism;
            Wolf* organism = new Wolf(x, y, this->organisms);
            organism->setStrength(strength);
            organism->setAge(age);
            this->organisms.push_back(organism);
        }
        else if (name == "Borscht") {
            delete organism;
            Borscht* organism = new Borscht(x, y, this->organisms);
            organism->setStrength(strength);
            organism->setAge(age);
            this->organisms.push_back(organism);
        }
        else if (name == "Dandelion") {
            delete organism;
            Dandelion* organism = new Dandelion(x, y, this->organisms);
            organism->setStrength(strength);
            organism->setAge(age);
            this->organisms.push_back(organism);
        }
        else if (name == "Grass") {
            delete organism;
            Grass* organism = new Grass(x, y, this->organisms);
            organism->setStrength(strength);
            organism->setAge(age);
            this->organisms.push_back(organism);
        }
        else if (name == "Guarana") {
            delete organism;
            Guarana* organism = new Guarana(x, y, this->organisms);
            organism->setStrength(strength);
            organism->setAge(age);
            this->organisms.push_back(organism);
        }
        else if (name == "Wolfberries") {
            delete organism;
            Wolfberries* organism = new Wolfberries(x, y, this->organisms);
            organism->setStrength(strength);
            organism->setAge(age);
            this->organisms.push_back(organism);
        }
    }

    file.close();
    return 1;
}