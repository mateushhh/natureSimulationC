#pragma once
#include "animal.h"

class Sheep : public Animal {
public:
    Sheep(int x, int y, std::vector<Organism*> otherOrganisms);
    ~Sheep();

    Organism* clone() override;
    void draw() override;
    virtual void action(int width, int height) override;
    virtual int collision(Organism* organism) override;
};