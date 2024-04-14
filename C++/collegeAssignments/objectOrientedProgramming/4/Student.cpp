#include "Student.h"

Student::Student(std::string firstName, std::string lastName, std::string CNP,
	int an, std::string grupa, bool bursier, float valBursa)
	:Person(firstName, lastName, CNP), an(an), grupa(grupa), bursier(bursier), valBursa(valBursa) {
}

std::string Student::getGrupa() {
	return grupa;
}

void Student::print() {
	Person::print();
	std::cout << an << " " << grupa << " " << bursier << " " << valBursa;
}