#pragma once
#include "animal.h"

class Turtle : public Animal {
public:
    Turtle(int x, int y, std::vector<Organism*> otherOrganisms);
    ~Turtle();

    Organism* clone() override;
    void draw() override;
    virtual void action(int width, int height) override;
    virtual int collision(Organism* organism) override;
};