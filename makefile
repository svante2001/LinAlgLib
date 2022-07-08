all:
	gcc main.c ./Core/Matrix.c ./Core/Vector.c ./MatrixOperations/MatrixOperations.c ./Regression/Regression.c -lm
	./a.out