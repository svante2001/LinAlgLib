file=$1

rm -rf a.out
gcc "$file" ./../Core/Matrix.c ./../MatrixOperations/MatrixOperations.c -lm
./a.out