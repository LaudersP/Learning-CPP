#ifndef REGISTER_SYSTEM_H
#define REGISTER_SYSTEM_H

#include <iostream>
#include <string>
#include <fstream>
#include <cctype>

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

class RegisterSystem {
private:
	std::string _filename;
	std::string _username;
	std::string _password;
	bool CheckRegistrationInfo();
	bool _length;
	bool _hasLower;
	bool _hasUpper;
	bool _hasNum;
	bool _hasSpecial;
	void SaveRegistratedInfo();
	
public:
	RegisterSystem(std::string filename);
	void PrintDatabasePath();
	void RequestRegistration();
};

#endif