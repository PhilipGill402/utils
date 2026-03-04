#include "vector.h"
#include "arena.h"
#include <stdlib.h>

void print_element(void* element) {
    printf("%d", *(int*)element);
}

int main(){
    arena_t arena = create_arena(PAGE_SIZE);
    vector_t vec = create_vector(sizeof(int), &arena);

    for (int i = 0; i < 25; i++) {
        int x = i;
        push_back(&vec, &x);
    }

    print_vector(&vec, print_element); 

    release_arena(&arena);
    return 0;
}


