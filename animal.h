#pragma once
#include "organism.h"

class Animal : public Organism {
public:
    Animal(std::string name, int strength, int initiative, int x, int y, std::vector<Organism*> otherOrganisms);
    virtual ~Animal();

    virtual Organism* clone() override;
    virtual void draw() override;
    virtual void action(int width, int height) override;
    virtual int collision(Organism* organism) override;
};
