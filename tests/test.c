#include "bst.h"

int comparator(value_t val1, value_t val2){
    return val1.val.i - val2.val.i; 
}

int main() {
    int (*comp_ptr)(value_t, value_t) = &comparator;

    bst_t* bst = bst_init(NULL, comp_ptr);
    
    for (int i = 0; i < 30; i++){
        value_t val = {.type=VAL_INT, .val.i=i};
        bst_add(bst, val);
    }
