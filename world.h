#pragma once
#include <vector>
#include <iostream>
#include <algorithm>
#include "conio2.h"
#include "organism.h"

class World {
private:
    int width;
    int height;
    int turn = 1;
    std::vector<Organism*> organisms; 

public:
    World(int width, int height);
    ~World();

    Organism* getOrganism(int i);
    void addOrganism(Organism* organism);
    void removeOrganism(int i);
    void sortOrganisms();
    void drawWorld();
    void executeTurn();
};
