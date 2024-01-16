/*
	Se dă un vector convex (elementele sale sunt în ordine strict crescătoare până la o anumită
	poziție, după care sunt strict descrescătoare). Să se determine maximul din vector cu ajutorul
	unui algoritm de tip D & I. Exemplu: v = {1, 2, 3, 4, 5, 6, 4, 3, 2} → max=6
*/

#include <iostream>
#include <vector>

void readArr(std::vector<int>& arr) {
	int n;
	std::cout << "n=";
	std::cin >> n;

	std::cout << "Introduceti elementele: \n";
	int temp;
	for (int i = 0; i < n; i++) {
		std::cin >> temp;
		arr.push_back(temp);
	}
}

void writeArr(const std::vector<int>& arr) {
	for (int el : arr)
		std::cout << el << " ";
}

int max(std::vector<int> arr, int st, int dr) {
	int mij = st + (dr - st) / 2;
	if (arr[mij - 1] < arr[mij] && arr[mij + 1] < arr[mij])
		return arr[mij];
	else if (arr[mij - 1] > arr[mij])
		return max(arr, st, mij - 1);
	else
		return max(arr, mij + 1, dr);
}

void main() {
	std::vector<int> arr;
	readArr(arr);
	std::cout << "Maximul din vector: " << max(arr, 0, arr.size() - 1);
}