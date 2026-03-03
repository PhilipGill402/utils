#include "string_t.h"

string_t create_string() {
    string_t string;
    string.str = malloc(sizeof(char) * 10);
    string.capacity = 10;
    string.len = 0;
    string.using_allocator = 0;

    return string;
}

string_t create_string_arena(arena_t* allocator) {
    string_t string;
    string.allocator = allocator;
    string.using_allocator = 1;
    string.str = reserve(sizeof(char) * 10, allocator);
    string.len = 0;
    string.capacity = 10;

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

string_t string_literal_arena(const char* str, arena_t* allocator) {
    string_t string;
    string.len = strlen(str);
    string.capacity = string.len * 2; 
    string.str = reserve(sizeof(char) * string.capacity, allocator); // this needs to be allocated on the heap so that when we release the string we can just call 'free()'
    strcpy(string.str, str);
    string.allocator = allocator;
    string.using_allocator = 1;

    return string;
}

int string_len(string_t* string) {
    return string->len;
}

void string_copy(string_t* dst, string_t* src) {
    if (src->len > dst->capacity) {
        if (dst->using_allocator) {
            char* new_str = reserve(sizeof(char) * 2 * src->len, dst->allocator);
            memcpy(new_str, dst->str, dst->len);
            release(dst->str, dst->allocator);
            dst->str = new_str;
        } else {
            dst->str = realloc(dst->str, sizeof(char) * 2 * src->len);
        }
        
        if (!dst->str) {
            fprintf(stderr, "realloc");
            return;
        }

        dst->capacity = 2 * src->len;
    } 

    for (int i = 0; i < src->len; i++) {
        dst->str[i] = src->str[i];
    }

    dst->len = src->len;
}

void string_append_chr(string_t* string, char ch) {
    if (string->len + 1 > string->capacity) {
        if (string->using_allocator) {
            char* new_str = reserve(sizeof(char) * 2 * (string->len + 1), string->allocator);
            memcpy(new_str, string->str, string->len);
            release(string->str, string->allocator);
            string->str = new_str;
        } else {
            string->str = realloc(string->str, sizeof(char) * 2 * (string->len + 1));
        }


        if (!string->str) {
            fprintf(stderr, "realloc");
            return;
        }

        string->capacity = 2 * (string->len + 1);
    }

    string->str[string->len] = ch;
    string->len++;
}

void string_cat(string_t* dst, string_t* src) {
    if (dst->capacity < src->len + dst->len) {
        if (dst->using_allocator) {
            char* new_str = reserve(sizeof(char) * 2 * (src->len + dst->len), dst->allocator);
            memcpy(new_str, dst->str, dst->len);
            release(dst->str, dst->allocator);
            dst->str = new_str;
        } else {
            dst->str = realloc(dst->str, sizeof(char) * 2 * (src->len + dst->len));
        }


        if (!dst->str) {
            fprintf(stderr, "realloc");
            return;
        }

        dst->capacity = 2 * (src->len + dst->len);
    }
    
    for (int i = dst->len, j = 0; i < dst->len + src->len; i++, j++) {
        dst->str[i] = src->str[j];
    }

    dst->len += src->len;
}

int string_compare(string_t* a, string_t* b) { 
    for (int i = 0; i < a->len && i < b->len; i++) {
        if (a->str[i] != b->str[i]) {
            return a->str[i] - b->str[i];
        }
    } 

    return 0;
}

void free_string(string_t* str) {
    if (str->using_allocator) {
        release(str->str, str->allocator);
    } else {
        free(str->str);
    }

    str->str = NULL;
    str->len = 0;
    str->capacity = 0;
}

void printstr(const string_t* str, int end) {
    for (int i = 0; i < str->len; i++) {
        putchar(str->str[i]);
    }

    if (end == 0) {
        putchar('\n');
    }
}
