#include "stack.h"


stack_int_t* stack_init(){
    stack_int_t* stack = malloc(sizeof(stack_int_t));
    
    stack->size = 0;
    stack->capacity = 10;
    stack->top = -1; // must start it at -1 to make it a 0 based index
    stack->stack = malloc(sizeof(int) * 10); // starts with a capacity of 10 integers
    
    return stack;
}

int stack_is_empty(stack_int_t* stack){
    return stack->size == 0;
}

int stack_push(stack_int_t* stack, int num){
    //checks if stack is full and if so, it doubles its capacity
    if (stack->size == stack->capacity){
        stack->stack = realloc(stack->stack, sizeof(int) * (stack->size * 2));
        
        if (!stack->stack){
            perror("realloc"); 
            return -1;
        }
        
        stack->capacity *= 2;
    }

    stack->stack[stack->size] = num;
    stack->top++;
    stack->size++;

    return 0;
}

int stack_pop(stack_int_t* stack){
    if (stack_is_empty(stack)){
        return -1;
    }    

    int num = stack->stack[stack->top];
    stack->top--;
    stack->size--;
    
    //if the stack gets below 25% then reduce it by 50%
    if (stack->size < stack->capacity / 4){
        stack->stack = realloc(stack->stack, sizeof(int) * (stack->size / 2));
        
        if (!stack->stack){
            perror("realloc"); 
            return -1;
        }

       stack->capacity /= 4;
    }

    return num;
}

int stack_top(stack_int_t* stack){
    if (stack_is_empty(stack)){
        return -1;
    }

    return stack->stack[stack->top];
}

int stack_size(stack_int_t* stack){
    return stack->size;
}

void stack_print(stack_int_t* stack){
    printf("[");
    for (int i = 0; i < stack->size; i++){
        printf("%d", stack->stack[i]);
        
        if (i != stack->size - 1){
            printf(", ");
        } 
    }

    printf("]\n");
}

void stack_release(stack_int_t* stack){
    free(stack->stack);
    stack->stack = NULL;
    free(stack);
    stack = NULL;
}
