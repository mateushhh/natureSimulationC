#include "plant.h"

Plant::Plant(std::string name, int strength, int initiative, int x, int y, std::vector<Organism*> otherOrganisms)
    : Organism(name, strength, initiative, x, y, otherOrganisms) {}

Plant::~Plant() {}

bool Plant::isPlant() const {
    return true;
};

Organism* Plant::clone() {
    return new Plant(*this);
}

void Plant::draw() {
    textcolor(BLACK);
    textbackground(LIGHTGREEN);
    Organism::draw();
}

int Plant::action(int width, int height) {
    //std::cout << *this;
    if (this->getAge()==0) { 
        int direction = (rand() % 4) + 1;

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
    }
    else {
        //5% chance of plant spreading to another grid block
        if (!(rand() % 20)) {
            this->setAge(getAge() + 1);
            return BREED;
        }
    }

    this->setAge(getAge() + 1);
    return NOTHING;
}

int Plant::collision(Organism* organism) {
    if (this->getStrength() >= organism->getStrength()) {
        return KILL;
    }
    else if (this->getStrength() < organism->getStrength()) {
        return DIES;
    }
    return 0;
}