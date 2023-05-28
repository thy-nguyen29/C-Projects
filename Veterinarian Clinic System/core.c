/*
*****************************************************************************
                        Assignment 1 - Milestone 3
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
#include "core.h"

//////////////////////////////////////
// USER INTERFACE FUNCTIONS
//////////////////////////////////////

// Clear the standard input buffer
void clearInputBuffer(void)
{
    // Discard all remaining char's from the standard input buffer:
    while (getchar() != '\n')
    {
        ; // do nothing!
    }
}

// Wait for user to input the "enter" key to continue
void suspend(void)
{
    printf("<ENTER> to continue...");
    clearInputBuffer();
    putchar('\n');
}


//////////////////////////////////////
// USER INPUT FUNCTIONS
//////////////////////////////////////

int inputInt(void)
{
    char newLine = 'x';
    int value;
    while (newLine != '\n')
    {
        scanf(" %d%c", &value, &newLine);
        if (newLine != '\n')
        {
            clearInputBuffer();
            printf("Error! Input a whole number: ");
        }
    }
    return value;
}

int inputIntPositive(void)
{
    int value = inputInt();
    while (value < 1)
    {
        printf("ERROR! Value must be > 0: ");
        value = inputInt();
    }
    return value;
}

int inputIntRange(int lowerBound, int upperBound)
{
    int value = inputInt();
    while (value < lowerBound || value > upperBound)
    {
        printf("ERROR! Value must be between %d and %d inclusive: ", lowerBound, upperBound);
        value = inputInt();
    }
    return value;
}

char inputCharOption(const char *validLetter)
{
    char input = '\0';
    char nexInput = '\0';
    int i = 0; 
    int len = strlen(validLetter);
    int flag = 1;
    do
    {
        scanf(" %c%c", &input, &nexInput);
        if (nexInput == '\n')
        {
            for (i = 0; i < len; i++)
            {
                if (validLetter[i] == input)
                {
                    flag = 0;
                }
            }
        }
        else
        {
            printf("ERROR: Character must be one of [%s]: ", validLetter);
        }
    } while (flag == 1);
    return input;
}

void inputCString(char* input, int minLen, int maxLen)
{
    char tempInput[100];
    int len = 0;
    int flag = 1;
    int i = 0;

    do
    {   
        
        scanf(" %[^\n]", &tempInput);       
        clearInputBuffer();
        len = 0;
        while (tempInput[len] != '\0')
        {
            len++;
        }
        if (minLen == maxLen && len != minLen)
        {
            printf("Invalid 10-digit number! Number: ", minLen);
        }
        else if (len > maxLen)
        {
            printf("ERROR: String length must be no more than %d chars: ", maxLen);
        }
        else if (len < minLen)
        {
            printf("ERROR: String length must be between %d and %d chars: ", minLen, maxLen);
        }
        else
        {
            strcpy(input, tempInput);
            flag = 0;
        }
    } while (flag == 1);

    return tempInput;
}


//////////////////////////////////////
// UTILITY FUNCTIONS
//////////////////////////////////////

void displayFormattedPhone(const char* phoneNum)
{
    if (phoneNum == NULL)
    {
        printf("(___)___-____");
        return;
    }
    int i = 0;
    int count = 0;
    int len = strlen(phoneNum);
    for (i = 0; i < len; i++)
    {
        if (phoneNum[i] >= '0' && phoneNum[i] <= '9')
        {
            count++;
        }
    }
    if (len != 10 || len != count)
    {
        printf("(___)___-____");
    }
    else
    {
        printf("(%c%c%c)%c%c%c-%c%c%c%c",
            phoneNum[0],
            phoneNum[1],
            phoneNum[2],
            phoneNum[3],
            phoneNum[4],
            phoneNum[5],
            phoneNum[6],
            phoneNum[7],
            phoneNum[8],
            phoneNum[9]);
    }
}