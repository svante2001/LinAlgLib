#include <stdio.h>
#include "./../Core/Matrix.h"
#include "./../MatrixOperations/MatrixOperations.h"

int main() {
    double a[] = { 1.0, 2.0, 3.0, 
                   4.0, 5.0, 6.0,
                   7.0, 8.0, 9.0};
    Matrix* m1 = SetMatrix(a, 3, 3);
    
    PrintMatrix(m1);
    PrintMatrix(SubSquareMatrix(m1, 2, 2));
}