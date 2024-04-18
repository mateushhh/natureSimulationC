#include "dandelion.h"

Dandelion::Dandelion(int x, int y, std::vector<Organism*> otherOrganisms)
    : Plant("Dandelion", 0, 0, x, y, otherOrganisms) {}

Dandelion::~Dandelion() {}

Organism* Dandelion::clone() {
    return new Dandelion(*this);
}

void Dandelion::draw() {
    textcolor(BLACK);
    textbackground(YELLOW);
    Organism::draw();
}

int Dandelion::action(int width, int height) {
    if (this->getAge() == 0) {
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
    this->setAge(getAge() + 1);
    for (int i = 0; i < 3; i++) {
        //5% chance of plant spreading to another grid block
        if (!(rand() % 20)){
            return BREED;
        }
    }       
    return NOTHING;
    }

int Dandelion::collision(Organism * organism) {
    return Plant::collision(organism);
}
