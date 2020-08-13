#include <stdio.h>
#include <stdlib.h>

char *count(const char *dna_strand) {
    int a[4] = { 0 };
    char *p = (char *)dna_strand;
    char *s = malloc(32);

    while (*p) {
        if      (*p == 'A') { a[0]++; }
        else if (*p == 'C') { a[1]++; }
        else if (*p == 'G') { a[2]++; }
        else if (*p == 'T') { a[3]++; }
        else                { s[0] = '\0'; return s; }
        p++;
    }

    sprintf(s, "A:%d C:%d G:%d T:%d", a[0], a[1], a[2], a[3]);

    return s;
}
