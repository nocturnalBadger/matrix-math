/**
 * @File matrixTest.c
 * Tests for matrix functions
 * @author Jeremy Schmidt
*/


#include "matrix.h"
#include <stdio.h>


int main()
{
    Matrix *myMatrix = newMatrix(3, 3);
    myMatrix->data[0][0] = 1;
    myMatrix->data[0][1] = 2;
    myMatrix->data[0][2] = 3;
    myMatrix->data[1][0] = 4;
    myMatrix->data[1][1] = 5;
    myMatrix->data[1][2] = 6;
    myMatrix->data[2][0] = 7;
    myMatrix->data[2][1] = 8;
    myMatrix->data[2][2] = 9;
    printMatrix(myMatrix);
    printf("\n");
    printMatrix(transpose(myMatrix));
    printf("\n");

    double in0[3][3] = {{2, 4, 6},
                       {8, 10, 12},
                       {14, 16, 18}};

    Matrix *a = fromArray(3, 3, in0);
    printMatrix(a);

    double in1[1][3] = {{1, 2, 3}};
    a = fromArray(1, 3, in1);
    Matrix *b = transpose(a);

    printf("\n");
    printMatrix(multiply(a, b));

    printf("\n");
    printMatrix(multiply(b, a));

    double in2[3][3] = {{1, 2, 3},
                        {3, 2, 1},
                        {1, 2, 3}};
    double in3[3][3] = {{4, 5, 6},
                        {6, 5, 4},
                        {4, 6, 5}};
    double in4[1][1] = {{5}};
    double in5[2][2] = {{2, 4},
                        {1, 6}};

    printf("\n");
    printMatrix(multiply(fromArray(3, 3, in2), fromArray(3, 3, in3)));

    printf("\n");
    printMatrix(subMat(1, 2, 1, 2, fromArray(3, 3, in2)));

    printf("\n");
    printMatrix(minor(1, 1, fromArray(3, 3, in2)));

    printf("\n%lf\n", determinant(fromArray(1, 1, in4)));

    printf("\n%lf\n", determinant(fromArray(2, 2, in5)));

    printf("\n%lf\n", determinant(fromArray(3, 3, in2)));

    printf("\n%lf\n", determinant(fromArray(3, 3, in3)));
}
