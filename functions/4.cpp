/*
Se citeste un numar natural n si un sir de n perechi de numere. Determinati si afisati perechea
pentru care valuarea cmmdc-ului dintre cele doua valori este maxima.
Exemplu: n=3
12 10
45 34
23 74.
se va afisa perechea: 45 35
*/

#include <iostream>

using namespace std;

int cmmdc(int first, int second) {
	while (first && second) {
		if (first > second) first -= second;
		else second -= first;
	}

	return first;
}

int main() {
	int n;
	cin >> n;

	int first, second, firstBckup, secondBckup, cmmdcCurrent, maxCmmdc = 0;
	for (int i = 0; i < n; i++) {
		cin >> first >> second;
		cmmdcCurrent = cmmdc(first, second);
			
		if (maxCmmdc < cmmdcCurrent) {
			maxCmmdc = cmmdcCurrent;
			firstBckup = first;
			secondBckup = second;
		}
	}

	cout << firstBckup << " " << secondBckup << " cmmdc: " << cmmdc(firstBckup, secondBckup);
}