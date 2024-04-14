#pragma once
#include "animal.h"

class Wolf : public Animal {
public:
    Wolf(int x, int y);
    ~Wolf();

    virtual void action(int width, int height) override;
    virtual int collision(Organism* organism) override;
};


