#include <ctype.h>

static const int lookup[26] = {
 // A  B  C  D  E  F  G  H
    1, 3, 3, 2, 1, 4, 2, 4,
 // I  J  K  L  M  N  O  P  Q
    1, 8, 5, 1, 3, 1, 1, 3, 10,
 // R  S  T  U  V  W  X  Y  Z
    1, 1, 1, 1, 4, 4, 8, 4, 10,
};

int score(const char *s) {
    int n = 0;
    for (; *s != '\0'; s++) {
        n += lookup[toupper(*s) - 'A'];
    }
    return n;
}
