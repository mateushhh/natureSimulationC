#pragma once
#include "animal.h"

class Human : public Animal {
private:
    int cooldown = 0;
public:
    Human(int x, int y, std::vector<Organism*> otherOrganisms);
    ~Human();

    void draw() override;
    virtual int action(int width, int height) override;
    virtual int collision(Organism* organism) override;
    int move(int dx, int dy, int width, int height);
    void special();
};