/*
Se dau n numere naturale distincte între [0, n]. Scriind o funcție de D & I, determinați
numărul lipsă.
*/

// file.in lipseste 16

#include <iostream>
#include <vector>
#include <fstream>

void readArr(std::vector<int>& arr) {
	std::ifstream in("file.in");

	int n; in >> n; n--;

	int temp;
	for (int i = 0; i < n; i++) {
		in >> temp;
		arr.push_back(temp);
	}

	in.close();
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

int missingNum(std::vector<int>& arr, int st, int dr) {
	if(st > dr)
		return st;

	int pi = part(arr, st, dr);

	if (arr[pi] != pi)
		return missingNum(arr, st, pi - 1);
	else
		return missingNum(arr, pi + 1, dr);
}

int main() {
	std::vector<int> arr;
	readArr(arr);
	std::cout << "Nr lipsa din vector: " << missingNum(arr, 0, arr.size() - 1);

	return 0;
}