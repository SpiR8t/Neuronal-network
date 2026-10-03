#ifndef MATRIX_H
#define MATRIX_h

#include <stddef.h>
#include <stdlib.h>

typedef struct
{
    size_t rows;
    size_t cols;
    double *data;
} Matrix;

Matrix *matrix_create(size_t rows, size_t cols);

void matrix_destroy(Matrix *matrix);

void matrix_randomize(Matrix *matrix);

void matrix_multiply(
    const Matrix *a,
    const Matrix *b,
    Matrix *result
);

#endif
