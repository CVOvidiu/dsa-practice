/*
Se citeste un numar natural n. Afisati toate perechile de numere de la 1 la n care au proprietatea
ca au aceeasi suma a cifrelor.
Exemplu: n=15 se vor afisa perechile: (1 10), (2 11), (3 12), (4 13), (5 14), (6 15)
*/

//TODO: Constructia numarului in loc de for-uri?

#include <iostream>

using namespace std;

int sumDigits(int num) {
	int sum = 0;

	while (num) {
		sum += num % 10;
		num /= 10;
	}

	return sum;
}

void sameSumDigits(int n) {
	for (int i = 1; i <= n; i++) {
		for (int j = i; j <= n; j++) { // sau 'j = i + 1' ca sa eliminam 'i != j'
			if (sumDigits(i) == sumDigits(j) && i != j) {
				cout << "(" << i << " " << j << ")\n";
			}
		}
	}
}

int main() {
	int n;

	cin >> n;

	sameSumDigits(n);
}