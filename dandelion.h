#pragma once
#include "plant.h"

class Dandelion : public Plant {
public:
    Dandelion(int x, int y, std::vector<Organism*> otherOrganisms);
    ~Dandelion();
    
    Organism* clone() override;
    void draw() override;
    int action(int width, int height) override;
    int collision(Organism* organism) override;
};


