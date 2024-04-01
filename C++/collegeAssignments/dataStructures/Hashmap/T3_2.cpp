// #2

#include <iostream>
#include <fstream>
#include <vector>
#include <unordered_map>

std::string palindrom(const std::string& arr) {
	std::unordered_map<char, int> ltrCount;
	for (const char& c : arr)
		ltrCount[c]++;

	int oddsCount = 0;
	char oddCharacter = '\0';
	std::string res = "";
	for (const auto& el : ltrCount) {
		if (el.second % 2 != 0) {
			if (++oddsCount > 1)
				return "";
			oddCharacter = el.first;
		}
		for (int i = 0; i < el.second / 2; i++)
			res.push_back(el.first);
	}
	/*
	res.reserve(res.size() * 2 + 1); // append can lead to iterator errors if `res` may reallocate
	if (oddCharacter != '\0') {
		res.push_back(oddCharacter);
		res.append(res.rbegin() + 1, res.rend());
	} else
	res.append(res.rbegin(), res.rend());
	*/
	std::string aux = res;
	if(oddCharacter != '\0')
		res.push_back(oddCharacter);
	std::reverse(aux.begin(), aux.end());
	res = res + aux;
	return res;
}

int main() {
	std::ifstream in("file.in");

	std::string arr; in >> arr;
	std::cout << palindrom(arr);
	in.close();
	return 0;
}