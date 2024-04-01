// #1

#include <iostream>
#include <fstream>
#include <vector>
#include <list>

class HashMap {
private:
	std::vector<std::list<int>> HM;
public:
	HashMap(const int& size) {
		HM.resize(size);
	}

	void insert(const std::pair<int, int>& pereche) {
		HM[pereche.first].push_back(pereche.second);
	}

	std::list<int> find(const int& key) {
		std::cout << key << " : ";
		for (auto it = HM[key].begin(); it != HM[key].end(); it++)
			std::cout << *it << " ";
		std::cout << "\n";
		return HM[key];
	}

	void print() {
		for (int i = 0; i < HM.size(); i++) {
			std::cout << i << " : ";
			for (auto it = HM[i].begin(); it != HM[i].end(); it++)
				std::cout << *it << " ";
			std::cout << "\n";
		}

	}
};

int main() {
	std::ifstream in("file.in");
	int size; in >> size;
	HashMap HM(size);
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