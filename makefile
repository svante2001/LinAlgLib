main:
	gcc -o main main.c ./Core/Matrix.c ./Core/Vector.c ./MatrixOperations/MatrixOperations.c ./Regression/Regression.c ./Latex/Latex.c -lm

clean:
	rm main
