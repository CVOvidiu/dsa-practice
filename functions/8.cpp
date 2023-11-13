/*
Se citesc un numar natural n de minim 3 cifre si o cifra c. Eliminati toate aparitiile cifrei c din
numarul n si afisati numarul astfel obtinut.
Exemplu: n= 2345324, c=2 rezulta numarul 34534
*/

#include <iostream>

using namespace std;

int elim(int num, int digit) {
	if (num < 100) return -1; // num has 3 digits minimum

	int build = 0, p = 1;
	while(num) {
		if (num % 10 != digit) {
			build = build + (num % 10) * p;
			p *= 10;
		}
		num /= 10;
	}

	return build;
}

int main() {
	int n, c;
	cin >> n >> c;

	cout << elim(n, c);
}