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
    for (int i = 0; i < 3; i++) {
        if (Plant::action(width, height))
            return BREED;
    }
    return NOTHING;
}

int Dandelion::collision(Organism * organism) {
    return Plant::collision(organism);
}
