#include <stdio.h>
#include <stdlib.h>
#include "../Core/Vector.h"
#include "../Core/Matrix.h"
#include "../MatrixOperations/MatrixOperations.h"

void helperPrint(Matrix* m) {
    printf("    \{\\left(\\!\\!\n      \\begin{array}{");
    for (int i = 0; i < m->cols; i++) {
        printf("r");
    }
    printf("}");
    for (int i = 0; i < m->rows; i++) {
        printf("\n");
        for (int j = 0; j < m->cols-1; j++) {
            printf("%5f & ", m->entry[i][j]);
        }
        printf("%5f \\\\", m->entry[i][m->cols-1]);
    }
}

void PrintMatrixLatex(Matrix* m) {
    printf("\\begin{equation}\n  \\begin{array}{rcl}\n");
    helperPrint(m);
    printf("\n      \\end{array}\n      \\!\\!\\right)}\n");
    printf("    \\end{array}\n");
    printf("\\end{equation}");
}


void GaussianEliminationLatex(Matrix* m) {
    printf("\\begin{equation}\n  \\begin{array}{rcl}\n");
    helperPrint(m);
    printf("\n      \\end{array}\n    \\!\\!\\right)}\n    &\n    \\xymatrix@C=15ex{\n        \\ar@{~>}[r]^-{\n           \\mathrm{Gauss-Jordan}");
    printf("\n        } &\n    }\n    &\n");
    helperPrint(GaussianElimination(m));
    printf("\n      \\end{array}\n      \\!\\!\\right)}\n   \\end{array}\n   \\label{LABEL}\n\\end{equation}");
}
