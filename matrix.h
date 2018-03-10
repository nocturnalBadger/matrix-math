/**
 * @File matrix.h
 * Declare functions for matrix operations and define the matrix type
 * @author Jeremy Schmidt
*/

#include<stdio.h>
#include<stdlib.h>
#include <stdbool.h>
#include <math.h>

struct matrixStruct {
    int rows;
    int columns;
    double **data; // Pointer to the start of a 2D array
};

typedef struct matrixStruct Matrix;

/**
 * Create a new matrix with the given dimmensions
 * @param rows number of rows
 * @param columns number of columns
 * @return reference to the new matrix
 */
Matrix *newMatrix(int rows, int columns);

/**
 * Create a matrix from a simple array of values
 * @param rows number of rows
 * @param columns number of columns
 * @return matrix containing the data given from the array
 */
Matrix *fromArray(int rows, int columns, double inputData[rows][columns]);

/**
 * Print out the contents of a matrix to stdout
 * @param m matrix to print
 */
void printMatrix(Matrix const *m);

/**
  * Compare two matrices to tell if their data are identical
  * @param a first matrix to compare
  * @param b second matrix to compare
  *
  * @return true if matrices are equal
  */
bool equals(Matrix const *a, Matrix const *b);

/**
 * Return a new matrix which is the transposition of the original
 * @param m input matrix
 * @return m.T
 */
Matrix *transpose(Matrix const *m);

/**
  * Get the determinant of a square matrix using the LePlace expansion
  * @param m a square matrix
  * @return determinant of the matrix
  */
double determinant(Matrix const *m);

/**
  * Get the magnitude of a single-column matrix (aka a vector)
  * @param m a column vector
  *
  * @return magnitude (length in n-d space) of the vector
  */
double mag(Matrix const *m);

/**
 * Multiply two matrices together
 * @param a first matrix (order matters) [NxM]
 * @param b second matrix [PxQ]
 * @return matrices multiplied together [NxQ]
 */
Matrix *multiply(Matrix const *a, Matrix const *b);

/**
  * Subtract one matrix from another
  * @param a first matrix
  * @param b second matrix
  * A and B must have the same dimmensions
  * @return new matrix which is the result of the operation A - B
  */
Matrix *subtract(Matrix const *a, Matrix const *b);

/**
  * Multiply a matrix by a constant
  * @param m input matrix
  * @param c constant multiple
  *
  * @return Result
  */
Matrix * scalarProd(Matrix const *m, double c);

/**
  * Copy a portion of a matrix to a new matrix
  * @param rowStart row index to begin copying
  * @param rowEnd row index to stop copying
  * @param colStart column index to begin copying
  * @param colEnd column index to stop copying
  * Indices are zero-indexed and inclusive
  * @return copy of the given portion of the matrix
  */
Matrix *subMat(int rowStart, int rowEnd, int colStart, int colEnd, Matrix const *m);

/**
  * Get a column vector from a matrix (specific case of subMat)
  * @param m input matrix
  * @param col column to get
  *
  * @return column matrix
  */
Matrix * column(Matrix const *m, int col);


/**
  * Get the sub-matrix which excludes the given row and column indices
  * @param x row index to exclude
  * @param y column index to exclude
  * @return an (n-1)x(n-1) matrix excluding the given row and column
  */
Matrix *minor(int x, int y, Matrix const *m);
