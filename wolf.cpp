#include "wolf.h"

Wolf::Wolf(int x, int y, std::vector<Organism*> otherOrganisms)
    : Animal("Wolf", 9, 5, x, y, otherOrganisms) {}

Wolf::~Wolf() {}

Organism* Wolf::clone() {
    std::cout << this->name << " is born.\n";
    return new Wolf(*this);
}

void Wolf::draw() {
    textcolor(RED);
    Organism::draw();
}

void Wolf::action(int width, int height) {
    Animal::action(width, height);
}

int Wolf::collision(Organism* organism) {
    return Animal::collision(organism);
}
