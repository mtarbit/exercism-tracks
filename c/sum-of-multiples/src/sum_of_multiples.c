#include <stddef.h>

int sum_of_multiples(const unsigned int *multiples, int elements, int limit) {
    int n, m, i, sum = 0;

    if (multiples == NULL) {
        return sum;
    }

    for (n = 1; n < limit; n++) {
        for (i = 0; i < elements; i++) {
            m = multiples[i];
            if (m && (n % m == 0)) {
                sum += n; break;
            }
        }
    }

    return sum;
}
