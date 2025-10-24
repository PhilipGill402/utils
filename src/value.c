#include "value.h"

void print_value(value_t val){
    switch(val.type){
        case VAL_INT:
            printf("%d", val.val.i);
            break;
        case VAL_CHAR:
            printf("%c", val.val.c);
            break;
        case VAL_DOUBLE:
            printf("%f", val.val.d);
            break;
        case VAL_FLOAT:
            printf("%f", val.val.f);
            break;
        default:
            printf("Type Not Found");
            break;
    }
}
