#include <iostream>
#include <fstream>
#include <vector>

bool mtxRead(std::vector<std::vector<int>>& mtx, int& numLin, int& numCol, const std::string& fileName) {
	std::ifstream in("file.in");
	if (!in.is_open()) {
		std::cerr << "Eroare la deschidere fisier\n";
		return 1;
	}

	if (!(in >> numLin >> numCol)) {
		std::cerr << "Eroare la citire\n";
		return 1;
	}

	mtx.resize(numLin);
	for (int i = 0; i < numLin; i++) {
		mtx[i].resize(numCol);
		for (int j = 0; j < numCol; j++) {
			if (!(in >> mtx[i][j])) {
				std::cerr << "Eroare la citire\n";
				return 1;
			}
		}
	}

	std::cout << "Citire efectuata cu succes.\n\n";

	in.close();
	return 0;
}

void mtxWrite(std::vector<std::vector<int>>& mtx, const int& numLin, const int& numCol) {
	std::cout << "Afisare matrice:\n";
	for (int i = 0; i < numLin; i++) {
		for (int j = 0; j < numCol; j++)
			std::cout << mtx[i][j] << " ";
		std::cout << "\n";
	}
	std::cout << "\n";
}

int main() {
	std::vector<std::vector<int>> mtx;
	int numLin, numCol;
	std::string fileName = "file.in";
	
	if (mtxRead(mtx, numLin, numCol, fileName))
		return 1;
	mtxWrite(mtx, numLin, numCol);

	return 0;
}