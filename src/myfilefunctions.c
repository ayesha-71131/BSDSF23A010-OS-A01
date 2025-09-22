#define _POSIX_C_SOURCE 200809L
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <ctype.h>

#include "myfilefunctions.h"

/* wordCount: counts lines, words, characters.
   Behavior: it rewinds file to start, scans to EOF, sets output params, and returns 0.
   Returns -1 on invalid args.
*/
int wordCount(FILE* file, int* lines, int* words, int* chars) {
    if (!file || !lines || !words || !chars) return -1;
    rewind(file);
    int c;
    int in_word = 0;
    int l = 0, w = 0, ch = 0;
    while ((c = fgetc(file)) != EOF) {
        ++ch;
        if (c == '\n') ++l;
        if (isspace((unsigned char)c)) {
            if (in_word) { ++w; in_word = 0; }
        } else {
            in_word = 1;
        }
    }
    if (in_word) ++w;
    *lines = l;
    *words = w;
    *chars = ch;
    return 0;
}

/* mygrep: scan file for lines containing search_str.
   On success, *matches will point to a malloc'd array of malloc'd strings.
   The caller is responsible for freeing matches[i] and free(*matches).
   Returns number of matches, or -1 on failure.
*/
int mygrep(FILE* fp, const char* search_str, char*** matches) {
    if (!fp || !search_str || !matches) return -1;
    rewind(fp);

    size_t capacity = 8;
    size_t count = 0;
    char** arr = malloc(capacity * sizeof(char*));
    if (!arr) return -1;

    char* line = NULL;
    size_t len = 0;
    ssize_t read;

    while ((read = getline(&line, &len, fp)) != -1) {
        if (strstr(line, search_str) != NULL) {
            if (count >= capacity) {
                capacity *= 2;
                char** tmp = realloc(arr, capacity * sizeof(char*));
                if (!tmp) {
                    /* cleanup */
                    for (size_t i = 0; i < count; ++i) free(arr[i]);
                    free(arr);
                    free(line);
                    return -1;
                }
                arr = tmp;
            }
            arr[count++] = strdup(line);
        }
    }
    free(line);
    *matches = arr;
    return (int)count;
}
