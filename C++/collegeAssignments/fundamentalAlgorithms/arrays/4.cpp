/*
 Se citeșc două numere naturale n și k și cele n elemente ale unui vector. Să se deplaseze
spre dreapta elementele vectorilor cu k-poziții. Primele k-elemente ale vectorului vor fi
a) zerorizate iar dimensiunea vectorului va crește k elemente
Ex: v = [1,2,3,4,5,6,7], k=3 afișare: [0,0,0,1,2,3,4,5,6,7]
b) înlocuite cu ultimele k elemente din vector astfel dimensiunea vectorului nu va
suferi modificări
Ex: v = [1,2,3,4,5,6,7], k=3 afișare: [5,6,7,1,2,3,4]
*/

#include <iostream>

void readArr(int*& arr, int& dim, int& k) {
	std::cin >> dim >> k;
	arr = new int[dim];
	for (int i = 0; i < dim; i++)
		std::cin >> arr[i];
}

void writeArr(int*& arr, int dim) {
	for (int i = 0; i < dim; i++) {
		std::cout << arr[i] << " ";
	}

	delete[] arr;
}

void modifArrA(int*& arr, int& dim, int k) {
	int* newArr = new int[dim + k];

	for (int i = 0; i < k; i++)
		newArr[i] = 0;

	int ind = k;
	for (int i = 0; i < dim; i++)
		newArr[ind++] = arr[i];

	dim += k;
	delete[] arr;
	arr = new int[dim];
	for (int i = 0; i < dim; i++)
		arr[i] = newArr[i];

	delete[] newArr;
}

void modifArrB(int*& arr, int dim, int k) {
	int* newArr = new int[dim];

	int ind = 0;
	for (int i = k + 1; i < dim; i++)
		newArr[ind++] = arr[i];

	for (int i = 0; i < k + 1; i++)
		newArr[ind++] = arr[i];

	delete[] arr;
	arr = new int[dim];
	for (int i = 0; i < dim; i++)
		arr[i] = newArr[i];

	delete[] newArr;
}

int main() {
	int n, k, * v;
	readArr(v, n, k);
	//modifArrA(v, n, k); // a)
	modifArrB(v, n, k); // b)
	writeArr(v, n);
}