#include <ctype.h>
#include <stdlib.h>
#include <stdbool.h>

bool is_pangram(const char *sentence) {
    int i, n = 26;
    char c;
    bool letters[26] = { false };

    if (sentence == NULL) {
        return false;
    }

    while (true) {
        c = tolower(*sentence++);
        i = (int)(c - 'a');

        if (!c) break;
        if (!isalpha(c)) continue;

        if (letters[i] == false) {
            letters[i] = true;
            n--;
        }
    }

    return !n;
}
