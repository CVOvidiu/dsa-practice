/*
Se citeste o matrice patratica cu n linii si n coloane (n<=100), cu
elemente numere naturale din intervalul [0,1000], avand elementele
distincte pe fiecare dintre cele doua diagonale. Interschimbati elementul
maxim de pe diagonala principala cu elementul minim de pe diagonala
secundara. Afisati matricea rezultata.
*/

#include <iostream>
#include <fstream>

bool readMtx(int**& mtx, int& n, const std::string fileName) {
	std::ifstream file(fileName);
	file >> n;
		
	if (!file.is_open()) {
		std::cerr << "Eroare la deschidere fisier";
		return false;
	}

	mtx = new int* [n];
	for (int i = 0; i < n; i++) {
		mtx[i] = new int[n];
		for (int j = 0; j < n; j++)
			file >> mtx[i][j];
	}

	file.close();
	return true;
}

void writeMtx(int** mtx, int n) {
	for (int i = 0; i < n; i++) {
		for (int j = 0; j < n; j++)
			std::cout << mtx[i][j] << " ";
		std::cout << std::endl;
	}
}

void changeMtx(int**& mtx, int n) {
	int cmax, vmax = -1, cmin, vmin = 1001;

	for (int i = 0; i < n; i++) {
		for (int j = 0; j < n; j++) {
			if (vmax < mtx[i][j] && i == j) {
				vmax = mtx[i][j];
				cmax = i;
			}
			if (vmin > mtx[i][j] && n - 1 == i + j) {
				vmin = mtx[i][j];
				cmin = i;
			}
		}
	}

	int vaux = mtx[cmax][cmax];
	mtx[cmax][cmax] = mtx[cmin][n - 1 - cmin];
	mtx[cmin][n - 1 - cmin] = vaux;
}

void dealoc(int** mtx, int n) {
	if (mtx == nullptr)
		return;

	for (int i = 0; i < n; i++)
		delete[] mtx[i];
	delete[] mtx;

	std::cout << std::endl << "Memoria a fost dealocata";
}

int main() {
	int n;
	int** mtx;
	std::string fileName = "file.txt";
	readMtx(mtx, n, fileName);
	writeMtx(mtx, n);
	changeMtx(mtx, n);
	std::cout << std::endl;
	writeMtx(mtx, n);
	dealoc(mtx, n);
}