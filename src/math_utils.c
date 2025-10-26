#include "math_utils.h"

double r_sin(double x){
    double result = 0.0f;

    for (int i = 0; i < PRECISION; i++){
        int sign = pow(-1.0f, (double)i);
        printf("%d\n", sign);
    } 
}


double d_sin(double x);
double r_cos(double x);
double d_cos(double x);
