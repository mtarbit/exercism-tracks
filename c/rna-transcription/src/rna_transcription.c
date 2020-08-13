#include <string.h>
#include <stdlib.h>

char *to_rna(const char *dna) {
    int n = strlen(dna);
    char *rna = malloc(n + 1);
    char c;

    for (int i = 0; i < n; i++) {
        c = dna[i];

        if      (c == 'G') { c = 'C'; }
        else if (c == 'C') { c = 'G'; }
        else if (c == 'T') { c = 'A'; }
        else if (c == 'A') { c = 'U'; }
        else               { return NULL; }

        rna[i] = c;
    }

    rna[n] = '\0';

    return rna;
}
