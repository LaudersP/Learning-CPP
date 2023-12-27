#include <LoginSystem.hpp>

LoginSystem::LoginSystem(std::string* filename) : _filenamePtr(filename) {
	// Rest of initialization here...
}

void LoginSystem::PrintDatabasePath() {
	if (_filenamePtr != nullptr) {
		std::cout << "Database file path: " << *_filenamePtr << std::endl;
	}
	else {
		std::cout << "ERROR) Invalid pointer to database!";
	}
}