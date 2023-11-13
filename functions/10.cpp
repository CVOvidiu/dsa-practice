/*
Se citeste un numar natural n, n>1000. Afisati cel mai mare numar care se pot obtine din n prin
eliminarea unei singure cifre.
Exemplu: din 45329 se obtine 5329 (e cel mai mare dintre numerele 4532 4539 4529 4329
5329)
*/

#include <iostream>
#include <cmath>

using namespace std;

int countDigits(int num) {
	int c = 0;
	while (num) {
		c++;
		num /= 10;
	}

	return c;
}

int biggestNum(int num) {
	int max = num / 10, poz = 2, built; // poz - de la coada; poz 1 - ultima cifra
	int digits = countDigits(num);

	while (poz <= digits) {
		int firstHalf = num / pow(10, poz); // partea din fata a num pana la poz
		int sndHalf = num % (int) pow(10, poz - 1); // partea din spate a num pana la poz
		built = firstHalf * pow(10, countDigits(sndHalf)) + sndHalf;

		if (max < built) max = built;

		poz++;
	}

	return max;
}

int main() {
	int n;
	cin >> n;

	cout << biggestNum(n);
}