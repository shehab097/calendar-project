#include <stdio.h>

#define TRUE 1
#define FALSE 0

int main() {
    char months_name[12][10] = { "January","February","March","April","May","June","July","August","September","October","November","December" };
    char weekly_dayes[7][4] = { "Sun","Mon","Tue","Wed","Ths","Fri" ,"Sat" };
    int monthly_days[12] = { 31,28,31,30,31,30,31,31,30,31,30,31 };
    int year = 2024;


    //leap year check
    if ((year % 4 == 0 && year % 100 != 0) || year % 400 == 0) {
        monthly_days[1] = 29; //february 29 day -leap year
    }

    // Zeller's Congruence to determine the day of the week for Jan 1st of the year
    int q = 1;  // day of the month
    int m = 13; // January as month 13 in the previous year (for Zeller's formula)
    int k = (year - 1) % 100; // last two digits of the (year )
    int j = (year - 1) / 100; // first two digits of the (year )
    int h = (q + 13 * (m + 1) / 5 + k + k / 4 + j / 4 + 5 * j) % 7;
    int start_day = (h + 5) % 7; // Adjust to make Sunday = 0


    for (int i = 0;i < 12;i++) {
        printf("\n%10s\n", months_name[i]);

        // Print week days
        for (int j = 0;j < 7;j++) {
            printf("%5s", weekly_dayes[j]);
        }
        printf("\n");

        // Print leading spaces for the first day
        for (int j = 0;j < start_day;j++) {
            printf("     ");
        }

        // Print days of the month
        for (int day = 1;day <= monthly_days[i];day++) {
            printf("%5d", day);
            start_day++;


            // Line break at the end of each week
            if (start_day % 7 == 0) {
                printf("\n");
            }
        }

        // Update starting day for the next month
        start_day = start_day % 7;
        printf("\n\n");

    }

    return 0;
}