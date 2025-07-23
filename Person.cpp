#include <iostream>
#include "Person.h"
#include <string>
#include <thread> 
#include <chrono> 

Person::Person() {
	id = -1;
	name = "Unknown";
	email = "Unknown";
	phone_number = "Unknown";

}

Person::Person(int entered_id, std::string entered_name, std::string entered_email, std::string entered_phone_number) {
	id = entered_id;
	name = entered_name;
	email = entered_email;
	phone_number = entered_phone_number;
}

// Set Methods
void Person::setSecurityAccess(int access) {
    security_access = access;
}
void Person::setID(int new_id) {
    id = new_id;
}
void Person::setName(std::string new_name) {
    name = new_name;
}
void Person::setEmail(std::string new_email) {
    email = new_email;
}
void Person::setPhoneNumber(std::string new_phone_number) {
    phone_number = new_phone_number;
}

// Get Methods
int Person::getID() {
    return id;
}
std::string Person::getName() {
    return name;
}
std::string Person::getEmail() {
    return email;
}
std::string Person::getPhoneNumber() {
    return phone_number;
}
int Person::getSecurityAccess() {
    return security_access;
}

void Person::displayInfo() {
	std::this_thread::sleep_for(std::chrono::milliseconds(750));
	std::cout << "\n==============================================================================================" << std::endl;
	std::cout << "Person Information:" << std::endl;
	std::cout << "==============================================================================================" << std::endl;
	std::cout << "\tID: " << id << std::endl;
	std::cout << "\tName: " << name << std::endl;
	std::cout << "\tEmail: " << email << std::endl;
	std::cout << "\tPhone Number: " << phone_number << std::endl;
	std::cout << "==============================================================================================" << std::endl;
}

// Methods to Update Information Regarding a Person
void Person::updateInfo() {
	int choice = -1;
	std::this_thread::sleep_for(std::chrono::milliseconds(750));
	std::cout << "\n==============================================================================================" << std::endl;
	std::cout << "Select the information you want to update:" << std::endl;
	std::cout << "==============================================================================================" << std::endl;
	std::cout << "\t1. ID" << std::endl;
	std::cout << "\t2. Name" << std::endl;
	std::cout << "\t3. Email" << std::endl;
	std::cout << "\t4. Phone Number" << std::endl;
	std::cout << "\t5. Exit" << std::endl;
	std::cout << "==============================================================================================" << std::endl << "\tEnter Choice: ";
	std::cin >> choice;

	while (choice < 1 || choice > 5) {
		std::cout << "\n\nInvalid choice. Please select a valid option (1-5): ";
		std::cin >> choice;
	}

	switch (choice) {
	case 1: {
		int new_id = -1;
		std::cout << "\n--> Enter new ID: ";
		std::cin >> new_id;

		updateID(new_id);
		break;
	}
	case 2: {
		std::string new_name = "";
		std::cout << "\n--> Enter new Name: ";
		std::cin.ignore(); // Clear the newline character from the input buffer
		std::getline(std::cin, new_name);

		updateName(new_name);
		break;
	}
	case 3: {
		std::string new_email = "";
		std::cout << "\n--> Enter new Email: ";
		std::cin.ignore(); // Clear the newline character from the input buffer
		std::getline(std::cin, new_email);

		updateEmail(new_email);
		break;
	}
	case 4: {
		std::string new_phone_number;
		std::cout << "\n--> Enter new Phone Number: ";
		std::cin.ignore(); // Clear the newline character from the input buffer
		std::getline(std::cin, new_phone_number);

		updatePhoneNumber(new_phone_number);
		break;
	}
	case 5: {
		std::cout << "\n--> Exiting update menu." << std::endl;
		return; // Exit the update menu
	}
	default: {
		std::cout << "\n--> Invalid choice. Please select a valid option (1-5): ";
		break;
	}
	}
}

void Person::updateID(int new_id) {
	id = new_id;
	std::cout << "--> ID successfully updated to: " << id << std::endl;
}
void Person::updateName(std::string new_name) {
	name = new_name;
	std::cout << "--> Name successfully updated to: " << name << std::endl;
}
void Person::updateEmail(std::string new_email) {
	email = new_email;
	std::cout << "--> Email successfully updated to: " << email << std::endl;
}
void Person::updatePhoneNumber(std::string new_phone_number) {
	phone_number = new_phone_number;
	std::cout << "--> Phone successfully Number updated to: " << phone_number << std::endl;
}

// Default Security Level Access
void Person::securityLevel() {
	std::this_thread::sleep_for(std::chrono::milliseconds(750));
	std::cout << "\n==============================================================================================" << std::endl;
	std::cout << "Security access level: General Access" << std::endl;
	std::cout << "==============================================================================================" << std::endl;
}