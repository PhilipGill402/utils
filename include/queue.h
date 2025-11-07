#pragma once
#include <stdlib.h>
#include <stdio.h>
#include "value.h"

typedef struct queue_t{
    int size;
    int capacity;
    int head;
    int rear;
    value_t* array;
} queue_t;

queue_t queue_init();
void queue_release(queue_t* queue);
int resize_queue(queue_t* queue, int new_capacity);
int enqueue(queue_t* queue, value_t val);
value_t* dequeue(queue_t* queue);
value_t* first(const queue_t* queue);
int is_empty(const queue_t* queue);
int queue_size(const queue_t* queue);
void print_queue(const queue_t* queue);
