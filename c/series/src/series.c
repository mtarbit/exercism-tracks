#include <stdlib.h>
#include <string.h>
#include "series.h"

series_results_t series(char *input_text, unsigned int substring_length) {
    unsigned int i, j;
    unsigned int len = strlen(input_text);
    unsigned int num = 0;

    if (substring_length && substring_length <= len) {
        num = (len - (substring_length - 1));
    }

    char **substrings = calloc(num, sizeof(char *));
    series_results_t results = {num, &substrings[0]};

    for (i = 0; i < num; i++) {
        substrings[i] = calloc(substring_length + 1, sizeof(char));
        for (j = 0; j < substring_length; j++) {
            substrings[i][j] = input_text[i + j];
        }
        substrings[i][j] = '\0';
    }

    return results;
}
