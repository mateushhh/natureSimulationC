#include <iostream>
#include "world.h"
#include "animal.h"
#include "plant.h"
#include "wolf.h"
#include "grass.h"

int main() {
    World world(10, 10);
    char currentMode = ' ';

    // Creating organisms and adding them to the world
    Wolf* wolf1 = new Wolf(5, 5);
    Wolf* wolf2 = new Wolf(8, 7);
    Grass* grass1 = new Grass(3, 2);
    world.addOrganism(wolf1);
    world.addOrganism(wolf2);
    world.addOrganism(grass1);

    // Main game loop
    while (currentMode != 'Q') {
        switch (currentMode) {
        case ' ' :
            world.drawWorld();
            world.executeTurn();
            
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
