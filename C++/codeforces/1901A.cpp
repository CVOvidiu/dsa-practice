// https://codeforces.com/problemset/problem/1901/A

#include <iostream>

int main() {
	int testCases; std::cin >> testCases;
	while (testCases--) {
		int numStations, middle; std::cin >> numStations >> middle;
		int minFuel; std::cin >> minFuel;
		int prev = minFuel;
		int elem;
		for (int i = 1; i < numStations; i++) {
			std::cin >> elem;
			if (elem - prev > minFuel)
				minFuel = elem - prev;
			prev = elem;
		}
		if ((middle - prev) * 2 > minFuel)
			minFuel = (middle - prev) * 2;
		std::cout << minFuel << "\n";
	}

	return 0;
}