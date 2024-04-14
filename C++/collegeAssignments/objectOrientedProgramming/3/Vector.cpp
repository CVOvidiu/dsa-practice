#include "Vector.h" 

Vector::Vector(int size, int init_value) {
	if (size > 0) {
		m_size = size;
		m_capacity = size + (size * BUFFER);
		m_elements = new float[m_capacity];
		for (int i = 0; i < size; i++)
			m_elements[i] = init_value;
	} else if (size == 0) {
		m_size = size;
		m_elements = new float[m_capacity];
	}
	else
		throw std::string("Constructor error: 'size' is negative");
}

Vector::Vector(Vector& ob) {
	m_size = ob.m_size;
	m_capacity = ob.m_capacity;
	if (ob.m_size != 0) {
		m_elements = new float[m_capacity];
		for (int i = 0; i < m_size; i++)
			m_elements[i] = ob.m_elements[i];
	}
}

void Vector::print() {
	for (int i = 0; i < m_size; i++)
		std::cout << m_elements[i] << " ";
	std::cout << "\n";
}

Vector::~Vector() {
	delete[] m_elements;
}

float& Vector::operator[](int poz) {
	if (poz >= 0 && poz < m_size)
		return m_elements[poz];
	else
		throw std::string("Operator [] error: Can't access that element");
}

float& Vector::at(int poz) {
	if (poz >= 0 && poz < m_size)
		return m_elements[poz];
	else
		throw std::string("'at' method error: Can't access that element");
}

int Vector::size() {
	return m_size;
}

void Vector::operator=(Vector& ob) {
	delete[] m_elements;
	m_size = ob.m_size;
	m_capacity = ob.m_capacity;
	if (ob.m_size != 0) {
		m_elements = new float[m_capacity];
		for (int i = 0; i < m_size; i++)
			m_elements[i] = ob.m_elements[i];
	}
}

void Vector::resize(int newSize, int init_value) {
	if (newSize < m_size)
		throw std::string("'resize' method error: Can't set a smaller size than the actual one");
	Vector aux(*this);
	m_size = newSize;
	m_capacity = newSize; // That's how 'resize' from STL works
	delete[] m_elements;
	m_elements = new float[m_capacity];
	for (int i = 0; i < aux.size(); i++)
		m_elements[i] = aux[i];
	for (int i = aux.size(); i < m_size; i++)
		m_elements[i] = init_value;
}

void Vector::remove(int index) {
	if (m_size == 0)
		throw std::string("'remove' method error: Vector is empty");
	if (index >= 0 && index < m_size) {
		for (int i = index; i < m_size; i++)
			m_elements[i] = m_elements[i + 1];
		m_size--;
	}
	else
		throw std::string("'remove' method error: Specified index is out of bounds");
}

void Vector::push_back(int value) {
	m_size++;
	if (m_size > m_capacity) {
		Vector aux(*this);
		delete[] m_elements;
		m_capacity = m_size + (m_size * BUFFER);
		m_elements = new float[m_capacity];
		for (int i = 0; i < aux.size(); i++)
			m_elements[i] = aux[i];
	}
	m_elements[m_size - 1] = value;
}
