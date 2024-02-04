#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>
#include <malloc.h>

struct Adresa
{
	char str[30];
	int nr, bl, ap;
	char sc;
};

typedef struct Adresa Adresa;

int readAdr(FILE* fis, Adresa* a)
{
	if (feof(fis))
		return 0;
	fgets(a->str, 30, fis);
	if (feof(fis))
		return 0;
	int r = fscanf(fis, "%d%d%d", &a->nr, &a->bl, &a->ap);
	if (r != 3)
	{
		printf("Eroare citire fisier\n");
		return 0;
	}
	char s[30];
	fgets(s, 30, fis);
	r = fscanf(fis, "%c", &a->sc);
	if (r != 1)
	{
		printf("Eroare citire fisier\n");
		return 0;
	}
	fgets(s, 30, fis);
	return 1;
}

int main()
{
	FILE* fis = fopen("adrese.txt", "r");
	Adresa* adr;
	int n;
	if (!fis)
	{
		printf("Eroare deschidere fisier\n");
		return 1;
	}
	fscanf(fis, "%d", &n);
	char s[30];
	fgets(s, 30, fis);
	adr = (Adresa*)malloc(n * sizeof(Adresa));
	if (!adr)
	{
		printf("Eroare alocare\n");
		fclose(fis);
		return 1;
	}
	for (int i = 0; i < n; i++)
	{
		if (!readAdr(fis, &adr[i]))
		{
			fclose(fis);
			free(adr);
			return 1;
		}
	}
	fclose(fis);
	for (int i = 0; i < n; i++)
		printf("Strada: %s, nr. %d, bl. %d, sc. %c, ap %d\n", adr[i].str, adr[i].nr, adr[i].bl, adr[i].sc,  adr[i].ap);
	free(adr);
	return 0;
}