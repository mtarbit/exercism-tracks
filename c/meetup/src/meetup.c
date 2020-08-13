#include <time.h>
#include <string.h>
#include <stdio.h>

int meetup_day_of_month(int year, int mon, const char *desc, const char *day_name) {
    int n = 0;
    int d = 0;

    struct tm time = {
        .tm_year = year - 1900,
        .tm_mon = mon - 1,
        .tm_mday = 1
    };

    // Get a zero-based week number and/or adjust time:

    if (strcmp(desc, "teenth") == 0) {
        n = 0; time.tm_mday = 13;
    } else if (strcmp(desc, "first") == 0) {
        n = 0;
    } else if (strcmp(desc, "second") == 0) {
        n = 1;
    } else if (strcmp(desc, "third") == 0) {
        n = 2;
    } else if (strcmp(desc, "fourth") == 0) {
        n = 3;
    } else if (strcmp(desc, "fifth") == 0) {
        n = 4;
    } else if (strcmp(desc, "last") == 0) {
        n = -1; time.tm_mon += 1;
    }

    // Get a zero-based day number:

    if (strcmp(day_name, "Sunday") == 0) {
        d = 0;
    } else if (strcmp(day_name, "Monday") == 0) {
        d = 1;
    } else if (strcmp(day_name, "Tuesday") == 0) {
        d = 2;
    } else if (strcmp(day_name, "Wednesday") == 0) {
        d = 3;
    } else if (strcmp(day_name, "Thursday") == 0) {
        d = 4;
    } else if (strcmp(day_name, "Friday") == 0) {
        d = 5;
    } else if (strcmp(day_name, "Saturday") == 0) {
        d = 6;
    }

    // Evaluate the time struct to find out which week-day
    // the requested month starts on, then adjust forwards
    // or backwards to find the requested day of the month:

    mktime(&time);

    time.tm_mday -= time.tm_wday;
    time.tm_mday += time.tm_wday > d ? 7 : 0;
    time.tm_mday += d;
    time.tm_mday += n * 7;

    mktime(&time);

    // Return the new day-of-the-month so long as it's
    // valid (i.e. it matches the requested month):

    if (time.tm_mon == (mon - 1)) {
        return time.tm_mday;
    } else {
        return 0;
    }
}
