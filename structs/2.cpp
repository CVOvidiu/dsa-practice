/*
Sa se citeasca dintr-un fisier un vector de carti, Pentru fiecare stim titlul, autorul si
anul de aparitie. Sa se grupeze cartile in functie de un anumit criteriu din cele 3.
Indicatie: incercati atat cu sortare, cat si fara sortare de vector
*/
//TODO: Fara sortare vector

#include <iostream>
#include <fstream>
#include <vector>
#include <algorithm>

struct Book {
	std::string title;
	std::string author;
	int year;
};

bool readArr(std::vector<Book>& arr, const std::string fileName) {
	std::ifstream in(fileName);

	if (!in.is_open()) {
		std::cerr << "Eroare la deschidere fisier.\n";
		return 1;
	}

	Book book;
	while (!in.eof()) {
		in >> book.title >> book.author >> book.year;
		arr.push_back(book);
	}

	std::cout << "Citirea a reusit\n\n";
	in.close();
	return 0;
}

void writeArr(std::vector<Book> arr) {
	std::cout << "Afisare:\n";
	for (Book elem : arr)
		std::cout << elem.title << " " << elem.author << " " << elem.year << "\n";
	std::cout << "\n";
}

bool comparator(Book b1, Book b2) {
	return b1.year < b2.year;
}

void sortArr(std::vector<Book>& arr) {
	std::cout << "Sortare vector.\n\n";

	std::sort(arr.begin(), arr.end(), comparator);
}

void QS(std::vector<Book>& arr, int st, int dr) {
	int i = st, j = dr;
	Book piv = arr[(dr + st) / 2];

	while (i <= j) { // Atat timp cat limita stanga nu a trecut peste limita dreapta
		while (arr[i].author < piv.author) // Cat timp sunt sortate corect, treci peste ele
			i++;
		while (arr[j].author > piv.author)
			j--;
		if (i <= j) { // Daca a dat de o pereche neordonata deoarece nu a trecut limita stanga peste dreapta
			// Interschimba-le si continua cu limita
			std::swap(arr[i], arr[j]);
			i++;
			j--;
		}
	}

	// Toate elementele mai mici decat pivotul sunt la st && asemenea pt dr => pivotul este in pozitia finala

	if (st < j)
		QS(arr, st, j);
	if (i < dr)
		QS(arr, i, dr);
}

int main() {
	std::vector<Book> arr;
	readArr(arr, "in.txt");
	writeArr(arr);
	//sortArr(arr); // Method 1: STL sort
	QS(arr, 0, arr.size() - 1); // Method 2: QuickSort
	writeArr(arr);
}