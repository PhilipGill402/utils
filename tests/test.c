#include "algorithms.h"
#include "vector.h"
#include <stdlib.h>

void print_vector(vector_t* vec) {
    for (int i = 0; i < vec->size; i++) {
        printf("%d, ", *(int*)get(vec, i));
    }
}

int main(){
    vector_t vec = create_vector(sizeof(int));

    for (int i = 10; i > 0; i--){
        int x = i;
        push_back(&vec, &x);
    }
    
    int x = 90;
    insert(&vec, &x, 5);
    erase(&vec, 7);
    
    print_vector(&vec);

    quick_sort(&vec, 0, vector_size(&vec));
    printf("\n");
    print_vector(&vec);

    return 0;
}
