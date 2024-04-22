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
            world->fill();
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
