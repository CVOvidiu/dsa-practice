/*
 Un număr natural se reţine într-un vector (număr mare), astfel încât fiecare componentă a
vectorului conţine câte o cifră a numărului. Să se înmulţească numărul cu un număr între 1
şi 9 (random generat). Documentatie random:
https://cplusplus.com/reference/cstdlib/rand/
*/

#include <iostream>
#include <stdlib.h>
#include <time.h> // Truly random

// presupunem ca numarul o sa fie introdus cu spatii intre cifre si o sa fie introdusa si dimensiunea

void readArr(int*& arr, int& dim) {
	std::cin >> dim;
	arr = new int[dim];
	for (int i = 0; i < dim; i++)
		std::cin >> arr[i];
}

void multiply(int*& arr, int dim) {
	srand(time(NULL));
	int randNum = (rand() % 9) + 1; // 1 -> 9
	std::cout << "\nRand: " << randNum << "\n";
	int transport = 0, *newArr = new int[dim + 1];

	int ind = 0;
	for (int i = dim - 1; i >= 0; i--) {
		newArr[ind++] = (arr[i] * randNum + transport) % 10;
		transport = (arr[i] * randNum + transport) / 10; // 12 * 8 = 1*8+1 2*8%10=6; 99*9= 8 9*9=81+8=89%10=9 9*9=81%10=1
	}
	if (transport)
		newArr[ind] = transport;

	if (transport)
		for (int i = dim; i >= 0; i--)
			std::cout << newArr[i] << " ";
	else
		for (int i = dim - 1; i >= 0; i--)
			std::cout << newArr[i] << " ";
}

void main() {
	int* v, n;
	readArr(v, n);
	multiply(v, n);
}