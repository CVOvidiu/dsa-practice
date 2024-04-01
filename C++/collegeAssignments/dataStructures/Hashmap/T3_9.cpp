// #9

#include <iostream>
#include <unordered_map>
#include <set>

bool elemsInSet(const std::set<int>& s, const std::set<int>& s2) {
	return s == s2;
}

struct set_hash {
	std::size_t operator() (std::set<int> set) const {
		int res = std::hash<int>()(*(set.begin()));
		for (auto it = set.begin()++; it != set.end(); it++)
			res ^= std::hash<int>()(*it);
		return res;
	}
};

int main() {
	std::unordered_map<std::set<int>, int, set_hash> map;
	int x, y, z; std::cin >> x >> y >> z;

	do {
		std::set<int> init = { x, y, z };
		auto it = std::find_if(map.begin(), map.end(), [init](const auto& item) {
			return elemsInSet(std::get<0>(item), init);
			});
		if (map.empty()) {
			map.insert({ init, 1 });
			std::cout << "Numar aparitii: " << 1 << "\n";
		}
		else if (it != map.end()) {
			it->second++;
			std::cout << "Numar aparitii: " << it->second << "\n";
		}
		else {
			map.insert({ init, 1 });
			std::cout << "Numar aparitii: " << 1 << "\n";
		}
	} while (std::cin >> x >> y >> z);
	return 0;
}