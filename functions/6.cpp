/*
Sa se afiseze cel mai mic numar care se poate forma cu cifrele lui n, fiecare cifra repetandu-se
de cate ori se repeta si in n.
Exemplu: 1204192 se va afisa: 1012249
*/

// Vector de frecventa

#include <iostream>

using namespace std;

int buildSmallNum(int num) {
	int frecv[10] = { 0 }; // Initializare toate pozitiile cu 0

	while (num) { // Initializare vector cu numar de aparitii
		frecv[num % 10]++;
		num /= 10;
	}

	int build = 0;
	for (int i = 1; i <= 9; i++) { // Initializare prima cifra a nr construit pt a pune zero-urile
		if (frecv[i]) {
			build = build * 10 + i;
			frecv[i]--;
			break;
		}
	}
	while (frecv[0]) { // Cat timp sunt zero-uri
		build = build * 10;
		frecv[0]--;
	}
	for (int i = 1; i <= 9; i++) { // Formeaza restul numarului
		while (frecv[i]) {
			build = build * 10 + i;
			frecv[i]--;
		}
	}

	return build;
}

int main() {
	int n;
	cin >> n;

	cout << buildSmallNum(n);
}