#ifndef _VECTOR_H
#define _VECTOR_H

typedef struct Vector Vector;

Vector* CreateVector(int h);
void FreeVector(Vector* v);
void PrintVector(Vector* v);

#endif