#include "bst.h"

int comparator(value_t val1, value_t val2){
    return val1.val.i - val2.val.i; 
}

void double_value(value_t* val){
    val->val.i *= 2;
}

int main() {
    int (*comp_ptr)(value_t, value_t) = &comparator;

    bst_t tree_a = bst_init(NULL, comp_ptr);
    
    // Add elements
    bst_add(&tree_a, make_int(5));
    bst_add(&tree_a, make_int(3));
    bst_add(&tree_a, make_int(7));
    bst_add(&tree_a, make_int(2));
    bst_add(&tree_a, make_int(4));
    bst_add(&tree_a, make_int(6));
    bst_add(&tree_a, make_int(8));
    
    print_inorder(&tree_a);
    
    bst_t tree_b = bst_copy(&tree_a);
    
    print_inorder(&tree_b);
     
    return 0; 
}
