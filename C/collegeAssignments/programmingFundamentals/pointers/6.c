// Sa se insereze un element nou intr-un sir de n numere, alocat dinamic, cu n citit
// de la tastatura.

#define _CRT_SECURE_NO_WARNINGS

#include <stdlib.h>
#include <stdio.h>

void readArr(int* n, int** v) {
    printf("n="); scanf("%d", &(*n));

    *v = (int*)malloc((*n) * sizeof(int));

    printf("elemente sir: ");
    for (int i = 0; i < (*n); i++)
        scanf("%d", (*v) + i);
}

void writeArr(int n, int* v) {
    printf("output: ");
    for (int i = 0; i < n; i++)
        printf("%d ", v[i]);
}

int* addElem(int* n, int** v) {
    int ne;
    printf("\nnew elem=");
    scanf("%d", &ne);

    int* nv = (int*)malloc(((*n) + 1) * sizeof(int));
    for (int i = 0; i < (*n); i++)
        nv[i] = *((*v) + i);
    free(*v);
    nv[*n] = ne;
    *n = *n + 1;

    return nv;
}

int main() {
    int* v, *nv;
    int n;

    readArr(&n, &v);
    writeArr(n, v);
    nv = addElem(&n, &v);
    writeArr(n, nv);
}