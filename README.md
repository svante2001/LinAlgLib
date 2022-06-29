# LinAlgLib
This library is 1 indexed which means the $2 \times 2$ entry of the matrix below is 5.

$$
\left(\begin{array}{cc} 
    1 & 2 & 3 \\
    4 & 5 & 6 \\
    7 & 8 & 9
\end{array}\right)
$$ 

## Examples
A collection of examples can be found in the `Examples` directory. NB: a shell script is present
to compiling and running the examples and this script should be run in the `Examples` directory as 
follows:
<br />
`./RunExample.sh [ExampleFile].c`

## Core matrix functions
```c
Matrix* CreateMatrix(int n_rows, int m_cols);
int Rows(Matrix* m);
int Cols(Matrix* m);
double GetEntry(Matrix* m, int row, int col);
void SetEntry(Matrix* m, int row, int col, double value);
Matrix* SetMatrix(double* arr, int rows, int cols);
void PrintMatrix(Matrix* m);
```

## Matrix operation functions
```c
Matrix* MatrixProduct(Matrix* a, Matrix* b);
Matrix* TransposeMatrix(Matrix* m);
Matrix* SubSquareMatrix(Matrix* m, int row, int col);
double Determinant(Matrix* m);
```