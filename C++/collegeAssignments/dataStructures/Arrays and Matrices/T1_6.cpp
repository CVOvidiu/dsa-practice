// #6

#include <iostream>
#include <fstream>
#include <vector>

struct Coordonata {
	int x, y;

	int dist(Coordonata c2) {
		return std::sqrt(std::pow(c2.x - x, 2) + std::pow(c2.y - y, 2));
	}
};

bool readArr(std::vector<Coordonata>& arr, std::ifstream& in) {
	int numCoords; in >> numCoords;

	for (int i = 0; i < numCoords; i++) {
		Coordonata c;
		if (!(in >> c.x >> c.y)) {
			std::cerr << "Eroare la citire produs\n";
			return 1;
		}
		arr.push_back(c);
	}

	return 0;
}

std::pair<Coordonata, Coordonata> Dist(std::vector<Coordonata>& arr, const std::string& option) {
	std::pair<Coordonata, Coordonata> res;
	int dist = arr[0].dist(arr[1]);
	bool sw;

	for (auto it = arr.begin(); it != arr.end(); it++) {
		for(auto it2 = it + 1; it2 != arr.end(); it2++) {
			if (
				((*it2).dist(*it) >= dist && option == "max") ||
				((*it2).dist(*it) <= dist && option == "min")
				) {
				res.first = *it;
				res.second = *it2;
				dist = (*it2).dist(*it);
			}
		}
	}

	std::cout << "Distanta cea mai ";
	if(option == "max")
		std::cout << "mare: (" << res.first.x << ", " << res.first.y << ") si (" << res.second.x << ", " << res.second.y << ")\n";
	else
		std::cout << "mica: (" << res.first.x << ", " << res.first.y << ") si (" << res.second.x << ", " << res.second.y << ")\n";

	return res;
}

int main() {
	std::ifstream in("file.in");
	if (!in.is_open()) {
		std::cerr << "Eroare la deschidere fisier\n";
		return 1;
	}

	std::vector<Coordonata> arr;
	readArr(arr, in);
	in.close();

	Dist(arr, "max");
	Dist(arr, "min");
	
	return 0;
}