#pragma once
#include "plant.h"

class Wolfberries : public Plant {
public:
    Wolfberries(int x, int y, std::vector<Organism*> otherOrganisms);
    ~Wolfberries();

    Organism* clone() override;
    void draw() override;
    int action(int width, int height) override;
    int collision(Organism* organism) override;
};


