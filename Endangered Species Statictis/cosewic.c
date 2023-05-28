#define _CRT_SECURE_NO_WARNINGS

#include <stdio.h>
#include <string.h>
#include <stdlib.h>

#include "cosewic.h"

#define STARTING_YEAR 2010
#define ENDING_YEAR 2019

/************************************/
/*      USER INPUT FUNCTIONS       */
/**********************************/

void clearInputBuffer(void)
{
    // Discard all remaining char's from the standard input buffer:
    while (getchar() != '\n')
    {
        ; // do nothing!
    }
}

int inputIntRange(int lowerBound, int upperBound)
{
    int value = inputInt();
    if (value < lowerBound || value > upperBound)
    {
        
        printf("\nInvalid menu selection!\n");
    }
    return value;
}

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
            printf("Invalid menu selection!");
        }
    }
    return value;
}


/************************************/
/*         FILE FUNCTIONS          */
/**********************************/


int loadData(char* DATA_FILE, FileData *data, int MAX_RECORDS) 
{
    int i;
    int temp = 0;
    int records = 0;
    FILE* file = NULL;
    file = fopen(DATA_FILE, "r");
    

    if (file != NULL) 
    {  
        fscanf(file, "%*[^\n]\n");
        for (i = 0; i < MAX_RECORDS; i++)
        {
            if (fscanf(file, "%d,%[^,],%[^,],%d,%[^\n]\n", 
                &data[i].year, data[i].taxOn, data[i].status, &data[i].countData, data[i].province) > 0)
            {
                records++;
            }
            if (data[temp].province[0] == 'A') strcpy(data[temp].province, "Alberta");
            else if (data[temp].province[0] == 'B') strcpy(data[temp].province, "British Columbia");
            else if (data[temp].province[0] == 'M') strcpy(data[temp].province, "Manitoba");
            else if (data[temp].province[0] == 'O') strcpy(data[temp].province, "Ontario");
            else if (data[temp].province[0] == 'P') strcpy(data[temp].province, "Prince Edward Island");
            else if (data[temp].province[0] == 'Q') strcpy(data[temp].province, "Quebec");
            else if (data[temp].province[0] == 'S') strcpy(data[temp].province, "Saskatchewan");
            else if (data[temp].province[0] == 'Y') strcpy(data[temp].province, "Yukon Territory");
            else if (data[temp].province[1] == 'B') strcpy(data[temp].province, "New Brunswick");
            else if (data[temp].province[1] == 'L') strcpy(data[temp].province, "Newfoundland");
            else if (data[temp].province[1] == 'S') strcpy(data[temp].province, "Nova Scotia");
            else if (data[temp].province[1] == 'T') strcpy(data[temp].province, "Northwest Territories");
            else if (data[temp].province[1] == 'U') strcpy(data[temp].province, "Nunavut");
            temp++;
            if (temp >= MAX_RECORDS) break;
        }
        fclose(file);

    }   
    return records;
}

void mainLogic(FileData *data, int records)
{
    int minYear = 7000;
    int maxYear = 0;
    int selection = 0;
    
    for (int i = 0; i < records; i++)
    {
        if (data[i].year > maxYear)
        {
            maxYear = data[i].year;
        }
        if (data[i].year < minYear) 
        {
            minYear = data[i].year;
        }
    }
    do 
    {
        printf("=======================================================\n"
            "         Canada Species at Risk Analysis\n"
            "            (Data Years : %d - %d)\n"
            "=======================================================\n", STARTING_YEAR, ENDING_YEAR);
        printf("1. View by year (sorted ASCENDING by year)\n"
            "2. View by province (sorted DESCENDING by totals)\n"
            "3. View by taxon (sorted ASCENDING by totals)\n"
            "4. View by province and taxon\n"
            "-------------------------------------------------------\n"
            "0. Exit\n"
            "-------------------------------------------------------\n"
            "Selection: ");
        selection = inputIntRange(0, 4);
        putchar('\n');
        switch (selection)
        {   
        case 0: {
            printf("Application Terminated!\n\n");
            break;
        }
        case 1: {
            displayDataByYear(data, records);
            break;
        }
        case 2: {
            displayDataByProvince(data, records);
            break;
        }
        case 3: {
            displayDataByTaxon(data, records);
            break;
        }
        case 4: {
            displayByProvinceAndTaxon(data, records);
            break;
        }
        }

    } while (selection);
}

