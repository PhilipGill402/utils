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

value_t make_int(int i){
    value_t val;
    val.type = VAL_INT;
    val.val.i = i;

    return val;
}

value_t make_char(char c){
    value_t val;
    val.type = VAL_CHAR;
    val.val.c = c;

    return val;
}

value_t make_double(double d){
    value_t val;
    val.type = VAL_DOUBLE;
    val.val.d = d;

    return val;
}

value_t make_float (float f){
    value_t val;
    val.type = VAL_FLOAT;
    val.val.f = f;

    return val;
}
