file=$1

gcc "$file" ./../Core/Matrix.c ./../MatrixOperations/MatrixArithmetics.c
./a.out