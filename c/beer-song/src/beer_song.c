#include <stdio.h>
#include <stdbool.h>

#define BOTTLES 99
#define BOTTLE_SIZE 18
#define ACTION_SIZE 34

int bottle(char *s, int n, bool capitalize) {
    switch (n) {
        case 0:  return snprintf(s, BOTTLE_SIZE, "%co more bottles", (capitalize ? 'N' : 'n'));
        case 1:  return snprintf(s, BOTTLE_SIZE, "1 bottle");
        default: return snprintf(s, BOTTLE_SIZE, "%d bottles", n);
    }
}

int action(char *s, int n) {
    switch (n) {
        case 0:  return snprintf(s, ACTION_SIZE, "Go to the store and buy some more");
        case 1:  return snprintf(s, ACTION_SIZE, "Take it down and pass it around");
        default: return snprintf(s, ACTION_SIZE, "Take one down and pass it around");
    }
}

int verse(char *response, int n) {
    if (n < 0 || n > BOTTLES) return 0;

    char s_bottle_curr_a[BOTTLE_SIZE];
    char s_bottle_curr_b[BOTTLE_SIZE];
    char s_bottle_next[BOTTLE_SIZE];
    char s_action[ACTION_SIZE];

    bottle(s_bottle_curr_a, n, true);
    bottle(s_bottle_curr_b, n, false);
    bottle(s_bottle_next, (n ? (n - 1) : BOTTLES), false);
    action(s_action, n);

    return sprintf(
        response,
        "%s of beer on the wall, %s of beer.\n%s, %s of beer on the wall.\n",
        s_bottle_curr_a,
        s_bottle_curr_b,
        s_action,
        s_bottle_next
    );
}

void sing(char *response, int n, int m) {
    for (int i = n; i >= m; i--) {
        response += verse(response, i);
        if (i > m) *response++ = '\n';
    }
}