void displayDataByYear (FileData* data, int records)
{
    DataByYear dt[100] = { {0} };
    int temp = 0;
    int i = 0, j = 0;

    for (int i = 0; i < records; i++)
    {

        for (j = 0; j < temp; j++)
        {
            if (dt[j].year == data[i].year)
                break;
        }
        if (j == temp)
        {
            dt[temp++].year = data[i].year;
            
        }  
        dt[j].total += data[i].countData;

        if (strcmp(data[i].status, "EXTINCT") == 0) 
        {
            dt[j].extinct += data[i].countData;
        }         
        else if (strcmp(data[i].status, "EXTIRPATED") == 0)
        {
            dt[j].extirpated += data[i].countData;
        }         
        else if (strcmp(data[i].status, "ENDANGERED") == 0)
        {
            dt[j].endangered += data[i].countData;
        }          
        else if (strcmp(data[i].status, "THREATENED") == 0)
        {
            dt[j].threatened += data[i].countData;
        }         
        else if (strcmp(data[i].status, "SPECIAL CONCERN") == 0)
        {
            dt[j].concern += data[i].countData;
        }    
    }

    for (int i = 0; i < temp - 1; i++)
    {
        for (int j = 0; j < temp - i - 1; j++)
        {
            if (dt[j].year > dt[j + 1].year)
            {
                DataByYear tmp = dt[j];
                dt[j] = dt[j + 1];
                dt[j + 1] = tmp;
            }
        }
    }
 
    printf("YEAR EXTINCT EXTIRPATED ENDANGERED THREATENED CONCERN     TOTAL\n");
    printf("---- ------- ---------- ---------- ---------- ------- ---------\n");
    int textinct, textirpated, tendangered, tthreatened, tconcern, ttotal;
    textinct = textirpated = tendangered = tthreatened = tconcern = ttotal = 0;
    for (int i = 0; i < temp; i++)
    {
        printf("%4d %7d %10d %10d %10d %7d %9d\n", dt[i].year, dt[i].extinct,
            dt[i].extirpated, dt[i].endangered, dt[i].threatened, dt[i].concern, dt[i].total);
        textinct += dt[i].extinct;
        textirpated += dt[i].extirpated;
        tendangered += dt[i].endangered;
        tthreatened += dt[i].threatened;
        tconcern += dt[i].concern;
        ttotal += dt[i].total;
    }
    printf("     ------- ---------- ---------- ---------- ------- ---------\n");
    printf("     %7d %10d %10d %10d %7d %9d\n", textinct, textirpated, tendangered, tthreatened, tconcern, ttotal);
    putchar('\n');
}

void displayDataByProvince(FileData* data, int records)
{
    DataByProvince dt[100] = { {0} };
    int temp = 0;
    for (int i = 0; i < records; i++)
    {
        int j;
        for (j = 0; j < temp; j++)
        {
            if (strcmp(data[i].province, dt[j].province) == 0)
                break;
        }
        if (j == temp)
        {
            strcpy(dt[temp++].province, data[i].province);
           
        }
        dt[j].total += data[i].countData;
        if (strcmp(data[i].status, "EXTINCT") == 0)
        {
            dt[j].extinct += data[i].countData;
        }
           
        else if (strcmp(data[i].status, "EXTIRPATED") == 0)
        {
            dt[j].extirpated += data[i].countData;
        }
            
        else if (strcmp(data[i].status, "ENDANGERED") == 0)
        {
            dt[j].endangered += data[i].countData;
        }
            
        else if (strcmp(data[i].status, "THREATENED") == 0)
        {
            dt[j].threatened += data[i].countData;
        }
            
        else if (strcmp(data[i].status, "SPECIAL CONCERN") == 0)
        {
            dt[j].concern += data[i].countData;
        }
           
    }
    for (int i = 0; i < temp - 1; i++)
    {
        for (int j = 0; j < temp - i - 1; j++)
        {
            if (dt[j].total < dt[j + 1].total)
            {
                DataByProvince tmp = dt[j];
                dt[j] = dt[j + 1];
                dt[j + 1] = tmp;
            }
        }
    }

    printf("PROVINCE             EXTINCT EXTIRPATED ENDANGERED THREATENED CONCERN     TOTAL\n");
    printf("-------------------- ------- ---------- ---------- ---------- ------- ---------\n");
    int textinct, textirpated, tendangered, tthreatened, tconcern, ttotal;
    textinct = textirpated = tendangered = tthreatened = tconcern = ttotal = 0;
    for (int i = 0; i < temp; i++)
    {
        printf("%-21s%7d %10d %10d %10d %7d %9d\n", dt[i].province, dt[i].extinct,
            dt[i].extirpated, dt[i].endangered, dt[i].threatened, dt[i].concern, dt[i].total);
        textinct += dt[i].extinct;
        textirpated += dt[i].extirpated;
        tendangered += dt[i].endangered;
        tthreatened += dt[i].threatened;
        tconcern += dt[i].concern;
        ttotal += dt[i].total;
    }
    printf("-------------------- ------- ---------- ---------- ---------- ------- ---------\n");
    printf("                     %7d %10d %10d %10d %7d %9d\n", textinct, textirpated, tendangered, tthreatened, tconcern, ttotal);
    putchar('\n');
}

