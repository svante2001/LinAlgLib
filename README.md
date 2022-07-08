# LinAlgLib
This library is $1$ indexed which means the $2 \times 2$ entry of the $3 \times 3$ matrix below is $5$.

$$
\left(\begin{array}{cc} 
    1 & 2 & 3 \\
    4 & 5 & 6 \\
    7 & 8 & 9
\end{array}\right)
$$ 

## Compiling and running
Run `make` within the project folder.

## Core
### Matrix
```c
Matrix* CreateMatrix(int n_rows, int m_cols);
int Rows(Matrix* m);
int Cols(Matrix* m);
double GetEntry(Matrix* m, int row, int col);
void SetEntry(Matrix* m, int row, int col, double value);
Matrix* SetMatrix(double* arr, int rows, int cols);
void PrintMatrix(Matrix* m);
```
### Vector
```c
Vector* CreateVector(int h);
void FreeVector(Vector* v);
int Height(Vector* v);
double GetElement(Vector* v, int index);
void SetElement(Vector* v, int index, double value);
Vector* SetVector(double* arr, int height);
void PrintVector(Vector* v);
```

## Matrix operations
```c
Matrix* MatrixProduct(Matrix* a, Matrix* b);
Matrix* TransposeMatrix(Matrix* m);
Matrix* SubSquareMatrix(Matrix* m, int row, int col);
double Determinant(Matrix* m);
Matrix* ElementaryRowReplacement(Matrix* m, int i, double x, int j);
Matrix* ElementaryRowInterchange(Matrix* m, int i, int j);
Matrix* ElementaryRowScaling(Matrix* m, int i, double x);
Matrix* GaussianElimination(Matrix* m);
Matrix* RREF(Matrix* m);
Matrix* InverseMatrix(Matrix* m);
```

## Regression
```c
Matrix* LinearRegression(double x[], double y[], int points);
Matrix* PolynomialRegression(double x[], double y[], int dimension);
```