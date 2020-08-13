#include <math.h>
#include <stdbool.h>
#include "sieve.h"

unsigned int sieve(const unsigned int limit, primes_array_t primes) {
    bool values[limit];
    unsigned int i, j;
    unsigned int values_index = 0;
    unsigned int primes_index = 0;

    for (i = 2; i <= limit; i++) {
        values[i] = true;
    }

    for (i = 2; i <= sqrt(limit); i++) {
        if (values[i]) {
            for (j = 0; j <= limit; j++) {
                if ((values_index = (i * i) + (i * j)) > limit) {
                    break;
                } else {
                    values[values_index] = false;
                }
            }
        }
    }

    for (i = 2; i <= limit; i++) {
        if (values[i]) {
            primes[primes_index++] = i;
        }
    }

    return primes_index;
}
