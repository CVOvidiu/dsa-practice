/*
	Se dă o matrice sortată crescător complet. Să se determine daca exista elementul k dat in
	matrice, cu ajutorul unui algoritm de tip D & I. 
*/

#include <iostream>
#include <fstream>

bool readMtx(int**& mtx, int& n, int& m, const std::string fileName) {
	std::ifstream file(fileName);
	if (!file.is_open()) {
		std::cerr << "Eroare la deschidere fisier";
		return false;
	}

	if (!(file >> n >> m)) {
		std::cerr << "Eroare la citire dimensiuni";
		return false;
	}

	mtx = new int* [n];
	for (int i = 0; i < n; i++) {
		mtx[i] = new int[m];
		for (int j = 0; j < m; j++)
			if (!(file >> mtx[i][j])) {
				std::cerr << "Eroare la citire valori matrice";
				return false;
			}
	}

	file.close();
	return true;
}

void writeMtx(int** mtx, int n, int m) {
	for (int i = 0; i < n; i++) {
		for (int j = 0; j < m; j++)
			std::cout << mtx[i][j] << " ";
		std::cout << std::endl;
	}
}

bool isK(int** mtx, int n, int m, int st, int dr) {
	int k; std::cout << "k = "; std::cin >> k;

	while (st <= dr) {
		int mij = (st + dr) / 2;
		int elemMij = mtx[mij / m][mij % m];

		if (elemMij == k)
			return true;
		else if (elemMij < k)
			st = mij + 1;
		else
			dr = mij - 1;
	}

	return false;
}

void main() {
	int** mtx;
	int n, m;
	readMtx(mtx, n, m, "file.in");
	writeMtx(mtx, n, m);
	std::cout << "Este k?: " << isK(mtx, n, m, 0, (n * m) - 1);
}