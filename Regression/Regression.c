#include "../Core/Matrix.h"
#include "../Core/Vector.h"
#include "../MatrixOperations/MatrixOperations.h"
#include <math.h>

Matrix* LinearRegression(double x[], double y[], int points) {
    Matrix* A = CreateMatrix(points, 1);
    for (int i = 1; i <= points; i++) {
        SetEntry(A, i, 1, 1.0);
    }
    Vector* v = SetVector(x, points);
    A = AugmentVectorRight(A, v);

    Matrix* B = SetMatrix(y, points, 1);

    return MatrixProduct(InverseMatrix(MatrixProduct(TransposeMatrix(A), A)), MatrixProduct(TransposeMatrix(A), B));
}

Matrix* PolynomialRegression(double x[], double y[], int points, int dimension) {
    Matrix* A = CreateMatrix(points, 1);
    for (int i = 1; i <= points; i++) {
        SetEntry(A, i, 1, 1.0);
    }
    for (int i = 1; i <= dimension; i++) {
        Vector* v = CreateVector(points);
        for (int j = 1; j <= points; j++) {
            SetElement(v, j, pow(x[j-1], (double)i));
        }
        A = AugmentVectorRight(A, v);
    }
    Matrix* B = SetMatrix(y, points, 1);
    
    return MatrixProduct(InverseMatrix(MatrixProduct(TransposeMatrix(A), A)), MatrixProduct(TransposeMatrix(A), B));
}