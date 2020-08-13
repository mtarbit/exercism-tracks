#include <math.h>
#include "complex_numbers.h"

complex_t c_add(complex_t a, complex_t b)
{
    complex_t c;
    c.real = a.real + b.real;
    c.imag = a.imag + b.imag;
    return c;
}

complex_t c_sub(complex_t a, complex_t b)
{
    complex_t c;
    c.real = a.real - b.real;
    c.imag = a.imag - b.imag;
    return c;
}

complex_t c_mul(complex_t a, complex_t b)
{
    complex_t c;
    c.real = (a.real * b.real) - (a.imag * b.imag);
    c.imag = (a.imag * b.real) + (a.real * b.imag);
    return c;
}

complex_t c_div(complex_t a, complex_t b)
{
    complex_t c;
    c.real = ((a.real * b.real) + (a.imag * b.imag)) / ((b.real * b.real) + (b.imag * b.imag));
    c.imag = ((a.imag * b.real) - (a.real * b.imag)) / ((b.real * b.real) + (b.imag * b.imag));
    return c;
}

double c_abs(complex_t x)
{
    return sqrt((x.real * x.real) + (x.imag * x.imag));
}

complex_t c_conjugate(complex_t x)
{
    complex_t c;
    c.real = x.real;
    c.imag = -x.imag;
    return c;
}

double c_real(complex_t x)
{
    return x.real;
}

double c_imag(complex_t x)
{
    return x.imag;
}

complex_t c_exp(complex_t x)
{
    complex_t a;
    complex_t b;

    a.real = exp(x.real);
    a.imag = 0.0;

    b.real = cos(x.imag);
    b.imag = sin(x.imag);

    return c_mul(a, b);
}
