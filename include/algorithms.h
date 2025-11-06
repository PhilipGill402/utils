#pragma once
#include "vector.h"
#include "value.h"

int binary_search(const vector_t* arr, value_t element, int (*comparator)(value_t, value_t));
