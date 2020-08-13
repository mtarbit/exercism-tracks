#include "leap.h"

bool is_leap_year(int y) {
    bool div_4   = (y %   4 == 0);
    bool div_100 = (y % 100 == 0);
    bool div_400 = (y % 400 == 0);

    return (div_4 && (!div_100 || div_400));
}
