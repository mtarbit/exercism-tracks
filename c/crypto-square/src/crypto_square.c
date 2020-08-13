#include <ctype.h>
#include <stdlib.h>
#include <string.h>
#include <math.h>

char *ciphertext(const char *input) {
    int i, j, l = strlen(input);
    char *alnums = calloc(l + 1, sizeof(char));

    for (i = 0, j = 0; i < l; i++) {
        if (isalnum(input[i])) {
            alnums[j++] = tolower(input[i]);
        }
    }

    int cols = ceil(sqrt(j));
    int rows = round(sqrt(j));

    int result_len = (cols * (rows + 1));
    char *result = calloc(result_len, sizeof(char));

    if (result_len) {
        memset(result, ' ', result_len - 1);

        for (int c = 0; c < cols; c++) {
            for (int r = 0; r < rows; r++) {
                i = (r * cols) + c;
                j = (c * (rows + 1)) + r;
                if (alnums[i]) {
                    result[j] = alnums[i];
                }
            }
        }
    }

    free(alnums);

    return result;
}