void displayDataByTaxon(FileData* data, int records)
{
    DataByTaxon dt[100] = { {0} };
    int temp = 0;

    int i = 0;
    for (int i = 0; i < records; i++)
    {
        int j = 0;
        for (j = 0; j < temp; j++)
        {
            if (strcmp(data[i].taxOn, dt[j].taxon) == 0)
                break;
        }
        if (j == temp)
            strcpy(dt[temp++].taxon, data[i].taxOn);
        dt[j].total += data[i].countData;
        if (strcmp(data[i].status, "EXTINCT") == 0)
            dt[j].extinct += data[i].countData;
        else if (strcmp(data[i].status, "EXTIRPATED") == 0)
            dt[j].extirpated += data[i].countData;
        else if (strcmp(data[i].status, "ENDANGERED") == 0)
            dt[j].endangered += data[i].countData;
        else if (strcmp(data[i].status, "THREATENED") == 0)
            dt[j].threatened += data[i].countData;
        else if (strcmp(data[i].status, "SPECIAL CONCERN") == 0)
            dt[j].concern += data[i].countData;
    }
    for (int i = 0; i < temp - 1; i++)
    {
        for (int j = 0; j < temp - i - 1; j++)
        {
            if (dt[j].total > dt[j + 1].total)
            {
                DataByTaxon tmp = dt[j];
                dt[j] = dt[j + 1];
                dt[j + 1] = tmp;
            }
        }
    }
   
    printf("TAXON           EXTINCT EXTIRPATED ENDANGERED THREATENED CONCERN     TOTAL\n");
    printf("--------------- ------- ---------- ---------- ---------- ------- ---------\n");
    int textinct, textirpated, tendangered, tthreatened, tconcern, ttotal;
    textinct = textirpated = tendangered = tthreatened = tconcern = ttotal = 0;
    for (int i = 0; i < temp; i++)
    {
        printf("%-15s %7d %10d %10d %10d %7d %9d\n", dt[i].taxon, dt[i].extinct,
            dt[i].extirpated, dt[i].endangered, dt[i].threatened, dt[i].concern, dt[i].total);
        textinct += dt[i].extinct;
        textirpated += dt[i].extirpated;
        tendangered += dt[i].endangered;
        tthreatened += dt[i].threatened;
        tconcern += dt[i].concern;
        ttotal += dt[i].total;
    }
    printf("                ------- ---------- ---------- ---------- ------- ---------\n");
    printf("                %7d %10d %10d %10d %7d %9d\n\n", textinct, textirpated, tendangered, tthreatened, tconcern, ttotal);
}

