#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "gust.h"
#include <time.h>



#define MAX_GUST 1000

static struct Gust gust_data[MAX_GUST];
static int gust_count = 0;

void process_gust(char* line) {
    struct Gust gust;
    sscanf(line, "%ld,3,%lf,%lf", &gust.timestamp, &gust.prev, &gust.current);
    gust_data[gust_count++] = gust;
}

void print_gust_data() {
    int i;
    char time_str[20];
    printf("%-10s %-8s %-20s\n", "Date","Time", "Wind Change");
    for (i = 0; i < gust_count; i++) {
        strftime(time_str, sizeof(time_str), "%Y/%m/%d %H:%M:%S", localtime(&gust_data[i].timestamp));
        printf("%-20s", time_str);
        if (gust_data[i].current > gust_data[i].prev) {
            printf("Increasing\n");
        } else if (gust_data[i].current < gust_data[i].prev) {
            printf("Decreasing\n");
        } else {
            printf("Unchanged\n");
        }
    }
    printf("\n");
}