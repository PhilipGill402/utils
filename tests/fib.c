#include "matrix.h"

int main() {
    matrix_t ident = matrix_init(2,2);
    matrix_set(&ident, 0, 0, 1);
    matrix_set(&ident, 0, 1, 1);
    matrix_set(&ident, 1, 0, 1);
    matrix_set(&ident, 1, 1, 0);
    
    matrix_t fib = matrix_pow(&ident, 1000);

    matrix_print(&fib);
    
}
