#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <time.h>
#include "temp.h"
#include "wind.h"
#include "gust.h"

#define MAX_LINE_LENGTH 100

int main() {
    char line[MAX_LINE_LENGTH];
    long timestamp;
    int type;
    double value1, value2;
    char temp_line[100], wind_line[100], gust_line[100];

    while (fgets(line, sizeof(line), stdin) != NULL) {
        line[strcspn(line, "\n")] = 0;
        
        if (sscanf(line, "%ld,%i,%lf,%lf", &timestamp, &type, &value1, &value2)) {
            switch (type) {
                case 1:
                    sprintf(temp_line, "%ld,1,%f", timestamp, value1);
                    process_temp(temp_line);
                    break;
                case 2:
                    sprintf(wind_line, "%ld,2,%f,%f", timestamp, value1, value2);
                    process_wind(wind_line);
                    break;
                case 3:
                    sprintf(gust_line, "%ld,3,%f,%f", timestamp, value1, value2);
                    process_gust(gust_line);
                    break;
                default:
                    break;
            }
        } else {
            continue;
        }
    }
    print_temp_data();
    print_wind_data();
    print_gust_data();

    return 0;
}