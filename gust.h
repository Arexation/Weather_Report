#ifndef GUST_H
#define GUST_H

#include <time.h>

struct Gust {
    time_t timestamp;
    double prev;
    double current;
};

void process_gust(char* line);
void print_gust_data();

#endif