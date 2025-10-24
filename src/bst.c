#include "bst.h"

node_t* node_init(value_t element){
    node_t* node = malloc(sizeof(node_t));
    node->element = element;
    node->left = NULL;
    node->right = NULL;

    return node;
}

//pass NULL for no root
bst_t* bst_init(value_t* element, int (*comparator)(value_t, value_t)){
    node_t* root;

    if (element == NULL){
        root = NULL; 
    } else {
        root = node_init(*element);
    }

    bst_t* bst = malloc(sizeof(bst_t));
    bst->root = root;
    bst->comparator = comparator;
    
    return bst;
}

void node_release_helper(node_t* node){
    if (node == NULL){
        return;
    } 

    node_release_helper(node->left);
    node_release_helper(node->right);
    free(node);
    node = NULL;
}

void bst_release(bst_t* bst){
    //free all nodes
    node_release_helper(bst->root);
    free(bst);
    
    bst = NULL;
}

int bst_height(bst_t* bst, node_t* node){
    if (node == NULL){
        return 0; 
    }
    
    int left_height = bst_height(bst, node->left);
    int right_height = bst_height(bst, node->right);

    return (right_height > left_height ? right_height : left_height) + 1;
}

int bst_add(bst_t* bst, value_t element){
    if (bst->root == NULL){
        bst->root = node_init(element);

        return 1;
    } 

    node_t* current = bst->root;
    
    while (current != NULL){
        if (bst->comparator(element, current->element) > 0){
            //if the element is greater than the current node
            if (current->right == NULL){
                current->right = node_init(element);
                break;
            }
            current = current->right;
        } else if (bst->comparator(element, current->element) < 0){
            //if the element is less than the current node
            if (current->left == NULL){
                current->left = node_init(element);
                break;
            }
            current = current->left;
        } else {
            //if the elements are equal
            return -1;
        }
    }

    return 0;
}


int bst_remove(bst_t* bst, value_t element){
    node_t* current = bst->root;
    node_t* prev = NULL;

    while (current != NULL && bst->comparator(current->element, element) != 0){
        prev = current;
        
        //current node is greater than our element
        if (bst->comparator(current->element, element) > 0){ 
             
            current = current->left;
        } else if (bst->comparator(current->element, element) < 0){
            //current node is less than our element 
            current = current->right;
        }
    }
    

    //the value is not in the tree 
    if (current == NULL){
        return -1;
    } 

    //case 1 - node is a leaf node
    if (current->left == NULL && current->right == NULL){
        //node to be removed is the root
        if (bst->root == current){
            bst->root = NULL;
        }
        
        if (prev->left == current){
            prev->left = NULL;
        } else {
            prev->right = NULL;
        }
    }

    //case 2 - node has one child
    if (current->left != NULL ^ current->right != NULL){
        //node to be removed is the root 
        if (bst->root == current){
            if (current->left != NULL){
                bst->root = current->left;
            } else {
                bst->root = current->right;
            }
        } else {
            if (current->left != NULL && prev->left == current){
                prev->left = current->left;
            } else if (current->left != NULL && prev->right == current){
                prev->right = current->left;
            } else if (current->right != NULL && prev->left == current){
                prev->left = current->right;
            } else {
                prev->right = current->right;
            }
        }
    } 

    //case 3 - node has two children
    if (current->left != NULL && current->right != NULL){
        //find inorder successor
        node_t* replacement_parent = current;
        node_t* replacement = current->right;
        
        while (replacement->left != NULL){
            replacement_parent = replacement;
            replacement = replacement->left;
        }

        current->element = replacement->element;
        
        node_t* replacement_child = replacement->right;
        if (replacement_parent->left == replacement){
            replacement_parent->left = replacement_child;
        } else {
            replacement_parent->right = replacement_child;
        }
    
        free(replacement); 

        //we must return now because we just replaced current, we don't want to remove it
        return 1;
    } 


    //successful removal, time to cleanup
    free(current);
    current = NULL; 

    return 1;
}

node_t* bst_find(bst_t* bst, value_t element){
    node_t* current = bst->root;

    while (current != NULL && bst->comparator(current->element, element) != 0){
        if (bst->comparator(current->element, element) > 0){
            current = current->left;
        } else {
            current = current->right;
        }
    }

    return current; 

}

int bst_contains(bst_t* bst, value_t element){
    return bst_find(bst, element) != NULL;
}

node_t* bst_min(bst_t* bst){
    node_t* current = bst->root;

    while (current->left != NULL){
        current = current->left;
    }

    return current;
}

