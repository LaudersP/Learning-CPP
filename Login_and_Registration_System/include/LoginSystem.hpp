#ifndef LOGIN_SYSTEM_H
#define LOGIN_SYSTEM_H

#include <iostream>
#include <string>

class LoginSystem {
private:
	std::string* _filenamePtr;
	
public:
	LoginSystem(std::string* filename);
	void PrintDatabasePath();
};

#endif