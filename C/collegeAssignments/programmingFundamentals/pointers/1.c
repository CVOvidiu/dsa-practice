#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>
#include <malloc.h>

void alocareMatrice(int n, int m, float*** mat);
void citireMatrice(int n, int m, float** mat);
void afisareMatrice(int n, int m, float** mat);
float medieAritmetica(int n, float* v);
void getMediiLinii(int n, int m, float** mat, float** v);
void swap(float* x1, float* x2);
void swap_ptr(float** x1, float** x2);
int partitionare(int n, int m, float** mat, float* v);
int qSort(int n, int m, float** mat, float* v);

int main()
{
	int n, m;
	float** mat, * medii;
	printf("Dati dimensiunile matricii:\n");
	scanf("%d%d", &n, &m);
	alocareMatrice(n, m, &mat);
	printf("Dati elementele matricii:\n");
	citireMatrice(n, m, mat);
	getMediiLinii(n, m, mat, &medii);
	qSort(0, n, mat, medii);
	afisareMatrice(n, m, mat);
	free(medii);
	for (int i = 0; i < n; i++)
		free(mat[i]);
	free(mat);
	return 0;
}

void alocareMatrice(int n, int m, float*** mat)
{
	int i;
	*mat = (float**)malloc(n * sizeof(float*));
	for (i = 0; i < n; i++)
		(*mat)[i] = (float*)malloc(m * sizeof(float));
}

void citireMatrice(int n, int m, float** mat)
{
	int i, j;
	for (i = 0; i < n; i++)
		for (j = 0; j < m; j++)
			scanf("%f", &mat[i][j]);

}
void afisareMatrice(int n, int m, float** mat)
{
	int i, j;
	for (i = 0; i < n; i++)
	{
		for (j = 0; j < m; j++)
			printf("%f ", mat[i][j]);
		printf("\n");
	}
}


float medieAritmetica(int n, float* v)
{
	float s = 0.f;
	int i;

	for (i = 0; i < n; i++)
		s += v[i];
	return  s / n;
}


void getMediiLinii(int n, int m, float** mat, float** v)
{
	int  i, j;
	*v = (float*)calloc(n, sizeof(float));
	for (i = 0; i < n; i++)
	{
		for (j = 0; j < m; j++)
			(*v)[i] += mat[i][j];
		(*v)[i] /= m;
	}
}

void swap(float* x1, float* x2) {
	float aux = *x1;
	*x1 = *x2;
	*x2 = aux;
}
void swap_ptr(float** x1, float** x2)
{
	float* aux = *x1;
	*x1 = *x2;
	*x2 = aux;
}
int partitionare(int first, int last, float** mat, float* v)
{
	int i = first, j;
	float p = v[last - 1];
	for (j = first; j < last; j++)
	{
		if (v[j] < p)
		{
			swap(&v[i], &v[j]);
			swap_ptr(&mat[i], &mat[j]);
			i++;
		}
	}
	swap(&v[i], &v[last - 1]);
	swap_ptr(&mat[i], &mat[last-1]);
	return i;
}

int qSort(int first, int last, float** mat, float* v) {
	if (first < last)
	{
		int i = partitionare(first, last, mat, v);
		qSort(first, i - 1, mat, v);
		qSort( i + 1, last, mat, v);
	}
}