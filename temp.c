#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "temp.h"
#include <time.h>

#define MAX_TEMP 1000

static struct Temp temp_data[MAX_TEMP];
static int temp_count = 0;

void process_temp(char* line) {
    struct Temp temp;
    sscanf(line, "%ld,1,%lf", &temp.timestamp, &temp.celsius);
    temp_data[temp_count++] = temp;

}


void print_temp_data() {
    int i;
    char time_str[20];
    printf("%-10s %-8s %-10s\n", "Date","Time", "Celsius");
    for (i = 0; i < temp_count; i++) {
        strftime(time_str, sizeof(time_str), "%Y/%m/%d %H:%M:%S", localtime(&temp_data[i].timestamp));
        printf("%-20s%-10.2f\n", time_str, temp_data[i].celsius);
    }
    printf("\n");
}