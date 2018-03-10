/**
 * @File qr.c
 * Implement the Gram-Schmidt method for QR decomposition
 * @author Jeremy Schmidt
*/

#include "qr.h"


void qrDecomp(Matrix const *a, Matrix *q, Matrix *r)
{
    int m = a->rows;
    int n = a->columns;

    // Wj = Aj - Q_1*R_1_j - Q_2*R_2_j ... - Q_(j-1)*R_n_j
    // Qj = Wj / mag(W_j)
    // R_i_j = Qi.T * Aj

    for (int j = 0; j < n; ++j) {
        Matrix *w = column(a, j); // Start with column j of A
        for (int i = j - 1; i >= 0; --i) { // Won't run on first iteration of outer
            w = subtract(w, scalarProd(column(q, i), r->data[i][j]));
        }
        r->data[j][j] = mag(w);
        // Copy to column of q while dividing by r_jj
        for (int i = 0; i < m; ++i) {
            q->data[i][j] = w->data[i][0] / r->data[j][j];
        }
        // Fill in all the other R values for this column
        Matrix *qjt = transpose(column(q, j));
        for (int rj = j; rj < n; ++rj) {
            // Taking the only data field from this mult should be the same as a dotprod
            r->data[j][rj] = multiply(qjt, column(a, rj))->data[0][0];
        }
    }
}


bool verifyQR(Matrix const *a, Matrix const *q, Matrix const *r)
{
    int n = a->columns;
    // R is right triangular
    for (int i = 0; i < n; ++i) {
        for (int j = 0; j < i; ++j) {
            if (r->data[i][j] != 0)
                return false;
        }
    }
    // A = QR
    if (!equals(a, multiply(q, r))) {
        return false;
    }
    // Q is orthogonal
    if (!equals(multiply(transpose(q), q), identity(q->columns))) {
        return false;
    }
    return true;
}

