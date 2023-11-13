/*
Se citeste un numar natural n si apoi n numere naturale. Afisati cate dintre numerele citite au
rasturnatul egal cu primul numar citit.
Exemplu: n=7, 231 78 132 30 132 8 132 se va afisa: 3
*/

#include <iostream>
#include <cmath>

using namespace std;

int numDigits(int num) {
	int c = 0;

	while (num) {
		c++;
		num /= 10;
	}

	return c;
}

// //* Cu pow
// int flipped(int num) {
// 	int aux = 0;
// 	int tens = pow(10, numDigits(num) - 1);

// 	while (num) {
// 		aux += (num % 10) * tens;
// 		tens /= 10;
// 		num /= 10;
// 	}

// 	return aux;
// }

//* Fara pow
int flipped(int num) {
	int aux = 0;

	while(num) {
		aux = aux * 10 + num % 10;
		num /= 10;
	}

	return aux;
}

int main() {
	int n, first, num, c = 0;
	cin >> n;
	cin >> first;

	// Se poate scrie si intr-o functie
	for (int i = 0; i < n - 1; i++) {
		cin >> num;
		if (flipped(num) == first) c++;
	}
	
	cout << c;
}