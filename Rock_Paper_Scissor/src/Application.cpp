#include <iostream>
#include <cstdlib>
#include <cctype>
#include "titles.hpp"

// --- OS decleration for terminal clearing ---
#define WINDOWS
#define LINUX
#define MACOS

#if defined(WINDOWS)
#define CLEAR system("cls")
#elif defined(LINUX) || defined(MACOS)
#define CLEAR system('clear')
#else
#error "Unsupported OS"
#endif

// Main
int main() {
    using std::cin;
    using std::toupper;

    // Loop status
    bool done = false;
    char userInputChar = NULL;
    int userInputInt = 0;

    while (!done) {
        switch (userInputChar) {
        case 'Y': {
            do {
                // Clear terminal
                CLEAR;

                // Print "graphics"
                PrintTitle();
                PrintGameMenu();

                cin >> userInputInt;
            } while (userInputInt < 1 || userInputInt > 3);

            break;
        }
        case 'N': {
            done = true;
            break;
        }
        default: {
            do {
                // Clear terminal
                CLEAR;

                // Print "graphics"
                PrintTitle();
                PrintMainMenu();

                // Get user input and ensure it is uppercase
                cin >> userInputChar;
                userInputChar = toupper(userInputChar);
            } while (userInputChar != 'Y' && userInputChar != 'N');

            break;
        }
        }
    }

    return 0;
}