/*
Găsirea celui mai lung șir: Se citește un tablou de șiruri de caractere și se
găsește cel mai lung șir din tablou.
*/

#include <iostream>
#include <fstream>

bool biggestString(const std::string fileName) {
	std::ifstream file(fileName);

	if (!file.is_open()) {
		std::cerr << "Eroare la deschidere fisier";
		return false;
	}

	std::string str, bigString = "";
	while (!file.eof()) {
		if (!(file >> str)) {
			std::cerr << "Eroare la citire string " << str;
			return false;
		}
		else {
			if (str.size() > bigString.size())
				bigString = str;
		}
	}

	std::cout << bigString;

	file.close();
	return true;
}

void main() {
	std::string fileName = "file.txt";
	biggestString(fileName);
}