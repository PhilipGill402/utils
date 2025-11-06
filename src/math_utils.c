#include "math_utils.h"

double r_sin(double x){
    double result = 0.0f;
    
    //convert to domain [pi/2, -pi/2] because the taylor series is only accurate until around pi/2
    int quadrant = 1;
    while (!(x <= M_PI/2 && x >= -M_PI/2)){
        x -= M_PI;
        quadrant += 2;
    }
    
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

int i_clamp(int x, int min, int max){
    if (x < min){
        x = min;
    } else if (x > max){
        x = max;
    }

    return x;
}

double d_clamp(double x, double min, double max){
    if (x < min){
        x = min;
    } else if (x > max){
        x = max;
    }

    return x;
}

int i_max(int a, int b){
    return a > b ? a : b;
}

double d_max(double a, double b){
    return a > b ? a : b;
}

int i_min(int a, int b){
    return a < b ? a : b;
}

double d_min(double a, double b){
    return a < b ? a : b;
}

double mean(double* arr, size_t len){
    double total = 0;

    for (int i = 0; i < len; i++){
        total += arr[i];
    }

    return total / len;
}

double stddev(double* arr, size_t len){
    double arr_mean = mean(arr, len);
    double sqr_dst = 0; 

    for (int i = 0; i < len; i++){
        sqr_dst += (arr[i] - arr_mean) * (arr[i] - arr_mean);
    }

    return mu_sqrt(sqr_dst / len, -1);
}

int i_abs(int x){
    if (x < 0){
        return x *= -1;
    }

    return x;
}

double d_abs(double x){
    if (x < 0){
        return x *= -1;
    }

    return x;
}

double mu_sqrt(double x, double epsilon){
    double next_guess;
    double prev_guess;
    
    if (epsilon == -1){
        epsilon = 1e-12;
    }

    if (x >= 1){
        prev_guess = x / 2.0;
    } else if (x > 0 && x < 1){
        prev_guess = 1.0;
    } else if (x == 0){
        return 0;
    } else {
        //can't find square root of a negative number
        return -1;
    }
    
    do{
        next_guess = prev_guess - (.5 * (prev_guess - (x / prev_guess)));
        prev_guess = next_guess;
    } while (d_abs((next_guess*next_guess) - x) > epsilon);

    return next_guess;
}
