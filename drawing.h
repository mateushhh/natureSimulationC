#pragma once
#include <iostream>

// Funkcja ustawia kursor na podanej pozycji na ekranie terminala/konsoli
void gotoxy(int x, int y) {
    std::cout << "\033[" << y << ";" << x << "H"; // Ustawia kursor na pozycji (x, y)
}