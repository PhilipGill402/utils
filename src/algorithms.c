#include "algorithms.h"

int binary_search(const vector_t* arr, int element){
    int left = 0;
    int mid = vector_size(arr) / 2;
    int right = vector_size(arr);

    while (element != *(int*)get(arr, mid)){
       int mid_element = *(int*)get(arr, mid); 
        if (mid_element < element){
            left = mid;
            mid = (left + right) / 2;
        } else if (mid_element > element) {
            right = mid;
            mid = (left + right) / 2;
        }

        if (mid == 0){
            break;
        }
    }
    

    //element was not found
    if (*(int*)get(arr, mid) != element){
        return -1;
    }

    return mid;
}

void swap_vals(vector_t* arr, int index_a, int index_b){
    int* a = (int*)get(arr, index_a);
    int* b = (int*)get(arr, index_b);
    int* temp = (int*)malloc(sizeof(int));
    
    memcpy(temp, a, arr->element_size);
    memcpy(a, b, arr->element_size);
    memcpy(b, temp, arr->element_size);

    free(temp);
}

int partition(vector_t* arr, int pivot_index){
    int pivot = *(int*)get(arr, pivot_index);
    int left = 1;
    int right = vector_size(arr) - 1;
    swap_vals(arr, pivot_index, 0);

    while (left <= right) {
        while (*(int*)get(arr, left) <= pivot) {
            left++;
        }
        while (*(int*)get(arr, right) > pivot) {
            right--;
        }
        if (right > left) {
            swap_vals(arr, left, right);
        }
    } 
    swap_vals(arr, 0, right);

    return right;
}

void quick_sort(vector_t* arr, int left, int right){
    if (left >= right) {
        return;
    } 

    int median = (left + right) / 2;
    int j = partition(arr, median);
    quick_sort(arr, left, j-1);
    quick_sort(arr, j+1, right);
}
