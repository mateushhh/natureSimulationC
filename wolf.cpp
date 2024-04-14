#include "wolf.h"

Wolf::Wolf(int x, int y)
    : Animal("Wolf", 9, 5, x, y) {}

Wolf::~Wolf() {}

void Wolf::action(int width, int height) {
    Animal::action(width, height);
}

int Wolf::collision(Organism* organism) {
    return Animal::collision(organism);
}
