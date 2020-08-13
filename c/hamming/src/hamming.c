#include <stddef.h>

int compute(const char *a, const char *b) {
    int n = 0;

    if (a == NULL || b == NULL) {
        return -1;
    }

    while (1) {
        if (!*a && !*b) break;
        if (!*a || !*b) return -1;

        if (*a++ != *b++) {
            n++;
        }
    }

    return n;
}
