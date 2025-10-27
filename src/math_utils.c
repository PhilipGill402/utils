#include "math_utils.h"

double r_sin(double x){
    double result = 0.0f;
    
    //convert to domain [pi/2, -pi/2] because the taylor series is only accurate until around pi/2
    int quadrant = 1;
    while (!(x <= M_PI/2 && x >= -M_PI/2)){
        x -= M_PI;
        quadrant += 2;
    }
    
    printf("Sin Angle: %f\n", x);   
    
    quadrant %= 4;

    

    for (int i = 0; i < PRECISION; i++){
        int sign = pow(-1.0f, (double)i);
        double top = pow(x, (double)((2 * i) + 1));
        double bottom = factorial((2 * i) + 1);

        result += sign * (top / bottom);
    } 
    
    if (quadrant == 3 || quadrant == 4){
        result *= -1;
    }
    
    return result;
}


double d_sin(double x){
    double angle = (M_PI / 180) * x;
    return r_sin(angle);
}

double r_cos(double x){
    double result = 0.0f;
    
    //convert to domain [pi/2, -pi/2] because the taylor series is only accurate until around pi/2
    int quadrant = 1;
    while (!(x <= M_PI/2 && x >= -M_PI/2)){
        x -= M_PI;
        quadrant += 2;
    }
    
    printf("Cos Angle: %f\n", x);

    quadrant %= 4;



    for (int i = 0; i < PRECISION; i++){
        int sign = pow(-1.0f, (double)i);
        double top = pow(x, (double)(2 * i));
        double bottom = factorial(2 * i);

        result += sign * (top / bottom);
    } 
    
    if (quadrant == 2 || quadrant == 3){
        result *= -1;
    }

    return result;
}

double d_cos(double x){
    double angle =  (M_PI / 180) * x;
    return r_cos(angle);
}

int i_pow(int x, int y){
    int result = 1;

    while (y > 0){
        int last_bit = y & 1;

        if (last_bit){
            result *= x;
        }

        x *= x;

        y = y >> 1;
    }

    return result;
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
