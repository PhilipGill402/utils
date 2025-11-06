#include "algorithms.h"
#include "vector.h"
#include <stdlib.h>

int comparator(value_t a, value_t b){
    return a.val.i - b.val.i;
}

int main(){
    vector_t vec = create_vector();
    value_t val;

    for (int i = 10; i > 0; i--){
        val.type = VAL_INT;
        val.val.i = i*10;
        push_back(&vec, val);
    }
    
    print_vector(&vec);
    quick_sort(&vec, 0, vector_size(&vec) - 1, comparator);
    print_vector(&vec);

    return 0;
}
