#include "qr.h"
#include <stdio.h>

int main()
{
    double in0[4][3] = {
        {-3, -8, -9},
        {-3, -10, 15},
        {-3, -8, 7},
        {-3, -10, -1}};
    Matrix *q = newMatrix(4, 3);
    Matrix *r = newMatrix(3, 3);

    qrDecomp(fromArray(4, 3, in0), q, r);
    printMatrix(q);
    printMatrix(r);
    return 0;
}

