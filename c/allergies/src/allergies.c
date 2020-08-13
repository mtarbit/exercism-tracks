#include <stdlib.h>
#include "allergies.h"

bool is_allergic_to(allergen_t allergen, int score) {
    return score & (1 << allergen);
}

void get_allergens(int score, allergen_list_t *list) {
    list->count = 0;
    list->allergens = malloc(sizeof(allergen_t) * ALLERGEN_COUNT);

    for (int i = 0; i < ALLERGEN_COUNT; i++) {
        if (is_allergic_to(i, score)) {
            list->allergens[list->count++] = (allergen_t)i;
        }
    }
}
