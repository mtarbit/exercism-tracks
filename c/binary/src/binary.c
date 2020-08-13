#include "binary.h"

int convert(const char *s) {
    char c;
    int i = 0;
    int n = 0;

    while ((c = s[i++]) != '\0') {
        if (c != '0' && c != '1') {
            n = INVALID; break;
        }

        n <<= 1;

        if (c == '1') {
            n++;
        }
    }

    return n;
}
