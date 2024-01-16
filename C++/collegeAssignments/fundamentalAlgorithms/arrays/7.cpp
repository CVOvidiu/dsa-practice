/*
 Se citește un număr natural n și n medii (numere reale cu doua zecimale cu valori
cuprinse intre 1 şi 10). Să se afişeze o statistică a mediilor astfel: numărul de medii
cuprinse în intervalul [1,2], numărul de medii cuprinse în intervalul (2,3], …, numărul de
medii cuprinse în intervalul (9,10].
*/

#include <iostream>

void readArr(double*& arr, int& dim) {
	std::cin >> dim;
	arr = new double[dim];
	for (int i = 0; i < dim; i++)
		std::cin >> arr[i];
}

void stats(double* arr, int dim) {
	int* newArr = new int[10](); // () pt full de 0

	for (int i = 0; i < dim; i++) {
		if (arr[i] - (double)(long)arr[i] == 0 && i != 0) // (double)(long) ca sa fie posibila operatia intre double
			newArr[(long)arr[i] - 2]++;
		else
			newArr[(long)arr[i] - 1]++;
	}

	for (int i = 0; i < 9; i++) {
		if (i == 0 && newArr[i])
			std::cout << "[" << i + 1 << ":" << i + 2 << "] -> " << newArr[i] << "\n";
		else if (newArr[i])
			std::cout << "(" << i + 1 << ":" << i + 2 << "] -> " << newArr[i] << "\n";
	}
}

void main() {
	int n;
	double *v;
	readArr(v, n);
	stats(v, n);
}