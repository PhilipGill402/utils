#include "bst.h"
#include "arena.h"

int comparator(void* val1, void* val2){
    return *(int*)val1 - *(int*)val2; 
}

int main() {
    int (*comp_ptr)(void*, void*) = &comparator;
    arena_t arena = create_arena(PAGE_SIZE);

    bst_t tree_a = bst_init(NULL, sizeof(int), &arena, comp_ptr);
    
    // Add elements
    for (int i = 0; i < 25; i++) {
        int x = i; 
        bst_add(&tree_a, &x);
    }

    for (int i = 0; i < 25; i++) {
        int x = i;
        printf("%d\n", bst_contains(&tree_a, &x));
    }
    
    //print_inorder(&tree_a);
    
    bst_t tree_b = bst_copy(&tree_a);
    
    //print_inorder(&tree_b);
    release_arena(&arena); 
    return 0; 
}
