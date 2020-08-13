#include <ctype.h>
#include <stdbool.h>
#include <stdlib.h>
#include <string.h>
#include "anagram.h"

int compare_chars(const void *a, const void *b) {
    char ca = *(const char *)a;
    char cb = *(const char *)b;
    return (ca != cb) ? (ca < cb) ? -1 : 1 : 0;
}

char *get_comparable(const char *str, int len) {
    char *dup = malloc(len + 1);

    for (int i = 0; i <= len; i++) {
        dup[i] = tolower(str[i]);
    }

    qsort((void *)dup, len, sizeof(char), compare_chars);

    return dup;
}

bool is_anagram(const char *a, const char *b) {
    size_t a_len = strlen(a);
    size_t b_len = strlen(b);

    if (a_len != b_len || strcasecmp(a, b) == 0) {
        return false;
    }

    char *a_dup = get_comparable(a, a_len);
    char *b_dup = get_comparable(b, b_len);

    bool is_anagram = (strcmp(a_dup, b_dup) == 0);

    free(a_dup);
    free(b_dup);

    return is_anagram;
}

void anagrams_for(const char *word, struct candidates *candidates) {
    for (int i = 0; i < (int)candidates->count; i++) {
        if (is_anagram(word, candidates->candidate[i].candidate)) {
            candidates->candidate[i].is_anagram = IS_ANAGRAM;
        } else {
            candidates->candidate[i].is_anagram = NOT_ANAGRAM;
        }
    }
}
