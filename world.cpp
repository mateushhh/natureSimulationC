#include "world.h"

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
    std::sort(organisms.begin(), organisms.end(), compareInitiative);
}

void World::drawWorld() {
    system("cls"); 

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
    std::cout << "WASD - Walking\n";
    std::cout << "SPACE - Next turn\n\n";
    std::cout << "Turn: " << turn << "\n";
    std::cout << "Activity Log:\n";
}

void World::executeTurn() {
    sortOrganisms();
    int result ,preX, preY;
    int numberOfAnimals = (int)organisms.size();
    for (int i = 0; i < numberOfAnimals; i++) {
        preX = organisms[i]->getX();
        preY = organisms[i]->getY();
        organisms[i]->action(width, height);
        for (int j = 0; j < numberOfAnimals; j++) {
            if (i != j && organisms[i]->getX() == organisms[j]->getX() && organisms[i]->getY() == organisms[j]->getY()) {
                result = organisms[i]->collision(organisms[j]);
                if (result == KILL);
                    //removeOrganism(j);
                else if (result == DIES)
                    removeOrganism(i);
                else if (result == BREED) {
                    organisms[i]->setX(preX);
                    organisms[i]->setY(preY);
                    if (organisms[i]->getAge() < 10 || organisms[j]->getAge() < 10)
                        break;
                    Organism* newOrganism = organisms[i]->clone();
                    newOrganism->setAge(0);
                    newOrganism->action(width, height);
                    addOrganism(newOrganism);
                    break;
                }
            }
        }
    }
    sortOrganisms();
    turn++;
}