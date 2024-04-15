#include "fox.h"

Fox::Fox(int x, int y, std::vector<Organism*> otherOrganisms)
    : Animal("Fox", 3, 7, x, y, otherOrganisms) {}

Fox::~Fox() {}

Organism* Fox::clone() {
    std::cout << this->name << " is born.\n";
    return new Fox(*this);
}

void Fox::draw() {
    textcolor(BROWN);
    Organism::draw();
}

void Fox::action(int width, int height) {
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

    //Check if Fox moved
    if (preX == getX() && preY == getY())
        return action(width, height);

    //Check if Fox doesnt meet someone stronger than him, if so make a different move.
    for (int i = 0; i < otherOrganisms.size(); i++) {
        if (this != otherOrganisms[i] && otherOrganisms[i]->getX() == getX() && otherOrganisms[i]->getY() == getY()) {
            if (getStrength() < otherOrganisms[i]->getStrength()) {
                setX(preX);
                setY(preY);
                return action(width, height);
            }
        }
    }

    this->setAge(getAge() + 1);
    std::cout << *this;
}

int Fox::collision(Organism* organism) {
    return Animal::collision(organism);
}
