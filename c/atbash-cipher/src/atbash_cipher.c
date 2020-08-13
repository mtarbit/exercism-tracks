#include <ctype.h>
#include <string.h>
#include <stdio.h>
#include <stdlib.h>

char *atbash_encode(char *input) {
    int n = 0;
    int l = strlen(input);
    char *result = malloc(l + (l / 5) + 1);
    char *p = result;
    char c;

    while ((c = *input++) != '\0') {
        if (isalnum(c) == 0) continue;
        if (isalpha(c)) {
            c = tolower(c);
            c = 'z' - (c - 'a');
        }
        if (n && n % 5 == 0) {
            *p++ = ' ';
        }
        *p++ = c;
        n++;
    }

    *p = '\0';

    return result;
}

char *atbash_decode(char *input) {
    char *result = malloc(strlen(input) + 1);
    char *p = result;
    char c;

    while ((c = *input++) != '\0') {
        if (isalnum(c) == 0) continue;
        if (isalpha(c)) {
            c = 'a' + ('z' - c);
        }
        *p++ = c;
    }

    *p = '\0';

    return result;
}
