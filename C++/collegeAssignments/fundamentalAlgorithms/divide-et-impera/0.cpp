// Suma tuturor elem din vector

#include <iostream>
#include <vector>

void readArr(std::vector<int>& arr) {
	int n;
	std::cout << "n=";
	std::cin >> n;

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

int suma(std::vector<int> arr, int st, int dr) {
	if (st == dr)
		return arr[st];
	else {
		int mij = (st + dr) / 2;
		int s1 = suma(arr, st, mij);
		int s2 = suma(arr, mij + 1, dr);

		return s1 + s2;
	}
}

void main() {
	std::vector<int> arr;
	readArr(arr);

	std::cout << "Suma elementelor: " << suma(arr, 0, arr.size() - 1);
}