#include <stdio.h>
#include "Core/Matrix.h"
#include "MatrixOperations/MatrixOperations.h"

int main() {
    double a[] = { 1.0, 2.0, 3.0, 
                   4.0, 5.0, 6.0,
                   7.0, 8.0, 9.0 };
    Matrix* m = SetMatrix(a, 3, 3);
    PrintMatrix(m);
    FreeMatrix(m);

    // See README.md for all the implemented functions.
}