#include <stdio.h>
#include "hamming.h"

int main(int argc, char *argv[]) {
    printf("hamming distance: %d\n", compute("abcdef", "acxdef"));
    return 0;
}
