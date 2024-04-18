#include "animal.h"

Animal::Animal(std::string name, int strength, int initiative, int x, int y, std::vector<Organism*> otherOrganisms)
    : Organism(name, strength, initiative, x, y, otherOrganisms) {
    //std::cout << this->name << " is born.\n";
}

Animal::~Animal() {
    //std::cout << this->name << " has died.\n";
}

bool Animal::isAnimal() const {
    return true;
};

Organism* Animal::clone() {
    std::cout << this->name << " is born.\n";
    return new Animal(*this);
}

void Animal::draw() {
    Organism::draw();
}

int Animal::action(int width, int height) {
    int direction = (rand() % 4) + 1;
    int preX = getX();
    int preY = getY();

    switch (direction) {
    case UP:
        if (this->getY() != 1)
            setY(getY() - 1);
        break;
    case LEFT:
        if (this->getX() != 1)
            setX(getX() - 1);
        break;
    case DOWN:
        if (this->getY() != height)
            setY(getY() + 1);
        break;
    case RIGHT:
        if (this->getX() != width)
            setX(getX() + 1);
        break;
    }

    if (preX == getX() && preY == getY())
        return action(width,height);

    this->setAge(getAge() + 1);
    //std::cout << *this;
    return NOTHING;
}

int Animal::collision(Organism* organism) {
    if (this->name == organism->getName()) {
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