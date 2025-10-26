#include "math_utils.h"

double r_sin(double x){
    double result = 0.0f;

    for (int i = 0; i < PRECISION; i++){
        int sign = pow(-1.0f, (double)i);
        double top = pow(x, (double)((2 * i) + 1));
        double bottom = factorial((2 * i) + 1);

        result += sign * (top / bottom);
    } 

    return result;
}


double d_sin(double x){
    double angle = (M_PI / 180) * x;
    return r_sin(angle);
}

double r_cos(double x){
    double result = 0.0f;

    for (int i = 0; i < PRECISION; i++){
        int sign = pow(-1.0f, (double)i);
        double top = pow(x, (double)(2 * i));
        double bottom = factorial(2 * i);

        result += sign * (top / bottom);
    } 

    return result;
}

double d_cos(double x){
    double angle =  (M_PI / 180) * x;
    return r_cos(angle);
}

int factorial(int x){
    if (x == 0){
        return 1;
    }
    
    int result = 1;

    for (int i = x; i > 0; i--){
        result *= i; 
    }

    return result;
}
