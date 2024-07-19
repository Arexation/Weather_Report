#ifndef WIND_H
#define WIND_H

#include <time.h>

struct Wind {
    time_t timestamp;
    double kmPerH;
    int degrees;
};

void process_wind(char* line);
void print_wind_data();

#endif