void displayByProvinceAndTaxon(FileData* data, int records)
{
    char province[30], taxon[30];
    int selection = 0;
    while (selection > 13 || selection < 1)
    {
        printf("Choose a Province\n");
        printf("----------------------------------\n");
        printf(" 1) AB (Alberta)\n");
        printf(" 2) BC (British Columbia)\n");
        printf(" 3) MB (Manitoba)\n");
        printf(" 4) NB (New Brunswick)\n");
        printf(" 5) NL (Newfoundland)\n");
        printf(" 6) NS (Nova Scotia)\n");
        printf(" 7) NT (Northwest Territories)\n");
        printf(" 8) NU (Nunavut)\n");
        printf(" 9) ON (Ontario)\n");
        printf("10) PE (Prince Edward Island)\n");
        printf("11) QC (Quebec)\n");
        printf("12) SK (Saskatchewan)\n");
        printf("13) YT (Yukon Territory)\n");
        printf("Selection: ");
        selection = inputIntRange(1, 13);
        putchar('\n');
        switch (selection)
        {
        case 1:
            strcpy(province, "Alberta");
            break;
        case 2:
            strcpy(province, "British Columbia");
            break;
        case 3:
            strcpy(province, "Manitoba");
            break;
        case 4:
            strcpy(province, "New Brunswick");
            break;
        case 5:
            strcpy(province, "Newfoundland");
            break;
        case 6:
            strcpy(province, "Nova Scotia");
            break;
        case 7:
            strcpy(province, "Northwest Territories");
            break;
        case 8:
            strcpy(province, "Nunavut");
            break;
        case 9:
            strcpy(province, "Ontario");
            break;
        case 10:
            strcpy(province, "Prince Edward Island");
            break;
        case 11:
            strcpy(province, "Quebec");
            break;
        case 12:
            strcpy(province, "Saskatchewan");
            break;
        case 13:
            strcpy(province, "Yukon Territory");
            break;
        }
    }

    selection = 0;

    while (selection < 1 || selection > 10)
    {
        printf("Choose a Taxon\n");
        printf("---------------\n");
        printf(" 1) Mammals\n");
        printf(" 2) Birds\n");
        printf(" 3) Reptiles\n");
        printf(" 4) Amphibians\n");
        printf(" 5) Fishes\n");
        printf(" 6) Arthropods\n");
        printf(" 7) Molluscs\n");
        printf(" 8) Vascular Plants\n");
        printf(" 9) Mosses\n");
        printf("10) Lichens\n");
        printf("Selection: ");
        selection = inputIntRange(1, 10);
        putchar('\n');
        switch (selection)
        {
        case 1:
            strcpy(taxon, "Mammals");
            break;
        case 2:
            strcpy(taxon, "Birds");
            break;
        case 3:
            strcpy(taxon, "Reptiles");
            break;
        case 4:
            strcpy(taxon, "Amphibians");
            break;
        case 5:
            strcpy(taxon, "Fishes");
            break;
        case 6:
            strcpy(taxon, "Arthropods");
            break;
        case 7:
            strcpy(taxon, "Molluscs");
            break;
        case 8:
            strcpy(taxon, "Vascular Plants");
            break;
        case 9:
            strcpy(taxon, "Mosses");
            break;
        case 10:
            strcpy(taxon, "Lichens");
            break;
        }
    }


    printf("*** Data filtered by PROVINCE and TAXON ***\n\n");

    printf("    Province: % s\n", province);
    printf("    Taxon   : %s\n\n", taxon);
    printf("EXTINCT EXTIRPATED ENDANGERED THREATENED CONCERN     TOTAL\n");
    printf("------- ---------- ---------- ---------- ------- ---------\n");


    int textinct, textirpated, tendangered, tthreatened, tconcern, ttotal;
    textinct = textirpated = tendangered = tthreatened = tconcern = ttotal = 0;

    int i = 0;
    for (int i = 0; i < records; i++)
    {
        if (strcmp(province, data[i].province) != 0 || strcmp(taxon, data[i].taxOn))
            continue;
        ttotal += data[i].countData;
        if (strcmp(data[i].status, "EXTINCT") == 0)
            textinct += data[i].countData;
        else if (strcmp(data[i].status, "EXTIRPATED") == 0)
            textirpated += data[i].countData;
        else if (strcmp(data[i].status, "ENDANGERED") == 0)
            tendangered += data[i].countData;
        else if (strcmp(data[i].status, "THREATENED") == 0)
            tthreatened += data[i].countData;
        else if (strcmp(data[i].status, "SPECIAL CONCERN") == 0)
            tconcern += data[i].countData;
    }
    printf("%7d % 10d % 10d % 10d % 7d % 9d\n", textinct, textirpated, tendangered, tthreatened, tconcern, ttotal);
    putchar('\n');
}