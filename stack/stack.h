#include <stdio.h>
#include <stdlib.h>

typedef struct stack_int_t {
    int size;
    int capacity;
    int top;
    int* stack; 
} stack_int_t;

stack_int_t* stack_init();
int stack_push(stack_int_t* stack, int num);
int stack_pop(stack_int_t* stack);
int stack_top(stack_int_t* stack);
int stack_size(stack_int_t* stack);
int stack_is_empty(stack_int_t* stack);
void stack_print(stack_int_t* stack);
void stack_release(stack_int_t* stack);
