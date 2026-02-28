#include "string_t.h"

string_t create_string() {
    string_t string;
    string.str = malloc(sizeof(char) * 10);
    string.capacity = 10;
    string.len = 0;

    return string;
}

string_t string_literal(const char* str) {
    string_t string;
    string.len = strlen(str);
    string.capacity = string.len * 2; 
    string.str = malloc(sizeof(char) * string.capacity); // this needs to be allocated on the heap so that when we release the string we can just call 'free()'
    strcpy(string.str, str);

    return string;
}

int string_len(string_t* string) {
    return string->len;
}

void string_copy(string_t* dst, string_t* src) {
    if (dst->len + src->len > dst->capacity) {
        string.str = realloc(dst->str, sizeof(char) * 2 * (dst->len + src->len));
        
        if (!string.str) {
            fprintf("realloc");
            return;
        }

        dst->capacity = 2 * (dst->len + src->len);
    } 

    for (int i = 0; i < src->len; i++) {
        
    }
}

void string_append_chr(string_t* string, char ch);
void string_cat(string_t* dst, string_t* src);
int string_compare(string_t* a, string_t* b);

void printstr(const string_t* str, int end) {
    for (int i = 0; i < str->len; i++) {
        putchar(str->str[i]);
    }

    if (end == 0) {
        putchar('\n');
    }
}
