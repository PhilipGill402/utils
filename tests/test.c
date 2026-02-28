#include "string_t.h"
#include <stdlib.h>


int main(){
    string_t str = string_literal("hello world");

    printstr(&str, 0);

    return 0;
}
