#include <ctype.h>
#include <string.h>
#include "word_count.h"

int word_store(const char *word, word_count_word_t *words) {
    for (int i = 0; i < MAX_WORDS; i++) {
        // Found an unused entry:
        if (words[i].count == 0) {
            words[i].count = 1;
            strncpy(words[i].text, word, MAX_WORD_LENGTH + 1);
            return 1;
        }
        // Found a matching entry:
        if (strcmp(words[i].text, word) == 0) {
            words[i].count++;
            return 0;
        }
    }
    return 0;
}

int word_count(const char *input_text, word_count_word_t *words) {
    char c, c_prev, c_next;
    char word[MAX_WORD_LENGTH + 1];
    int i_min = 0;
    int i_max = strlen(input_text);
    int j = 0;
    int n = 0;

    // Mainly so we can check for .count == 0 in word_store:
    memset(words, 0, sizeof(word_count_word_t) * MAX_WORDS);

    for (int i = 0; ; i++) {
        c = input_text[i];
        c_prev = (i <= i_min) ? 0 : input_text[i - 1];
        c_next = (i >= i_max) ? 0 : input_text[i + 1];

        if (isalnum(c) || (c == '\'' && isalnum(c_prev) && isalnum(c_next))) {
            word[j++] = tolower(c);
            word[j] = '\0';
        } else if (j) {
            n += word_store(word, words);
            j = 0;
        }

        if (!c) break;

        if (j > MAX_WORD_LENGTH) {
            return EXCESSIVE_LENGTH_WORD;
        }

        if (n >= MAX_WORDS) {
            return EXCESSIVE_NUMBER_OF_WORDS;
        }
    }

    return n;
}
