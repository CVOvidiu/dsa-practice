// https://codeforces.com/problemset/problem/1900/A

#include <iostream>
#include <string>

int numWaterCells(int numCells, std::string cells) {
	int validCellsCounter = 0;
	int sumWaterCells = 0;
	for (const char& el : cells) {
		if (el == '.')
			validCellsCounter++;
		else {
			sumWaterCells += validCellsCounter;
			validCellsCounter = 0;
		}

		if (validCellsCounter > 2)
			return 2;
	}
	sumWaterCells += validCellsCounter;
	return sumWaterCells;
}

int main() {
	int testCases; std::cin >> testCases;
	while (testCases--) {
		int numCells; std::cin >> numCells;
		std::string cells; std::cin >> cells;
		std::cout << numWaterCells(numCells, cells) << "\n";
	}

	return 0;
}