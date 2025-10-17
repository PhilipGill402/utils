#include "vector.h"

vector_t* create_vector(){
    //start with 10 elements
    vector_t* vec = malloc(sizeof(*vec));
    if (!vec){
        fprintf(stderr, "Failed to allocat memory for the vector\n");
        return NULL;
    }
    
    vec->array = malloc(10 * sizeof(value_t));

    if (!vec->array){
        fprintf(stderr, "Failed to allocate memory for the array\n");
        free(vec);
        return NULL;
    }

    vec->size = 0;
    vec->capacity = 10;

    return vec;
}

vector_iterator_t* iterator(vector_t* vec){
    return create_iterator(vec); 
}

void reserve(vector_t* vec, int new_capacity){
    value_t* ptr = realloc(vec->array, sizeof(value_t) * new_capacity);

    if (ptr == NULL){
        fprintf(stderr, "Reallocation failed\n");
        return;
    }
    
    vec->capacity = new_capacity;
    vec->array = ptr;
    
}

int size(vector_t* vec){
    return vec->size;
}

void push_back(vector_t* vec, value_t element){
    // if the array is full then double its capacity  
    if (size(vec) == vec->capacity){
        reserve(vec, vec->capacity * 2);
    } 

    vec->array[size(vec)] = element;
    vec->size++;

}

value_t* pop_back(vector_t* vec){
    if (size(vec) == 0){
        fprintf(stderr, "pop_back() called on empty vector\n");
        return 0;
    } 

    value_t* element = &vec->array[size(vec)-1];
    vec->size--;
    
    //if the size of the vector drops to 25% of its capacity then halve its capacity
    if (size(vec) * 4 <= vec->capacity){
        reserve(vec, (int)(vec->capacity / 2));
    }


    return element;
}

//TODO: rewrite
void print_vector(vector_t* vec){
    printf("<");
    for (int i = 0; i < size(vec) - 1; i++){
        value_t element = vec->array[i];

        switch(element.type){
            case VAL_INT:
                printf("%d, ", element.val.i);
                break;
            case VAL_CHAR:
                printf("%c, ", element.val.c);
                break;
            case VAL_DOUBLE:
                printf("%f, ", element.val.d);
                break;
            case VAL_FLOAT:
                printf("%f, ", element.val.f);
                break;
            default:
                printf("Type not Recognized, ");
                break;
        } 

    }
    if (!empty(vec)){
        value_t element = vec->array[size(vec) - 1];
        switch(element.type){
            case VAL_INT:
                printf("%d", element.val.i);
                break;
            case VAL_CHAR:
                printf("%c", element.val.c);
                break;
            case VAL_DOUBLE:
                printf("%f", element.val.d);
                break;
            case VAL_FLOAT:
                printf("%f", element.val.f);
                break;
            default:
                printf("Type not Recognized, ");
                break;
        }
    }
    
    printf(">\n");
}

void destroy_vector(vector_t* vec){
    free(vec->array);
    vec->array = NULL;
    vec->size = 0;
    vec->capacity = 0;
}

bool empty(vector_t* vec){
    if (vec == NULL) {
        fprintf(stderr, "empty() called on NULL vector\n");
        return true;
    }
    
    return size(vec) == 0;
}

value_t* get(vector_t* vec, int index){
    if (index > size(vec)){
        fprintf(stderr, "'index' is out of the range of the vector");
        return NULL;
    }
    return &vec->array[index];
}

value_t* front(vector_t* vec){
    if (empty(vec)){
        fprintf(stderr, "cannot get first element of empty vector\n");
        return NULL;
    }

    return &vec->array[0];
}

value_t* back(vector_t* vec){
    if (empty(vec)){
        fprintf(stderr, "cannot get last element of empty vector\n");
        return NULL;
    }

    return &vec->array[size(vec) - 1];
}

void insert(vector_t* vec, value_t element, int index){
    //if the vector is full then reserve double its capacity
    if (size(vec) + 1 > vec->capacity){
        reserve(vec, vec->capacity * 2);
    }

    //shift everything over one
    for (int i = size(vec) + 1; i >= index; i--){
        vec->array[i] = vec->array[i - 1]; 
    }
    
    //set the element at index to the given element
    vec->array[index] = element;
    vec->size++;

}

void erase(vector_t* vec, int index){
    if (index >= size(vec)){
        fprintf(stderr, "index given is outside the bounds of the vector\n");
        return;
    }
    
    //we're removing the last element
    if (index == size(vec) - 1){
        vec->size--;
    } else {
        for (int i = index; i < size(vec) - 1; i++){
            vec->array[i] = vec->array[i + 1];
        }

        vec->size--;
    }
    
    if (size(vec) * 4 <= vec->capacity){
        reserve(vec, (int)(vec->capacity / 2));
    }

    
}

void swap(vector_t* vec, vector_t* other_vec){
    //array 
    value_t* tmp = vec->array; 
    vec->array = other_vec->array;
    other_vec->array = tmp;
    
    //size
    int temp = vec->size;
    vec->size = other_vec->size;
    other_vec->size = temp;

    //capcaity
    temp = vec->capacity;
    vec->capacity = other_vec->capacity;
    other_vec->capacity = temp;

}

void clear(vector_t* vec){
    vec->size = 0;
    reserve(vec, 10);
}

void assign(vector_t* vec, value_t element, int num_copies){
    if (num_copies > vec->capacity){
        reserve(vec, num_copies * 2);
    }

    vec->size = num_copies;

    for (int i = 0; i < size(vec); i++){
        vec->array[i] = element;
    }
}

int capacity(vector_t* vec){
    return vec->capacity;
}

void downsize(vector_t* vec, int new_size){
    if (new_size > size(vec)){
        fprintf(stderr, "given size is larger than size of the vector\n");
        return;
    } 
     
    vec->size = new_size;

    if (size(vec) > capacity(vec)){
        reserve(vec, 2 * size(vec));
    }
}

void upsize(vector_t* vec, int new_size, value_t element){
    if (new_size < size(vec)){
        fprintf(stderr, "given size is smaller than size of the vector\n");
        return;
    } 
    
    int old_size = vec->size; 
    vec->size = new_size;

    if (size(vec) > capacity(vec)){
        reserve(vec, 2 * size(vec));
    }

    for (int i = old_size; i < new_size; i++){
        vec->array[i] = element;
    }
}

void shrink_to_fit(vector_t* vec){
    vec->capacity = vec->size;
}

value_t* data(vector_t* vec){
    return vec->array;
}



vector_iterator_t* create_iterator(vector_t* vec){
    vector_iterator_t* itr = malloc(sizeof(*itr));
    itr->current = vec->array;
    itr->end = vec->array + size(vec);
    return itr;
}

int has_next(vector_iterator_t* itr){
    return itr->current != itr->end;
}


value_t* next(vector_iterator_t* itr){
    if (has_next(itr)){
        value_t* element = itr->current;
        itr->current++;

        return element;
    } else {
        fprintf(stderr, "vector has no more elements\n");
        return NULL;
    }
}

void resize(vector_t* vec, int new_size){
    if (size(vec) > capacity(vec)){
        reserve(vec, 2 * new_size);
    } 
    
    vec->size = new_size;
}
