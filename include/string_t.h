#ifndef INCLUDE_STRING_H_
#define INCLUDE_STRING_H_
#include <stdlib.h>
#include <stdio.h>
#include <string.h>

typedef struct {
    char* str;
    int len;
    int capacity;
} string_t;

string_t create_string();
string_t string_literal(const char* str);
int string_len(string_t* string);
void string_copy(string_t* dst, string_t* src);
void string_append_chr(string_t* string, char ch);
void string_cat(string_t* dst, string_t* src);
int string_compare(string_t* a, string_t* b);
void free_string(string_t* str);
void printstr(const string_t* str, int end);

#endif // !INCLUDE_STRING_H_
