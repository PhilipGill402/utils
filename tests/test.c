#include "queue.h"
#include <stdlib.h>


int main(){
    queue_t queue = create_queue(sizeof(int));

    for (int i = 10; i > 0; i--){
        int x = i;
        enqueue(&queue, &x);
    }

    for (int i = 0; i < 10; i++) {
        printf("%d\n", *(int*)dequeue(&queue));
    }

    return 0;
}
