#ifndef LOGIN_SYSTEM_H
#define LOGIN_SYSTEM_H

#include <iostream>
#include <string>
#include <fstream>

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

class LoginSystem {
private:
	std::string _filename;
	std::string _username;
	std::string _password;
	bool CheckLogginInfo();
	bool _logginFound;
	
public:
	LoginSystem(std::string filename);
	void PrintDatabasePath();
	void RequestLoggin();
};

#endif