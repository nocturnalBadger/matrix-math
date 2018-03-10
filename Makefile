CC = gcc
CFLAGS = -Wall -std=c99 -g
LDFLAGS = -lm

tests: matrixTest choleskyTest qrTest

matrixTest: matrix.h matrix.o

choleskyTest: matrix.h matrix.o cholesky.h cholesky.o

qrTest: matrix.h matrix.o qr.h qr.o


clean:
	rm ./*.o
	rm matrixTest
	rm choleskyTest
