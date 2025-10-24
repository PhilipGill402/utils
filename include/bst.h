#pragma once
#include <stdlib.h>
#include <stdio.h>
#include "value.h"

typedef struct node_t{
    value_t element;
    struct node_t* left;
    struct node_t* right;
} node_t;

typedef struct bst_t{
    node_t* root;
    int (*comparator)(value_t, value_t);
} bst_t;

node_t* node_init(value_t element);
bst_t* bst_init(value_t* element, int (*comparator)(value_t, value_t));
int height(bst_t* bst, node_t* node);
int bst_add(bst_t* bst, value_t element);
int bst_remove(bst_t* bst, value_t element);
void print_inorder(node_t* node);
void print_postorder(node_t* node);
void print_preorder(node_t* node);
