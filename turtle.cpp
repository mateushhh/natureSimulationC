#include "turtle.h"

Turtle::Turtle(int x, int y, std::vector<Organism*> otherOrganisms)
    : Animal("Turtle", 2, 1, x, y, otherOrganisms) {}

Turtle::~Turtle() {}

Organism* Turtle::clone() {
    std::cout << this->name << " is born.\n";
    return new Turtle(*this);
}

void Turtle::draw() {
    textcolor(GREEN);
    Organism::draw();
}

void Turtle::action(int width, int height) {
    int direction;
    int preX = getX();
    int preY = getY();

    //75% that turtle stays in place
    int stay = rand() % 4;
    while (!stay) {
        direction = (rand() % 4) + 1;
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

        //Check if Turtle moved
        if (preX != getX() || preY != getY())
            break;
    }

    this->setAge(getAge() + 1);
    std::cout << *this;
}

int Turtle::collision(Organism* organism) {
    if (this->name[0] == organism->getName()[0]) {
        return BREED;
    }
    else if (this->getStrength() >= organism->getStrength()) {
        return KILL;
    }
    else if (this->getStrength() < organism->getStrength()) {
        if(organism->getStrength() >= 5)
            return DIES;
    }
    return NOTHING;
}
