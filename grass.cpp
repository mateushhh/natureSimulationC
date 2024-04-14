#include "grass.h"

Grass::Grass(int x, int y)
    : Plant("Grass", 0, 0, x, y) {}

Grass::~Grass() {}

void Grass::action(int width, int height) {}

int Grass::collision(Organism* organism) {
    return NOTHING;
}
