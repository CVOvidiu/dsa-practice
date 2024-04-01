// #4

#include <iostream>
#include <fstream>
#include <vector>
#include <unordered_map>

std::unordered_map<int, std::list<std::pair<int, int>>> makeMap(const std::vector<int>& arr) {
	std::unordered_map<int, std::list<std::pair<int, int>>> sumSeq;
	int sum;
	for (int i = 0; i < arr.size(); i++) {
		sum = arr[i];
		sumSeq[sum].push_back(std::make_pair(i, i));
		for (int j = i + 1; j < arr.size(); j++) {
			sum += arr[j];
			sumSeq[sum].push_back(std::make_pair(i, j));
		}
	}

	return sumSeq;
}

int main() {
	std::ifstream in("file.in");

	std::vector<int> arr;
	int elem;
	while (in >> elem)
		arr.push_back(elem);
	in.close();

	std::unordered_map<int, std::list<std::pair<int, int>>> map = makeMap(arr);

	int k; std::cin >> k;
	do {
		auto it = std::find_if(map.begin(), map.end(), [k](const auto& item) {
			return std::get<0>(item) == k;
			});
		if (it != map.end())
			for (auto const& pair : it->second)
				std::cout << "(" << pair.first << ", " << pair.second << ")\n";
		else
			std::cout << "Nu exista solutie\n";
	}
	while (std::cin >> k);
	return 0;
}