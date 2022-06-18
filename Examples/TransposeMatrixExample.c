#include <stdio.h>
#include "./../Core/Matrix.h"
#include "./../MatrixOperations/MatrixOperations.h"

int main() {
    double a[] = { 1.0, 2.0, 3.0, 
                   4.0, 5.0, 6.0 };
    Matrix* m = SetMatrix(a, 2, 3);
    
    PrintMatrix(m);
    PrintMatrix(TransposeMatrix(m));
}