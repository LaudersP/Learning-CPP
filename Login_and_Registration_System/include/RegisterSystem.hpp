#ifndef REGISTER_SYSTEM_H
#define REGISTER_SYSTEM_H

#include <iostream>
#include <string>

class RegisterSystem {
private:
	std::string* _filenamePtr;
	
public:
	RegisterSystem(std::string* filename);
	void PrintDatabasePath();
};

#endif