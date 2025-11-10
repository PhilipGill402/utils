#pragma once
#include <stdlib.h>
#include <stdio.h>

typedef struct matrix_t {
    int rows;
    int cols;
    double* arr;
} matrix_t;


//initialization and destruction
matrix_t matrix_init(int rows, int cols);
void matrix_release(matrix_t* matrix);

//adding and retrieving data
void matrix_set(matrix_t* matrix, int row, int col, double num);
double matrix_get(const matrix_t* matrix, int row, int col);

//math
matrix_t matrix_add(const matrix_t* matrix_a, const matrix_t* matrix_b);
matrix_t matrix_sub(const matrix_t* matrix_a, const matrix_t* matrix_b);
matrix_t matrix_scalar_mul(const matrix_t* matrix, double scalar);
matrix_t matrix_mul(const matrix_t* matrix_a, const matrix_t* matrix_b);
matrix_t matrix_transpose(const matrix_t* matrix);

//equality
int matrix_equal(const matrix_t* a, const matrix_t* b, double tol);
int matrix_is_square(const matrix_t* m);
int matrix_is_symmetric(const matrix_t* m, double tol);
int matrix_is_identity(const matrix_t* m, double tol);

//miscellaneous
void matrix_print(const matrix_t* matrix);
matrix_t matrix_copy(const matrix_t* matrix);
