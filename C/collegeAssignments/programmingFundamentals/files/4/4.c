/*
43. Dintr-un fişier binar se citesc elementele unui şir de numere reale. Să se sorteze
crescător şirul şi să se depună după aceea vectorul în acelaşi fişier.
*/

#define _CRT_SECURE_NO_WARNINGS

#include <stdio.h>
#include <malloc.h>
#include <string.h>

void swap(double* v1, double* v2) {
	double aux = *v1;
	*v1 = *v2;
	*v2 = aux;
}

int QS(double* v, int st, int dr) {
	int i = st, j = dr;
	double piv = v[(st + dr) / 2];

	while (i <= j) {
		while (v[i] < piv)
			i++;
		while (v[j] > piv)
			j--;
		if (i <= j) {
			swap(&v[i], &v[j]);
			i++;
			j--;
		}
	}

	if (st < j)
		QS(v, st, j);
	if (i < dr)
		QS(v, i, dr);
}

int main() {
	double* v;
	int n;

	// Write template in binary file
	/*int n = 5;
	double w[] = { 5, 5.2, 7.3, 27, 1.2 };*/

	FILE* fin = fopen("in.txt", "rb");
	if (fin == NULL) {
		perror("Eroare la deschidere fisier");
		return 1;
	}

	FILE* fout = fopen("out.txt", "wb");
	if (fout == NULL) {
		perror("Eroare la deschidere fisier");
		return 1;
	}

	// Write template in binary file
	/*fwrite(&n, sizeof(int), 1, fin);
	fwrite(&w, sizeof(w), 1, fin);*/

	fread(&n, sizeof(int), 1, fin);
	printf("%d", n);

	v = (double*)malloc(n * sizeof(double));

	for (int i = 0; i < n; i++)
		fread(&v[i], sizeof(double), 1, fin);

	fclose(fin);
	printf("\n");

	for (int i = 0; i < n; i++)
		printf("%.2lf ", v[i]);

	printf("\n");

	QS(v, 0, n - 1);

	// Verify if array was sorted correctly
	for (int i = 0; i < n; i++)
		printf("%.2lf ", v[i]);

	// Write in another (should be in the same binary file but I don't want to reupload data when running)
	//binary file the resulted array
	fwrite(v, sizeof(double), n, fout);
	fclose(fout);
	fout = fopen("out.txt", "rb");
	if (fout == NULL) {
		perror("Eroare la deschidere fisier");
		return 1;
	}
	// Read from binary file that array to check if it was written correctly
	for (int i = 0; i < n; i++)
		fread(&v[i], sizeof(double), 1, fout);

	printf("\n");
	// Output from binary file
	for (int i = 0; i < n; i++)
		printf("%.2lf ", v[i]);
}