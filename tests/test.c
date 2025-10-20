#include "queue.h"

int main() {
    queue_t* queue = queue_init(); 

    for (int i = 0; i < 30; i++){
        value_t val = {.type = VAL_INT, .val.i = i};
        enqueue(queue, val);
    }
    
    for (int i = 0; i < 10; i++){
        dequeue(queue);
    }
    print_queue(queue);
    value_t val = {.type = VAL_CHAR, .val.c = 'A'};


    return 0;
}

