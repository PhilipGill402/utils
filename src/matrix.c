#include "matrix.h"

matrix_t matrix_init(int rows, int cols){
    matrix_t matrix;
    matrix.rows = rows;
    matrix.cols = cols;
    matrix.determinant = NAN;
    
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

void swap_rows(matrix_t* matrix, int row_a, int row_b) {
    int start_index_a = row_a * matrix->cols;
    int end_index_a = start_index_a + matrix->cols;

    double temp[matrix->cols];
    
    for (int i = start_index_a, idx = 0; i < end_index_a; i++, idx++) {
        temp[idx] = matrix->arr[i];

    }

    int start_index_b = row_b * matrix->cols;
    int end_index_b = start_index_b + matrix->cols;

    for (int i = start_index_b, idx = 0; i < end_index_b; i++, idx++) {
        matrix->arr[start_index_a+idx] = matrix->arr[start_index_b+idx];
    }
    
    for (int i = start_index_b, idx = 0; i < end_index_b; i++, idx++) {
        matrix->arr[i] = temp[idx];
    }
}

void mul_row(matrix_t* matrix, int row, double scalar) {
    int start_index = row * matrix->cols;
    int end_index = start_index + matrix->cols;

    for (int i = start_index; i < end_index; i++) {
        matrix->arr[i] = scalar * matrix->arr[i];
    }
}

void add_rows(matrix_t* matrix, int dst_row, int src_row, int scalar) {
    int start_index_dst = dst_row * matrix->cols;
    int end_index_dst = start_index_dst + matrix->cols;

    int start_index_src = src_row * matrix->cols;
    int end_index_src = start_index_src + matrix->cols;

    for (int dst = start_index_dst, src = start_index_src; dst < end_index_dst; dst++, src++) {
        matrix->arr[dst] += scalar * matrix->arr[src];
    }
}

int is_zero(double x) {
    double eps = 1e-12;
    return fabs(x) <= eps;
}

matrix_t find_rref(matrix_t* matrix) {
    matrix_t rref = matrix_copy(matrix);
    double factor = 1.0f;
    int is_invertible = 1;


    for (int i = 0; i < matrix->rows; i++) {
        double pivot = matrix_get(&rref, i, i);
        
        if (is_zero(pivot)) {
            is_invertible = 0;
            continue;
        }

        mul_row(&rref, i, 1/pivot);
        factor *= 1/pivot;
        

        for (int j = 0; j < matrix->rows; j++) {
            if (j == i) {
                continue;
            }
            
            double entry = matrix_get(&rref, j, i);
            add_rows(&rref, j, i, -entry);
        }
    }
    
    // if the given matrix has not had its determinant calculated, then calculate it
    if (isnan(matrix->determinant)) {
        if (!is_invertible) {
            //if a matrix is invertible then its determinant is 0
            matrix->determinant = 0;
        } else {
            //since the matrix is the identity matrix, its determinant is the factor found 
            matrix->determinant = factor;
        }

    }

    return rref;
}

double matrix_determinant(matrix_t* matrix) {
    if (isnan(matrix->determinant)) {
        find_rref(matrix);
    }

    return matrix->determinant;
} 

matrix_t matrix_inverse(const matrix_t* matrix);
matrix_t matrix_div(const matrix_t* matrix_a, const matrix_t* matrix_b);

matrix_t matrix_transpose(const matrix_t* matrix) {
    matrix_t new_matrix = matrix_init(matrix->cols, matrix->rows);

    for (int col = 0; col < matrix->cols; col++) {
        for (int row = 0; row < matrix->rows; row++) {
            double entry = matrix_get(matrix, row, col);
            matrix_set(&new_matrix, col, row, entry);
        }
    }

    return new_matrix;
}

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


matrix_t matrix_copy(const matrix_t* matrix) {
    matrix_t new_matrix = matrix_init(matrix->rows, matrix->cols);

    for (int row = 0; row < matrix->rows; row++) {
        for (int col = 0; col < matrix->cols; col++) {
            double entry = matrix_get(matrix, row, col);
            matrix_set(&new_matrix, row, col, entry);
        }
    }

    return new_matrix;
}


