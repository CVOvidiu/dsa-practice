/*
 Se citeșc două numere naturale n și m și doi vectori crescători de lungime n, respectiv m.
Să se creeze și să se afișeze vectorul ordonat crescător obținut prin reuniunea celor doi
vector. Ex: v1 = [1,2,5,10,13,20] v2 = [1,6,7,9,15,25], afisare: [1,1,2,5,6,7,9,10,13,15,20,25]
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

int* createArr(int* arr1, int dim1, int* arr2, int dim2) {
	int* newArr = new int[dim1 + dim2];

	int i = 0, j = 0, ind = 0;
	while (i < dim1 && j < dim2) {
		if (arr1[i] < arr2[j])
			newArr[ind++] = arr1[i++];
		else
			newArr[ind++] = arr2[j++];
	}

	if (i < dim1)
		for (int k = i; k < dim1; k++)
			newArr[ind++] = arr1[k];
	else
		for (int k = j; k < dim2; k++)
			newArr[ind++] = arr2[k];

	delete[] arr1, arr2;
	return newArr;
}

void main() {
	int *v1, *v2, *v3, n, m;
	readArr(v1, n);
	readArr(v2, m);
	v3 = createArr(v1, n, v2, m);
	writeArr(v3, n + m);
}