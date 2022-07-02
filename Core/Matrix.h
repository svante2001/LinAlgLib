#ifndef _MATRIX_H
#define _MATRIX_H

typedef struct Matrix Matrix;

Matrix* CreateMatrix(int n_rows, int m_cols);
void FreeMatrix(Matrix* m);
int Rows(Matrix* m);
int Cols(Matrix* m);
double GetEntry(Matrix* m, int row, int col);
void SetEntry(Matrix* m, int row, int col, double value);
Matrix* SetMatrix(double* arr, int rows, int cols);
void PrintMatrix(Matrix* m);

#endif // _MATRIX_H