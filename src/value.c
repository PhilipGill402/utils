#include "value.h"

void print_value(value_t val){
    switch(val.type){
        case VAL_INT:
            printf("%d", val.val.i);
        case VAL_CHAR:
            printf("%c", val.val.c);
        case VAL_DOUBLE:
            printf("%f", val.val.d);
        case VAL_FLOAT:
            printf("%f", val.val.f);
        default:
            printf("Type Not Found");
    }
}
