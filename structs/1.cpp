/*
Sa se citeasca dintr-un fisier un vector de dati calendaristice. Pentru fiecare data stim
ziua, luna si anul. Sa se afiseze cea mai recentă data (cea mai mare).
*/

#include <iostream>
#include <fstream>
#include <vector>
#include <tuple>

struct Date {
	int day;
	int month;
	int year;
};

bool readArr(std::vector<Date>& arr, const std::string fileName) {
	std::ifstream in(fileName);

	if (!in.is_open()) {
		std::cerr << "Eroare la deschidere fisier.\n";
		return 1;
	}

	Date date;
	while (!in.eof()) {
		in >> date.day >> date.month >> date.year;
		arr.push_back(date);
	}

	std::cout << "Citirea a reusit\n\n";
	in.close();
	return 0;
}

void writeArr(std::vector<Date> arr) {
	std::cout << "Afisare:\n";
	for (Date elem : arr)
		std::cout << elem.day << " " << elem.month << " " << elem.year << "\n";
	std::cout << "\n";
}

Date recentDate(std::vector<Date> arr) {
	Date max = arr[0];
	for (Date elem : arr) {
		/*if (
			(elem.year > max.year) ||
			(elem.year == max.year && elem.month > max.month) ||
			(elem.year == max.year && elem.month == max.month && elem.day > max.day)
			)
			max = elem;*/

		if (std::tie(elem.year, elem.month, elem.day) > std::tie(max.year, max.month, max.day))
			max = elem;
	}

	return max;
}

int main() {
	std::vector<Date> arr;
	readArr(arr, "in.txt");
	writeArr(arr);
	Date max = recentDate(arr);
	std::cout << "Recent date:\n" << max.day << " " << max.month << " " << max.year << "\n";
}