#include "matrix.h"

int main(){
    matrix_t matrix = matrix_init(4, 4);
    int counter = 0;

    for (int i = 0; i < 4; i++){
        for (int j = 0; j < 4; j++){
            matrix_set(&matrix, i, j, counter);
            counter++;
        }
    }
    
    //printf("%f\n", matrix_get(&matrix, 0, 1));

    matrix_print(&matrix);

    return 0;
}
