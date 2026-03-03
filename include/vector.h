#ifndef UTILS_VECTOR_H_
#define UTILS_VECTOR_H_

#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>
#include <string.h>
#include "arena.h"

typedef struct vector_t{
    arena_t* allocator;
    int using_allocator;
    void* array; 
    int size;
    int capacity;
    size_t element_size;
} vector_t; 

typedef struct vector_iterator_t{
    void* current;
    void* end;
    size_t element_size;
} vector_iterator_t;

//initializing and destroying
vector_t create_vector(size_t element_size);
vector_t create_vector_arena(size_t element_size, arena_t* allocator);
void free_vector(vector_t* vec);



//managing size
void vector_reserve(vector_t* vec, int new_capacity);
void resize(vector_t* vec, int new_capacity);
int vector_size(const vector_t* vec);
int vector_capacity(const vector_t* vec);
void downsize(vector_t* vec, int new_size);
void upsize(vector_t* vec, int new_size, void* element);
void shrink_to_fit(vector_t* vec);

//adding / deleting values
void push_back(vector_t* vec, void* element);
void* pop_back(vector_t* vec);

//accessing data
void* get(const vector_t* vec, int index);
void* front(const vector_t* vec);
void* back(const vector_t* vec);
void insert(vector_t* vec, void* element, int index);
void erase(vector_t* vec, int index);
void swap(vector_t* vec, vector_t* other_vec);
void clear(vector_t* vec);
void assign(vector_t* vec, void* element, int num_copies);
void* data(const vector_t* vec);

//iterators
vector_iterator_t* iterator(vector_t* vec);
vector_iterator_t* create_iterator(const vector_t* vec);
int has_next(const vector_iterator_t* itr);
void* next(vector_iterator_t* itr);

//miscellanenous
bool empty(const vector_t* vec);

#endif // !UTILS_VECTOR_H_
