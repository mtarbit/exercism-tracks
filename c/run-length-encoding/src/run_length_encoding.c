#include <ctype.h>
#include <math.h>
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

char *encode(const char *str) {
    char c;
    int len = strlen(str) + 1;
    int num = 1;
    int res_idx = 0;
    char *res = calloc(len, sizeof(char));

    while ((c = *str++) != '\0') {
        if (c == *str) {
            num++;
        } else if (num > 1) {
            res_idx += sprintf(res + res_idx, "%d%c", num, c);
            num = 1;
        } else {
            res[res_idx++] = c;
        }
    }

    return res;
}

char *decode(const char *str) {
    char c;
    int len = strlen(str) + 1;
    int num = 1;
    int buf_idx = 0;
    int res_idx = 0;
    int new_idx = 0;
    char *buf = malloc(len);
    char *res = malloc(len);

    while ((c = *str++) != '\0') {
        if (isdigit(c)) {
            buf[buf_idx++] = c;
        } else {
            buf[buf_idx] = '\0';
            num = ((buf_idx) ? atoi(buf) : 1);

            new_idx = res_idx + num;
            if (new_idx >= len) {
                len = fmax((new_idx + 1), len * 2);
                res = realloc(res, len);
            }

            memset(res + res_idx, c, num);

            res_idx = new_idx;
            buf_idx = 0;
        }
    }

    res[res_idx] = '\0';

    free(buf);

    return res;
}
