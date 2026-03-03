#include "vector.h"
#include "string_t.h"
#include "arena.h"
#include <stdlib.h>

void print_vec(vector_t* vec) {
    for (int i = 0; i < vec->size; i++) {
        printf("%d\n", *(int*)get(vec, i));
    }
}

int main(){
    arena_t arena = create_arena(PAGE_SIZE);
    string_t str = string_literal("hello world", &arena);
    printstr(&str, 0);

    release_arena(&arena);
    return 0;
}


