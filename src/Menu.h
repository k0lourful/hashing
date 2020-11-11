#pragma once

#include <iostream>
#include "HashTable.h"
#include "clearScreen.h"

void choice(const int &c, HashTable &arr) {
    clearScreen();

    switch (c) {
        case 0: {

            break;
        }

        default:
            std::cout << "Invalid input, try again.\n\n";
            break;
    }
}

void menu(HashTable &arr) {
    short int c;
    while (true) {
        std::cout << "Options:\n\n";
        std::cout << "0. Print table\n";

        std::cin >> c;

        choice(c, arr);
    }
}
