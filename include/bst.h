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
bst_t bst_init(value_t* element, int (*comparator)(value_t, value_t));
void bst_release(bst_t* bst);

//adding and removing
int bst_add(bst_t* bst, value_t element);
int bst_remove(bst_t* bst, value_t element);

//searching
node_t* bst_find(const bst_t* bst, value_t element);
int bst_contains(const bst_t* bst, value_t element);
node_t* bst_min(const bst_t* bst);
node_t* bst_max(const bst_t* bst);

//utilities
int bst_height(const bst_t* bst, const node_t* node);
int bst_count(const bst_t* bst, const node_t* node);
void bst_map(const bst_t* bst, void (*func)(value_t*));
int bst_compare(const bst_t* bst_a, const bst_t* bst_b, int (*comparator)(value_t, value_t));
bst_t bst_copy(const bst_t* bst);

//printing
void print_inorder(const bst_t* bst);
void print_postorder(const bst_t* bst);
void print_preorder(const bst_t* bst);
