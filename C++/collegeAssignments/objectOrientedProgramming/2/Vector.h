#pragma once

#include <iostream>

class Vector {
	float* m_elements;
	int m_size;
public:
	//Vector(int size);
	Vector(int size, float val_init = 0);
	Vector(Vector& ob);
	~Vector();

	void print();
	//void operator = (const Vector& ob);
	Vector& operator =(const Vector& ob);
	float& operator[](int poz);
	friend Vector operator * (float alfa, Vector& ob);
	friend std::ostream& operator << (std::ostream& os, Vector& ob);
	friend std::istream& operator >> (std::istream& is, Vector& ob);
};

