#define _CRT_SECURE_NO_WARNINGS

#include <stdio.h>
#include <string.h>
#include <stdlib.h>

struct Produs {
	char nume_produs[30];
	int cantitate;
	int pret;
};

typedef struct Produs Produs;

Produs readProdus(FILE* file) {
	Produs prod;

	char s[30];
	fgets(s, 30, file);

	fgets(prod.nume_produs, 30, file);
	prod.nume_produs[strlen(prod.nume_produs) - 1] = '\0';
	fscanf(file, "%d%d", &prod.cantitate, &prod.pret);

	return prod;
}

void writeProdus(Produs prod) {
	printf("%s: %d x %d", prod.nume_produs, prod.cantitate, prod.pret);
}

Produs* prodArrayAlloc(int n) {
	return (Produs*)malloc(n * sizeof(Produs));
}

void prodArrayInit(FILE* file, int n, Produs* v) {
	Produs prod;
	for (int i = 0; i < n; i++) {
		prod = readProdus(file);
		v[i] = prod;
	}
}

int prodComp(Produs* p1, Produs* p2) {
	int pret1 = p1->cantitate * p1->pret;
	int pret2 = p2->cantitate * p2->pret;
	if (pret1 < pret2)
		return 1;

	if (pret1 == pret2)
		if (strcmp(p1->nume_produs, p2->nume_produs) > 0)
			return 1;
	
	return 0;
}

void prodScump(int n, Produs* v) {
	int max = 0;
	Produs prodMax;
	for (int i = 0; i < n; i++)
		if (max < v[i].pret) {
			max = v[i].pret;
			prodMax = v[i];
		}
	printf("\nProdusul cel mai scump:");
	writeProdus(prodMax);
}

int main() {
	FILE* fin = fopen("in.txt", "r");
	if (fin == NULL) {
		perror("Eroare la deschidere fisier");
		return 1;
	}

	Produs* prod;

	int n;
	fscanf(fin, "%d", &n);

	prod = prodArrayAlloc(n);
	if (!prod) {
		perror("Eroare la alocare");
		return 1;
	}

	prodArrayInit(fin, n, prod);
	prodScump(n, prod);

	// Fisier binar

	FILE* binar = fopen("binar.bin", "wb");
	if (binar == NULL) {
		perror("Eroare la deschidere fisier");
		return 1;
	}
	fwrite(&n, sizeof(int), 1, binar);

	qsort(&prod, n, sizeof(Produs), prodComp);
	fwrite(&prod, sizeof(Produs), n, binar);

	fclose(fin);
	fclose(binar);
	free(prod);

	return 0;
}