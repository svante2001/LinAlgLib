#include <stdio.h>
#include <stdlib.h>

struct Vector {
    int height;
    double* element;
};
typedef struct Vector Vector;

Vector* CreateVector(int h) {
    struct Vector* vector = malloc(sizeof(Vector));
    vector->height = h;
    double* e = calloc(h, sizeof(double*));
    vector->element = e;
    return vector;
}

void PrintVector(Vector* v) {
    printf("\n");
    for (int i = 0; i < v->height; i++) {
        printf("%12f\n", v->element[i]);
    }
    printf("\n");
}