node_t* bst_max(bst_t* bst){
    node_t* current = bst->root;

    while (current->right != NULL){
        current = current->right;
    }

    return current;
}

int bst_count(bst_t* bst, node_t* node){
    if (node == NULL){
        return 0; 
    }
    
    int left_count = bst_count(bst, node->left);
    int right_count = bst_count(bst, node->right);

    return right_count + left_count + 1;
}

void bst_map_helper(node_t* node, void (*func)(value_t*)){
    if (node == NULL){
        return;
    } 
    
    func(&node->element); 
    bst_map_helper(node->left, func);
    bst_map_helper(node->right, func);

}

void bst_map(bst_t* bst, void (*func)(value_t*)){
    node_t* node = bst->root;
    bst_map_helper(node, func);
}

int bst_compare_helper(node_t* node_a, node_t* node_b, int (*comparator)(value_t, value_t)){
    if (node_a == NULL && node_b == NULL){
        return 1;
    }

    if (node_a == NULL ^ node_b == NULL){
        return 0;
    }

    if (comparator(node_a->element, node_b->element) != 0){
        return 0;
    }

    if (bst_compare_helper(node_a->left, node_b->left, comparator) == 0){
        return 0;
    }

    if (bst_compare_helper(node_a->right, node_b->right, comparator)){
        return 0;
    }

    return 1;
}

int bst_compare(bst_t* bst_a, bst_t* bst_b, int (*comparator)(value_t, value_t)){
    //if no comparator is given, then a comparator from one of the bsts 
    if (comparator == NULL){
        if (bst_a->comparator != NULL){
            comparator = bst_a->comparator;
        } else if (bst_b->comparator != NULL){
            comparator = bst_b->comparator;
        } else {
            //no comparator was found
            return -1;
        }
    }
    
    if (bst_compare_helper(bst_a->root, bst_b->root, comparator) == 0){
        return 0;
    }

    return 1;

    
}

node_t** bst_level_order(bst_t* bst){
    node_t** queue = malloc(sizeof(node_t*) * bst_count(bst, bst->root));
    node_t** result = malloc(sizeof(node_t*) * bst_count(bst, bst->root));
    int queue_size = 0;
    int queue_head = 0;
    int result_size = 0;

    if (queue == NULL || result == NULL || bst->root == NULL){
        return NULL;
    }

    queue[queue_size] = bst->root;
    queue_size++;

    while (queue_size >= 0){
        result[result_size] = queue[queue_head];
        
        if (queue[queue_head]->left != NULL){
            node_t* left_child = queue[queue_head]->left;
            queue[queue_size] = left_child;
            queue_size++;
        }
        
        if (queue[queue_head]->right != NULL){
            node_t* right_child = queue[queue_head]->right;
            queue[queue_size] = right_child;
            queue_size++;
        }

        queue_head++;
        result_size++;
    }

    return result; 
}

bst_t* bst_copy(bst_t* bst){
    bst_t* new_bst = bst_init(NULL, bst->comparator);
    new_bst->root = bst->root;
    
    

    return new_bst;
}

void print_inorder_helper(node_t* node, int* first){
    if (node == NULL){
        return;
    }

    print_inorder_helper(node->left, first);

    if (*first == 0){
        printf(", ");
    }
    print_value(node->element); 
    *first = 0;

    print_inorder_helper(node->right, first);
}

void print_inorder(bst_t* bst){
    printf("[");
    int first = 1;
    print_inorder_helper(bst->root, &first);
    printf("]\n");    
}

void print_postorder_helper(node_t* node, int* first){
    if (node == NULL){
        return;
    }

    print_postorder_helper(node->left, first);
    
    print_postorder_helper(node->right, first);
    
    if (*first == 0){
        printf(", ");
    }
    
    print_value(node->element); 
    *first = 0;
}

void print_postorder(bst_t* bst){
    printf("[");
    int first = 1;
    print_postorder_helper(bst->root, &first);
    printf("]\n");
}

void print_preorder_helper(node_t* node, int* first){
    if (node == NULL){
        return;
    }

    if (*first == 0){
        printf(", ");
    }
    
    print_value(node->element); 
    *first = 0;

    print_preorder_helper(node->left, first);
    
    print_preorder_helper(node->right, first);
    
    
}

void print_preorder(bst_t* bst){
    printf("[");
    int first = 1;
    print_preorder_helper(bst->root, &first);
    printf("]\n");
}
