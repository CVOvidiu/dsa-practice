/*
Se citește un număr natural n și cele n elemente ale unui vector. Să se înlocuiască
elementele de pe pozițiile pare cu cea mai mică cifra din număr iar cele de pe pozițiile impare
cu 0 dacă numărul e prim și cu 1 altfel.
*/

#include <iostream>

void citireVector(int*& vect, int& dim) {
	std::cin >> dim;

	vect = new int[dim];

	for (int i = 0; i < dim; i++)
		std::cin >> vect[i];
}

void afisareVector(int* vect, int dim) {
	for (int i = 0; i < dim; i++)
		std::cout << vect[i] << " ";

	delete[] vect;
}

int smallestDigit(int num) {
	int smallest = 10;
	while (num) {
		if (smallest > num % 10) smallest = num % 10;
		num /= 10;
	}
	return smallest;
}

bool prim(int num) {
	for (int d = 2; d * d <= num; d++) {
		if (num % d == 0) return 1;
	}
	return 0;
}

void modificareVector(int*& vect, int dim) {
	for (int i = 0; i < dim; i++) {
		if (i % 2 == 0) {
			// inlocuit cu cea mai mica cifra din numar
			vect[i] = smallestDigit(vect[i]);
		}
		else {
			// daca numar e prim inlocuit cu 0
			// daca numar nu e prim inlocuit cu 1
			vect[i] = prim(vect[i]);
		}
	}
}

void main() {
	int *v, n;
	
	citireVector(v, n);
	modificareVector(v, n);
	afisareVector(v, n);
}