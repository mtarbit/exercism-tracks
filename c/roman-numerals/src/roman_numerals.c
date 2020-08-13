#include <stdlib.h>
#include <stdio.h>
#include <string.h>
#include <math.h>

#define BUFFER_SIZE 22

int roman_digit(char *str, int digit, int value) {
    char *c;

    switch (value) {
        case    1: c = "IVX"; break;
        case   10: c = "XLC"; break;
        case  100: c = "CDM"; break;
        case 1000: memset(str, 'M', digit); return digit;
    }

    switch (digit) {
        case 0: return 0;
        case 1: return sprintf(str, "%c",       c[0]);
        case 2: return sprintf(str, "%c%c",     c[0], c[0]);
        case 3: return sprintf(str, "%c%c%c",   c[0], c[0], c[0]);
        case 4: return sprintf(str, "%c%c",     c[0], c[1]);
        case 5: return sprintf(str, "%c",       c[1]);
        case 6: return sprintf(str, "%c%c",     c[1], c[0]);
        case 7: return sprintf(str, "%c%c%c",   c[1], c[0], c[0]);
        case 8: return sprintf(str, "%c%c%c%c", c[1], c[0], c[0], c[0]);
        case 9: return sprintf(str, "%c%c",     c[0], c[2]);
    }

    return 0;
}

char *to_roman_numeral(int num) {
    int value;
    int digit;
    char *str = malloc(BUFFER_SIZE);
    char *ptr = str;

    if (num > 9999) return NULL;

    for (int i = 3; i >= 0; i--) {
        value = pow(10, i);
        digit = num / value;
        ptr += roman_digit(ptr, digit, value);
        num %= value;
    }

    *ptr = '\0';

    return str;
}
