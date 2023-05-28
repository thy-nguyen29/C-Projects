/*
*****************************************************************************
                          Workshop - #6 (P2)
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
#define maxNoItems 10
#include <stdio.h>

int main(void)
{
    const double minIncome = 500.00;
    const double maxIncome = 400000.00;
    double       cost[maxNoItems], netIncome, sum = 0;                           // Net Monthly Income, Summary of Items' costs.
    int          priority[maxNoItems], item, selection, i = 0, financeYes = 0;   // financeYes: item's finance status = 'y'
    char         finance[maxNoItems + 1];

    printf("+--------------------------+\n"
        "+   Wish List Forecaster   |\n"
        "+--------------------------+\n");
    // INCOME PART
    do
    {
        printf("\nEnter your monthly NET income: $");
        scanf(" %lf", &netIncome);
        if (netIncome < minIncome)
        {
            printf("ERROR: You must have a consistent monthly income of at least $%.2lf\n", minIncome);
        }
        if (netIncome > maxIncome)
        {
            printf("ERROR: Liar! I'll believe you if you enter a value no more than $%.2lf\n", maxIncome);
        }
    } while (netIncome < minIncome || netIncome > maxIncome);
    // WISH LIST PART
    do
    {
        printf("\nHow many wish list items do you want to forecast?: ");
        scanf(" %d", &item);
        if (item < 1 || item > maxNoItems)
        {
            printf("ERROR: List is restricted to between 1 and %d items.\n", maxNoItems);
        }
    } while (item < 1 || item > maxNoItems);
    i += item;
    // ITEMS LIST PART
    for (i = 0; i < item; i++)
    {
        printf("\nItem-%d Details:\n", i + 1);
        do
        {
            printf("   Item cost: $");
            scanf(" %lf", &cost[i]);
            if (cost[i] < 100.00)
            {
                printf("      ERROR: Cost must be at least $100.00\n");
            }
        } while (cost[i] < 100.00);
        do
        {
            printf("   How important is it to you? [1=must have, 2=important, 3=want]: ");
            scanf(" %d", &priority[i]);
            if (priority[i] < 1 || priority[i] > 3)
            {
            printf("      ERROR: Value must be between 1 and 3\n");
            }
        } while (priority[i] < 1 || priority[i] > 3);
        do
        {
            printf("   Does this item have financing options? [y/n]: ");
            scanf(" %c", &finance[i]);
            if (finance[i] != 'y' && finance[i] != 'n')
            {
                printf("      ERROR: Must be a lowercase 'y' or 'n'\n");
            }
        } while (finance[i] != 'y' && finance[i] != 'n');
    }
    // TABLE PART
    printf("\nItem Priority Financed        Cost\n"
        "---- -------- -------- -----------\n");
    for (i = 0; i < item; i++)
    {
        printf("%3d  %5d    %5c    %11.2lf\n", i + 1, priority[i], finance[i], cost[i]);
        sum += cost[i];
    }
    printf("---- -------- -------- -----------\n");
    printf("                      $%11.2lf\n", sum);
   
    // FORCASTING PART
    do
    {
        printf("\nHow do you want to forecast your wish list?\n"
            " 1. All items (no filter)\n"
            " 2. By priority\n"
            " 0. Quit/Exit\n");
        printf("Selection: ");
        scanf(" %d", &selection);
        if (selection == 1)
        {   

            printf("\n====================================================\n");
            printf("Filter:   All items\n");
            printf("Amount:   $%10.2lf\n", sum);
            printf("Forecast: %d years, %d months\n", ((int)(sum / netIncome) / 12), (((int)(sum / netIncome) % 12) + 1));
            for (i = 0; i < item; i++)
            {            
                if (priority[i] == 1 && finance[i] == 'y')
                {
                    financeYes = 1;
                }
            }
            if (financeYes == 1)
            {
                printf("NOTE: Financing options are available on some items.\n"
                    "      You can likely reduce the estimated months.\n");
            }
            printf("====================================================\n");
        }
        else if (selection == 2)
        {
            sum = 0;
            financeYes = 0;
            printf("\nWhat priority do you want to filter by? [1-3]: ");
            scanf(" %d", &priority[i]);
            printf("\n====================================================\n");
            printf("Filter:   by priority (%d)\n", priority[i]);
            if (priority[i] == 1)
            {
                for (i = 0; i < item; i++)
                {
                    if (priority[i] == 1)
                    {
                        sum += cost[i];                       
                    }
                    if (priority[i] == 1 && finance[i] == 'y')
                    {
                        financeYes = 1;
                    }
                }
                printf("Amount:   $%8.2lf\n", sum);
                printf("Forecast: %d years, %d months\n", ((int)(sum / netIncome) / 12), (((int)(sum / netIncome) % 12) + 1));
                if (financeYes == 1)
                {
                    printf("NOTE: Financing options are available on some items.\n"
                        "      You can likely reduce the estimated months.\n");
                }
            }
            else if (priority[i] == 2)
            {
                for (i = 0; i < item; i++)
                {
                    if (priority[i] == 2)
                    {
                        sum += cost[i];                    
                    }
                    if (priority[i] == 2 && finance[i] == 'y')
                    {
                        financeYes = 1;
                    }
                }
                printf("Amount:   $%9.2lf\n", sum);
                printf("Forecast: %d years, %d months\n", ((int)(sum / netIncome) / 12), (((int)(sum / netIncome) % 12) + 1));
                if (financeYes == 1)
                {
                    printf("NOTE: Financing options are available on some items.\n"
                        "      You can likely reduce the estimated months.\n");
                }
            }
            else if (priority[i] == 3)
            {
                for (i = 0; i < item; i++)
                {
                    if (priority[i] == 3)
                    {
                        sum += cost[i];                                        
                    }
                    if (priority[i] == 3 && finance[i] == 'y')
                    {
                        financeYes = 1;
                    }
                }
                printf("Amount:   $%10.2lf\n", sum);
                printf("Forecast: %d years, %d months\n", ((int)(sum / netIncome) / 12), (((int)(sum / netIncome) % 12) + 1));
                if (financeYes == 1)
                {
                    printf("NOTE: Financing options are available on some items.\n"
                        "      You can likely reduce the estimated months.\n");
                }
            }
            printf("====================================================\n");
        }
        else if (selection < 0 || selection > 2)
        {
            printf("\nERROR: Invalid menu selection.\n");
        }
    }while (selection != 0);
    printf("\nBest of luck in all your future endeavours!\n");   

    return 0;
}
