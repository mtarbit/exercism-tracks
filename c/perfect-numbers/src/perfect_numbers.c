#include "perfect_numbers.h"

kind classify_number(int n) {
    int total = 0;

    if (n <= 0) {
        return ERROR;
    }

    for (int m = 1; m <= (n / 2); m++) {
        if (n % m == 0) {
            total += m;
        }
    }

    if (total == n) {
        return PERFECT_NUMBER;
    } else if (total > n) {
        return ABUNDANT_NUMBER;
    } else if (total < n) {
        return DEFICIENT_NUMBER;
    }

    return ERROR;
}

