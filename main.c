#include <stdio.h>
#include "Core/Matrix.h"

int main() {
    Matrix* m = CreateMatrix(5, 5);
    SetEntry(m, 2, 2, 3.14);
    PrintMatrix(m);
    printf("\nEntry 2x2: %f\n", GetEntry(m, 2, 2));
}