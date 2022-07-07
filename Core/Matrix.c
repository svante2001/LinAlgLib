#include <stdio.h>
#include <stdlib.h>
#include "Vector.h"

struct Matrix {
    int rows;
    int cols;
    double** entry;
};
typedef struct Matrix Matrix;

Matrix* CreateMatrix(int n_rows, int m_cols) {
    struct Matrix* matrix = malloc(sizeof(Matrix));
    matrix->rows = n_rows;
    matrix->cols = m_cols;
    double** entry = calloc(n_rows, sizeof(double*));
    for(int i = 0; i < n_rows; i++){
        entry[i] = calloc(m_cols, sizeof(double));
    }
    matrix->entry = entry;
    return matrix;
}

void FreeMatrix(Matrix* m) {
    for(int i = 0; i < m->rows; i++) {
        free((double*)m->entry[i]);
    }
    free((double**)m->entry);
    free((Matrix*)m);
}

int Rows(Matrix* m) {
    return m->rows;
}

int Cols(Matrix* m) {
    return m->cols;
}

double GetEntry(Matrix* m, int row, int col) {
    return m->entry[row-1][col-1];
}

void SetEntry(Matrix* m, int row, int col, double value) {
    m->entry[row-1][col-1] = value;
}

Matrix* SetMatrix(double* arr, int rows, int cols) {
    Matrix* m = CreateMatrix(rows, cols);
    for (int i = 0; i < rows; i++) {
        for (int j = 0; j < cols; j++) {
            SetEntry(m, i+1, j+1, arr[cols * i+j]);
        }
    }
    return m;
}

Matrix* AugmentVectorRight(Matrix* m, Vector* v) {
    Matrix* AugmentedMatrix = CreateMatrix(Rows(m), Cols(m) + 1);
    for (int i = 1; i <= Rows(m); i++) {
        for (int j = 1; j <= Cols(m); j++) {
            SetEntry(AugmentedMatrix, i, j, GetEntry(m, i, j));
        }
    }
    for (int i = 1; i <= Height(v); i++) {
        SetEntry(AugmentedMatrix, i, Cols(m)+1, GetElement(v, i));
    }
    return AugmentedMatrix;
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