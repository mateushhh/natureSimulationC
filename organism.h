#pragma once
#include <string>
#include <iostream>
#include "conio2.h"
#define UP 1
#define LEFT 2
#define DOWN 3
#define RIGHT 4
#define BREED 3
#define KILL 2
#define DIES 1
#define NOTHING 0

class Organism {
protected:
    int strength;
    int initiative;
    int x;
    int y;
    std::string name;

public:
    Organism(std::string name, int strength, int initiative, int x, int y);
    virtual ~Organism();

    void setX(int x);
    void setY(int y);
    int getX();
    int getY();
    int getStrength();
    int getInitiative();
    std::string getName();

    virtual Organism* clone() = 0;
    virtual void draw();
    virtual void action(int width, int height) = 0;
    virtual int collision(Organism* organism) = 0;

    friend std::ostream& operator<<(std::ostream& os, const Organism& organism);
};

bool compareInitiative(Organism* a, Organism* b);