# LinAlgLib

## Core - matrix
### Creating a matrix:
`Matrix* m = CreateMatrix(rows, cols);`

### Getting an entry:
`double d = GetEntry(Matrix* m, int row, int col);`

### Setting an entry:
`SetEntry(Matrix* m, int row, int col, double value);`

### Setting a matrix:
`SetMatrix(double* arr, int rows, int cols);`
<br />
In-code example:
```c
double a[] = { 1.0, 2.0, 3.0, 
4.0, 5.0, 6.0 };

Matrix* m = SetMatrix(a, 2, 3);
```
### Printing a matrix
`PrintMatrix(Matrix* m);`