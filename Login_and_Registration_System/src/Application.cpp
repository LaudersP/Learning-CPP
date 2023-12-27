#include <iostream>
#include <LoginSystem.hpp>
#include <RegisterSystem.hpp>

int main() {
	// Create a string to hold the path to the database
	std::string databasePath = "../../temp/database.txt";
	std::string* databasePtr = &databasePath;	// String pointer

	// Create a instance of the LoginSystem class passing the 'databasePath' point
	LoginSystem logginUser(databasePtr);

	// Create a instance of the LoginSystem class passing the 'databasePath' point
	RegisterSystem registorUser(databasePtr);
}