/*
Sa se verifice daca cifrele lui n sunt in progresie aritmetica. Exemplu: n = 2596 se va afisa:
Cifrele lui 2596 nu sunt in progresie aritmetica.
Exemplu: n=2468 se va afisa: Cifrele lui 2468 sunt in progresie aritmetica
*/

/*
Progresie aritmetica:
1) a_n = a_(n-1) + r, n -> N, n >= 2
2) r(ratia) = a_n - a_(n-1)
*/

#include <iostream>

using namespace std;

bool isArithmeticProgression(int num) {
	if (num < 10) return false; // n >= 2

	int last = num % 10; // Ultimul termen
	int secondLast = num / 10 % 10; // Penultimul termen

	int ratio = last - secondLast;
	while (num > 9) { // ca secondLast sa existe
		last = num % 10;
		secondLast = num / 10 % 10;
		if (last - secondLast != ratio) return false;
		num /= 10;
	}

	return true;
}

int main() {
	int n;
	cin >> n;

	cout << isArithmeticProgression(n);
}