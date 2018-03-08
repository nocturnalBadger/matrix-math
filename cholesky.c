/**
 * @File cholesky.c
 * Implementation of cholesky decomposition
 * @author Jeremy Schmidt
*/


#include "matrix.h"
#include "cholesky.h"

#include <stdbool.h>

Matrix *choleskyDecomp(Matrix const *s)
{
    int n = s->rows;
    // Form a column of L based on valued from the first column of S
    Matrix *l = newMatrix(n, n);
    double rp = sqrt(s->data[0][0]);
    l->data[0][0] = rp;
    for (int i = 1; i < n; ++i) {
        // Copy V into lower part of L
        l->data[i - 1][0] = s[i][0] / rp;
    }
    // Base case
    if (n == 1) {
        return l;
    }
    // The bottom part of that L is used with the remaining part of S to form new S
    Matrix *v = newMatrix(n - 1, 1);
    // Copy from bottom of L to v
    for (int i = 1; i < n; ++i) {
        v->data[i - 1][0] = l->data[i][0];
    }
    Matrix *s_prime = subtract(subMat(1, s->rows, 1, s->columns, s), multiply(v, transpose(v)));

    // Apply recursively on the now smaller S.
    Matrix *l_prime = choleskyDecomp(s_prime);
    // New L's are padded with 0's to maintain NxN size
    for (int i = 1; i < n; ++i) {
        for (int k = 0; k < i; ++k) {
            // Fill with zeros to make lower triangular
            l->data[i][k] = 0;
        }
        // Copy from l_prime (result from recursive decomp)
        for (int j = i; j < n; ++j) {
            l->data[i][j] = l_prime[i - 1][j];
        }
    }
}

bool verify(Matrix *s, Matrix *l)
{

}
