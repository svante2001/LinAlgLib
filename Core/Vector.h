#ifndef _VECTOR_H
#define _VECTOR_H

typedef struct Vector Vector;

Vector* CreateVector(int h);
void FreeVector(Vector* v);
int Height(Vector* v);
double GetElement(Vector* v, int index);
void SetElement(Vector* v, int index, double value);
Vector* SetVector(double* arr, int height);
void PrintVector(Vector* v);

#endif