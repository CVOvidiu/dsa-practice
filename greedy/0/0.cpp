/*
	Într-un laborator de analize chimice se utilizează n reactivi. Se ştie că, pentru a evita accidentele
	sau deprecierea reactivilor, aceştia trebuie să fie stocaţi în condiţii de mediu speciale. Mai exact, pentru
	fiecare reactiv, se precizează intervalul de temperatură [tmin, tmax] în care trebuie să se încadreze
	temperatura de stocare a acestuia. Reactivii vor fi plasaţi în frigidere. Orice frigider are un dispozitiv cu
	ajutorul căruia putem stabili temperatura (constantă) care va fi in interiorul acelui frigider (exprimată
	într-un număr întreg de grade Celsius)
	a. Să se specifice care este numărul minim de frigidere de care avem nevoie pentru a stoca cei
	n-reactivi astfel încât diferența tmax - tmin să fie de maxim K grade celsius, K – precizat.
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