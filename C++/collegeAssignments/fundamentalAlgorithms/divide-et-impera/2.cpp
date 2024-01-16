// Al n-lea minim din vector

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

int part(std::vector<int>& arr, int st, int dr) {
	int piv = arr[dr];
	int i = st;

	for (int j = st; j <= dr - 1; j++)
		if (arr[j] < piv) {
			std::swap(arr[i], arr[j]);
			i++;
		}
	std::swap(arr[i], arr[dr]);
	return i;
}

int nthMin(std::vector<int>& arr, int st, int dr, int& magicNum) {
	int pi = part(arr, st, dr);

	if (pi > magicNum)
		return nthMin(arr, st, pi - 1, magicNum);
	else if (pi < magicNum)
		return nthMin(arr, pi + 1, dr, magicNum);
	else
		return arr[pi];
}

void main() {
	std::vector<int> arr;
	readArr(arr);

	int magicNum;
	std::cout << "Al n-lea minim: ";
	std::cin >> magicNum;
	if (arr.size() < magicNum)
		std::cerr << "Eroare: Array-ul este prea mic";
	else {
		magicNum--;
		std::cout << "Al " << magicNum + 1 << "-lea cel mai mic elem : " << nthMin(arr, 0, arr.size() - 1, magicNum);
	}
}