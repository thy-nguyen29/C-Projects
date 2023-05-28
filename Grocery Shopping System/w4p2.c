/*
*****************************************************************************
                          Workshop - #4 (P2)
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

int main(void)

{
    int apples = 0, oranges = 0, pears = 0, tomatoes = 0, cabbages = 0;
    int total = (apples + oranges + pears + tomatoes + cabbages);
    int pickApples = 0, pickOranges = 0, pickPears = 0, pickTomatoes = 0, pickCabbages = 0;
    int i;
    do
    {
            printf("Grocery Shopping"
            "\n================");
        do
        {
            printf("\nHow many APPLES do you need? : ");
            scanf(" %d", &apples);
            if (apples < 0)
                printf("ERROR: Value must be 0 or more.");
        } while (apples < 0);
        do
        {
            printf("\nHow many ORANGES do you need? : ");
            scanf(" %d", &oranges);
            if (oranges < 0)
                printf("ERROR: Value must be 0 or more.");
        } while (oranges < 0);
        do
        {
            printf("\nHow many PEARS do you need? : ");
            scanf(" %d", &pears);
            if (pears < 0)
                printf("ERROR: Value must be 0 or more.");
        } while (pears < 0);
        do
        {
            printf("\nHow many TOMATOES do you need? : ");
            scanf(" %d", &tomatoes);
            if (tomatoes < 0)
                printf("ERROR: Value must be 0 or more.");
        } while (tomatoes < 0);
        do
        {
            printf("\nHow many CABBAGES do you need? : ");
            scanf(" %d", &cabbages);
            if (cabbages < 0)
                printf("ERROR: Value must be 0 or more.");
        } while (cabbages < 0);

        // Picking products section

        printf("\n--------------------------"
            "\nTime to pick the products!"
            "\n--------------------------");
        printf("\n");
        while (apples >= 1)
        {   
            printf("\nPick some APPLES... how many did you pick? : ");
            scanf(" %d", &pickApples);
            if (pickApples < 1)
            {
                printf("ERROR: You must pick at least 1!");
            }
            else if (pickApples > apples)
            {
                printf("You picked too many... only %d more APPLE(S) are needed.", apples);
            }
            else if (pickApples < apples)
            {
                printf("Looks like we still need some APPLES...");
                apples -= pickApples;
            }
            else if (pickApples = apples)
            {
                printf("Great, that's the apples done!");
                apples -= pickApples;
            }
        }
        printf("\n");
        while (pears >= 1)
        {
            printf("\nPick some PEARS... how many did you pick? : ");
            scanf(" %d", &pickPears);
            if (pickPears < 1)
            {
                printf("ERROR: You must pick at least 1!");
            }
            else if (pickPears > pears)
            {
                printf("You picked too many... only %d more PEAR(S) are needed.", pears);
            }
            else if (pickPears < pears)
            {
                printf("Looks like we still need some PEARS...");
                pears -= pickPears;
            }
            else if (pickPears = pears)
            {
                printf("Great, that's the pears done!");
                pears -= pickPears;
            }
        }
        printf("\n");
        while (cabbages >= 1)
        {
            printf("\nPick some CABBAGES... how many did you pick? : ");
            scanf(" %d", &pickCabbages);
            if (pickCabbages < 1)
            {
                printf("ERROR: You must pick at least 1!");
            }
            else if (pickCabbages > cabbages)
            {
                printf("You picked too many... only %d more CABBAGE(S) are needed.", cabbages);
            }
            else if (pickCabbages < cabbages)
            {
                printf("Looks like we still need some CABBAGES...");
                cabbages -= pickCabbages;
            }
            else if (pickCabbages = cabbages)
            {
                printf("Great, that's the cabbages done!");
                cabbages -= pickCabbages;
            }
        }
        printf("\n");
        while (oranges >= 1)
        {
            printf("\nPick some ORANGES... how many did you pick? : ");
            scanf(" %d", &pickOranges);
            if (pickOranges < 1)
            {
                printf("ERROR: You must pick at least 1!");
            }
            else if (pickOranges > oranges)
            {
                printf("You picked too many... only %d more ORANGE(S) are needed.", oranges);
            }
            else if (pickOranges < oranges)
            {
                printf("Looks like we still need some ORANGES...");
                oranges -= pickOranges;
            }
            else if (pickOranges = oranges)
            {
                printf("Great, that's the oranges done!");
                oranges -= pickOranges;
            }
        }
        printf("\n");
        while (tomatoes >= 1)
        {
            printf("\nPick some TOMATOES... how many did you pick? : ");
            scanf(" %d", &pickTomatoes);
            if (pickTomatoes < 1)
            {
                printf("ERROR: You must pick at least 1!");
            }
            else if (pickTomatoes > tomatoes)
            {
                printf("You picked too many... only %d more TOMATO(ES) are needed.", tomatoes);
            }
            else if (pickTomatoes < tomatoes)
            {
                printf("Looks like we still need some TOMATOES...");
                tomatoes -= pickTomatoes;
            }
            else if (pickTomatoes = tomatoes)
            {
                printf("Great, that's the tomatoes done!");
                tomatoes -= pickTomatoes;
            }
        }
            printf("\n\n");
            printf("All the items are picked!");
            printf("\n\nDo another shopping? (0=NO): ");
            scanf(" %d", &i);
            printf("\n");
    }while (i != 0);

    printf("\nYour tasks are done for today - enjoy your free time!\n");

    return 0;
} 
