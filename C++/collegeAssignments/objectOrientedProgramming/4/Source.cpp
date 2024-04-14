/*
	University staff management
	Inheritance practice
*/

#include "Student.h";

int main() {
	Student s("George", "C", "525213");

	s.print();
	std::cout << "\n";
	s.Person::print();

	return 0;
}