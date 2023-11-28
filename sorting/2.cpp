/*
Se da un vector de numere intregi pozitive de dimensiune “dim”. Sa se sorteze
elementele crescator pana la jumatatea sirului, iar de la jumatate la final toate elementele
sa se sorteze descrescator.

EX: 10
	123 456 789 234 567 890 345 678 901 432
	123 234 456 567 789 901 890 678 432 345
*/

#include <iostream>
#include <vector>

void readArr(int*& arr, int dim) {
	arr = new int[dim];

	std::cout << "Elem vector:\n";
	for (int i = 0; i < dim; i++)
		std::cin >> arr[i];
}

void writeArr(int* arr, int dim) {
	std::cout << "\nAfisare vector:\n";
	for (int i = 0; i < dim; i++)
		std::cout << arr[i] << " ";
	std::cout << "\n";
}

bool comparatorDesc(int x, int y) {
	return x > y;
}

bool comparatorCresc(int x, int y) {
	return x < y;
}

void quickSort(int*& arr, int st, int dr, bool comparator(int x, int y)) {
	int i = st, j = dr;
	int piv = arr[(dr + st) / 2];

	while (i <= j) { // Atat timp cat limita stanga nu a trecut peste limita dreapta
		while (comparator(arr[i], piv) && i < dr) // Cat timp sunt sortate corect, treci peste ele
			i++;
		while (!comparator(arr[j], piv) && j > st)
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
		quickSort(arr, st, j, comparator);
	if (i < dr)
		quickSort(arr, i, dr, comparator);
}

int main() {
	int dim;
	std::cout << "Dim = ";
	std::cin >> dim;

	int* arr = nullptr;
	readArr(arr, dim);
	quickSort(arr, 0, (dim - 1) / 2, comparatorCresc);
	quickSort(arr, (dim - 1) / 2 + 1, dim - 1, comparatorDesc);
	writeArr(arr, dim);
}