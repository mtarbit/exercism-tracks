#include <stdio.h>
#include "clock.h"

#define CLOCK_FORMAT "%02d:%02d"

void clock(time_text_t time_text, int hour, int minute) {
    int minute_hours = minute / 60;

    minute %= 60;
    if (minute < 0) {
        minute += 60;
        minute_hours -= 1;
    }

    hour += minute_hours;
    hour %= 24;
    if (hour < 0) {
        hour += 24;
    }

    sprintf(time_text, CLOCK_FORMAT, hour, minute);
}

void clock_add(time_text_t time_text, int minute_offset) {
    int hour;
    int minute;
    sscanf(time_text, CLOCK_FORMAT, &hour, &minute);
    clock(time_text, hour, minute + minute_offset);
}
