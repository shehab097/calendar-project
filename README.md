Here's the `README.md` documentation for your calendar program in C:

---

# Calendar Program

This C program generates a yearly calendar for a specified year, displaying each month in a structured, tabular format. The program considers leap years and correctly adjusts the days in February when applicable. It also uses Zeller's Congruence to determine the day of the week for January 1st of the specified year to start the calendar accurately.

## Features

- Displays the calendar month-by-month with proper day alignment.
- Adjusts February to 29 days in leap years.
- Calculates the starting day of each month to ensure correct alignment.
- Outputs each month with days arranged in weekly rows, starting from Sunday.

## Code Details

### Constants

- `TRUE` and `FALSE` are defined for Boolean values.
- Arrays for month names, day abbreviations, and monthly day counts are predefined.

### Functions and Logic

- **Leap Year Check**: The program first checks if the year is a leap year to determine the number of days in February.
- **Zeller's Congruence**: This algorithm determines the weekday for January 1st, allowing correct alignment for each month’s start.
- **Printing the Calendar**: For each month, the program:
  - Prints the month name centered.
  - Prints weekday headers.
  - Aligns the starting day and prints each day in a tabular layout.

## Code Explanation

The main components of the program include:

1. **Leap Year Check**:
   ```c
   if ((year % 4 == 0 && year % 100 != 0) || year % 400 == 0) {
       monthly_days[1] = 29;
   }
   ```
   Checks if the input year is a leap year and sets February's days to 29 if true.

2. **Calculating Start Day**:
   ```c
   int h = (q + 13 * (m + 1) / 5 + k + k / 4 + j / 4 + 5 * j) % 7;
   int start_day = (h + 5) % 7;
   ```
   Calculates the starting day for January 1st using Zeller's Congruence.

3. **Printing the Monthly Calendar**:
   ```c
   for (int day = 1; day <= monthly_days[i]; day++) {
       printf("%5d", day);
       start_day++;
       if (start_day % 7 == 0) {
           printf("\n");
       }
   }
   ```
   Iterates through the days of each month, aligning them to start on the correct weekday and adding line breaks at the end of each week.

## Example Output

The program displays output similar to this:

```
    January
   Sun   Mon   Tue   Wed   Thu   Fri   Sat
                        1     2     3     4
    5     6     7     8     9    10    11
...
```

## Usage

1. **Set the Year**: The year can be modified directly in the code (e.g., `int year = 2024;`).
2. **Compile and Run**:
   ```bash
   gcc calendar.c -o calendar
   ./calendar
   ```

## Requirements

- C compiler (GCC or similar)

