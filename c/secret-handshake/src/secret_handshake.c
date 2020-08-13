#include <stdlib.h>
#include <stdio.h>

void reverse(void **arr, int len) {
    int i, j;
    void *a_ptr, *b_ptr;

    for (i = 0; i < (len / 2); i++) {
        j = len - (i + 1);
        a_ptr = (void *)arr[i];
        b_ptr = (void *)arr[j];
        arr[i] = b_ptr;
        arr[j] = a_ptr;
    }
}

const char **commands(int n) {
    int i = 0;
    const char **actions = calloc(4, sizeof(char *));

    if (n &  1) actions[i++] = "wink";
    if (n &  2) actions[i++] = "double blink";
    if (n &  4) actions[i++] = "close your eyes";
    if (n &  8) actions[i++] = "jump";
    if (n & 16) reverse((void **)actions, i);

    return actions;
}
