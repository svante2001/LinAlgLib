Matrix* MatrixProduct(Matrix* a, Matrix* b);
Matrix* TransposeMatrix(Matrix* m);
Matrix* SubSquareMatrix(Matrix* m, int row, int col);
double Determinant(Matrix* m);
Matrix* ElementaryRowReplacement(Matrix* m, int i, double x, int j);
Matrix* ElementaryRowInterchange(Matrix* m, int i, int j);
Matrix* ElementaryRowScaling(Matrix* m, int i, double x);
Matrix* ForwardReduction(Matrix* m);
Matrix* BackwardReduction(Matrix* m);