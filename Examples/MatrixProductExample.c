#include <stdio.h>
#include "./../Core/Matrix.h"
#include "./../MatrixOperations/MatrixOperations.h"

int main() {
    double a[] = { 1.0, 2.0, 3.0, 
                   4.0, 5.0, 6.0 };
    Matrix* m1 = SetMatrix(a, 2, 3);

    double b[] = { 7.0, 8.0, 
                   9.0, 10.0,
                   11.0, 12.0};
    Matrix* m2 = SetMatrix(b, 3, 2);
    
    PrintMatrix(m1);
    PrintMatrix(m2);
    PrintMatrix(MatrixProduct(m1, m2));
}