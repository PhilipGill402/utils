#include "math_utils.h"
#include <stdlib.h>

int main(){
    double* arr = malloc(sizeof(double) * 10);
    for (int i = 0; i < 10; i++){
        arr[i] = i;
    }
    double x = stddev(arr, 10); 
    printf("%f\n", x);

    return 0;
}
