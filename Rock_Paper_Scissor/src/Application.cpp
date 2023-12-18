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

    while (!done) {
        if (userInputChar == NULL) {
            do {
                // Clear terminal
                CLEAR;

                // Print "graphics"
                PrintTitle();
                PrintMainMenu();

                cin >> userInputChar;
                userInputChar = toupper(userInputChar);
            } while (userInputChar != 'Y' && userInputChar != 'N');
        } 
        else if (userInputChar == 'Y') {
            // Clear terminal
            CLEAR;

            // Game code here...
        }
        else if (userInputChar == 'N') {
            done = true;
            break;
        }
    }

    return 0;
}