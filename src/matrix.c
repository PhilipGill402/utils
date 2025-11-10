#include "matrix.h"

matrix_t matrix_init(int rows, int cols){
    matrix_t matrix;
    matrix.rows = rows;
    matrix.cols = cols;
    matrix.arr = malloc(sizeof(double) * rows * cols);

    return matrix;
}

void matrix_release(matrix_t* matrix){
    matrix->rows = 0;
    matrix->cols = 0;
    free(matrix->arr);
}

void matrix_set(matrix_t* matrix, int row, int col, double num){
    int index = (row * matrix->cols) + col; 
    matrix->arr[index] = num;
}

double matrix_get(const matrix_t* matrix, int row, int col){
    int index = (row * matrix->cols) + col;
    return matrix->arr[index];
}

void matrix_print(const matrix_t* matrix){
    for (int row = 0; row < matrix->rows; row++){
        printf("[");
        for (int col = 0; col < matrix->cols; col++){
            int index = (row * matrix->cols) + col;
            if (col != matrix->cols - 1){
                printf("%f, ", matrix->arr[index]);
            } else {
                printf("%f", matrix->arr[index]);
            }


        }
        printf("]\n");
    }
}
