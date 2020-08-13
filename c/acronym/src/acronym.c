#include <ctype.h>
#include <stdbool.h>
#include <stdio.h>
#include <stdlib.h>

void die(const char* msg) {
    fprintf(stderr, "Error: %s\n", msg);
    exit(EXIT_FAILURE);
}

char *abbreviate(const char *phrase)
{
    char c;
    int i = 0;
    int j = 0;
    char *result = NULL;

    if (phrase == NULL) {
        return NULL;
    }

    while (true) {
        c = phrase[i];

        if (!c) break;

        bool is_first = (i == 0);
        bool is_break = !isalpha(phrase[i-1]);
        bool is_contraction = (phrase[i-1] == '\'' && isalpha(phrase[i-2]));
        bool is_initial = (is_first || (is_break && !is_contraction));

        if (isalpha(c) && is_initial) {
            // Realloc with space for extra char and null terminator.
            result = realloc(result, sizeof(char) * (j + 2));

            if (result == NULL) die("Couldn't allocate memory.");

            result[j++] = toupper(c);
            result[j] = '\0';
        }

        i++;
    }

    return result;
}
