#include <stdlib.h>
#include <stddef.h>
#include <stdio.h>

static size_t **init_triangle(int n) {
    size_t **result;
    result = malloc(n * sizeof(size_t *));
    for (int i = 0; i < n; i++) {
        result[i] = calloc(n, sizeof(size_t));
    }
    return result;
}

void free_triangle(size_t **result, int n) {
    if (n == 0) n = 1;
    for (int i = 0; i < n; i++) {
        free(result[i]);
    }
    free(result);
}

size_t **create_triangle(int n) {
    size_t **result;
    size_t value, value_lft, value_rgt;
    int r, c;

    if (n < 0) {
        return NULL;
    }

    if (n) {
        result = init_triangle(n);
    } else {
        result = init_triangle(1);
    }

    for (r = 0; r < n; r++) {
        for (c = 0; c < n; c++) {
            if (r || c) {
                value_lft = (r && c) ? result[r - 1][c - 1] : 0;
                value_rgt = (r     ) ? result[r - 1][c    ] : 0;
                value = value_lft + value_rgt;
            } else {
                value = 1;
            }
            result[r][c] = value;
        }
    }

    return result;
}
