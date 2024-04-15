#include "organism.h"

//Constructors & Destructors
Organism::Organism(std::string name, int strength, int initiative, int x, int y)
    : name(name), strength(strength), initiative(initiative), x(x), y(y), age(0) {}

Organism::~Organism() {
    std::cout << name << " has died.\n";
}

//Setters & Getters
void Organism::setX(int x) {
    this->x = x;
}

void Organism::setY(int y) {
    this->y = y;
}

void Organism::setAge(int age) {
    this->age = age;
}

int Organism::getX() {
    return this->x;
}

int Organism::getY() {
    return this->y;
}

int Organism::getAge() {
    return this->age;
}

int Organism::getStrength() {
    return this->strength;
}

int Organism::getInitiative() {
    return this->initiative;
}

std::string Organism::getName() {
    return this->name;
}

//Drawing organism in the grid
void Organism::draw() {
    gotoxy(2 + 4 * x, y + 1);
    std::cout << name[0];
    textcolor(WHITE);
    textbackground(BLACK);
}

std::ostream& operator<<(std::ostream& os, const Organism& organism) {
    os << organism.name << " [" << organism.age << "] " << "(" << organism.x << ", " << organism.y << ")\n";
    return os;
}

bool compareInitiative(Organism* a, Organism* b) {
    return a->getInitiative() > b->getInitiative();
};