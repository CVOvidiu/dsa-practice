#pragma once

#include <iostream>

#define BUFFER 1/3
#define STARTCAPACITY 3

class Vector {
	float* m_elements = nullptr;
	int m_capacity = STARTCAPACITY, m_size = 0;
public:
	Vector(int size = 0, int init_value = 0);
	Vector(Vector& ob);
	void print();
	~Vector();
	float& operator [] (int poz);
	float& at(int poz);
	int size();
	void operator = (Vector& ob);
	void resize(int newSize, int init_value = 0);
	void remove(int index);
	void push_back(int value);
};