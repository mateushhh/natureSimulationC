#include "wolfberries.h"

Wolfberries::Wolfberries(int x, int y, std::vector<Organism*> otherOrganisms)
    : Plant("Wolfberries", 99, 0, x, y, otherOrganisms) {}

Wolfberries::~Wolfberries() {}

Organism* Wolfberries::clone() {
    return new Wolfberries(*this);
}

void Wolfberries::draw() {
    textcolor(BLACK);
    textbackground(LIGHTRED);
    Organism::draw();
}

int Wolfberries::action(int width, int height) {
    return Plant::action(width, height);
}

int Wolfberries::collision(Organism* organism) {
    return Plant::collision(organism);
}
