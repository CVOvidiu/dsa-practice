/*
	Greedy fisa 2 - 3a
*/

#include <iostream>
#include <vector>
#include <fstream>
#include <algorithm>

struct Reactiv {
	int tmin;
	int tmax;
};

bool readArr(std::vector<Reactiv>& reactivi, int& dim) {
	std::ifstream in("file.in");

	in >> dim;

	if (!in.is_open()) {
		std::cerr << "Eroare la deschidere fisier";
		return false;
	}

	Reactiv temp;
	for (int i = 0; i < dim; i++) {
		in >> temp.tmin >> temp.tmax;
		reactivi.push_back(temp);
	}

	in.close();
	return true;
}

void writeArr(const std::vector<Reactiv>& reactivi) {
	for (auto& elem : reactivi)
		std::cout << elem.tmin << " " << elem.tmax << "\n";
}

bool comparator(Reactiv r1, Reactiv r2) {
	return (r1.tmin < r2.tmin);
}

void greedy(std::vector<Reactiv> reactivi) {
	std::vector<Reactiv> frigider;
	frigider.push_back(reactivi[0]);

	int j = 0;
	for (int i = 1; i < reactivi.size(); i++) {
		if (reactivi[i].tmin <= frigider[j].tmax) {
			frigider[j].tmax = std::min(reactivi[i].tmax, frigider[j].tmax);
			frigider[j].tmin = std::max(reactivi[i].tmin, frigider[j].tmin);
		}
		else {
			frigider.push_back(reactivi[i]);
			j++;
		}
	}

	std::cout << "\nNumar frigidere: " << frigider.size() << "\n";
	writeArr(frigider);
}

int main() {
	int dim;
	std::vector<Reactiv> reactivi;
	if (!readArr(reactivi, dim))
		return 1;

	std::sort(reactivi.begin(), reactivi.end(), comparator);
	writeArr(reactivi);

	greedy(reactivi);

	return 0;
}