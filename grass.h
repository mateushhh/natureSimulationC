#pragma once
#include "plant.h"

class Grass : public Plant {
public:
    Grass(int x, int y);
    ~Grass();

    void action(int width, int height) override;
    int collision(Organism* organism) override;
};


