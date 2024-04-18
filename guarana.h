#pragma once
#include "plant.h"

class Guarana : public Plant {
public:
    Guarana(int x, int y, std::vector<Organism*> otherOrganisms);
    ~Guarana();

    Organism* clone() override;
    void draw() override;
    int action(int width, int height) override;
    int collision(Organism* organism) override;
};


