/*
	Implement STL Vector:
		- store vector elements using dynamic allocation *
		- size + capacity *
		- constructor with initial size *
		- print method *
		- copy constructor *
		- destructor *
		- [] overloading *
		- at, size method *
		- = overloading *
		- resize method (keep old values if there's the case and initialize remaining spaces) *
		- remove element at index *
		- pushback method *
*/

#include "Vector.h"

int main() {
	try {
		Vector v(5);
	}
	catch (const std::string e) {
		std::cerr << e;
		return 1;
	}

	return 0;
}