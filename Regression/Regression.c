#include "../Core/Matrix.h"
#include "../Core/Vector.h"
#include "../MatrixOperations/MatrixOperations.h"
#include <stdio.h>
#include <math.h>

Matrix* PolynomialRegression(double x[], double y[], int points, int dimension) {
    Matrix* A = CreateMatrix(points, 0);

    for (int i = 0; i <= dimension; i++) {    
        Vector* v = CreateVector(points);
        for (int j = 1; j <= points; j++) {
            SetElement(v, j, pow(x[j-1], (double)i));
        }
        A = AugmentVectorRight(A, v);
    }

    Matrix* B = SetMatrix(y, points, 1);
    return MatrixProduct(InverseMatrix(MatrixProduct(TransposeMatrix(A), A)), MatrixProduct(TransposeMatrix(A), B));
}

void PrintMatrixEquation(Matrix* m) {
    printf("f(x) = ");
    for (int i = 1; i < Rows(m)+1; i++) {
        double c = GetEntry(m, i, 1);

        if (fabs(c) > 0.0001) {
            if (i == 1) {
                printf("%f", c);
            } else if (i == 2) {
                printf("%f*x", c);
            } else {
                printf("%f*x^%d", c, i-1);
            }
            if (i == Rows(m)+1 || c < 0.0) {
                printf("+");
            }
        }
    }
    printf("\n");
}