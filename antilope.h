#pragma once
#include "animal.h"

class Antilope : public Animal {
public:
    Antilope(int x, int y, std::vector<Organism*> otherOrganisms);
    ~Antilope();

    Organism* clone() override;
    void draw() override;
    virtual int action(int width, int height) override;
    virtual int collision(Organism* organism) override;
};