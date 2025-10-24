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

//initialization / destruction
node_t* node_init(value_t element);
bst_t* bst_init(value_t* element, int (*comparator)(value_t, value_t));
void bst_release(bst_t* bst);

//adding and removing
int bst_add(bst_t* bst, value_t element);
int bst_remove(bst_t* bst, value_t element);

//searching
node_t* bst_find(bst_t* bst, value_t element);
int bst_contains(bst_t* bst, value_t element);
node_t* bst_min(bst_t* bst);
node_t* bst_max(bst_t* bst);

//utilities
int bst_height(bst_t* bst, node_t* node);
int bst_count(bst_t* bst, node_t* node);
void bst_map(bst_t* bst, void (*func)(value_t*));
int bst_compare(bst_t* bst_a, bst_t* bst_b, int (*comparator)(value_t, value_t));


//printing
void print_inorder(bst_t* bst);
void print_postorder(bst_t* bst);
void print_preorder(bst_t* bst);
