/**
 * @File cholesky.h
 * Declaration of functions used for cholesky decomposition
 * @author Jeremy Schmidt
*/

#include "matrix.h"

#include<stdbool.h>
#include <stdbool.h>
#include <math.h>

/**
 * Deccompose a given matrix such that
 * @param s is an nxn matrix
 * @return l is a matrix such that s = l * l.T
 *          and l is lower triangular
 */
Matrix *choleskyDecomp(Matrix const *s);

/**
 * Verify that two given matrices exhibit the properties of cholesky decomposition (see above
 * @param s matrix s as described above
 * @param matrix l
 * @return true if the conditions are met
 */
bool verify(Matrix const *s, Matrix const *l);
