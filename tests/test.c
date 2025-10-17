#include "vector.h"

int main() {
    vector_t* vec = create_vector();

    for (int i = 0; i < 30; i++){
        value_t val = {.type = VAL_INT, .val.i = i};
        push_back(vec, val);
    }
    
    value_t val = {.type = VAL_CHAR, .val.c = 'A'};
    push_back(vec, val);

    print_vector(vec);


    return 0;
}

