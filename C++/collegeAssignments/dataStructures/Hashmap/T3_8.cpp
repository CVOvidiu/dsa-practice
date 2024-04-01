// #8

#include <iostream>
#include <unordered_map>
#include <set>
#include <list>
#include <fstream>

bool elemsInSet(std::set<char> s, std::set<char> s2) {
	return s == s2;
}

struct set_hash {
	std::size_t operator() (std::set<char> set) const {
		int res = std::hash<char>()(*(set.begin()));
		for (auto it = set.begin()++; it != set.end(); it++)
			res ^= std::hash<char>()(*it);
		return res;
	}
};

using mapType = std::unordered_map<std::set<char>, std::list<std::string>, set_hash>;


mapType makeMap(const std::string& str, mapType& map) {
	std::set<char> init;
	for (const char& c : str)
		init.insert(c);
	auto it = std::find_if(map.begin(), map.end(), [init](const auto& item) {
		return elemsInSet(std::get<0>(item), init);
		});
	if (map.empty()) {
		std::list<std::string> l;
		l.push_back(str);
		map.insert({ init, l });
	}
	else if (it != map.end()) {
		it->second.push_back(str);
	}
	else {
		std::list<std::string> l;
		l.push_back(str);
		map.insert({ init, l });
	}

	return map;
}

void printPairs(const mapType& map) {
	for (const auto& el : map) {
		for (const auto& el2 : el.second)
			std::cout << el2 << " ";
		std::cout << "\n";
	}
}

int main() {
	std::ifstream in("file.in");
	std::string str; in >> str;
	mapType map;

	do makeMap(str, map);
	while (in >> str);
	printPairs(map);
	
	return 0;
}