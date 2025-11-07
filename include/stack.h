#pragma once
#include <stdio.h>
#include <stdlib.h>
#include "value.h"


typedef struct value_stack_t {
    int size;
    int capacity;
    int top;
    value_t* stack; 
} value_stack_t;

value_stack_t stack_init();
int stack_push(value_stack_t* stack, value_t val);
value_t* stack_pop(value_stack_t* stack);
value_t* stack_top(const value_stack_t* stack);
int stack_size(const value_stack_t* stack);
int stack_is_empty(const value_stack_t* stack);
void stack_print(const value_stack_t* stack);
void stack_release(value_stack_t* stack);
