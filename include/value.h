#pragma once

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
