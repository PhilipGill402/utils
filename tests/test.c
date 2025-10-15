#include "stack.h"

int main() {
    value_stack_t* stack = stack_init();

    for (int i = 0; i < 5; i++) {
        value_t v = {.type = VAL_INT, .val.i = i};
        stack_push(stack, v);
    }

    value_t c = {.type = VAL_CHAR, .val.c = 'A'};
    stack_push(stack, c);

    value_t f = {.type = VAL_FLOAT, .val.f = 3.14f};
    stack_push(stack, f);

    stack_print(stack);

    stack_release(stack);
    return 0;
}

