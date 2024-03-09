#include <iostream>
#include <fstream>

bool mtxAlloc(int**& mtx, int& height, int& width, std::ifstream& in) {
	in >> height >> width;

	mtx = new int*[height];
	if (!mtx) {
		std::cerr << "Eroare la alocare\n";
		return 1;
	}
	for (int i = 0; i < height; i++) {
		mtx[i] = new int[width];
		if (!mtx[i]) {
			std::cerr << "Eroare la alocare\n";
			return 1;
		}
	}

	std::cout << "Alocare efectuata cu succes.\n\n";

	return 0;
}

void mtxDealloc(int**& mtx, const int& height) {
	for (int i = 0; i < height; i++)
		delete mtx[i];
	delete mtx;

	std::cout << "Dealocare efectuata.\n\n";
}

bool mtxRead(int**& mtx, const int& height, const int& width, std::ifstream& in) {
	for (int i = 0; i < height; i++)
		for (int j = 0; j < width; j++) {
			if (!(in >> mtx[i][j])) {
				std::cerr << "Eroare la citire\n";
				return 1;
			}
		}

	std::cout << "Citire efectuata cu succes.\n\n";

	return 0;
}

void mtxWrite(int**& mtx, const int& height, const int& width) {
	std::cout << "Afisare matrice:\n";
	for (int i = 0; i < height; i++) {
		for (int j = 0; j < width; j++)
			std::cout << mtx[i][j] << " ";
		std::cout << "\n";
	}
	std::cout << "\n";
}

int main() {
	int** mtx;
	int height, width;

	std::ifstream in("file.in");
	if (!in.is_open()) {
		std::cerr << "Eroare la deschidere fisier\n";
		return 1;
	}

	if (mtxAlloc(mtx, height, width, in))
		return 1;
	if (mtxRead(mtx, height, width, in))
		return 1;
	mtxWrite(mtx, height, width);
	mtxDealloc(mtx, height);

	in.close();
	return 0;
}