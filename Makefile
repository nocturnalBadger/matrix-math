CC = gcc
CFLAGS = -Wall -std=c99 -g
LDFLAGS = -lm

tests: matrixTest choleskyTest

matrixTest: matrix.h matrix.o

choleskyTest: matrix.h matrix.o cholesky.h cholesky.o


clean:
	rm ./*.o
	rm matrixTest
	rm choleskyTest
