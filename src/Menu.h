#pragma once

#include <iostream>
#include "HashTable.h"
#include "clearScreen.h"

void choice(const int &c, HashTable &t) {
    clearScreen();

    switch (c) {
        case 0: {
            int s = t.getSize();
            if (!s) std::cout << "Table is empty.\n\n";
            else
                for (int i = 0; i < s; ++i)
                    std::cout << i << " -> " << t.getValue(i) << "\n";
            break;
        }

        case 1: {
            if (!t.getSize()) t.clear();

            int s;
            std::cout << "Enter table size: ";
            std::cin >> s;
            t.generateRandomTable(s);
            break;
        }

        case 2: {
            int val;
            std::cout << "Enter value: ";
            std::cin >> val;

            int res = t.insert(val);
            if (res == -1) std::cout << "Table is empty.\n\n";
            else if (res == 1) std::cout << "Table is full.\n\n";
            else std::cout << "Value inserted successfully.\n\n";

            break;
        }

        case 3: {
            if (!t.getSize()) std::cout << "Table is empty.\n\n";
            else {
                int val;
                std::cout << "Enter value: ";
                std::cin >> val;
                if (t.find(val))
                    std::cout << "Value exists.\n\n";
                else
                    std::cout << "Value doesn't exist.\n\n";
            }
            break;
        }

        case 4: {
            if (!t.getSize()) std::cout << "Table is empty.\n\n";
            else {
                int val;
                std::cout << "Enter value: ";
                std::cin >> val;
                if (t.remove(val)) std::cout << "Value doesn't exist.\n\n";
                else std::cout << "Value removed successfully.\n\n";
            }
            break;
        }

        case 5: {
            t.clear();
            std::cout << "Table cleared.\n\n";
            break;
        }

        case 6: {
            int s;
            std::cout << "Enter new table size: ";
            std::cin >> s;
            t.createTable(s);
            std::cout << "New table created.\n\n";

            break;
        }

        default:
            std::cout << "Invalid input, try again.\n\n";
            break;
    }
}

void menu(HashTable &t) {
    int c;
    std::cout << "Enter table size: ";
    std::cin >> c;
    t.createTable(c);

    while (true) {
        std::cout << "Options:\n\n";
        std::cout << "0. Print table\n";
        std::cout << "1. Fill random table\n";
        std::cout << "2. Insert value\n";
        std::cout << "3. Find if value exists\n";
        std::cout << "4. Remove value\n";
        std::cout << "5. Clear table\n";
        std::cout << "6. Create new table\n\n";
        std::cin >> c;

        choice(c, t);
    }
}
