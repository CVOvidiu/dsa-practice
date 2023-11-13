/*
Se citeste un numar natural n cu numar par de cifre. Calculati si afisati numarul obtinut din n
inversand cifra unitatilor cu a zecilor, cea a sutelor cu cea a miilor, etc.
Exemplu: n=123456 rezulta 214365
*/

#include <iostream>

using namespace std;

int swapPos(int num) {
	int build = 0, secondLast, last, p = 10, q = 1; // p, q - puterile
	while (num > 9) {
		last = num % 10;
		secondLast = num / 10 % 10;

		build = build + (last * p) + (secondLast * q);
		// Contruit din 2 in 2 pozitii
		p *= 100;
		q *= 100;
		num /= 100;
	}

	return build;
}

int main() {
	int n;
	cin >> n;

	cout << swapPos(n);
}