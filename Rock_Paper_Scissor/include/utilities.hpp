#ifndef TITLES_HPP
#define TITLES_HPP

#include <cstdlib>
#include <ctime>
#include <iostream>

using std::cout;
using std::endl;
using std::srand;
using std::time;
using std::rand;

// Function declerations
void PrintLoop(const int width, const char startingChar, const char middleChar, const char endingChar);
void PrintTitle();
void PrintMainMenu();
void PrintGameMenu();
char GetComputerChoice();
void PrintDraw();
void PrintWin();
void PrintLoss();
void PrintPlayAgain();

#endif