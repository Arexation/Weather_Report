#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "wind.h"
#include <time.h>

#define MAX_WIND 1000

static struct Wind wind_data[MAX_WIND];
static int wind_count = 0;

void process_wind(char* line) {
    struct Wind wind;
    sscanf(line, "%ld,2,%lf,%d", &wind.timestamp, &wind.kmPerH, &wind.degrees);
    wind_data[wind_count++] = wind;
}

void print_wind_data() {
    int i;
    char time_str[20];
    printf("%-10s %-8s %-4s %-2s\n", "Date","Time", "Speed", "Direction");
    for (i = 0; i < wind_count; i++) {
        strftime(time_str, sizeof(time_str), "%Y/%m/%d %H:%M:%S", localtime(&wind_data[i].timestamp));
        printf("%s %.2f %d\n", time_str, wind_data[i].kmPerH, wind_data[i].degrees);
    }
    printf("\n");
}