/*
Sa se testeze daca un vector de numere intregi dat este sortat crescator.
	a. Daca da, atunci fiind dat un element “elem”, sa se insereze elementul la locul lui,
	adica astfel incat sa ramana un sir sortat crescator.
	b. Daca nu este sortat crescator, atunci sa se identifice daca exista un eventual element
	care strica “ordinea”, iar daca exista unul singur, atunci sa se elimine acel element.
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

int* elimArr(int*& arr, int& dim, int poz) {
	int* res = new int[dim - 1];

	for (int i = 0; i < poz; i++)
		res[i] = arr[i];

	for (int i = poz + 1; i < dim; i++)
		res[i - 1] = arr[i];

	delete[] arr;
	dim--;
	return res;
}

bool verifArr(int*& arr, int& dim) {
	bool ascending = true;
	int encounters = 0, poz;

	for (int i = 0; i < dim - 1; i++) 
		if (arr[i] > arr[i + 1]) {
			ascending = false;
			poz = i + 1;
			encounters++;
		}

	if (encounters > 1)
		std::cout << "Mai multe elemente strica ordinea";
	else
		arr = elimArr(arr, dim, poz);
	
	return ascending;
}

int* insertElem(int*& arr, int& dim, int& elem) {
	std::cout << "Elem: ";
	std::cin >> elem;

	int* res = new int[dim + 1];
	int poz;
	for (int i = 0; i < dim; i++)
		if (elem > arr[i])
			res[i] = arr[i];
		else {
			poz = i;
			break;
		}

	res[poz] = elem;

	int idx = poz + 1;
	for (int i = poz; i < dim; i++) {
		res[idx] = arr[i];
		idx++;
	}

	delete[] arr;
	arr = new int[dim + 1];
	dim++;
	return res;
}

int main() {
	int dim, elem;
	std::cout << "Dim = ";
	std::cin >> dim;
	int* arr = nullptr;
	//genRandArr(arr, dim);
	readArr(arr, dim);
	if (verifArr(arr, dim))
		arr = insertElem(arr, dim, elem);

	writeArr(arr, dim);
}