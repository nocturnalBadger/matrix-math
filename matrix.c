/**
 * @File matrix.c
 * General functions for working with matrices
 * @author Jeremy Schmidt
*/


#include "matrix.h"

#define DOUBLE_TOLERENCE 0.0001

Matrix *newMatrix(int rows, int columns)
{
    Matrix *m = malloc(sizeof(Matrix));
    m->rows = rows;
    m->columns = columns;
    m->data = (double **) malloc(rows * sizeof(double (*)[columns]));
    for (int i = 0; i < rows; ++i) {
        m->data[i] = (double *) malloc(columns * sizeof(double));
    }
    return m;
}

void freeMatrix(Matrix *m)
{
    for (int i = 0; i < m->rows; ++i) {
        free(m->data[i]);
    }
    free(m);
}

Matrix *fromArray(int rows, int columns, double inputData[rows][columns])
{
    Matrix *m = newMatrix(rows, columns);
    for (int i = 0; i < rows; ++i) {
        for (int j = 0; j < columns; ++j) {
            m->data[i][j] = inputData[i][j];
        }
    }
    return m;
}

Matrix * identity(int n)
{
    Matrix *result = newMatrix(n, n);
    for (int i = 0; i < n; ++i) {
        for (int j = 0; j < n; ++j) {
            if (i == j) {
                result->data[i][j] = 1;
            }
            else {
                result->data[i][j] = 0;
            }
        }
    }
    return result;
}


void printMatrix(Matrix const *m)
{
    printf("\n");
    for (int i = 0; i < m->rows; ++i) {
        for (int j = 0; j < m->columns; ++j) {
            printf("% 3.1lf ", m->data[i][j]);
        }
        printf("\n");
    }
}

bool equals(Matrix const *a, Matrix const *b)
{
    if (a->rows != b->rows || a->columns != b->columns) {
        return false;
    }
    for (int i = 0; i < a->rows; ++i) {
        for (int j = 0; j < a->columns; ++j) {
            if (abs(a->data[i][j] - b->data[i][j]) > DOUBLE_TOLERENCE) {
                return false;
            }
        }
    }
    return true;
}

Matrix *transpose(Matrix const *m)
{
    Matrix *t = newMatrix(m->columns, m->rows);

    for (int i = 0; i < m->rows; ++i) {
        for (int j = 0; j < m->columns; ++j) {
            t->data[j][i] = m->data[i][j];
        }
    }
    return t;
}

double determinant(Matrix const *m)
{
    int n = m->rows; // Must be square
    if (n == 1) {
        return m->data[0][0];
    }
    double det = 0;
    int i = 0; // Some row of the matrix. Just use the first.
    for (int j = 0; j < n; ++j) {
        double cofactor = pow(-1, i + j) * determinant(minor(i, j, m));
        det += m->data[i][j] * cofactor;
    }
    return det;
}

double mag(Matrix const *m)
{
    double a = 0;
    for (int i = 0; i < m->rows; ++i) {
        a += pow(m->data[i][0], 2);
    }
    return sqrt(a);
}

Matrix *multiply(Matrix const *a, Matrix const *b)
{
    Matrix *result = newMatrix(a->rows, b->columns);
    // Iterate over each spot where we will place a result
    for (int i = 0; i < result->rows; ++i) {
        for (int j = 0; j < result->columns; ++j) {
            // Next, dotprod the i'th row in A with the j'th column of B
            double cell = 0;
            for (int p = 0; p < b->rows; ++p) {
                cell += a->data[i][p] * b->data[p][j];
            }
            result->data[i][j] = cell;
        }
    }
    return result;
}


Matrix * scalarProd(Matrix const *m, double c)
{
    Matrix *result = newMatrix(m->rows, m->columns);
    for (int i = 0; i < m->rows; ++i) {
        for (int j = 0; j < m->columns; ++j) {
            result->data[i][j] = m->data[i][j] * c;
        }
    }
    return result;
}

Matrix *subtract(Matrix const *a, Matrix const *b)
{
    Matrix *result = newMatrix(a->rows, a->columns);
    for (int i = 0; i < a->rows; ++i) {
        for (int j = 0; j < a->columns; ++j) {
            result->data[i][j] = a->data[i][j] - b->data[i][j];
        }
    }
    return result;
}

Matrix *subMat(int rowStart, int rowEnd, int colStart, int colEnd, Matrix const *m)
{
    Matrix *result = newMatrix(rowEnd - rowStart + 1, colEnd - colStart + 1);
    for (int i = rowStart; i <= rowEnd; ++i) {
        for (int j = colStart; j <= colEnd; ++j) {
            result->data[i - rowStart][j - colStart] = m->data[i][j];
        }
    }
    return result;
}


Matrix * column(Matrix const *m, int col)
{
    return subMat(0, m->rows - 1, col, col, m);
}

Matrix *minor(int x, int y, Matrix const *m)
{
    Matrix *result = newMatrix(m->rows - 1, m->columns - 1);
    for (int i = 0; i < m->rows; ++i) {
        if (i == x) {
            continue;
        }
        for (int j = 0; j < m->columns; ++j) {
            if (j == y) {
                continue;
            }
            result->data[i > x ? i - 1 : i][j > y ? j - 1 : j] = m->data[i][j];
        }
    }
    return result;
}
