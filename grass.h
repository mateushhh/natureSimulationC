#pragma once
#include "plant.h"

class Grass : public Plant {
public:
    Grass(int x, int y, std::vector<Organism*> otherOrganisms);
    ~Grass();

    //Add clone() and draw()
    void action(int width, int height) override;
    int collision(Organism* organism) override;
};


