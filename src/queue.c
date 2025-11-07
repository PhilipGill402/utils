#include "queue.h"

queue_t queue_init(){
    queue_t queue;
    queue.size = 0;
    queue.capacity = 10;
    queue.head = 0;
    queue.rear = 0;
    queue.array = malloc(sizeof(value_t) * 10);

    return queue;
}

void queue_release(queue_t* queue){
    free(queue->array);
    queue->array = NULL;
}

int resize_queue(queue_t* queue, int new_capacity){
    value_t* new_array = malloc(sizeof(value_t) * new_capacity);
    if (new_array == NULL){
        fprintf(stderr, "failed to allocate memory");
        return -1;
    }
    
    for (int i = 0; i < queue->size; i++){
        int index = (queue->head + i) % queue->capacity;
        new_array[i] = queue->array[index];
    }
    
    free(queue->array);
    queue->array = new_array;
    queue->head = 0;
    queue->rear = queue->size;
    queue->capacity = new_capacity;

    return 0;
}

int enqueue(queue_t* queue, value_t val){
    if (queue->size == queue->capacity){
        if (resize_queue(queue, queue->capacity * 2) == -1){
            fprintf(stderr, "failed to resize queue"); 
            return -1;
        }
    } 
    
    if (is_empty(queue)){
        queue->head = queue->rear;
    }
    
    queue->array[queue->rear] = val;
    queue->size++;
    queue->rear = (queue->rear + 1) % queue->capacity;
    return 0;
}

value_t* dequeue(queue_t* queue){
    if (is_empty(queue)){
        fprintf(stderr, "can't dequeue from empty queue");
        return NULL;
    } 
    
    value_t* val = &queue->array[queue->head];
    queue->size--;
    queue->head = (queue-> head + 1) % queue->capacity;
    
    //resizing if we get below 25% capacity
    if (queue->size < queue->capacity / 4){
        resize_queue(queue, queue->capacity / 4);
    }

    return val;
}

value_t* first(const queue_t* queue){
    return &queue->array[queue->head];
}

int is_empty(const queue_t* queue){
    return queue->size == 0;
}

int queue_size(const queue_t* queue){
    return queue->size;
}

void print_queue(const queue_t* queue){
    printf("[");
    for (int i = 0; i < queue->size; i++){
        int index = (queue->head + i) % queue->capacity;
        value_t val = queue->array[index];
        print_value(val);
        
        if (i != queue->size - 1){
            printf(", ");
        } 
    }

    printf("]\n");
}
