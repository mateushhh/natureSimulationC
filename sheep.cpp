#include "sheep.h"

Sheep::Sheep(int x, int y, std::vector<Organism*> otherOrganisms)
    : Animal("Sheep", 4, 4, x, y, otherOrganisms) {}

Sheep::~Sheep() {}

Organism* Sheep::clone() {
    std::cout << this->name << " is born.\n";
    return new Sheep(*this);
}

void Sheep::draw() {
    textcolor(LIGHTBLUE);
    Organism::draw();
}

int Sheep::action(int width, int height) {
    return Animal::action(width, height);
}

int Sheep::collision(Organism* organism) {
    return Animal::collision(organism);
}
