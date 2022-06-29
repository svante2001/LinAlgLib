all: 
	rm a.out
	gcc main.c ./Core/Matrix.c ./MatrixOperations/MatrixOperations.c -lm
	./a.out