main:
	gcc -o main main.c ./Core/Matrix.c ./Core/Vector.c ./MatrixOperations/MatrixOperations.c -lm

clean:
	rm main
