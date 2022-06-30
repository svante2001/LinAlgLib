#include "../Core/Matrix.h"
#include <math.h>

// A boolean type is needed.
typedef enum { False, True } boolean;

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

double Determinant(Matrix* m) {
    int r = Rows(m);

    if (r == 1) return GetEntry(m, 1, 1);
    else if (r == 2) return (GetEntry(m, 1, 1) * GetEntry(m, 2, 2)) - (GetEntry(m, 2, 1) * GetEntry(m, 1, 2));
    else {
        double res = 0.0;
        for (int i = 1; i <= Cols(m); i++) {
            double cofactor = pow(-1.0, i) * GetEntry(m, 1, i) * Determinant(SubSquareMatrix(m, 1, i));
            res += cofactor;        
        }
        return res;
    }
}

Matrix* ElementaryRowReplacement(Matrix* m, int i, double x, int j) {
    for (int k = 1; k <= Cols(m); k++) {
        SetEntry(m, i, k, (GetEntry(m, i, k) + x * GetEntry(m, j, k)));
    }
    return m;
}

Matrix* ElementaryRowInterchange(Matrix* m, int i, int j) {
    for (int k = 1; k <= Cols(m); k++) {
        double first = GetEntry(m, i, k);
        double second = GetEntry(m, j, k);
        SetEntry(m, i, k, second);
        SetEntry(m, j, k, first);
    }
    return m;
}

Matrix* ElementaryRowScaling(Matrix* m, int i, double x) {
    for (int k = 1; k <= Cols(m); k++) {
        SetEntry(m, i, k, (x * GetEntry(m, i, k)));
    }
    return m;
}

Matrix* ForwardReduction(Matrix* m) {
    int r = Rows(m);
    int c = Cols(m);

    for (int a = 1; a <= r-1; a++) {
        for (int j = a; j <= c; j++) {
            boolean foundPivot = False;
            for (int i = a; i <= r; i++) {
                if (GetEntry(m, i, j) != 0.0) {
                    foundPivot = True;
                    ElementaryRowInterchange(m, i, a);
                    for (int b = a+1; b <= r; b++) {
                        if (GetEntry(m, b, j) != 0.0) {
                            ElementaryRowReplacement(m, b, (-GetEntry(m, b, j) / GetEntry(m, a, j)), a);
                        }
                    }
                    break;
                }
            }
            if (foundPivot == True) break;
        }
    }
    return m;
}