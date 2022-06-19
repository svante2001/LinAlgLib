#include "../Core/Matrix.h"

Matrix* MatrixProduct(Matrix* a, Matrix* b) {
    int n = Cols(a);
    int m = Rows(a);
    int p = Cols(b);
    
    Matrix* c = CreateMatrix(m, p);

    for (int i = 1; i <= m; i++) {
        for (int j = 1; j <= p; j++) {
            double sum = 0;
            for (int k = 1; k <= n; k++) {
                sum += GetEntry(a, i, k) * GetEntry(b, k, j);
            }
            SetEntry(c, i, j, sum);
        }
    }
    return c;
}

Matrix* TransposeMatrix (Matrix* m) {
    int rows = Rows(m);
    int cols = Cols(m);
    
    Matrix* mt = CreateMatrix(cols, rows);

    for (int i = 1; i <= cols; i++) {
        for (int j = 1; j <= rows; j++) {
            SetEntry(mt, i, j, GetEntry(m, j, i));
        }
    }
    return mt;
}

Matrix* SubSquareMatrix(Matrix* m, int row, int col) {
    int r = Rows(m);
    int c = Cols(m);

    Matrix* ssm = CreateMatrix(r-1, c-1);

    int RowCounter = 1;
    int ColCounter = 1;

    for (int i = 1; i <= r; i++) {
        ColCounter = 1;
        if (i != row) {
            for (int j = 1; j <= c; j++) {
                if (j != col) {
                    SetEntry(ssm, RowCounter, ColCounter, GetEntry(m, i, j));
                    ColCounter++;
                }
            }
            RowCounter++;
        }
    }
    return ssm;
}