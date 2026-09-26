#include "matrix.h"

Matrix *matrix_create(size_t rows, size_t cols);

void matrix_destroy(Matrix *matrix);

void matrix_randomize(Matrix *matrix);

void matrix_multiply(
    const Matrix *a,
    const Matrix *b,
    Matrix *result
);