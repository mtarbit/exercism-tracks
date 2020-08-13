#include <ctype.h>
#include <stdbool.h>

bool is_isogram(const char phrase[])
{
    char c;
    int i, counts[26] = { 0 };

    if (phrase == NULL) {
        return false;
    }

    while (true) {
        c = tolower(*phrase++);
        i = (int)(c - 'a');

        if (!c) break;
        if (!isalpha(c)) continue;
        if (counts[i]) return false;

        counts[i]++;
    }

    return true;
}
