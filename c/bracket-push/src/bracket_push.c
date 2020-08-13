#include <string.h>
#include "bracket_push.h"

bool is_paired(const char *input) {
    int depth = 0;
    char stack[strlen(input)];
    char c;
    short c_type;
    short c_open;

    while ((c = *input++) != '\0') {
        switch (c) {
            case '[': c_type =  0; c_open =  1; break;
            case ']': c_type =  0; c_open =  0; break;
            case '{': c_type =  1; c_open =  1; break;
            case '}': c_type =  1; c_open =  0; break;
            case '(': c_type =  2; c_open =  1; break;
            case ')': c_type =  2; c_open =  0; break;
            default:  c_type = -1; c_open = -1; break;
        }

        if (c_open == 1) {
            stack[depth++] = c_type;
        }

        if (c_open == 0) {
            if (depth == 0 || c_type != stack[--depth]) {
                return false;
            }
        }
    }

    return !depth;
}
