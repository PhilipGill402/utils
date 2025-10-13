#include <stdio.h>
#include <stdlib.h>

typedef enum {
    VAL_INT,
    VAL_CHAR,
    VAL_DOUBLE,
    VAL_FLOAT
} Value_Type;

typedef struct value_t{
    Value_Type type;
    union {
        int i;
        char c;
        double d;
        float f;
    } val;
} value_t;

typedef struct value_stack_t {
    int size;
    int capacity;
    int top;
    value_t* stack; 
} value_stack_t;

value_stack_t* stack_init();
int stack_push(value_stack_t* stack, value_t val);
value_t* stack_pop(value_stack_t* stack);
value_t* stack_top(value_stack_t* stack);
int stack_size(value_stack_t* stack);
int stack_is_empty(value_stack_t* stack);
void stack_print(value_stack_t* stack);
void stack_release(value_stack_t* stack);
