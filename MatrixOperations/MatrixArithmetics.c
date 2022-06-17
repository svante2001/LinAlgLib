#include "../Core/Matrix.h"
#include <stdio.h>

Matrix* MatrixProduct(Matrix* a, Matrix* b) {
    int n = Cols(a);
    int m = Rows(a);
    int p = Cols(b);
    
    Matrix* c = CreateMatrix(m, p);

    for (int i = 0; i < m; i++) {
        for (int j = 0; j < p; j++) {
            double sum = 0;
            for (int k = 0; k < n; k++) {
                sum += GetEntry(a, i+1, k+1) * GetEntry(b, k+1, j+1);
            }
            SetEntry(c, i+1, j+1, sum);
        }
    }
    return c;
}

