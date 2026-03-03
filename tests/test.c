#include "vector.h"
#include "queue.h"
#include "arena.h"
#include <stdlib.h>

void print_vec(vector_t* vec) {
    for (int i = 0; i < vec->size; i++) {
        printf("%d\n", *(int*)get(vec, i));
    }
}

int main(){
    arena_t arena = create_arena(PAGE_SIZE);
    queue_t queue = create_queue(sizeof(int), &arena);

    for (int i = 0; i < 25; i++) {
        int x = i;
        enqueue(&queue, &x);
    }

    for (int i = 0; i < 25; i++) {
        printf("%d\n", *(int*)dequeue(&queue));
    }

    release_arena(&arena);
    return 0;
}


