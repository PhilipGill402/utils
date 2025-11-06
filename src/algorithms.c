#include "algorithms.h"

int binary_search(const vector_t* arr, value_t element, int (*comparator)(value_t, value_t)){
    int left = 0;
    int mid = vector_size(arr) / 2;
    int right = vector_size(arr);

    while (comparator(*get(arr, mid), element) != 0){
        int comparison = comparator(element, *get(arr, mid));
        
        if (comparison > 0){
            left = mid;
            mid = (left + right) / 2;
        } else if (comparison < 0) {
            right = mid;
            mid = (left + right) / 2;
        }

        if (mid == 0){
            break;
        }
    }
    

    //element was not found
    if (comparator(element, *get(arr, mid)) != 0){
        return -1;
    }
    

    return mid;
}

void swap_vals(vector_t* arr, int index_a, int index_b){
    value_t temp = arr->array[index_a];
    arr->array[index_a] = arr->array[index_b];
    arr->array[index_b] = temp;
}

int partition(vector_t* arr, int left, int right, int pivot_index, int (*comparator)(value_t, value_t)){
    value_t pivot = *get(arr, pivot_index);
    swap_vals(arr, pivot_index, right);
    int p = left;

    for (int i = left; i < right; i++){
        if (comparator(*get(arr, i), pivot) < 0){
            swap_vals(arr, i, p);
            p++;
        }
    }
    swap_vals(arr, p, right);

    return p;
}

void quick_sort(vector_t* arr, int left, int right, int (*comparator)(value_t, value_t)){
    if (right <= left){
        return;
    }

    int median = (left + right) / 2;
    int j = partition(arr, left, right, median, comparator);
    quick_sort(arr, left, j-1, comparator);
    quick_sort(arr, j+1, right, comparator);
}
