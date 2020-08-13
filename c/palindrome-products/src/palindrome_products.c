#include "palindrome_products.h"
#include <math.h>
#include <stdlib.h>
#include <stdio.h>

static factor_t *init_factor(void *next) {
    factor_t *f = malloc(sizeof(factor_t));

    f->factor_a = 0;
    f->factor_b = 0;
    f->next = next;

    return f;
}

static void *free_factor(factor_t *f) {
    if (f != NULL) {
        f->next = free_factor(f->next);
        free(f);
    }
    return NULL;
}

static factor_t *set_factor(factor_t *f, int a, int b, int c) {
    if (c == (f->factor_a * f->factor_b)) {
        f = init_factor((void *)f);
    } else {
        f->next = free_factor(f->next);
    }

    f->factor_a = a;
    f->factor_b = b;

    return f;
}

static product_t *init_product(void) {
    product_t *p = malloc(sizeof(product_t));

    p->smallest = -1;
    p->largest = -1;
    p->error = malloc(ERROR_MAX_LEN);
    p->factors_sm = init_factor((void *)NULL);
    p->factors_lg = init_factor((void *)NULL);

    return p;
}

void free_product(product_t *p) {
    p->factors_sm = free_factor(p->factors_sm);
    p->factors_lg = free_factor(p->factors_lg);
    free(p->error);
    free(p);
}

static int is_palindromic_number(int n) {
    int len = 1 + floor(log10(n));
    char buf[len + 1];

    snprintf(buf, len + 1, "%d", n);

    for (int i = 0; i < (len / 2); i++) {
        if (buf[i] != buf[len - (i + 1)]) {
            return 0;
        }
    }

    return 1;
}

product_t *get_palindrome_product(int min, int max) {
    int a, b, c;

    product_t *p = init_product();

    for (a = min; a <= max; a++) {
        for (b = a; b <= max; b++) {
            c = a * b;
            if (is_palindromic_number(c)) {
                if (p->smallest == -1 || p->smallest >= c) {
                    p->smallest = c;
                    p->factors_sm = set_factor(p->factors_sm, a, b, c);
                }
                if (p->largest == -1 || p->largest <= c) {
                    p->largest = c;
                    p->factors_lg = set_factor(p->factors_lg, a, b, c);
                }
            }
        }
    }

    if (min > max) {
        snprintf(p->error, ERROR_MAX_LEN, "invalid input: min is %d and max is %d", min, max);
    } else if (p->smallest == -1) {
        snprintf(p->error, ERROR_MAX_LEN, "no palindrome with factors in the range %d to %d", min, max);
    }

    return p;
}
