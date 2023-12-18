#include "titles.hpp"

#define WIDTH 90

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

    cout << static_cast<char>(179) << "     ____             __   ____                        _____      _                      " << static_cast<char>(179) << endl;
    cout << static_cast<char>(179) << "    / __ \\____  _____/ /__/ __ \\____ _____  ___  _____/ ___/_____(_)_____________  _____ " << static_cast<char>(179) << endl;
    cout << static_cast<char>(179) << "   / /_/ / __ \\/ ___/ //_/ /_/ / __ `/ __ \\/ _ \\/ ___/\\__ \\/ ___/ / ___/ ___/ __ \\/ ___/ " << static_cast<char>(179) << endl;
    cout << static_cast<char>(179) << "  / _, _/ /_/ / /__/ ,< / ____/ /_/ / /_/ /  __/ /   ___/ / /__/ (__  |__  ) /_/ / /     " << static_cast<char>(179) << endl;
    cout << static_cast<char>(179) << " /_/ |_|\\____/\\___/_/|_/_/    \\__,_/ .___/\\___/_/   /____/\\___/_/____/____/\\____/_/      " << static_cast<char>(179) << endl;
    cout << static_cast<char>(179) << "                                  /_/                                                    " << static_cast<char>(179) << endl;

    // Print space worth
    PrintLoop(WIDTH, 179, ' ', 179);
}

void PrintMainMenu() {
    PrintLoop(WIDTH, 198, 205, 181);
}