#include "grass.h"

Grass::Grass(int x, int y, std::vector<Organism*> otherOrganisms)
    : Plant("Grass", 0, 0, x, y, otherOrganisms) {}

Grass::~Grass() {}

Organism* Grass::clone() {
    return new Grass(*this);
}

void Grass::draw() {
    textcolor(BLACK);
    textbackground(LIGHTGREEN);
    Organism::draw();
}

int Grass::action(int width, int height) {
    return Plant::action(width, height);
}

int Grass::collision(Organism* organism) {
    return Plant::collision(organism);
}
