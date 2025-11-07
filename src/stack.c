#include "stack.h"


value_stack_t stack_init(){
    value_stack_t stack;
    
    stack.size = 0;
    stack.capacity = 10;
    stack.top = -1; // must start it at -1 to make it a 0 based index
    stack.stack = malloc(sizeof(value_t) * 10); // starts with a capacity of 10 values 
    
    return stack;
}

int stack_is_empty(const value_stack_t* stack){
    return stack->size == 0;
}

int stack_push(value_stack_t* stack, value_t val){
    //checks if stack is full and if so, it doubles its capacity
    if (stack->size == stack->capacity){
        stack->stack = realloc(stack->stack, sizeof(value_t) * (stack->size * 2));
        
        if (!stack->stack){
            perror("realloc"); 
            return -1;
        }
        
        stack->capacity *= 2;
    }

    stack->stack[stack->size] = val;
    stack->top++;
    stack->size++;

    return 0;
}

value_t* stack_pop(value_stack_t* stack){
    if (stack_is_empty(stack)){
        return NULL;
    }    

    value_t* num = &stack->stack[stack->top];
    stack->top--;
    stack->size--;
    
    //if the stack gets below 25% then reduce it by 50%
    if (stack->size < stack->capacity / 4){
        stack->stack = realloc(stack->stack, sizeof(value_t) * (stack->size / 2));
        
        if (!stack->stack){
            perror("realloc"); 
            return NULL;
        }

       stack->capacity /= 4;
    }

    return num;
}

value_t* stack_top(const value_stack_t* stack){
    if (stack_is_empty(stack)){
        return NULL;
    }

    return &stack->stack[stack->top];
}

int stack_size(const value_stack_t* stack){
    return stack->size;
}

void stack_print(const value_stack_t* stack){
    printf("[");
    for (int i = 0; i < stack->size; i++){
        value_t val = stack->stack[i];
        print_value(val);
           
        if (i != stack->size - 1){
            printf(", ");
        } 
    }

    printf("]\n");
}

void stack_release(value_stack_t* stack){
    free(stack->stack);
    stack->stack = NULL;
}
