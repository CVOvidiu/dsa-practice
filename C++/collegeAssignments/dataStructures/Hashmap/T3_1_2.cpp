// #1 (without vector resize)

#include <iostream>
#include <fstream>
#include <vector>
#include <list>
#include <algorithm>

class HashMap {
private:
	std::vector<std::pair<int, std::list<int>>> HM;
public:
	void insert(const std::pair<int, int>& pereche) {
		auto it = std::find_if(HM.begin(), HM.end(), [pereche](const auto& item) {
			return std::get<0>(item) == pereche.first;
			});
		if (HM.empty() || it == HM.end()) {
			std::list<int> aux;
			aux.push_back(pereche.second);
			HM.push_back(std::make_pair(pereche.first, aux));
		}
		else
			it->second.push_back(pereche.second);
	}

	std::pair<int, std::list<int>> find(const int& key) {
		auto it = std::find_if(HM.begin(), HM.end(), [key](const auto& item) {
			return std::get<0>(item) == key;
			});
		if (!HM.empty() && it != HM.end()) {
			std::cout << key << " : ";
			for (const auto& el : it->second)
				std::cout << el << " ";
			std::cout << "\n";
			return *it;
		}
		else {
			std::cout << "Cheia nu exista.\n";
			std::list<int> aux;
			return std::make_pair(INT_MAX, aux);
		}
	}

	void print() {
		for (const auto& el : HM) {
			std::cout << el.first << " : ";
			for (auto it = el.second.begin(); it != el.second.end(); it++)
				std::cout << *it << " ";
			std::cout << "\n";
		}
	}
};

int main() {
	std::ifstream in("file.in");
	int size; in >> size;
	HashMap HM;
	std::pair<int, int> pereche;
	while (in >> pereche.first >> pereche.second)
		HM.insert(pereche);
	in.close();

	int running = 1;
	while (running) {
		system("CLS");
		std::cout << "====== Menu ======\n";
		std::cout << "   Choose between options:\n";
		std::cout << "1. Find key\n";
		std::cout << "2. Insert pair\n";
		std::cout << "3. Print table\n";
		std::cout << "0. EXIT\n\n";
		int option, key, value;
		std::cout << "   Your option: ";
		std::cin >> option;

		switch (option) {
		case 0: {
			running = 0;
			break;
		}
		case 1: {
			system("CLS");
			std::cout << "Enter key to find: "; std::cin >> key;
			HM.find(key);
			system("pause");
			break;
		}
		case 2: {
			system("CLS");
			std::cout << "Enter pair to insert: "; std::cin >> key >> value;
			HM.insert(std::make_pair(key, value));
			break;
		}
		case 3: {
			system("CLS");
			std::cout << "Print hashmap:\n";
			HM.print();
			system("pause");
			break;
		}
		}
	}
	return 0;
}