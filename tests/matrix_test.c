#include "matrix.h"

int main(){
    matrix_t matrix_a = matrix_init(3, 3);

    int counter = 1;

    for (int i = 0; i < 3; i++){
        for (int j = 0; j < 3; j++){
            matrix_set(&matrix_a, i, j, counter);
            counter++;
        }
    }
    
    matrix_t rref = find_rref(&matrix_a);

    matrix_print(&rref);

    printf("\n\n");

    printf("%f\n", matrix_determinant(&matrix_a)); 

    return 0;
}
