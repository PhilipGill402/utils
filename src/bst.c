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


int bst_remove(bst_t* bst, value_t element);
void print_inorder(bst_t* bst, node_t* node);
void print_postorder(bst_t* bst, node_t* node);
void print_preorder(bst_t* bst, node_t* node);
