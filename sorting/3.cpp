/*
Sa se genereze un sir de numere cu ajutorul funcției rand din stdlib.h. Sa se sorteze
crescator toate elementele de pe poziții pare din acest sir de numere.
*/

#include <iostream>
#include <vector>
#include <stdlib.h>
#include <time.h>

//void readArr(int*& arr, int dim) {
//	arr = new int[dim];
//
//	std::cout << "Elem vector:\n";
//	for (int i = 0; i < dim; i++)
//		std::cin >> arr[i];
//}

void genRandArr(int*& arr, int dim) {
	arr = new int[dim];

	srand(time(NULL));
	for (int i = 0; i < dim; i++)
		arr[i] = rand() % 1000 + 1;
}

void writeArr(int* arr, int dim) {
	std::cout << "\nAfisare vector:\n";
	for (int i = 0; i < dim; i++)
		std::cout << arr[i] << " ";
	std::cout << "\n";
}

void quickSort(std::vector<int>& arr, int st, int dr) {
	int i = st, j = dr;
	int piv = arr[(dr + st) / 2];

	while (i <= j) { // Atat timp cat limita stanga nu a trecut peste limita dreapta
		while (arr[i] < piv) // Cat timp sunt sortate corect, treci peste ele
			i++;
		while (arr[j] > piv)
			j--;
		if (i <= j) { // Daca a dat de o pereche neordonata deoarece nu a trecut limita stanga peste dreapta
			// Interschimba-le si continua cu limita
			std::swap(arr[i], arr[j]);
			i++;
			j--;
		}
	}

	// Toate elementele mai mici decat pivotul sunt la st && asemenea pt dr => pivotul este in pozitia finala

	if (st < j)
		quickSort(arr, st, j);
	if (i < dr)
		quickSort(arr, i, dr);
}

void sortArr(int*& arr, int dim) {
	std::vector<int> evens;

	for (int i = 1; i < dim; i += 2)
		evens.push_back(arr[i]);

	quickSort(evens, 0, evens.size() - 1);

	int evensIndex = 0;
	for (int i = 1; i < dim; i += 2) {
		arr[i] = evens[evensIndex];
		evensIndex++;
	}
}

int main() {
	int dim;
	std::cout << "Dim = ";
	std::cin >> dim;

	int* arr = nullptr;
	genRandArr(arr, dim);
	//readArr(arr, dim);
	writeArr(arr, dim);
	sortArr(arr, dim);
	writeArr(arr, dim);
}