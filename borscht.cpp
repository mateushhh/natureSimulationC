#include "borscht.h"

Borscht::Borscht(int x, int y, std::vector<Organism*> otherOrganisms)
    : Plant("Borscht", 10, 0, x, y, otherOrganisms) {}

Borscht::~Borscht() {}

Organism* Borscht::clone() {
    return new Borscht(*this);
}

void Borscht::draw() {
    textcolor(BLACK);
    textbackground(WHITE);
    Organism::draw();
}

int Borscht::action(int width, int height) {
    //Kills everything around it
    int numberOfOrganisms = (int)this->otherOrganisms.size();
    for (int i = 0; i < numberOfOrganisms; i++) {
        if (this->otherOrganisms[i]->getX() == this->getX() - 1 && this->otherOrganisms[i]->getY() == this->getY())
            otherOrganisms[i]->die();
        else if (this->otherOrganisms[i]->getX() == this->getX() + 1 && this->otherOrganisms[i]->getY() == this->getY())
            otherOrganisms[i]->die();
        else if (this->otherOrganisms[i]->getX() == this->getX() && this->otherOrganisms[i]->getY() == this->getY() - 1)
            otherOrganisms[i]->die();
        else if (this->otherOrganisms[i]->getX() == this->getX() && this->otherOrganisms[i]->getY() == this->getY() + 1)
            otherOrganisms[i]->die();
        if (!this->otherOrganisms[i]->alive())
            std::cout << "Borsch killed " << otherOrganisms[i]->getName() << '\n';
    }
    this->setAge(getAge() + 1);
    return NOTHING;
}

int Borscht::collision(Organism* organism) {
    return Plant::collision(organism);
}
