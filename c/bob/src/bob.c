#include <ctype.h>
#include <string.h>
#include <stdbool.h>

const char *hey_bob(const char *message) {
    int l = strlen(message);
    char c;

    bool has_upper = false;
    bool has_lower = false;
    bool has_alnum = false;

    bool is_question = false;
    bool is_shouting = false;
    bool is_nonempty = false;

    for (int i = 0; i < l; i++) {
        if (isspace(message[i])) {
            continue;
        }

        c = message[i];

        has_upper |= isupper(c);
        has_lower |= islower(c);
        has_alnum |= isalnum(c);
    }

    if (c == '?') {
        is_question = true;
    }
    if (has_upper && !has_lower) {
        is_shouting = true;
    }
    if (has_alnum) {
        is_nonempty = true;
    }

    if (is_shouting && is_question) {
        return "Calm down, I know what I'm doing!";
    }
    if (is_shouting) {
        return "Whoa, chill out!";
    }
    if (is_question) {
        return "Sure.";
    }
    if (is_nonempty) {
        return "Whatever.";
    }

    return "Fine. Be that way!";
}
