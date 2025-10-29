#pragma once
#include <stdlib.h>

typedef struct dual_t{
    double real;
    double dual;
} dual_t;

dual_t* dual_init(double real, double dual);
dual_t* dual_add(dual_t a, dual_t b);
dual_t* dual_mul(dual_t a, dual_t b);
void dual_release(dual_t dual);
