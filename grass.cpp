#include "grass.h"

Grass::Grass(int x, int y, std::vector<Organism*> otherOrganisms)
    : Plant("Grass", 0, 0, x, y, otherOrganisms) {}

Grass::~Grass() {}

void Grass::action(int width, int height) {}

int Grass::collision(Organism* organism) {
    return NOTHING;
}
