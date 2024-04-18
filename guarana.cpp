#include "guarana.h"

Guarana::Guarana(int x, int y, std::vector<Organism*> otherOrganisms)
    : Plant("Guarana", 0, 0, x, y, otherOrganisms) {}

Guarana::~Guarana() {}

Organism* Guarana::clone() {
    return new Guarana(*this);
}

void Guarana::draw() {
    textcolor(BLACK);
    textbackground(RED);
    Organism::draw();
}

int Guarana::action(int width, int height) {
    return Plant::action(width, height);
}

int Guarana::collision(Organism* organism) {
    if (this->getStrength() >= organism->getStrength()) {
        return KILL;
    }
    else if (this->getStrength() < organism->getStrength()) {
        if (organism->isAnimal())
            organism->setStrength(organism->getStrength()+3);
        return DIES;
    }
    return NOTHING;
}
