#include "utilities.hpp"

#define WIDTH 90

// Macro function for code simplicity
#define PRINT(integer) static_cast<char>(integer)

// Function implementations
void PrintLoop(const int width, const char startingChar, const char middleChar, const char endingChar) {
    for (int i = 0; i <= width; i++) {
        if (i == 0) {
            cout << startingChar;
        }
        else if (i == width) {
            cout << endingChar << endl;
        }
        else {
            cout << middleChar;
        }
    }
}

void PrintTitle() {
    // Print top part of box
    PrintLoop(WIDTH, 218, 196, 191);

    cout << PRINT(179) << "     ____             __   ____                        _____      _                      " << PRINT(179) << endl;
    cout << PRINT(179) << "    / __ \\____  _____/ /__/ __ \\____ _____  ___  _____/ ___/_____(_)_____________  _____ " << PRINT(179) << endl;
    cout << PRINT(179) << "   / /_/ / __ \\/ ___/ //_/ /_/ / __ `/ __ \\/ _ \\/ ___/\\__ \\/ ___/ / ___/ ___/ __ \\/ ___/ " << PRINT(179) << endl;
    cout << PRINT(179) << "  / _, _/ /_/ / /__/ ,< / ____/ /_/ / /_/ /  __/ /   ___/ / /__/ (__  |__  ) /_/ / /     " << PRINT(179) << endl;
    cout << PRINT(179) << " /_/ |_|\\____/\\___/_/|_/_/    \\__,_/ .___/\\___/_/   /____/\\___/_/____/____/\\____/_/      " << PRINT(179) << endl;

    // Print title divider with a modified version of the 'PrintLoop' function
    for (int i = 0; i <= (WIDTH + 10); i++) {
        if (i == 0) {
            cout << PRINT(198);
        }
        else if (i == (WIDTH + 10)) {
            cout << PRINT(181) << endl;
        }
        else if (i >= 34 && i <= 48) {
            cout << " /_/ ";
            i = 48;
        }
        else {
            cout << PRINT(205);
        }
    }
}

void PrintMainMenu() {
    // Print title
    PrintTitle();

    // Print space line
    PrintLoop(WIDTH, 179, ' ', 179);

    // --- Print text ---
    for (int i = 1; i < 11; i++) {
        switch (i) {
        case 1:
            cout << PRINT(179) << " WELCOME...";
            PrintLoop((WIDTH - 12), ' ', ' ', 179);
            break;
        case 2:
            PrintLoop(WIDTH, 179, ' ', 179);
            PrintLoop(WIDTH, 179, ' ', 179);
            break;
        case 3:
            cout << PRINT(179) << " RULES                              ";
            break;
        case 4:
            cout << PRINT(179) << " -----------------------------------";
            break;
        case 5:
            cout << PRINT(179) << " ROCK VS SCISSOR  -> ROCK WINS      ";
            break;
        case 6:
            cout << PRINT(179) << " ROCK VS PAPER    -> PAPER WINS     ";
            break;
        case 7:
            cout << PRINT(179) << " PAPER VS SCISSOR -> SCISSOR WINS   ";
            break;
        case 8:
            cout << PRINT(179) << " -----------------------------------";
            break;
        case 9:
            PrintLoop(WIDTH, 179, ' ', 179);
            cout << PRINT(179) << " THINK YOU HAVE WHAT IT TAKES? (Y/N)";
            break;
        case 10:
            PrintLoop(WIDTH, 179, ' ', 179);
            PrintLoop(WIDTH, 192, 196, 217);
            cout << " >> ";
            break;
        }

        // Finish lines
        if (i > 2 && i < 10) {
            for (int j = 0; j < 54; j++) {
                if (j == 53) {
                    cout << PRINT(179) << endl;
                }
                else {
                    cout << " ";
                }
            }
        }
    }
}

void PrintGameMenu() {
    // Print title
    PrintTitle();

    // Print space line
    PrintLoop(WIDTH, 179, ' ', 179);

    // --- Print text ---
    for (int i = 1; i < 8; i++) {
        switch (i) {
        case 1:
            cout << PRINT(179) << " CHOOSE WISELY:";
            break;
        case 2:
            PrintLoop(WIDTH, 179, ' ', 179);
            break;
        case 3:
            cout << PRINT(179) << " (R)OCK        ";
            break;
        case 4:
            cout << PRINT(179) << " (P)APER       ";
            break;
        case 5:
            cout << PRINT(179) << " (S)CISSOR     ";
            break;
        case 6:
            PrintLoop(WIDTH, 179, ' ', 179);
            break;
        case 7:
            PrintLoop(WIDTH, 192, 196, 217);
            cout << " >> ";
            break;
        }

        // Finish lines
        if (i != 2 && i < 6) {
            for (int j = 0; j < 75; j++) {
                if (j == 74) {
                    cout << PRINT(179) << endl;
                }
                else {
                    cout << " ";
                }
            }
        }
    }
}

char GetComputerChoice() {
    // Seed the generator with current time
    srand(static_cast<unsigned int>(time(0)));

    // Generate a number and range it between 1 and 3
    int randomNumber = (rand() % 3) + 1;

    switch (randomNumber) {
    case 1:
        return 'R';
    case 2:
        return 'P';
    case 3:
        return 'S';
    }
}

