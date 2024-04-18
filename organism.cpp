#include "organism.h"

//Constructors & Destructors
Organism::Organism(std::string name, int strength, int initiative, int x, int y, std::vector<Organism*> otherOrganisms)
    : name(name), strength(strength), initiative(initiative), x(x), y(y), age(0), life(true), otherOrganisms(otherOrganisms) {}

Organism::~Organism() {}

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

void Organism::setStrength(int strength) {
    this->strength = strength;
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

bool Organism::alive() {
    return this->life;
}

void Organism::die() {
    this->life = false;
}

bool Organism::isAnimal() const { 
    return false; 
}

bool Organism::isPlant() const { 
    return false; 
}

//Drawing organism in the grid
void Organism::draw() {
    gotoxy(2 + 4 * x, y + 1);
    std::cout << name[0];
    textcolor(WHITE);
    textbackground(BLACK);
}

std::ostream& operator<<(std::ostream& os, const Organism& organism) {
    os << organism.name << " [" << organism.age << "] " << "(" << organism.x << ", " << organism.y << ")";
    return os;
}

bool compareInitiative(Organism* a, Organism* b) {
    return a->getInitiative() > b->getInitiative();
};