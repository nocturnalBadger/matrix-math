/**
 * @File choleskyTest.c
 * Tests for Cholesky decomposition
 * @author Jeremy Schmidt
*/

#include "cholesky.h"
#include <stdio.h>

int main()
{
    double in0[3][3] = {{4, -6, 8},
                        {-6, 13, -16},
                        {8, -16, 36}};

    Matrix *s = fromArray(3, 3, in0);
    Matrix *l = choleskyDecomp(s);
    printMatrix(l);
    printf("\n%d\n", verifyCholesky(s, l));
    freeMatrix(s);
    freeMatrix(l);
    return 0;
}

