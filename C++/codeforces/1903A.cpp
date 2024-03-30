// https://codeforces.com/problemset/problem/1903/A

#include <iostream>
#include <vector>
#include <algorithm>

int main() {
	int testCases; std::cin >> testCases;
	while (testCases--) {
		int numBoxes, maxLenReverse; std::cin >> numBoxes >> maxLenReverse;
		std::vector<int> arr;
		for (int i = 0; i < numBoxes; i++) {
			int elem; std::cin >> elem;
			arr.push_back(elem);
		}
		if (maxLenReverse >= 2)
			std::cout << "YES\n";
		else {
			std::vector<int> aux = arr;
			std::sort(aux.begin(), aux.end());
			if (aux == arr)
				std::cout << "YES\n";
			else
				std::cout << "NO\n";
		}
	}

	return 0;
}