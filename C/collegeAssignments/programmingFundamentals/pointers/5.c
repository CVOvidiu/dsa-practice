// Sa se determine maximul de pe fiecare linie a unei matrici si sa se stocheze intr-un vector.
// Matricea si vectorul sa fie alocate in aceeasi zona de memorie.

#define _CRT_SECURE_NO_WARNINGS

#include <stdio.h>
#include <stdlib.h>

int main() {
	int n;
	double** mat, * v;
	scanf("%d", &n);
	mat = (double**)malloc(n * sizeof(double*));
	// verif alocare
	double* p = (double*)malloc(n * (n + 1) * sizeof(double));
	//verif alocarew
	for (int i = 0; i < n; i++)
		mat[i] = p + n * i;
	v = p + n * n;

	for (int i = 0; i < n; i++)
		for (int j = 0; j < n; j++)
			scanf("%lf", &mat[i][j]);

	for (int i = 0; i < n; i++) {
		v[i] = -1E10;
		for (int j = 0; j < n; j++)
			if (v[i] < mat[i][j])
				v[i] = mat[i][j];
	}

	for (int i = 0; i < n; i++)
		printf("%.0lf ", v[i]);

	free(p);
	free(mat);

	return 0;

	// OR

	//int n;
	//double** mat, * v;
	//scanf("%d", &n);
	//mat = (double**)malloc(n * sizeof(double*));
	//// verif alocare
	//double** p = (double**)malloc(n * (n + 1) * sizeof(double) + n * sizeof(double*));
	//mat = p;
	//double* p1 = p + n;
	//for (int i = 0; i < n; i++)
	//	mat[i] = p1 + n * i;
	//v = p1 + n * n;
	//for (int i = 0; i < n; i++)
	//	for (int j = 0; j < n; j++)
	//		scanf("%lf", &mat[i][j]);

	//for (int i = 0; i < n; i++) {
	//	v[i] = -1E10;
	//	for (int j = 0; j < n; j++)
	//		if (v[i] < mat[i][j])
	//			v[i] = mat[i][j];
	//}

	//for (int i = 0; i < n; i++)
	//	printf("%.0lf ", v[i]);

	//free(p);
}