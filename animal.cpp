#include "animal.h"

Animal::Animal(std::string name, int strength, int initiative, int x, int y)
    : Organism(name, strength, initiative, x, y) {}

Animal::~Animal() {}

Organism* Animal::clone() {
    return new Animal(*this);
}

void Animal::draw() {
    textcolor(RED);
    Organism::draw();
}

void Animal::action(int width, int height) {
    int direction;
    while (1) {
        direction = (rand() % 4) + 1;
        switch (direction) {
        case UP:
            if (this->getY() != 1) {
                this->setY(getY() - 1);
                std::cout << name << " moves to (" << getX() << ", " << getY() << ").\n";
                return;
            }
            break;
        case LEFT:
            if (this->getX() != 1) {
                this->setX(getX() - 1);
                std::cout << name << " moves to (" << getX() << ", " << getY() << ").\n";
                return;
            }
            break;
        case DOWN:
            if (this->getY() != height) {
                this->setY(getY() + 1);
                std::cout << name << " moves to (" << getX() << ", " << getY() << ").\n";
                return;
            }
            break;
        case RIGHT:
            if (this->getX() != width) {
                this->setX(getX() + 1);
                std::cout << name << " moves to (" << getX() << ", " << getY() << ").\n";
                return;
            }
            break;
        }
    }
}

int Animal::collision(Organism* organism) {
    if (this->name[0] == organism->getName()[0]) {
        return BREED;
    }
    else if (this->getStrength() >= organism->getStrength()) {
        return KILL;
    }
    else if (this->getStrength() < organism->getStrength()) {
        return DIES;
    }
    return 0;
}