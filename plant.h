#pragma once
#include "organism.h"

class Plant : public Organism {
public:
    Plant(std::string name, int strength, int initiative, int x, int y, std::vector<Organism*> otherOrganisms);
    virtual ~Plant();

    virtual bool isPlant() const;
    virtual Organism* clone() override;
    virtual void draw() override;
    virtual int action(int width, int height) override;
    virtual int collision(Organism* organism) override;
};