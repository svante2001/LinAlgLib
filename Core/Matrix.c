#include <stdio.h>
#include <stdlib.h>

struct Matrix {
    int rows;
    int cols;
    double** entry;
};
typedef struct Matrix Matrix;

Matrix* CreateMatrix(int n_rows, int n_cols) {
    struct Matrix* matrix = malloc(sizeof(Matrix));
    matrix->rows = n_rows;
    matrix->cols = n_cols;
    double** entry = malloc(sizeof(double*) * n_rows); 
    for(int x = 0; x < n_rows; x++){
        entry[x] = calloc(n_cols, sizeof(double));
    }
    matrix->entry = entry;
    return matrix;
}

void PrintMatrix(Matrix* m) {
    for (int i = 0; i < m->rows; i++) {
        printf("\n");
        for (int j = 0; j < m->cols; j++) {
            printf("%12f", m->entry[i][j]);
        }
    }
    printf("\n");
}