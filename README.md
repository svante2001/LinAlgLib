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

## Core - matrix
### Creating a matrix:
`Matrix* m = CreateMatrix(rows, cols);`

### Getting the row size
`int r = Rows(Matrix* m);`

### Getting the column size
`int c = Cols(Matrix* m);`

### Getting an entry:
`double d = GetEntry(Matrix* m, int row, int col);`

### Setting an entry:
`SetEntry(Matrix* m, int row, int col, double value);`

### Setting a matrix:
`Matrix* m = SetMatrix(double* arr, int rows, int cols);`

### Printing a matrix
`PrintMatrix(Matrix* m);`

## Matrix operations
### Matrix product
`Matrix* m = MatrixProduct(Matrix* a, Matrix* b);`

### Transpose matrix
`Matrix* m = TransposeMatrix (Matrix* m);`