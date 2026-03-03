#include "string_t.h"
#include "arena.h"
#include <stdlib.h>


int main(){
    arena_t arena = create_arena(PAGE_SIZE);
    string_t str = string_literal_arena("hello world", &arena);
    string_t src = string_literal_arena("Whats up", &arena);
    
    printstr(&str, 0);
    printstr(&src, 0);

    free_string(&str);
    free_string(&src);

    release_arena(&arena);
    return 0;
}
