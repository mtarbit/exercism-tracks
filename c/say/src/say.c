#include <math.h>
#include <stdio.h>
#include <stdlib.h>

// The longest supported answer is, e.g:
// -------------------------------------
// seven hundred seventy-seven billion
// seven hundred seventy-seven million
// seven hundred seventy-seven thousand
// seven hundred seventy-seven

#define ANSWER_MAX_LEN 136

int say(long num, char **ans) {
    char *ones[]  = {"zero", "one", "two", "three", "four", "five", "six", "seven", "eight", "nine"};
    char *teens[] = {"ten", "eleven", "twelve", "thirteen", "fourteen", "fifteen", "sixteen", "seventeen", "eighteen", "nineteen"};
    char *tens[]  = {"zero", "ten", "twenty", "thirty", "forty", "fifty", "sixty", "seventy", "eighty", "ninety"};
    char *zeros[] = {"hundred", "thousand", "million", "billion"};

    char *s = *ans = malloc(ANSWER_MAX_LEN + 1);
    long n = num;
    int m, p;

    if (n < 0 || n >= 1000000000000) return -1;

    for (int i = 3; i >= 0; i--) {
        p = pow(10, 3 * i);
        m = n / p;
        n = n % p;

        if (m >= 100) {
            s += sprintf(s, "%s %s ", ones[m / 100], zeros[0]);
            m %= 100;
        }

        if (m >= 20) {
            s += sprintf(s, "%s", tens[m / 10]);
            m %= 10;
            s += sprintf(s, m ? "-" : " ");
        }

        if (m >= 10) {
            s += sprintf(s, "%s ", teens[m - 10]);
        } else if (m > 0 || (i == 0 && num == 0)) {
            s += sprintf(s, "%s ", ones[m]);
        }

        if (m && i) {
            s += sprintf(s, "%s ", zeros[i]);
        }

    }

    *(--s) = '\0';

    return 0;
}
