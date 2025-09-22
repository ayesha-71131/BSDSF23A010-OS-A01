#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#include "mystrfunctions.h"
#include "myfilefunctions.h"

int main(void) {
    /* Test string functions */
    char dst[128];
    int n;

    n = mystrcpy(dst, "Hello");
    printf("mystrcpy -> copied %d chars, dst=\"%s\"\n", n, dst);

    n = mystrncpy(dst, "Multifile Test", sizeof(dst));
    printf("mystrncpy -> copied %d chars, dst=\"%s\"\n", n, dst);

    n = mystrcat(dst, " ++ appended");
    printf("mystrcat -> resulting length %d, dst=\"%s\"\n", n, dst);

    printf("mystrlen(\"%s\") = %d\n", dst, mystrlen(dst));

    /* Create sample file for testing file functions */
    const char* sample_name = "sample_test.txt";
    FILE* out = fopen(sample_name, "w");
    if (!out) {
        perror("fopen for sample file");
        return 1;
    }
    fprintf(out, "This is line one.\n");
    fprintf(out, "Second line with test word.\n");
    fprintf(out, "Third line: another test.\n");
    fclose(out);

    FILE* in = fopen(sample_name, "r");
    if (!in) {
        perror("fopen for reading");
        return 1;
    }

    int lines = 0, words = 0, chars = 0;
    if (wordCount(in, &lines, &words, &chars) == 0) {
        printf("wordCount -> lines=%d, words=%d, chars=%d\n", lines, words, chars);
    } else {
        printf("wordCount failed\n");
    }

    char** matches = NULL;
    int found = mygrep(in, "test", &matches);
    if (found >= 0) {
        printf("mygrep -> found %d matching lines:\n", found);
        for (int i = 0; i < found; ++i) {
            printf("MATCH[%d]: %s", i, matches[i]);
            free(matches[i]);
        }
        free(matches);
    } else {
        printf("mygrep failed\n");
    }

    fclose(in);
    printf("All tests finished. Remove sample file '%s' if you want.\n", sample_name);
    return 0;
}
