#ifndef PASCALS_TRIANGLE_H
#define PASCALS_TRIANGLE_H

#include <stddef.h>

size_t **create_triangle(int n);
void free_triangle(size_t **result, int n);

#endif
