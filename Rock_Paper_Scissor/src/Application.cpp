#include <iostream>
#include "utilities.hpp"

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
        switch (userInputChar) {
        case 'Y': {
            do {
                // Clear terminal
                CLEAR;

                // Print "graphics"
                PrintGameMenu();

                cin >> userInputChar;
                userInputChar = toupper(userInputChar);
            } while (userInputChar != 'R' && userInputChar != 'P' && userInputChar != 'S');

            char computerChoice = GetComputerChoice();

            // Check for draw
            if (userInputChar == computerChoice) {
                // Clear terminal
                CLEAR;

                // Print "graphics"
                PrintDraw();
            }
            // Check for win
            else if ((userInputChar == 'R' && computerChoice == 'S') || (userInputChar == 'P' && computerChoice == 'R') || (userInputChar == 'S' && computerChoice == 'P')) {
                // Clear terminal
                CLEAR;

                // Print "graphics"
                PrintWin();
            }
            // Lose
            else {
                // Clear terminal
                CLEAR;

                // Print "graphics"
                PrintLoss();
            }

            // Ask to play again
            PrintPlayAgain();

            cin >> userInputChar;
            userInputChar = toupper(userInputChar);

            if (userInputChar == 'N') {
                done = true;
            }

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