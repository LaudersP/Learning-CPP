#include <RegisterSystem.hpp>

RegisterSystem::RegisterSystem(std::string filename) {
	_filename = filename;
	_length = false;
	_hasLower = false;
	_hasUpper = false;
	_hasNum = false;
	_hasSpecial = false;
}

void RegisterSystem::PrintDatabasePath() {
	if (_filename.empty()) {
		std::cout << "ERROR) No file path!\n";
	}
	else {
		std::cout << "Database file path: " << _filename << std::endl;
	}
}

void RegisterSystem::RequestRegistration() {
	// Clear terminal
	CLEAR;

	std::cout << "REGISTER\n";
	std::cout << "-----------------------------------\n";
	std::cout << "\nPASSWORD MUST:\n";
	std::cout << "1. BE 6 CHARACTERS LONG\n";
	std::cout << "2. CONTAIN AN UPPER AND LOWERCASE LETTER\n";
	std::cout << "3. CONTAIN AN NUMBER\n";
	std::cout << "4. CONTAIN AN SPECIAL CHARACTER";
	std::cout << "	(!, @, #, $, %)\n\n";
	std::cout << "-----------------------------------\n\n";

	// Request wanted username
	std::cout << "USERNAME: ";
	std::cin >> _username;

	// Request wanted password
	std::cout << "PASSWORD: ";
	std::cin >> _password;

	// Check wanted loggin info
	if (CheckRegistrationInfo()) {
		SaveRegistratedInfo();
	}
}

bool RegisterSystem::CheckRegistrationInfo() {
	// Clear terminal
	CLEAR;

	// ==== Check for already used usernames ====
	// Open output file
	std::ifstream databaseFile(_filename);

	if (databaseFile.is_open()) {
		// Variable to hold dataline
		std::string dataline;

		// Variable to hold extracted username
		std::string usedUsername;

		while (databaseFile >> dataline) {
			usedUsername.clear();

			// Extract username from database
			for (uint8_t i = 0; i < _username.length(); i++) {
				usedUsername += dataline[i];
			}

			if (usedUsername == _username) {
				std::cout << "USERNAME TAKEN!\n";
				return false;
			}
		}

		databaseFile.close();

		// ==== Check password requirements ====
		if (_password.length() >= 6) {
			_length = true;
		}

		for (uint8_t i = 0; i < _password.length(); i++) {
			if (std::islower(_password[i])) {
				_hasLower = true;
			}
			else if (std::isupper(_password[i])) {
				_hasUpper = true;
			}
			else if (std::isdigit(_password[i])) {
				_hasNum = true;
			}
			else if (_password[i] == '!' ||
				_password[i] == '@' ||
				_password[i] == '#' ||
				_password[i] == '$' ||
				_password[i] == '%') {
				_hasSpecial = true;
			}
		}

		if (_length && _hasLower && _hasUpper && _hasNum && _hasSpecial) {
			return true;
		}
		else {
			if (_length == false) {
				std::cout << "PASSWORD MUST BE 6 CHARACTERS LONG\n";
			}
			if (_hasLower == false) {
				std::cout << "PASSWORD MUST CONTAIN LOWERCASE LETTER!\n";
			} 
			if (_hasUpper == false) {
				std::cout << "PASSWORD MUST CONTAIN UPPERCASE LETTER!\n";
			}
			if (_hasNum == false) {
				std::cout << "PASSWORD MUST CONTAIN AN NUMBER!\n";
			}
			if (_hasSpecial == false) {
				std::cout << "PASSWORD MUST CONTAIN AN SPECIAL CHARACTER (!, @, #, $, %)!\n";
			}
			return false;
		}
	}
}

void RegisterSystem::SaveRegistratedInfo() {
	// Open database file
	std::ifstream databaseFileRead(_filename);

	// Variable to hold number of lines
	uint8_t lines = 0;

	// Variable just to temp grab dataline
	std::string dataline;

	while (databaseFileRead >> dataline) {
		lines++;
	}

	databaseFileRead.close();

	// Open database file
	std::ofstream databaseFile(_filename, std::ios::app);


	if (databaseFile.is_open()) {
		// Variable to hold registered loggin info
		dataline = _username + ":" + _password;

		if (lines == 0) {
			databaseFile << dataline;
		}
		else {
			databaseFile << std::endl << dataline;
		}

		std::cout << "ACCOUNT REGISTERED!\n\n";
	}
	else {
		std::cout << "ERROR) Unable to open database!\n";
	}

	databaseFile.close();
}