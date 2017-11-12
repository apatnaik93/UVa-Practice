#include <time.h>
#include <stdio.h>

int main() {
    int y = 2008;
    int m = 01;
    int d = 23;
    int skip = 280;

    // Represent the date as struct tm.                                                           
    // The subtractions are necessary for historical reasons.
    struct tm  t = { 0 };
    t.tm_mday = d;
    t.tm_mon = m-1;
    t.tm_year = y-1900;

    // Add 'skip' days to the date.                                                               
    t.tm_mday += skip;
    mktime(&t);

    // Print the date in ISO-8601 format.                                                         
    char buffer[30];
    strftime(buffer, 30, "%Y-%m-%d", &t);
    puts(buffer);
}
