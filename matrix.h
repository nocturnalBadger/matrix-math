/**
 * @File matrix.h
 * Declare functions for matrix operations and define the matrix type
 * @author Jeremy Schmidt
*/


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
void printMatrix(Matrix *m);

/**
 * Return a new matrix which is the transposition of the original
 * @param m input matrix
 * @return m.T
 */
Matrix *transpose(Matrix *m);

/**
 * Multiply two matrices together
 * @param a first matrix (order matters) [NxM]
 * @param b second matrix [PxQ]
 * @return matrices multiplied together [NxQ]
 */
Matrix *multiply(Matrix *a, Matrix *b);
