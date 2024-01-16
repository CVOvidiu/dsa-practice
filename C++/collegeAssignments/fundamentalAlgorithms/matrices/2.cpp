/*
Se citeste o matrice patratica cu n linii si n coloane (n<=100), cu
elemente numere naturale din intervalul [0,1000]. Sa se determine sumele
elementelor celor 4 triunghiuri determinate de diagonala principala si cea
secundara.
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

	return true;
	file.close();
}

void writeMtx(int** mtx, int n) {
	for (int i = 0; i < n; i++) {
		for (int j = 0; j < n; j++)
			std::cout << mtx[i][j] << " ";
		std::cout << std::endl;
	}
}

void sumTriangles(int**& mtx, int n) {
	int s[4] = {};

	/*
	[0][0] [0][1] [0][2] [0][3]
	[1][0] [1][1] [1][2] [1][3]
	[2][0] [2][1] [2][2] [2][3]
	[3][0] [3][1] [3][2] [3][3]
	*/

	for (int i = 0; i < n; i++) {
		for (int j = 0; j < n; j++) {
			if ((i <= j) && ((i + j) <= (n - 1))) // N
				s[0] += mtx[i][j];
				//std::cout << mtx[i][j] << " ";
			if ((i >= j) && ((i + j) <= (n - 1))) // W
				s[1] += mtx[i][j];
				//std::cout << mtx[i][j] << " ";
			if ((i >= j) && ((i + j) >= (n - 1))) // S
				s[2] += mtx[i][j];
				//std::cout << mtx[i][j] << " ";
			if ((i <= j) && ((i + j) >= (n - 1))) // E
				s[3] += mtx[i][j];
				//std::cout << mtx[i][j] << " ";
		}
	}

	std::cout << "N: " << s[0] << "\n";
	std::cout << "W: " << s[1] << "\n";
	std::cout << "S: " << s[2] << "\n";
	std::cout << "E: " << s[3] << "\n";
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
	sumTriangles(mtx, n);
	dealoc(mtx, n);
}