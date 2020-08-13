#ifndef PALINDROME_PRODUCTS_H
#define PALINDROME_PRODUCTS_H

#define ERROR_MAX_LEN 256

typedef struct factor_t {
    int factor_a;
    int factor_b;
    struct factor_t *next;
} factor_t;

typedef struct {
    int smallest;
    int largest;
    char *error;
    factor_t *factors_sm;
    factor_t *factors_lg;
} product_t;

product_t *get_palindrome_product(int min, int max);
void free_product(product_t *product);

#endif
