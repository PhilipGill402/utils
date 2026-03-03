#include "vector.h"
#include "main.h"
#include <stdlib.h>

void print_vec(vector_t* vec) {
    for (int i = 0; i < vec->size; i++) {
        printf("%d\n", *(int*)get(vec, i));
    }
}

int main(){
    arena_t arena = create_arena(PAGE_SIZE);
    vector_t vec = create_vector_arena(sizeof(int), &arena); 
    
    for (int i = 0; i < 25; i++) {
        int x = i; 
        push_back(&vec, &x);    
    }

    print_vec(&vec);

    

    release_arena(&arena);
    return 0;
}


