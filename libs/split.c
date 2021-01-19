#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#include "split.h"

// split a string into an array of strings based on delimiter
char **split(char *s, const char *delim)
{
    char **split_s;
    char *token;
    size_t len, s_len;
    int i;
    
    len = strlen(s);
    
    split_s = malloc(sizeof(char*)*(len)*2);
    if (split_s == NULL) {
        fprintf(stderr, "split: could not allocate memory\n");
        exit(EXIT_FAILURE);
    }

    i = 0;
    token = strtok(s, delim);
    while (token != NULL) {
        *split_s = token;
        if (**split_s == ' ' || **split_s == '\n')
            memmove(*split_s, *(split_s)+1, strlen(*split_s));

        // add null terminator at end of each string
        s_len = strlen(*split_s);
        split_s+=s_len;
        *split_s = 0;
        split_s -= s_len;

        token = strtok(NULL, delim);
        split_s++;
        i++;
    }
    *split_s = NULL;
    split_s -= i;
    return split_s;
}


// print_arr: each string in an array of strings
void print_arr(char **vec)
{
    int len = 0;
    while (*vec) {
        printf("%s\n", *vec);
        len++;
        vec++;
    }
    vec -= len;
}


// arr_len: get length of an array of strings
int arr_len(char **vec)
{
    int l = 0;
    while(*vec) {
        vec++;
        l++;
    }
    vec -= l;
    return l;
}
