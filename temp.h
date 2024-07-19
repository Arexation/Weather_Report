#ifndef TEMP_H
#define TEMP_H

#include <time.h>

struct Temp {
    time_t timestamp;
    double celsius;
};

void process_temp(char* line);
void print_temp_data();

#endif