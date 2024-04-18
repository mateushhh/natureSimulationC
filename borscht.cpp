#include "borscht.h"

Borscht::Borscht(int x, int y, std::vector<Organism*> otherOrganisms)
    : Plant("Borscht", 10, 0, x, y, otherOrganisms) {}

Borscht::~Borscht() {}

Organism* Borscht::clone() {
    return new Borscht(*this);
}

void Borscht::draw() {
    textcolor(BLACK);
    textbackground(WHITE);
    Organism::draw();
}

int Borscht::action(int width, int height) {
    //Make it kill everything around it
    this->setAge(getAge() + 1);
    return NOTHING;
}

int Borscht::collision(Organism* organism) {
    return Plant::collision(organism);
}
