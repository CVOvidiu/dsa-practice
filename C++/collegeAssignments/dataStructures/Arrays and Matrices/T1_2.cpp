// #2

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

int format(std::vector<int> arr) {
	std::vector<int> frecv;
	frecv.resize(10);

	for (int elem : arr) {
		if (elem == 0)
			frecv[0]++;
		while (elem != 0) {
			int uc = elem % 10;
			frecv[uc]++;
			elem /= 10;
		}
	}

	int res = 0;
	for (int i = frecv.size() - 2; i >= 0; i = i - 2)
		while (frecv[i] != 0) {
			res = res * 10 + i;
			frecv[i]--;
		}
		
	return res;
}

int main() {
	std::ifstream in("file.in");
	if (!in.is_open()) {
		std::cerr << "Eroare la deschidere fisier\n";
		return 1;
	}

	std::vector<int> arr;
	readArr(arr, in);

	in.close();

	std::cout << format(arr);

	return 0;
}