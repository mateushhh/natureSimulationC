#pragma once
#include "animal.h"

class Fox : public Animal {
public:
    Fox(int x, int y, std::vector<Organism*> otherOrganisms);
    ~Fox();

    Organism* clone() override;
    void draw() override;
    virtual int action(int width, int height) override;
    virtual int collision(Organism* organism) override;
};