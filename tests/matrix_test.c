#include "matrix.h"

int main(){
    matrix_t matrix_a = matrix_init(3, 3);

    int counter = 1;
    
    // first row
    for (int i = 0; i < 3; i++){
        matrix_set(&matrix_a, 0, i, counter);
        counter++;
    }
    
    matrix_set(&matrix_a, 1, 0, 0);
    matrix_set(&matrix_a, 1, 1, 4);
    matrix_set(&matrix_a, 1, 2, 5);

    matrix_set(&matrix_a, 2, 0, 1);
    matrix_set(&matrix_a, 2, 1, 0);
    matrix_set(&matrix_a, 2, 2, 6);

    
    matrix_t rref = find_rref(&matrix_a);

    matrix_print(&rref);

    printf("\n\n");

    printf("%f\n", matrix_determinant(&matrix_a));

    matrix_t inverse = matrix_inverse(&matrix_a);

    matrix_print(&inverse);

    printf("\n\n");

    matrix_t copy = matrix_copy(&matrix_a);

    printf("%d\n", matrix_is_symmetric(&rref, 1e-12));

    matrix_t pow = matrix_pow(&matrix_a, 3);

    matrix_print(&pow);
    printf("\n\n");

    return 0;
}
