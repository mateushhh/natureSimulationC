#pragma once
#include <vector>
#include <iostream>
#include <algorithm>
#include <fstream>
#include <sstream>
#include "conio2.h"
#include "organism.h"

#include "antilope.h"
#include "fox.h"
#include "human.h"
#include "sheep.h"
#include "turtle.h"
#include "wolf.h"
#include "borscht.h"
#include "dandelion.h"
#include "grass.h"
#include "guarana.h"
#include "wolfberries.h"


class Organism;

class World {
private:
    int width;
    int height;
    int turn = 0;
    std::string activitylog;

public:
    std::vector<Organism*> organisms;

    World(int width, int height);
    ~World();

    Organism* getOrganism(int i);
    void addOrganism(Organism* organism);
    void removeOrganism(int i);
    void sortOrganisms();
    void drawWorld();
    void executeTurn();
    void saveFile();
    int loadFile(std::string filename);
    void fill();
};
