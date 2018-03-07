/**
 * @File matrix.c
 * General functions for working with matrices
 * @author Jeremy Schmidt
*/


#include<stdio.h>
#include "matrix.h"

#include<stdlib.h>

Matrix *newMatrix(int rows, int columns)
{
    Matrix *m = malloc(sizeof(Matrix));
    m->rows = rows;
    m->columns = columns;
    m->data = (double (*)[rows]) malloc(rows * sizeof(double (*)[columns]));
    for (int i = 0; i < rows; ++i) {
        m->data[i] = (double *) malloc(columns * sizeof(double));
    }
    return m;
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


void printMatrix(Matrix *m)
{
    for (int i = 0; i < m->rows; ++i) {
        for (int j = 0; j < m->columns; ++j) {
            printf("%.1lf ", m->data[i][j]);
        }
        printf("\n");
    }
}

Matrix *transpose(Matrix *m)
{
    Matrix *t = newMatrix(m->columns, m->rows);

    for (int i = 0; i < m->rows; ++i) {
        for (int j = 0; j < m->columns; ++j) {
            t->data[j][i] = m->data[i][j];
        }
    }
    return t;
}

Matrix *multiply(Matrix *a, Matrix *b)
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
