#include <stddef.h>

int *binary_search(int val, int arr[], size_t length) {
    int cmp;
    size_t lft = 0;
    size_t idx = length / 2;
    size_t rgt = length;
    size_t idx_last = -1;

    if (arr == NULL || length == 0) {
        return NULL;
    }

    while (1) {
        cmp = arr[idx];

        if (val == cmp) {
            return arr + idx;
        } else if (val < cmp) {
            rgt = idx;
        } else if (val > cmp) {
            lft = idx;
        }

        idx = lft + ((rgt - lft) / 2);

        if (idx == idx_last) {
            return NULL;
        } else {
            idx_last = idx;
        }
    }
}
