#include "human.h"

Human::Human(int x, int y, std::vector<Organism*> otherOrganisms)
    : Animal("Human", 5, 4, x, y, otherOrganisms) {}

Human::~Human() {}

void Human::draw() {
    textcolor(BLUE);
    textbackground(WHITE);
    Organism::draw();
}

int Human::action(int width, int height) {
    if (this->alive()) {
        char key;
        int dx = 0, dy = 0;

        std::cout << "Human move: ";
        key = std::toupper(getche());
        std::cout << '\n';
        switch (key) {
        case 'W':
            dy = -1;
            break;
        case 'A':
            dx = -1;
            break;
        case 'S':
            dy = 1;
            break;
        case 'D':
            dx = 1;
            break;
        case 'E':
            this->special();
        default:
            break;
        }

        move(dx, dy, width, height);
        this->cooldown -= 1;
        this->setAge(getAge() + 1);
    }
    return NOTHING;
}

int Human::collision(Organism* organism) {
    if (this->getStrength() >= organism->getStrength()) {
        return KILL;
    }
    else if (this->getStrength() < organism->getStrength()) {
        if (this->cooldown > 5) {
            return NOTHING;
        }
        return DIES;
    }
    return 0;
}

int Human::move(int dx, int dy, int width, int height) {
    int newX = getX() + dx;
    int newY = getY() + dy;
    if (newX >= 1 && newX <= width && newY >= 1 && newY <= height) {
        setX(newX);
        setY(newY);
        return 1; 
    }
    return 0;
}

void Human::special() {
    if (this->cooldown <= 0) {
        this->cooldown = 10;

    }
}