void PrintDraw() {
    // Print title
    PrintTitle();

    // Print text
    for (int i = 1; i < 9; i++) {
        // Spaces for centering
        if (i > 1 && i < 7) {
            for (int j = 0; j < 22; j++) {
                if (j == 0) {
                    cout << PRINT(179);
                }
                else {
                    cout << " ";
                }
            }
        }

        // Print
        switch (i) {
        case 1:
            PrintLoop(WIDTH, 179, ' ', 179);
            break;
        case 2:
            cout << "ooooooooo   oooooooooo        o   oooo     oooo";
            break;
        case 3:
            cout << " 888    88o  888    888      888   88   88  88 ";
            break;
        case 4:
            cout << " 888    888  888oooo88      8  88   88 888 88  ";
            break;
        case 5:
            cout << " 888    888  888  88o      8oooo88   888 888   ";
            break;
        case 6:
            cout << "o888ooo88   o888o  88o8  o88o  o888o  8   8    ";
            break;
        case 7:
            PrintLoop(WIDTH, 179, ' ', 179);
            break;
        case 8:
            PrintLoop(WIDTH, 198, 205, 181);
            break;
        }

        // Finish lines
        if (i != 1 && i < 7) {
            for (int j = 0; j < 22; j++) {
                if (j == 21) {
                    cout << PRINT(179) << endl;
                }
                else {
                    cout << " ";
                }
            }
        }
    }
}

void PrintWin() {
    // Print title
    PrintTitle();

    // Print text
    for (int i = 1; i < 9; i++) {
        // Spaces for centering
        if (i > 1 && i < 7) {
            for (int j = 0; j < 9; j++) {
                if (j == 0) {
                    cout << PRINT(179);
                }
                else {
                    cout << " ";
                }
            }
        }

        // Print
        switch (i) {
        case 1:
            PrintLoop(WIDTH, 179, ' ', 179);
            break;
        case 2:
            cout << "oooo     oooo  ooooo  oooo   oooo  oooo   oooo  ooooooooooo  oooooooooo  ";
            break;
        case 3:
            cout << " 88   88  88    888    8888o  88    8888o  88    888          888    888 ";
            break;
        case 4:
            cout << "  88 888 88     888    88 888o88    88 888o88    888ooo8      888oooo88  ";
            break;
        case 5:
            cout << "   888 888      888    88   8888    88   8888    888          888  88o   ";
            break;
        case 6:
            cout << "    8   8      o888o  o88o    88   o88o    88   o888ooo8888  o888o  88o8 ";
            break;
        case 7:
            PrintLoop(WIDTH, 179, ' ', 179);
            break;
        case 8:
            PrintLoop(WIDTH, 198, 205, 181);
            break;
        }

        // Finish lines
        if (i != 1 && i < 7) {
            for (int j = 0; j < 9; j++) {
                if (j == 8) {
                    cout << PRINT(179) << endl;
                }
                else {
                    cout << " ";
                }
            }
        }
    }
}

void PrintLoss() {
    // Print title
    PrintTitle();

    // Print text
    for (int i = 1; i < 9; i++) {
        // Spaces for centering
        if (i > 1 && i < 7) {
            for (int j = 0; j < 14; j++) {
                if (j == 0) {
                    cout << PRINT(179);
                }
                else {
                    cout << " ";
                }
            }
        }

        // Print
        switch (i) {
        case 1:
            PrintLoop(WIDTH, 179, ' ', 179);
            break;
        case 2:
            cout << "ooooo          ooooooo     oooooooo8  ooooooooooo  oooooooooo ";
            break;
        case 3:
            cout << " 888         o888   888o  888          888          888    888";
            break;
        case 4:
            cout << " 888         888     888   888oooooo   888ooo8      888oooo88 ";
            break;
        case 5:
            cout << " 888      o  888o   o888          888  888          888  88o  ";
            break;
        case 6:
            cout << "o888ooooo88    88ooo88    o88oooo888  o888ooo8888  o888o  88o8";
            break;
        case 7:
            PrintLoop(WIDTH, 179, ' ', 179);
            break;
        case 8:
            PrintLoop(WIDTH, 198, 205, 181);
            break;
        }

        // Finish lines
        if (i != 1 && i < 7) {
            for (int j = 0; j < 15; j++) {
                if (j == 14) {
                    cout << PRINT(179) << endl;
                }
                else {
                    cout << " ";
                }
            }
        }
    }
}

void PrintPlayAgain() {
    // Print blank line
    PrintLoop(WIDTH, 179, ' ', 179);

    // Print text
    cout << PRINT(179) << " WANT TO PLAY AGAIN? (Y/N)";

    // Finish line
    for (int i = 0; i < 64; i++) {
        if (i == 63) {
            cout << PRINT(179) << endl;
        }
        else {
            cout << " ";
        }
    }

    // Print blank line
    PrintLoop(WIDTH, 179, ' ', 179);

    // Print ending
    PrintLoop(WIDTH, 192, 196, 217);
    cout << " >> ";
}
