#include "matrix.h"

int main(){
    matrix_t matrix_a = matrix_init(2, 2);
    matrix_t matrix_b = matrix_init(2, 2);
    matrix_t matrix_c; 

    int counter = 0;

    for (int i = 0; i < 2; i++){
        for (int j = 0; j < 2; j++){
            matrix_set(&matrix_a, i, j, counter);
            counter++;
        }
    }
    
    for (int i = 0; i < 2; i++){
        for (int j = 0; j < 2; j++){
            matrix_set(&matrix_b, i, j, counter);
            counter++;
        }
    }

    matrix_print(&matrix_a);

    printf("\n\n");

    matrix_print(&matrix_b);
    
    printf("\n\n");

    matrix_c = matrix_mul(&matrix_a, &matrix_b);
    matrix_print(&matrix_c); 

    return 0;
}
