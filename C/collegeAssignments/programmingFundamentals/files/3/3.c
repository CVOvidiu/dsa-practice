// Colocviu model

#define _CRT_SECURE_NO_WARNINGS

#include <stdlib.h>
#include <stdio.h>
#include <math.h>

struct Complex {
    double re;
    double im;
};

typedef struct Complex Complex;

int readComplex(FILE* file, Complex* num) {
    if (feof(file))
        return 0;
    fscanf(file, "%lf%lf", &num->re, &num->im);
    
    return 1;
}

void writeFormatComplex(Complex num) {
    if (num.re == 0)
        printf("i * %.2lf\n", num.im);
    else if(num.im == 0)
        printf("%.2lf\n", num.re);
    else
        printf("%.2lf + i * %.2lf\n", num.re, num.im);
}

int complexModule(Complex num) {
    return sqrt(pow(num.re, 2) + pow(num.im, 2));
}

int compareModules(Complex num1, Complex num2) {
    if (complexModule(num1) > complexModule(num2))
        return 1;
    else return 0;
}

Complex* complexArrAlloc(int n) {
    return (Complex*)malloc(n * sizeof(Complex));
}

Complex* readComplexArr(FILE* file, int n) {
    Complex* v = complexArrAlloc(n);

    for (int i = 0; i < n; i++)
        readComplex(file, &v[i]);

    return v;
}

int sumModules(int n, Complex* v) {
    int s = 0;
    for (int i = 0; i < n; i++)
        s += complexModule(v[i]);
    printf("Suma modulelor: %d", s);
}

void swap(Complex* num1, Complex* num2) {
    Complex aux = *num1;
    *num1 = *num2;
    *num2 = aux;
}

int QS(Complex* v, int st, int dr) {
    int i = st, j = dr;
    Complex piv = v[(st + dr) / 2];

    while (i <= j) {
        while(!(compareModules(v[i], piv)) && i < dr)
            i++;
        while(!(compareModules(v[j], piv)) && j > st)
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
    FILE* file = fopen("in.txt", "r");
    if (!file) {
        perror("Eroare la deschidere fisier.");
        return 1;
    }

    int n;
    Complex* v;
    fscanf(file, "%d", &n);
    v = readComplexArr(file, n);
    sumModules(n, v);

    //QS(v, 0, n - 1);

    /*FILE* bin = fopen("binar.bin", "wb");
    if (!bin) {
        perror("Eroare la deschidere fisier.");
        return 1;
    }*/

    //fwrite(v, n, sizeof(Complex), bin);
    /*printf("\n");
    for (int i = 0; i < n; i++)
        printf("%.2lf %.2lf = %d\n", v[i].re, v[i].im, complexModule(v[i]));*/
}