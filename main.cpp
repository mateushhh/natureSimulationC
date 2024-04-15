#include <iostream>
#include "world.h"
#include "animal.h"
#include "plant.h"
#include "wolf.h"
#include "sheep.h"
#include "fox.h"
#include "turtle.h"
#include "grass.h"

int main() {
    World* world = new World(20, 20);
    char currentMode = ' ';

    // Creating organisms and adding them to the world
    Wolf* wolf1 = new Wolf(3, 12, world->organisms);
    Wolf* wolf2 = new Wolf(13, 2, world->organisms);
    Sheep* sheep1 = new Sheep(9, 6, world->organisms);
    Sheep* sheep2 = new Sheep(3, 8, world->organisms);
    Sheep* sheep3 = new Sheep(6, 10, world->organisms);
    Fox* fox1 = new Fox(5, 17, world->organisms);
    Fox* fox2 = new Fox(17, 5, world->organisms);
    Turtle* turtle1 = new Turtle(10, 7, world->organisms);
    Turtle* turtle2 = new Turtle(12, 9, world->organisms);
    //Grass* grass1 = new Grass(3, 2, world->organisms);
    world->addOrganism(wolf1);
    world->addOrganism(wolf2);
    world->addOrganism(sheep1);
    world->addOrganism(sheep2);
    world->addOrganism(sheep3);
    world->addOrganism(fox1);
    world->addOrganism(fox2);
    world->addOrganism(turtle1);
    world->addOrganism(turtle2);
    //world->addOrganism(grass1);

    // Main game loop
    while (currentMode != 'Q') {
        switch (currentMode) {
        case ' ' :
            world->drawWorld();
            world->executeTurn();
            
            break;
        case 'W' :
            break;
        case 'A':
            break;
        case 'S':
            break;
        case 'D':
            break;
        }
        currentMode = std::toupper(getch());
    }

    return 0;
}
