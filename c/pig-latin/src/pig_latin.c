#include <ctype.h>
#include <stdbool.h>
#include <stdio.h>
#include <stdlib.h>
#include <string.h>


bool is_consonant(const char c) {
    switch (c) {
        case 'a':
        case 'e':
        case 'i':
        case 'o':
        case 'u':
            return false;
        default:
            return true;
    }
}


int translate_str(char *str, char *res) {
    int n;
    int i = 0;
    int j = 0;
    int l = strlen(str);
    char *consonants = malloc(l);
    char c;

    while ((c = str[j++]) != '\0') {
        bool is_u_after_q = (c == 'u' && consonants[i - 1] == 'q');
        bool is_y_break = (c == 'y' && i > 0);

        if ((is_consonant(c) && !is_y_break) || is_u_after_q) {
            consonants[i++] = c;
        } else {
            j--;
            break;
        }

        if (i == 2) {
            bool is_xr_start = (consonants[0] == 'x' && consonants[1] == 'r');
            bool is_yt_start = (consonants[0] == 'y' && consonants[1] == 't');
            if (is_xr_start || is_yt_start) {
                j = 0;
                i = 0;
                break;
            }
        }
    }

    consonants[i] = '\0';

    n = sprintf(res, "%s%s%s", str + j, consonants, "ay");

    free(consonants);

    return n;
}


char *translate(const char *phrase) {
    int l = strlen(phrase);

    char c;
    char *str = malloc(l);
    char *res = malloc(l + 2);

    int i = 0;
    int j = 0;
    int k = 0;

    while (true) {
        c = phrase[i++];
        if (isalnum(c)) {
            str[j++] = c;
        } else if (j) {
            str[j] = '\0'; j = 0;
            k += translate_str(str, res + k);
            if (c == '\0') break;
            res[k++] = ' ';
        }
    }

    free(str);

    return res;
}
