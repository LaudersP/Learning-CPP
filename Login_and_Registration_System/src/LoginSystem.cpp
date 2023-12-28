#include <LoginSystem.hpp>

LoginSystem::LoginSystem(std::string filename) {
	_filename = filename;
	_logginFound = false;
}

void LoginSystem::PrintDatabasePath() {
	if (_filename.empty()) {
		std::cout << "ERROR) No file path!\n";
	}
	else {
		std::cout << "Database file path: " << _filename << std::endl;
	}
}

void LoginSystem::RequestLoggin() {
	// Clear terminal
	CLEAR;

	std::cout << "LOGGIN\n";
	std::cout << "-----------------------------------\n";

	// Request username
	std::cout << "USERNAME: ";
	std::cin >> _username;

	// Request password
	std::cout << "PASSWORD: ";
	std::cin >> _password;

	// Check loggin status
	if (CheckLogginInfo()) {
		std::cout << "FOUND!\n";
	}
	else {
		std::cout << "Incorrect username/password!\n";
		std::cout << "Please try again or make an account!";
	}
}

bool LoginSystem::CheckLogginInfo() {
	// Clear terminal
	CLEAR;

	// Open output file
	std::ifstream databaseFile(_filename);

	if (databaseFile.is_open()) {
		// Variable to hold loggin info to look for
		std::string wanted = _username + ':' + _password;

		// Variable to hold dataline
		std::string dataline;

		while (databaseFile >> dataline) {
			if (dataline == wanted) {
				_logginFound = true;

				break;
			}
		}
	}
	else {
		std::cout << "Unable to open!\n";
	}

	databaseFile.close();

	return _logginFound;
}