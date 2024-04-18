#pragma once
#include "animal.h"

class Wolf : public Animal {
public:
    Wolf(int x, int y, std::vector<Organism*> otherOrganisms);
    ~Wolf();

    Organism* clone() override;
    void draw() override;
    virtual int action(int width, int height) override;
    virtual int collision(Organism* organism) override;
};