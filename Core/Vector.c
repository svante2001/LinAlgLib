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

void FreeVector(Vector* v) {
    free((double*)v->element);
    free((Vector*)v);
}

int Height(Vector* v) {
    return v->height;
}

double GetElement(Vector* v, int index) {
    return v->element[index-1];
}

void SetElement(Vector* v, int index, double value) {
    v->element[index-1] = value;
}

Vector* SetVector(double* arr, int height) {
    Vector* v = CreateVector(height);
    for (int i = 1; i <= height; i++) {
        SetElement(v, i, arr[i-1]);
    }
    return v;
}

void PrintVector(Vector* v) {
    printf("\n");
    for (int i = 0; i < v->height; i++) {
        printf("%12f\n", v->element[i]);
    }
    printf("\n");
}