/*
Se citește un număr natural n și cele n cele n elemente ale unui vector. Să se șteargă din
vector acele elemente care sunt egale cu suma vecinilor săi.
*/

#include <iostream>

void citVect(int*& vect, int& dim) {
	std::cin >> dim;

	vect = new int[dim];

	for (int i = 0; i < dim; i++)
		std::cin >> vect[i];

	std::cout << "Vectorul a fost initializat\n";
}

void afVect(int* vect, int dim) {
	for (int i = 0; i < dim; i++) {
		std::cout << vect[i] << " ";
	}

	delete[] vect;
	std::cout << "\nVectorul a fost sters";
}

// Pt vectorul cu pozitii de sters
//void stergere(int*& vect, int& dim, int poz) {
//	for (int i = 0; i < dim; i++) {
//		if (poz == i + 1) {
//			vect[poz] = vect[poz + 1];
//			dim--;
//		}
//	}
//}

// 2 8* 6* -2* -8* -6* 2 <-- cu * am marcat pozitile de sters; putem avea cazul asta;
// e imposibil sa stergem la fiecare pas pozitia de sters pentru ca pierdem vecinii
//  => vector cu pozitiile de sters si stergem toate pozitiile
// sau vector in care copiem direct elementele vectorului care nu sunt de sters

void modifVect(int*& vect, int& dim) {
	// Trebuie sa aflam dimensiunea vectorului rezultat
	int counter = 2; // 2 pt ca excludem primul si ultimul element (ei au un vecin lipsa)
	for (int i = 1; i < dim - 1; i++)
		if (vect[i] != vect[i - 1] + vect[i + 1]) counter++;

	// Vectorul de pozitii
	int* rez = new int[counter];
	rez[0] = vect[0]; // Ii dam primul element ca nu are vecin

	int ind = 1; // indicele vectorului rezultat
	for (int i = 1; i < dim - 1; i++) 
		if (vect[i] != vect[i - 1] + vect[i + 1]) {
			rez[ind] = vect[i]; // ind++ - pune pe pozitie si DUPA incrementeaza
			ind++;
		}
	rez[ind] = vect[dim - 1]; // a ramas ultima pozitie necompletata

	delete[] vect;
	vect = new int[counter];
	for (int i = 0; i < counter; i++)
		vect[i] = rez[i];

	dim = counter;

	delete[] rez;
}

void main() {
	int n, *v;

	citVect(v, n);
	modifVect(v, n);
	afVect(v, n);
}