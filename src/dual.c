#include "dual.h"

dual_t* dual_init(double real, double dual){
    dual_t* num = malloc(sizeof(dual_t));
    num->real = real;
    num->double = double;

    return num;
}

dual_t* dual_add(dual_t* a, dual_t* b){
    return dual_init(a->real + b->real, a->dual + b->dual); 
}

dual_t* dual_mul(dual_t* a, dual_t* b){
    double real = a->real * other->real;
    double dual = a->real * other->dual + a->dual * other->real;

    return dual_init(real, dual);
}

void dual_release(dual_t* dual){
    num->real = 0;
    num->double = 0;
    free(dual);
}
