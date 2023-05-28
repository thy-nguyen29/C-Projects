/*
*****************************************************************************
                          Workshop - #5 (P2)
Full Name  : Thy Nguyen
Student ID#: 105310221
Email      : nnguyen90@myseneca.ca
Section    : NEE

Authenticity Declaration:
I declare this submission is the result of my own work and has not been
shared with any other student or 3rd party content provider. This submitted
piece of work is entirely of my own creation.
*****************************************************************************
*/

#define _CRT_SECURE_NO_WARNINGS

#include <stdio.h>
#define MIN_YEAR 2012 
#define MAX_YEAR 2022
#define LOG_DAYS 3

int main(void)
{
    const int JAN = 1, DEC = 12;
    int year, month, day;
    double morningRate, eveningRate;            // Morning Rating & Evening Rating
    double sumMorRate = 0, sumEveRate = 0;      // Summary of Morning Rating & Summary of Evening Rating

    printf("General Well-being Log\n"
        "======================\n");
    do
    {
        printf("Set the year and month for the well-being log (YYYY MM): ");
        scanf(" %4d %d", &year, &month);

        if (year > MAX_YEAR || year < MIN_YEAR)
        {  printf("   ERROR: The year must be between %4d and %4d inclusive\n", MIN_YEAR, MAX_YEAR);
        }
        if (month < 1 || month > 12)
        {  printf("   ERROR: Jan.(%d) - Dec.(%d)\n", JAN, DEC);
        }
    } while (year != 2022 || month != 2);
    printf("\n");
    printf("*** Log date set! ***\n");
    for (day = 1; day <= LOG_DAYS; day++)
    {
        printf("\n%4d-", year);
        if (month == 1)
        {printf("JAN");  }
        else if (month == 2)
        {printf("FEB");  }
        else if (month == 3)
        {printf("MAR");  }
        else if (month == 4)
        {printf("APR");  }
        else if (month == 5)
        {printf("MAY");  }
        else if (month == 6)
        {printf("JUN");  }
        else if (month == 7)
        {printf("JUL");  }
        else if (month == 8)
        {printf("AUG");  }
        else if (month == 9)
        {printf("SEP");  }
        else if (month == 10)
        {printf("OCT");  }
        else if (month == 11)
        {printf("NOV");  }
        else if (month == 12)
        {printf("DEC");  }
        printf("-%02d\n", day);
        do
        {
            printf("   Morning rating (0.0-5.0): ");
            scanf(" %lf", &morningRate);
            if (morningRate < 0.00 || morningRate > 5.00)
            {   printf("      ERROR: Rating must be between 0.0 and 5.0 inclusive!\n");
            }
        }while (morningRate < 0.00 || morningRate > 5.00);
        sumMorRate += morningRate;
        morningRate += morningRate;
        do
        {
            printf("   Evening rating (0.0-5.0): ");
            scanf(" %lf", &eveningRate);
            if (eveningRate < 0.00 || eveningRate > 5.00)
            {   printf("      ERROR: Rating must be between 0.0 and 5.0 inclusive!\n");
            }
        }  while (eveningRate < 0.00 || eveningRate > 5.00);
        sumEveRate += eveningRate;
        eveningRate += eveningRate;
    }
    printf("\nSummary\n"
        "=======\n");
    printf("Morning total rating: %.3lf\n", sumMorRate);
    printf("Evening total rating:  %.3lf\n", sumEveRate);
    printf("----------------------------\n");
    printf("Overall total rating: %.3lf\n\n", sumMorRate + sumEveRate);
    printf("Average morning rating:  %.1lf\n", sumMorRate / LOG_DAYS);
    printf("Average evening rating:  %.1lf\n", sumEveRate / LOG_DAYS);
    printf("----------------------------\n");
    printf("Average overall rating:  %.1lf\n", ((sumMorRate + sumEveRate) / LOG_DAYS) / 2); 
    return 0;
}
