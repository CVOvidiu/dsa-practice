#include "Vector.h"

//Vector::Vector(int size) {
//	if (size > 0) {
//		m_elements = new float[size];
//		m_size = size;
//		return;
//	}
//
//	m_elements = nullptr;
//	m_size = 0;
//}

Vector::Vector(int size, float val_init) {
	if (size > 0) {
		m_elements = new float[size];
		m_size = size;
		for (int i = 0; i < size; i++)
			m_elements[i] = val_init;
		return;
	}

	m_elements = nullptr;
	m_size = 0;
}

Vector::~Vector() {
	if (m_elements != nullptr) {
		delete[] m_elements;
	}
}

Vector::Vector(Vector& v) {
	m_size = v.m_size;
	if (m_size != 0) {
		m_elements = new float[m_size];
		for (int i = 0; i < m_size; i++)
			m_elements[i] = v.m_elements[i];
	}
	else
		m_elements = nullptr;
}

void Vector::print() {
	std::cout << "Afisare: ";
	for (int i = 0; i < m_size; i++)
		std::cout << m_elements[i] << " ";
	std::cout << "\n";
}

//void Vector::operator = (const Vector& ob) {
//	if (m_elements)
//		delete[] m_elements;
//
//	m_size = ob.m_size;
//	m_elements = new float[m_size];
//	for (int i = 0; i < m_size; i++)
//		m_elements[i] = ob.m_elements[i];
//}

Vector& Vector::operator = (const Vector& ob) {
	if (this == &ob)
		return *this;
	if (m_elements)
		delete[] m_elements;

	m_size = ob.m_size;
	m_elements = new float[m_size];
	for (int i = 0; i < m_size; i++)
		m_elements[i] = ob.m_elements[i];

	return *this;
}

float& Vector::operator [] (int poz) {
	if(poz > 0 || poz < m_size)
		return m_elements[poz];
}

Vector operator * (float alfa, Vector& ob) {
	if (ob.m_size > 0) {
		Vector produs(ob.m_size);
		for (int i = 0; i < ob.m_size; i++) {
			produs[i] = alfa * ob[i];
		}
		return produs;
	}

	Vector produs(0);
	return produs;
}

std::ostream& operator << (std::ostream& os, Vector& ob) {
	for (int i = 0; i < ob.m_size; i++)
		os << ob[i] << " ";
	os << "\n";

	return os;
}

std::istream& operator >> (std::istream& is, Vector& ob) {
	int dim;
	is >> dim;
	if (dim <= 0)
		return is;
	if (ob.m_elements != nullptr)
		delete[] ob.m_elements;
	ob.m_elements = new float[dim];
	ob.m_size = dim;

	for (int i = 0; i < ob.m_size; i++)
		is >> ob.m_elements[i];

	return is;
}
