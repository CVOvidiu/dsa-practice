/*
Se da un vector de numere intregi pozitive de dimensiune “dim”. Sa se sorteze
elementele palindroame din vectorul dat.

EX:	10
	121 34 545 78 676 12 454 89 787 43
	121 34 454 78 545 12 676 89 787 43
*/

#include <iostream>
#include <vector>

int flipped(int num) {
	int aux = 0;

	while (num) {
		aux = aux * 10 + num % 10;
		num /= 10;
	}

	return aux;
}

bool isPalindrome(int num) {
	return flipped(num) == num;
}

void readArr(int*& arr, int dim) {
	arr = new int[dim];

	std::cout << "Elem vector:\n";
	for (int i = 0; i < dim; i++)
		std::cin >> arr[i];
}

void writeArr(int* arr, int dim) {
	std::cout << "\nAfisare vector:\n";
	for (int i = 0; i < dim; i++)
		std::cout << arr[i] << " ";
	std::cout << "\n";
}

void quickSort(std::vector<int>& arr, int st, int dr) {
	int i = st, j = dr;
	int piv = arr[(dr + st) / 2];

	while (i <= j) { // Atat timp cat limita stanga nu a trecut peste limita dreapta
		while (arr[i] < piv) // Cat timp sunt sortate corect, treci peste ele
			i++;
		while (arr[j] > piv)
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
		quickSort(arr, st, j);
	if (i < dr)
		quickSort(arr, i, dr);
}

void sortPalindromes(int*& arr, int dim) {
	std::vector<int> palindromes;

	for (int i = 0; i < dim; i++)
		if (isPalindrome(arr[i]))
			palindromes.push_back(arr[i]);

	// Sort palindromes
	quickSort(palindromes, 0, palindromes.size() - 1);

	int pIndex = 0;
	for(int i = 0; i < dim; i++)
		if (isPalindrome(arr[i])) {
			arr[i] = palindromes[pIndex];
			pIndex++;
		}
}

int main() {
	int dim;
	std::cout << "Dim = ";
	std::cin >> dim;

	int* arr = nullptr;
	readArr(arr, dim);
	sortPalindromes(arr, dim);
	writeArr(arr, dim);
}