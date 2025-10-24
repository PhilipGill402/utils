#include "bst.h"

int comparator(value_t val1, value_t val2){
    return val1.val.i - val2.val.i; 
}

value_t make_int(int x) {
    value_t v;
    v.type = VAL_INT;
    v.val.i = x;
    return v;
}

int main() {
    int (*comp_ptr)(value_t, value_t) = &comparator;

    bst_t* tree = bst_init(NULL, comp_ptr);
    
    // Add elements
    bst_add(tree, make_int(5));
    bst_add(tree, make_int(3));
    bst_add(tree, make_int(7));
    bst_add(tree, make_int(2));
    bst_add(tree, make_int(4));
    bst_add(tree, make_int(6));
    bst_add(tree, make_int(8));

    printf("BST created.\n\n");

    // Print traversals
    printf("In-order: ");
    print_inorder(tree->root);

    printf("Pre-order: ");
    print_preorder(tree->root);

    printf("Post-order: ");
    print_postorder(tree->root);

    // Remove a few nodes
    printf("\nRemoving 3 (has two children)...\n");
    bst_remove(tree, make_int(3));
    print_inorder(tree->root);

    printf("\nRemoving 7 (has two children)...\n");
    bst_remove(tree, make_int(7));
    print_inorder(tree->root);

    printf("\nRemoving 2 (leaf)...\n");
    bst_remove(tree, make_int(2));
    print_inorder(tree->root);

    printf("\nRemoving 5 (root)...\n");
    bst_remove(tree, make_int(5));
    print_inorder(tree->root);
    
    printf("\nRoot: ");
    print_value(tree->root->element);
    printf("\n");
    printf("\nAll tests complete.\n");

    return 0; 
}
