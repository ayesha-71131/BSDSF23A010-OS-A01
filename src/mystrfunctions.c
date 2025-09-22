#include "mystrfunctions.h"

/* Implementations — simple, safe behaviors and clear return values:
   - mystrlen: returns length (int) of the string, 0 if s == NULL
   - mystrcpy: copies src into dest, returns number of chars copied (excluding '\0'), -1 on NULL
   - mystrncpy: copies up to n-1 characters and always null-terminates if n>0.
                returns number of chars copied (excluding '\0'), -1 on NULL or n<=0
   - mystrcat: appends src to dest, returns resulting length (excluding '\0'), -1 on NULL
*/

int mystrlen(const char* s) {
    if (!s) return 0;
    int len = 0;
    while (s[len]) ++len;
    return len;
}

int mystrcpy(char* dest, const char* src) {
    if (!dest || !src) return -1;
    int i = 0;
    while ((dest[i] = src[i]) != '\0') ++i;
    return i; /* number of characters copied (excluding null) */
}

int mystrncpy(char* dest, const char* src, int n) {
    if (!dest || !src || n <= 0) return -1;
    int i = 0;
    /* Copy at most n-1 chars so we can null-terminate safely */
    for (; i < n - 1 && src[i]; ++i) dest[i] = src[i];
    dest[i] = '\0';
    return i;
}

int mystrcat(char* dest, const char* src) {
    if (!dest || !src) return -1;
    int dlen = mystrlen(dest);
    int i = 0;
    while ((dest[dlen + i] = src[i]) != '\0') ++i;
    return dlen + i; /* resulting length excluding null */
}
