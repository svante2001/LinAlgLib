typedef struct Matrix Matrix;

Matrix* CreateMatrix(int n_rows, int m_cols);
double GetEntry(Matrix* m, int row, int col);
void SetEntry(Matrix* m, int row, int col, double value);
void PrintMatrix(Matrix* m);