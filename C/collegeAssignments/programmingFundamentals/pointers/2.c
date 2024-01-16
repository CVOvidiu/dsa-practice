// Dynamic allocation for an array of arrays of multiple dimensions.

#define _CRT_SECURE_NO_WARNINGS

#include <stdio.h>
#include <malloc.h>

int main() {
    printf("Number of arrays: ");
    int m;
    scanf("%d", &m);

    // Dimensions
    int* n;
    n = (int*)calloc(m, sizeof(int));
    if(n == NULL) {
        perror("Insufficient memory!");
        return 1;
    }
    printf("Number of elements for each array:\n");
    for(int i = 0; i < m; i++)
        scanf("%d", &n[i]);
    
    // Allocation
    float** a;
    a = (float**)calloc(m, sizeof(float*));
    if(a == NULL) {
        perror("Insufficient memory!");
        return 1;
    }
    for(int i = 0; i < m; i++) {
        a[i] = (float*)calloc(n[i], sizeof(float));
        if(a[i] == NULL) {
        perror("Insufficient memory!");
        return 1;
        }
    }

    // Initialization
    for(int i = 0; i < m; i++)
        for(int j = 0; j < n[i]; j++)
            scanf("%f", &a[i][j]);

    // Deallocation
    for(int i = 0; i < m; i++)
        free(a[i]);
    free(a);
    free(n);
}