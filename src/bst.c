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


int height(bst_t* bst, node_t* node){
    if (node == NULL){
        return 0; 
    }
    
    int left_height = height(bst, node->left);
    int right_height = height(bst, node->right);

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
        }
        
        //current node is less than our element
        if (bst->comparator(current->element, element) < 0){
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

        //don't worry about deleting the node, we do this at the bottom, no cleanup involved
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
        
        node_t* replacement_child = replacement_parent->right;
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

void print_inorder(node_t* node){
    printf("[");
    int first = 1;
    print_inorder_helper(node, &first);
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

void print_postorder(node_t* node){
    printf("[");
    int first = 1;
    print_postorder_helper(node, &first);
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

void print_preorder(node_t* node){
    printf("[");
    int first = 1;
    print_preorder_helper(node, &first);
    printf("]\n");
}



