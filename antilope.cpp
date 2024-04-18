#include "antilope.h"

Antilope::Antilope(int x, int y, std::vector<Organism*> otherOrganisms)
    : Animal("Antilope", 4, 4, x, y, otherOrganisms) {}

Antilope::~Antilope() {}

Organism* Antilope::clone() {
    //std::cout << this->name << " is born.\n";
    return new Antilope(*this);
}

void Antilope::draw() {
    textcolor(YELLOW);
    Organism::draw();
}

int Antilope::action(int width, int height) {
    int direction = (rand() % 4) + 1;
    int preX = getX();
    int preY = getY();

    switch (direction) {
    case UP:
        if (this->getY() > 2)
            setY(getY() - 2);
        break;
    case LEFT:
        if (this->getX() > 2)
            setX(getX() - 2);
        break;
    case DOWN:
        if (this->getY() < height-1)
            setY(getY() + 2);
        break;
    case RIGHT:
        if (this->getX() < width-1)
            setX(getX() + 2);
        break;
    }

    if (preX == getX() && preY == getY())
        return action(width, height);

    this->setAge(getAge() + 1);
    //std::cout << *this;
    return NOTHING;
}

int Antilope::collision(Organism* organism) {
    if (this->name[0] == organism->getName()[0]) {
        return BREED;
    }
    else if (this->getStrength() >= organism->getStrength()) {
        return KILL;
    }
    else if (this->getStrength() < organism->getStrength()) {
        if (rand() % 2) {
            return DODGE;
        }
        return DIES;
    }
    return NOTHING;
}
