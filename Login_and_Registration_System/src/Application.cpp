#include <iostream>
#include <LoginSystem.hpp>
#include <RegisterSystem.hpp>

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

int main() {
	// Create a string to hold the path to the database
	std::string databasePath = "..\\..\\temp\\database.txt";

	// Create a instance of the LoginSystem class passing the 'databasePath' point
	LoginSystem logginUser(databasePath);

	// Create a instance of the LoginSystem class passing the 'databasePath' point
	RegisterSystem registorUser(databasePath); 
	

	// Variable to hold loop status
	bool done = false;

	// Variable to hold the users input
	char userInput;


	// Macro function to clear terminal
	CLEAR;

	while (done == false) {
		// Main menu
		do {
			std::cout << "OPTIONS\n";
			std::cout << "-----------------------------------\n";
			std::cout << "(L)OGGIN\n";
			std::cout << "(R)EGISTER\n";
			std::cout << "(E)XIT\n";
			std::cout << "-----------------------------------\n";
			std::cout << ">> ";

			std::cin >> userInput;
			userInput = std::toupper(userInput);
		} while (userInput != 'L' && userInput != 'R' && userInput != 'E');

		// Call appropraite functions
		switch (userInput) {
		case 'L':
			logginUser.RequestLoggin();

			break;
		case 'R':
			registorUser.RequestRegistration();

			break;
		case 'E':
			// End program loop
			done = true;

			break;
		}
	}
}