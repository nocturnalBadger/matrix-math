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
    // Form a column of L based on valued from the first column of S

    // The bottom part of that L is used with the remaining corner of S to form new S

    // Apply recursively on the now smaller S.
    // New L's are padded with 0's to maintain NxN size

}

bool verify(Matrix *s, Matrix *l)
{

}
