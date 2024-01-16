/*
Sa se defineasca o structura Adresa care are campurile: strada(char[30]),
numar(int), bloc(int), scara(char), apartament(int). Sa se implementeze:
a) O functie care citeste o adresa dintr-un fisier text (pointerul catre fisier este
transmis ca parametru de intrare );
b) o functie care afiseaza informatiile despre o adresa sub forma: strada xxxxx,
nr x, bl. X, sc. X, ap. x
c) O functie care sa compare doua adrese dupa: strada, nr, bl, sc, ap
Sa se citeasca dintr-un fisier text(scris ca in exemplul de mai jos) un sir de n adrese,
alocat dinamic. Sa se afiseze strada cu cel mai lung nume, iar intr-un fisier binar sa se
scrie toate adresele sortate dupa strada, nr, bl, sc, ap.
Ex:
2
Iuliu Maniu
5
256
A
8
Stefan cel Mare
6
456
A
1
*/

#define _CRT_SECURE_NO_WARNINGS

#include <stdio.h>
#include <stdlib.h>

struct Adresa {
	char str[30];
	int nr, bl, ap;
	char sc;
};

typedef struct Adresa Adresa;

int readAdr(FILE* fis, Adresa* adr) {
	if (feof(fis))
		return 0;
	fgets(adr->str, 30, fis);
	if (feof(fis))
		return 0;
	int r = fscanf(fis, "%d%d\n%c\n%d", &adr->nr, &adr->bl, &adr->sc, &adr->ap);
	if (r != 4)
		return 0;
	// fortare trecut pe linia urmatoare pt ca cursorul se opreste la sfarsit de liniile anterioare
	char s[30];
	fgets(s, 30, fis);
	return 1;
}

int main() {
	int n;
	Adresa* adr;
	FILE* fis = fopen("adrese.txt", "r");
	if (!fis) {
		// mesaj
		return 1;
	}

	int r = fscanf(fis, "%d", &n);
	// if r != 1 err
	char s[30];
	fgets(s, 30, fis);
	adr = (Adresa*)malloc(n * sizeof(Adresa));
	for (int i = 0; i < n; i++) {
		if (!readAdr(fis, &adr[i])) {
			// mesaj
			fclose(fis);
			free(adr);
			return 1;
		}
	}
	fclose(fis);
	for (int i = 0; i < n; i++)
		printf("Strada:%s, nr:%d, bl:%d, sc:%c, ap:%d\n", adr[i].str, adr[i].nr, adr[i].sc, adr[i].ap);
	free(adr);
	return 0;
}
