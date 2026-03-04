#pragma once
#include <stdlib.h>
#include <stdio.h>
#include <string.h>

typedef struct arena_t arena_t;
void* reserve(size_t size, arena_t* arena);
void release(void* ptr, arena_t* arena);
void* move(void* ptr, size_t size, arena_t* arena);

typedef struct node_t{
    void* element;
    struct node_t* left;
    struct node_t* right;
} node_t;

typedef struct bst_t{
    arena_t* allocator; 
    size_t element_size;
    node_t* root;
    int (*comparator)(void* , void*);
} bst_t;

//initialization / destruction
node_t* node_init(void* element, size_t element_size, arena_t* allocator);
bst_t bst_init(void* element, size_t element_size, arena_t* allocator, int (*comparator)(void*, void*));
void bst_release(bst_t* bst);

//adding and removing
int bst_add(bst_t* bst, void* element);
int bst_remove(bst_t* bst, void* element);

//searching
node_t* bst_find(const bst_t* bst, void* element);
int bst_contains(const bst_t* bst, void* element);
node_t* bst_min(const bst_t* bst);
node_t* bst_max(const bst_t* bst);

//utilities
int bst_height(const bst_t* bst, const node_t* node);
int bst_count(const bst_t* bst, const node_t* node);
void bst_map(const bst_t* bst, void (*func)(void*));
int bst_compare(const bst_t* bst_a, const bst_t* bst_b, int (*comparator)(void*, void*));
bst_t bst_copy(const bst_t* bst);

//printing
void print_inorder(const bst_t* bst, void (*print_element)(void*));
void print_postorder(const bst_t* bst, void (*print_element)(void*));
void print_preorder(const bst_t* bst, void (*print_element)(void*));
