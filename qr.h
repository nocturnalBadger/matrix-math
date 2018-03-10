/**
 * @File qr.h
 * Define methods used for Gram-Schmidt method
 * @author Jeremy Schmidt
*/
#include "matrix.h"

#include <stdbool.h>

/**
  * Decompose matrix A into Q and R
  * @param a input matrix to be decomposed
  * @param q matrix initialized to be filled in as part of the result
  * @param r matrix initialized to be filled in as part of the result
  * Input:
  *   A is m x n where m >= n
  *   Q is m x n
  *   R is n x n
  * Output:
  *   A = QR
  *   Q.T * Q = I (Q is orthogonal)
  *   R is upper triangular
  */
void qrDecomp(Matrix const *a, Matrix *q, Matrix *r);


/**
  * Verify that a set of matrices have the properties of QR decomposition (see above)
  * Does not check dimmensions because the qrDecomp function takes pre-initialized matrices
  * @param a input matrix a
  * @param q Q component of decomposition
  * @param r R component of decomposition
  *
  * @return true if conditions are met and decomposition if valid
  */
bool verifyQR(Matrix const *a, Matrix const *q, Matrix const *r);
