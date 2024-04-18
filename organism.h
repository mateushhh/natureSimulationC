#pragma once
#include <string>
#include <vector>
#include <iostream>
#include "conio2.h"
class World;

#define UP 1
#define LEFT 2
#define DOWN 3
#define RIGHT 4
#define DODGE 4
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
    int age;
    bool life;
    std::string name;
    std::vector<Organism*> otherOrganisms;

public:
    Organism(std::string name, int strength, int initiative, int x, int y, std::vector<Organism*> otherOrganisms);
    virtual ~Organism();

    void setX(int x);
    void setY(int y);
    void setAge(int age);
    void setStrength(int strength);
    int getX();
    int getY();
    int getAge();
    int getStrength();
    int getInitiative();
    std::string getName();
    virtual bool isAnimal() const;
    virtual bool isPlant() const;

    bool alive();
    void die();
    virtual Organism* clone() = 0;
    virtual void draw();
    virtual int action(int width, int height) = 0;
    virtual int collision(Organism* organism) = 0;

    friend std::ostream& operator<<(std::ostream& os, const Organism& organism);
};

bool compareInitiative(Organism* a, Organism* b);