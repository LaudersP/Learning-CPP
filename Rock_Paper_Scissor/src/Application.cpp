#include <iostream>
#include <cstdlib>
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
    // Clear terminal
    CLEAR;

    PrintTitle();

    // Loop status
    bool done = false;

    PrintMainMenu();

    return 0;
}