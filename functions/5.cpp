/*
Se citeste un numar natural k din intervalul [1, 9]. Afisati toate numerele n formate din exact k
cifre care au proprietatea ca n - 1 si n + 1 sunt numere prime.
Exemplu: k=2 se vor afisa numerele: 12, 18, 30, 42, 60 si 72
*/

#include <iostream>

using namespace std;

int limInf(int k) {
	int p = 1;

	while (k - 1) {
		p *= 10;
		k--;
	}

	return p;
}

int limSup(int k) {
	int aux = 9;

	while (k - 1) {
		aux = aux * 10 + 9;
		k--;
	}

	return aux;
}

bool prim(int num) {
	for (int d = 2; d < num / 2; d++) {
		if (num % d == 0) return false;
	}
	return true;
}

bool proprietate(int num) {
	return prim(num - 1) && prim(num + 1);
}

int main() {
	int k;
	cin >> k;

	int infLim = limInf(k);
	int supLim = limSup(k);

	for (int i = infLim; i <= supLim; i++) {
		if (proprietate(i)) cout << i << '\n';
	}
}