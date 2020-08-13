#include "triangle.h"

static bool is_triangle(triangle_t t) {
    if (t.a > 0 && t.b > 0 && t.c > 0) {
        if (t.a + t.b >= t.c &&
            t.b + t.c >= t.a &&
            t.c + t.a >= t.b) {
            return true;
        }
    }
    return false;
}

bool is_equilateral(triangle_t t) {
    return (is_triangle(t) && (t.a == t.b && t.b == t.c));
}

bool is_isosceles(triangle_t t) {
    return (is_triangle(t) && (t.a == t.b || t.b == t.c || t.c == t.a));
}

bool is_scalene(triangle_t t) {
    return (is_triangle(t) && (t.a != t.b && t.b != t.c && t.c != t.a));
}

