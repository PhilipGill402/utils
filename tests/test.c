#include "stack.h"
#include <stdlib.h>


int main(){
    stack_s stack = create_stack(sizeof(int));

    for (int i = 10; i > 0; i--){
        int x = i;
        stack_push(&stack, &x);
    }

    for (int i = 0; i < 10; i++) {
        printf("%d\n", *(int*)stack_pop(&stack));
    }

    return 0;
}
