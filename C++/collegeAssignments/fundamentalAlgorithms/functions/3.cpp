/*
Se citesc doua numere naturale a si b. Calculati cate numere palindrom sunt din intervalul [a, b].
Un numar este palindrom daca are aceeasi valoare atat daca e citit de la stanga la dreapta cat si
de la dreapta la stanga (de exemplu 12321).
Exemplu: a=100, b=200 se va afisa: 101, 111, 121, 131, 141, 151, 161, 171, 181, 191
*/

#include <iostream>

using namespace std;

int flipped(int num) {
	int aux = 0;

	while (num) {
		aux = aux * 10 + (num % 10);
		num /= 10;
	}

	return aux;
}

bool isPalindrome(int num) {
	return flipped(num) == num;
}

int main() {
	int a, b;
	cin >> a >> b;

	for (int i = a; i <= b; i++) {
		if (isPalindrome(i))
			cout << i << '\n';
	}
}