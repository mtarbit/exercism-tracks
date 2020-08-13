#include "space_age.h"

float convert_planet_age(float orbital_period, long age_seconds) {
    return age_seconds / (orbital_period * EARTH_YEAR_SECONDS);
}
