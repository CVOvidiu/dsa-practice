// #1

#include <iostream>
#include <fstream>
#include <vector>

bool readArr(std::vector<int>& arr, std::ifstream& in) {
	int nr; in >> nr;

	for (int i = 0; i < nr; i++) {
		int num;
		if (!(in >> num)) {
			std::cerr << "Eroare la citire produs\n";
			return 1;
		}
		arr.push_back(num);
	}

	return 0;
}

std::vector<int> merge(std::vector<int>& arr1, std::vector<int>& arr2) {
	std::vector<int> res;
	int i = 0, j = arr2.size() - 1;
	while(i < arr1.size() && j >= 0)
		if (arr1[i] >= arr2[j]) {
			res.push_back(arr2[j]);
			j--;
		}
		else {
			res.push_back(arr1[i]);
			i++;
		}

	while (i < arr1.size()) {
		res.push_back(arr1[i]);
		i++;
	}

	while (j >= 0) {
		res.push_back(arr2[j]);
		j--;
	}

	return res;
}

int main() {
	std::ifstream in("file.in");
	if (!in.is_open()) {
		std::cerr << "Eroare la deschidere fisier\n";
		return 1;
	}

	std::vector<int> arr1, arr2;
	readArr(arr1, in);
	readArr(arr2, in);

	in.close();

	std::vector<int> arr3 = merge(arr1, arr2);
	for (const int& elem : arr3)
		std::cout << elem << " ";

	return 0;
}