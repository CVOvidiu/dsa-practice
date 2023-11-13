/*
Se citește un număr natural n și cele n elemente ale unui vector. Să se insereze în
vector între oricare două valori vecine suma și produsul acestora.
Obs: Determinarea sumei și a produsului a două numere se va realiza în cadrul unui
singure funcții.
*/

#include <iostream>

void readArr(int*& arr, int& dim) {
	std::cin >> dim;

	arr = new int[dim];

	for (int i = 0; i < dim; i++)
		std::cin >> arr[i];
}

void writeArr(int* arr, int dim) {
	for (int i = 0; i < dim; i++)
		std::cout << arr[i] << " ";

	delete[] arr;
}

void modifArr(int*& arr, int& dim) {
	// 1 2 3 4
	// 1 S P 2 S P 3 S P 4
	int sum, prod, newArrDim = dim + (dim - 1) * 2;
	int* newArr = new int[newArrDim];
	newArr[0] = arr[0];

	int ind = 1;
	for (int i = 0; i < dim - 1; i++) {
		newArr[ind] = arr[i] + arr[i + 1];
		newArr[ind + 1] = arr[i] * arr[i + 1];
		newArr[ind + 2] = arr[i + 1];
		ind += 3;
	}

	delete[] arr;
	dim = newArrDim;
	arr = new int[dim];
	for (int i = 0; i < dim; i++)
		arr[i] = newArr[i];
	delete[] newArr;
}

void main() {
	int n, *v;
	readArr(v, n);
	modifArr(v, n);
	writeArr(v, n);
}