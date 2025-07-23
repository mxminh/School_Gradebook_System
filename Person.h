#ifndef PERSON_H
#define PERSON_H

#include <string>

class Person {
private:
	int id;
	std::string name;
	std::string email;
	std::string phone_number;
	int security_access = -1; 

public:

	Person();
	Person(int, std::string, std::string, std::string);

	void setSecurityAccess(int);
	void setID(int);
	void setName(std::string);
	void setEmail(std::string);
	void setPhoneNumber(std::string);

	int getID();
	std::string getName();
	std::string getEmail();
	std::string getPhoneNumber();
	int getSecurityAccess();

	void virtual displayInfo();

	void virtual updateInfo();

	void virtual updateID(int);
	void virtual updateName(std::string);
	void virtual updateEmail(std::string);
	void virtual updatePhoneNumber(std::string);

	void virtual securityLevel();
};

#endif