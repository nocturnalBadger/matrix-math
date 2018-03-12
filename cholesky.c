/**
 * @File cholesky.c
 * Implementation of cholesky decomposition
 * @author Jeremy Schmidt
*/


#include "cholesky.h"


Matrix *choleskyDecomp(Matrix const *s)
{
    int n = s->rows;
    // Form a column of L based on valued from the first column of S
    Matrix *l = newMatrix(n, n);
    double rp = sqrt(s->data[0][0]);
    l->data[0][0] = rp;
    for (int i = 1; i < n; ++i) {
        // Copy V into lower part of L
        l->data[i][0] = s->data[i][0] / rp;
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
    // S' = r - v*v.T
    Matrix *r = subMat(1, s->rows - 1, 1, s->columns - 1, s);
    Matrix *s_prime = subtract(r, multiply(v, transpose(v)));

    // Apply recursively on the now smaller S.
    Matrix *l_prime = choleskyDecomp(s_prime);
    // New L's are padded with 0's to maintain NxN size
    for (int j = 1; j < n; ++j) {
        for (int k = 0; k < j; ++k) {
            // Fill with zeros to make lower triangular
            l->data[k][j] = 0;
        }
        // Copy from l_prime (result from recursive decomp)
        for (int i = j; i < n; ++i) {
            l->data[i][j] = l_prime->data[i - 1][j - 1];
        }
    }

    freeMatrix(v);
    freeMatrix(r);
    freeMatrix(s_prime);
    freeMatrix(l_prime);

    return l;
}

bool verifyCholesky(Matrix const *s, Matrix const *l)
{
    int n = s->rows;
    // L is NxN
    if (l->rows != n || l->columns != n) {
        return false;
    }
    // L is lower triangular
    for (int j = 0; j < n; ++j) {
        for (int i = 0; i < j; ++i) {
            if (l->data[i][j] != 0) {
                return false;
            }
        }
    }
    // L*L.T = S
    return equals(multiply(l, transpose(l)), s);
}
