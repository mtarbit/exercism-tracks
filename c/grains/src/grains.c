#include "grains.h"

#define SQUARE_MIN 1
#define SQUARE_MAX 64

uint64_t square(int n) {
    if (n < SQUARE_MIN || n > SQUARE_MAX) {
        return 0;
    } else {
        return 1ULL << (n - 1);
    }
}

uint64_t total(void) {
    uint64_t n = 0;
    for (int i = SQUARE_MIN; i <= SQUARE_MAX; i++) {
        n += square(i);
    }
    return n;
}
