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

//miscellaneous
void matrix_print(const matrix_t* matrix);
matrix_t matrix_copy(const matrix_t* matrix);
