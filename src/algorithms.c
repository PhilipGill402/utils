#include "algorithms.h"

int binary_search(const vector_t* arr, value_t element, int (*comparator)(value_t, value_t)){
    int left = 0;
    int mid = vector_size(arr) / 2;
    int right = vector_size(arr);

    while (comparator(*vector_get(arr, mid), element) != 0){
        int comparison = comparator(*vector_get(arr, mid), element);

        if (comparison > 0){
            left = mid;
            mid = (left + right) / 2;
        } else if (comparison < 0) {
            right = mid;
            mid = (left + right) / 2;
        }
    } 
    

    return mid;
}
