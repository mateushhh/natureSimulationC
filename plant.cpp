#include "plant.h"

Plant::Plant(std::string name, int strength, int initiative, int x, int y, std::vector<Organism*> otherOrganisms)
    : Organism(name, strength, initiative, x, y, otherOrganisms) {}

Plant::~Plant() {}

Organism* Plant::clone() {
    return new Plant(*this);
}

void Plant::draw() {
    textcolor(LIGHTGREEN);
    Organism::draw();
    //textbackground(LIGHTGREEN);
    //gotoxy(1 + 4 * x, y + 1);
    //std::cout << ' ' << name[0] << ' ';
    //textcolor(WHITE);
    //textbackground(BLACK);
}

void Plant::action(int width, int height) {
    
}

int Plant::collision(Organism* organism) {
    return NOTHING;
}