#pragma once

#include <iostream>

class Person {
protected:
	std::string firstName = "";
	std::string lastName = "";
	std::string CNP = "";
public:
	Person(std::string firstName, std::string lastName, std::string CNP);
	void setFirstName(std::string newName);
	std::string getFirstName();
	void print();
};