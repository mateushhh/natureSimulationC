#pragma once
#include "organism.h"

class Animal : public Organism {
public:
    Animal(std::string name, int strength, int initiative, int x, int y);
    virtual ~Animal();

    Organism* clone() override;
    void draw() override;
    virtual void action(int width, int height) override;
    virtual int collision(Organism* organism) override;
};
