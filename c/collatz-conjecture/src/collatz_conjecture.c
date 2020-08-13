#include "collatz_conjecture.h"

int steps(int start) {
    int steps;

    if (start <= 0) {
        return ERROR_VALUE;
    }

    for (steps = 0; start != 1; steps++) {
        if (start % 2 == 0) {
            start = start / 2;
        } else {
            start = start * 3 + 1;
        }
    }

    return steps;
}
