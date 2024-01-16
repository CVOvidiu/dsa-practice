/*
Se dă un vector v cu n elemente. Să se elimine din vector elementul cu indicele de
poziție p (citit de la tastatură) iar p să se insereze la începutul vectorului. Să se afișeze noul
vector. Ex: 2 51 2 91 3 cu p = 3, afiseaza 3 2 51 2 3
*/

#include <iostream>

void readArr(int*& arr, int& dim, int& poz) {
	std::cin >> dim >> poz;
	arr = new int[dim];
	for (int i = 0; i < dim; i++)
		std::cin >> arr[i];
}

void writeArr(int* arr, int dim) {
	for (int i = 0; i < dim; i++)
		std::cout << arr[i] << " ";
	delete[] arr;
}

void modifArr(int*& arr, int dim, int poz) {
	int* newArr = new int[dim];
	newArr[0] = poz;

	int ind = 1;
	for (int i = 0; i < poz; i++)
		newArr[ind++] = arr[i];

	for (int i = poz + 1; i < dim; i++)
		newArr[ind++] = arr[i];

	delete[] arr;
	arr = new int[dim];
	for (int i = 0; i < dim; i++)
		arr[i] = newArr[i];
	delete[] newArr;
}

void main() {
	int* v, n, p;
	readArr(v, n, p);
	modifArr(v, n, p);
	writeArr(v, n);
}