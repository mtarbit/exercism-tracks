#include <ctype.h>
#include <stdlib.h>
#include <string.h>

#define NANP_DIGITS 10

char *phone_number_clean(const char *input) {
    char *result = malloc(NANP_DIGITS + 1);
    char c;
    int i = 0;

    while ((c = *input++) != '\0') {
        if (isdigit(c)) {
            if (i == 0 && c == '1') continue;
            if (i == 0 && c <= '1') break;
            if (i == 3 && c <= '1') break;
            result[i++] = c;
        }
    }

    if (i != NANP_DIGITS) {
        memset(result, '0', NANP_DIGITS);
    }

    result[NANP_DIGITS] = '\0';

    return result;
}
