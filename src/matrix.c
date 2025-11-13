#include "matrix.h"

matrix_t matrix_init(int rows, int cols){
    matrix_t matrix;
    matrix.rows = rows;
    matrix.cols = cols;
    
    if (rows == 0 || cols == 0){
        matrix.arr = NULL;
    } else{
        matrix.arr = malloc(sizeof(double) * rows * cols);
    }
    
    return matrix;
}

void matrix_release(matrix_t* matrix){
    matrix->rows = 0;
    matrix->cols = 0;
    free(matrix->arr);
}

matrix_t matrix_identity(int dimension){
    matrix_t matrix = matrix_init(dimension, dimension);
    int curr_col = 0; 

    for (int row = 0; row < dimension; row++){
        for (int col = 0; col < dimension; col++){
            if (col == curr_col){
                matrix_set(&matrix, row, col, 1);
                curr_col++;
                row++;
            }
        }
    }

    return matrix;
}

void matrix_set(matrix_t* matrix, int row, int col, double num){
    int index = (row * matrix->cols) + col; 
    matrix->arr[index] = num;
}

double matrix_get(const matrix_t* matrix, int row, int col){
    int index = (row * matrix->cols) + col;
    return matrix->arr[index];
}

matrix_t matrix_add(const matrix_t* matrix_a, const matrix_t* matrix_b){
    if (matrix_a->rows != matrix_b->rows || matrix_a->cols != matrix_b->cols){
        //returns an empty matrix in case of error
        perror("matrix_add: dimensions of the matrices do not match"); 
        return matrix_init(0,0);
    }

    matrix_t new_matrix = matrix_init(matrix_a->rows, matrix_a->cols);

    for (int row = 0; row < matrix_a->rows; row++){
        for (int col = 0; col < matrix_a->cols; col++){
            double sum = matrix_get(matrix_a, row, col) + matrix_get(matrix_b, row, col);
            matrix_set(&new_matrix, row, col, sum); 
        } 

    }

    return new_matrix;
}

matrix_t matrix_sub(const matrix_t* matrix_a, const matrix_t* matrix_b){
    if (matrix_a->rows != matrix_b->rows || matrix_a->cols != matrix_b->cols){
        //returns an empty matrix in case of error
        perror("matrix_sub: dimensions of the matrices do not match"); 
        return matrix_init(0,0);
    }

    matrix_t new_matrix = matrix_init(matrix_a->rows, matrix_a->cols);

    for (int row = 0; row < matrix_a->rows; row++){
        for (int col = 0; col < matrix_a->cols; col++){
            double difference = matrix_get(matrix_a, row, col) - matrix_get(matrix_b, row, col);
            matrix_set(&new_matrix, row, col, difference); 
        } 

    }

    return new_matrix;
}

matrix_t matrix_scalar_mul(const matrix_t* matrix, double scalar){
    matrix_t new_matrix = matrix_init(matrix->rows, matrix->cols);

    for (int row = 0; row < matrix->rows; row++){
        for (int col = 0; col < matrix->cols; col++){
            double val = scalar * matrix_get(matrix, row, col);
            matrix_set(&new_matrix, row, col, val); 
        } 

    }

    return new_matrix; 
}

matrix_t matrix_mul(const matrix_t* matrix_a, const matrix_t* matrix_b){
    if (matrix_a->cols != matrix_b->rows){
        perror("matrix_mul: matrix a's columns do not match matrix b's rows");
        return matrix_init(0,0);
    }     

    matrix_t new_matrix = matrix_init(matrix_a->rows, matrix_b->cols);

    for (int i = 0; i < matrix_a->rows; i++){
        for (int j = 0; j < matrix_b->cols; j++){
            double sum = 0;
            for (int k = 0; k < matrix_a->cols; k++){
                sum += matrix_get(matrix_a, i, k) * matrix_get(matrix_b, k, j);
            }
            matrix_set(&new_matrix, i, j, sum); 
        } 

    }

    return new_matrix;
}

matrix_t matrix_determinant(const matrix_t* matrix);
matrix_t matrix_inverse(const matrix_t* matrix);
matrix_t matrix_div(const matrix_t* matrix_a, const matrix_t* matrix_b);
matrix_t matrix_transpose(const matrix_t* matrix);

int matrix_equal(const matrix_t* a, const matrix_t* b, double tol);
int matrix_is_square(const matrix_t* m);
int matrix_is_symmetric(const matrix_t* m, double tol);
int matrix_is_identity(const matrix_t* m, double tol);

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
        printf("]");

        if (row != matrix->rows - 1){
            printf("\n");
        }
    }
}


matrix_t matrix_copy(const matrix_t* matrix);


