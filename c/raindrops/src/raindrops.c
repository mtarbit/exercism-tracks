#include <stdio.h>
#include <stdbool.h>

void convert(char *result, int drops) {
    bool div_3 = (drops % 3 == 0);
    bool div_5 = (drops % 5 == 0);
    bool div_7 = (drops % 7 == 0);

    if (div_3 || div_5 || div_7) {
        if (div_3) {
            result += sprintf(result, "Pling");
        }
        if (div_5) {
            result += sprintf(result, "Plang");
        }
        if (div_7) {
            result += sprintf(result, "Plong");
        }
    } else {
        result += sprintf(result, "%d", drops);
    }
}
