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
    Matrix *r = subMat(1, s->rows, 1, s->columns, s);
    Matrix *v = subMat(1, r->rows, 0, 0, s);
    Matrix *s_prime = subtract(r, multiply(v, transpose(v)));
}

bool verify(Matrix *s, Matrix *l)
{

}
