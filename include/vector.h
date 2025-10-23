#pragma once
#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>
#include "value.h"

typedef struct vector_t{
    value_t* array; 
    int size;
    int capacity;
} vector_t; 

typedef struct vector_iterator_t{
    value_t* current;
    value_t* end;
} vector_iterator_t;

//initializing and destroying
vector_t* create_vector();
void destroy_vector(vector_t* vec);



//managing size
void reserve(vector_t* vec, int new_capacity);
void resize(vector_t* vec, int new_capacity);
int vector_size(vector_t* vec);
int vector_capacity(vector_t* vec);
void downsize(vector_t* vec, int new_size);
void upsize(vector_t* vec, int new_size, value_t element);
void shrink_to_fit(vector_t* vec);

//adding / deleting values
void push_back(vector_t* vec, value_t element);
value_t* pop_back(vector_t* vec);

//accessing data
value_t* get(vector_t* vec, int index);
value_t* front(vector_t* vec);
value_t* back(vector_t* vec);
void insert(vector_t* vec, value_t element, int index);
void erase(vector_t* vec, int index);
void swap(vector_t* vec, vector_t* other_vec);
void clear(vector_t* vec);
void assign(vector_t* vec, value_t element, int num_copies);
value_t* data(vector_t* vec);

//iterators
vector_iterator_t* iterator(vector_t* vec);
vector_iterator_t* create_iterator(vector_t* vec);
int has_next(vector_iterator_t* itr);
value_t* next(vector_iterator_t* itr);

//miscellanenous
void print_vector(vector_t* vec);
bool empty(vector_t* vec);

