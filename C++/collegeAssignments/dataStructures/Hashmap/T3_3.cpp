// #3

#include <iostream>
#include <fstream>
#include <vector>
#include <unordered_map>

bool permutare(const std::string& arr, const std::string& arr2) {
	std::unordered_map<char, int> ltrCount;
	for (const char& c : arr)
		ltrCount[c]++;

	for (const char& el : arr2) {
		ltrCount[el]--;
		if (ltrCount[el] == 0)
			ltrCount.erase(el);
	}

	if (ltrCount.empty())
		return 1;
	return 0;
}

int main() {
	std::ifstream in("file.in");

	std::string arr, arr2; in >> arr >> arr2;
	std::cout << permutare(arr, arr2);
	in.close();
	return 0;
}