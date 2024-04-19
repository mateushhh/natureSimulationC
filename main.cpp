#include <iostream>
#include "world.h"
#include "animal.h"
#include "plant.h"
#include "wolf.h"
#include "sheep.h"
#include "fox.h"
#include "turtle.h"
#include "antilope.h"
#include "grass.h"
#include "dandelion.h"
#include "guarana.h"
#include "wolfberries.h"
#include "borscht.h"
#include "human.h"

int main() {
    settitle("Mateusz Grzonka s198023");
    bool menu = true;
    World* world = new World(20, 20);

    while (menu) {
        system("cls");
        gotoxy(1, 1);
        std::cout << "NATURE SIMULATION\n";
        std::cout << "Mateusz Grzonka s198023\n";
        std::cout << "1. New Game\n";
        std::cout << "2. Load Game\n";
        std::cout << "3. Quit\n";

        std::string filename;
        char input = getch();

        switch (input) {
        case '1':
            int width, height;
            system("cls");
            gotoxy(1, 1);
            std::cout << "Width: ";
            std::cin >> width;
            std::cout << "Height: ";
            std::cin >> height;
            delete world;
            world = new World(width, height);
            menu = false;
            break;
        case '2':
            system("cls");
            gotoxy(1, 1);
            std::cout << "Filename: ";
            std::cin >> filename;
            world->loadFile(filename);
            menu = false;
            break;
        case '3':
            return 0;
        }
    }
    char currentMode = ' ';

    // Creating organisms and adding them to the world
    /*
    Wolf* wolf1 = new Wolf(3, 12, world->organisms);
    Wolf* wolf2 = new Wolf(13, 2, world->organisms);
    Sheep* sheep1 = new Sheep(9, 6, world->organisms);
    Sheep* sheep2 = new Sheep(3, 8, world->organisms);
    Fox* fox1 = new Fox(5, 17, world->organisms);
    Fox* fox2 = new Fox(17, 5, world->organisms);
    Turtle* turtle1 = new Turtle(12, 20, world->organisms);
    Turtle* turtle2 = new Turtle(17, 15, world->organisms);
    Antilope* antilope1 = new Antilope(15, 3, world->organisms);
    Antilope* antilope2 = new Antilope(14, 5, world->organisms);
    Grass* grass1 = new Grass(3, 2, world->organisms);
    Dandelion* dandelion1 = new Dandelion(9, 10, world->organisms);
    Guarana* guarana1 = new Guarana(10, 16, world->organisms);
    Wolfberries* wolfberries1 = new Wolfberries(18, 18, world->organisms);
    Borscht* borscht1 = new Borscht(20, 20, world->organisms);
    Human* human = new Human(1, 1, world->organisms);
    /*
    world->addOrganism(wolf1);
    world->addOrganism(wolf2);
    world->addOrganism(sheep1);
    world->addOrganism(sheep2);
    world->addOrganism(fox1);
    world->addOrganism(fox2);
    world->addOrganism(turtle1);
    world->addOrganism(turtle2);
    world->addOrganism(antilope1);
    world->addOrganism(antilope2);
    world->addOrganism(grass1);
    world->addOrganism(dandelion1);
    world->addOrganism(guarana1);
    world->addOrganism(wolfberries1);
    world->addOrganism(borscht1);
    world->addOrganism(human);
    */

    // Main game loop
    world->executeTurn();
    while (currentMode != 'Q') {
        switch (currentMode) {
        case ' ' :
            world->drawWorld();
            world->executeTurn();
            break;
        case 'P' :
            world->saveFile();
            break;
        }
        currentMode = std::toupper(getch());
    }

    return 0;
}
