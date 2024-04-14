#include "Person.h"

Person::Person(std::string firstName, std::string lastName, std::string CNP)
	:firstName(firstName), lastName(lastName), CNP(CNP) {
}

void Person::setFirstName(std::string newName) {
	firstName = newName;
}

std::string Person::getFirstName() {
	return firstName;
}

void Person::print() {
	std::cout << firstName << " " << lastName << " " << CNP;
}