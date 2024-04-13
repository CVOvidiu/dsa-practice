/*
	Vector class:
	- float* elements;
	- int size;
	Methods:
	- constructor that does memory allocation + initialization
	- destructor
	- copy constructor
	- print method
	- equal sign operator overloading
	- [] operator overloading => getters and setters
	- * operator overload
	- <<, >> operators overload
*/

#include <iostream>

#include "Vector.h"

int main() {
	Vector v(5, 10);
	Vector v1(v);
	v1.print();
	Vector v3(10, 20);
	v1 = v3;
	v1.print();

	std::cout << v;
	std::cin >> v1;
	std::cout << v1;
	//std::cout << (3 * v1); // This doesn't work?
	std::cout << v1;
	(3 * v1).print();

	return 0;
}