#pragma once
#include "plant.h"

class Borscht : public Plant {
public:
    Borscht(int x, int y, std::vector<Organism*> otherOrganisms);
    ~Borscht();

    Organism* clone() override;
    void draw() override;
    int action(int width, int height) override;
    int collision(Organism* organism) override;
};


