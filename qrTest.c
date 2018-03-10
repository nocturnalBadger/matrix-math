#include "qr.h"
#include <stdio.h>

int main()
{
    double in0[4][3] = {
        {-3, -8, -9},
        {-3, -10, 15},
        {-3, -8, 7},
        {-3, -10, -1}};
    Matrix *a = fromArray(4, 3, in0);
    Matrix *q = newMatrix(4, 3);
    Matrix *r = newMatrix(3, 3);

    qrDecomp(a, q, r);
    printMatrix(q);
    printMatrix(r);

    printf("%d", verifyQR(a, q, r));

    double in1[6][2] = {
        {3, 5},
        {2, 6},
        {8, 2},
        {6, 4},
        {0, 1},
        {3.5, 7}};
    Matrix *a1 = fromArray(6, 2, in1);
    Matrix *q1 = newMatrix(6, 2);
    Matrix *r1 = newMatrix(2, 2);

    qrDecomp(a1, q1, r1);
    printMatrix(q1);
    printMatrix(r1);

    printf("%d\n", verifyQR(a1, q1, r1));
    q1->data[0][0] += 1;
    printf("%d\n", verifyQR(a1, q1, r1));

    return 0;
}

