/*
*****************************************************************************
                          Workshop - #2 (P2)
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
    
    // declaration
    double smallShirtPrice, mediumShirtPrice, largeShirtPrice;
    int    patShirtNo, tomShirtNo, salShirtNo, coins;    //the number of shirts for each person

    // constant values
    const double TAX = 0.13;
    const char patSize = 'S', salSize = 'M', tomSize = 'L';

    

    printf("Set Shirt Prices\n");
    printf("================\n");
    printf("Enter the price for a SMALL shirt: $");
    scanf("%lf", &smallShirtPrice);
    printf("Enter the price for a MEDIUM shirt: $");
    scanf("%lf", &mediumShirtPrice);
    printf("Enter the price for a LARGE shirt: $");
    scanf("%lf", &largeShirtPrice);
    printf("\n");

    printf("Shirt Store Price List\n");
    printf("======================\n");
    printf("SMALL  : $%.2lf\n", smallShirtPrice);
    printf("MEDIUM : $%.2lf\n", mediumShirtPrice);
    printf("LARGE  : $%.2lf\n\n", largeShirtPrice);
    
    printf("Patty's shirt size is \'%c\'\n", patSize);
    printf("Number of shirts Patty is buying: ");
    scanf("%d", &patShirtNo);
    printf("\n");
    printf("Tommy's shirt size is \'%c\'\n", tomSize);
    printf("Number of shirts Tommy is buying: ");
    scanf("%d", &tomShirtNo);
    printf("\n");
    printf("Sally's shirt size is \'%c\'\n", salSize);
    printf("Number of shirts Sally is buying: ");
    scanf("%d", &salShirtNo);
    printf("\n");

    // Patty shopping cart
    double subTotalPat = patShirtNo * smallShirtPrice;
    int taxPat = (((subTotalPat * TAX) + 0.005) * 100);
    int totalPat = (((subTotalPat + 0.005) * 100) + taxPat);

    // Sally shopping cart
    double subTotalSal = salShirtNo * mediumShirtPrice;
    int taxSal = (((subTotalSal * TAX) + 0.005) * 100);
    int totalSal = (((subTotalSal + 0.005) * 100) + taxSal);

    // Tommy shopping cart
    double subTotalTom = tomShirtNo * largeShirtPrice;
    int taxTom = (((subTotalTom * TAX) + 0.005) * 100);
    int totalTom = (((subTotalTom + 0.005) * 100) + taxTom);

    // Total calculation
    double subTotalAll = subTotalPat + subTotalSal + subTotalTom;
    int taxAll = taxPat + taxSal + taxTom;
    int totalAll = totalPat + totalSal + totalTom;
    int totalShirt = patShirtNo + salShirtNo + tomShirtNo;

    printf("Customer Size Price Qty Sub-Total       Tax     Total\n");
    printf("-------- ---- ----- --- --------- --------- ---------\n");
    printf("Patty    %-4c %5.2lf %3d %9.4lf %9.4lf %9.4lf\n",
        patSize,
        smallShirtPrice,
        patShirtNo,
        subTotalPat,
        (double) taxPat / 100,
        (double) totalPat / 100);
    printf("Sally    %-4c %5.2lf %3d %9.4lf %9.4lf %9.4lf\n",
        salSize,
        mediumShirtPrice,
        salShirtNo,
        subTotalSal,
        (double) taxSal / 100,
        (double) totalSal / 100);
    printf("Tommy    %-4c %5.2lf %3d %9.4lf %9.4lf %9.4lf\n",
        tomSize,
        largeShirtPrice,
        tomShirtNo,
        subTotalTom,
        (double) taxTom / 100,
        (double) totalTom / 100);
    printf("-------- ---- ----- --- --------- --------- ---------\n");
    printf("%33.4lf %9.4lf %9.4lf\n\n",
        subTotalAll,
        (double) taxAll / 100,
        (double) totalAll / 100);

    int noTaxTotal = ((subTotalAll + 0.005) * 100);   // Price excluded taxes in cents
    
    printf("Daily retail sales represented by coins\n"
    "=======================================\n\n"
    "Sales EXCLUDING tax\n"
    "Coin     Qty   Balance\n"
    "-------- --- ---------\n");
    printf("%22.4lf\n", (double)noTaxTotal / 100);

    coins = noTaxTotal / 200,
    noTaxTotal = noTaxTotal % 200,
    printf("Toonies  %3d %9.4lf\n",
            coins,
            (double)noTaxTotal / 100);

    coins = noTaxTotal / 100,
    noTaxTotal = noTaxTotal % 100,
    printf("Loonies  %3d %9.4lf\n",
            coins,
            (double)noTaxTotal / 100);

    coins = noTaxTotal / 25,
    noTaxTotal = noTaxTotal % 25,
    printf("Quarters %3d %9.4lf\n",
            coins,
            (double)noTaxTotal / 100);

    coins = noTaxTotal / 10,
    noTaxTotal = noTaxTotal % 10,
    printf("Dimes  %5d %9.4lf\n",
            coins,
            (double)noTaxTotal / 100);

    coins = noTaxTotal / 5,
    noTaxTotal = noTaxTotal % 5,
    printf("Nickels %4d %9.4lf\n",
            coins,
            (double)noTaxTotal / 100);

    coins = noTaxTotal / 1,
    noTaxTotal = noTaxTotal % 1,
    printf("Pennies %4d %9.4lf\n\n",
            coins,
            (double)noTaxTotal / 100);

    double avgCostExTax = (double)(subTotalAll / totalShirt);
    printf("Average cost/shirt: $%7.4lf\n\n", avgCostExTax);
  

    int incTaxTotal = totalAll;

    printf("Sales INCLUDING tax\n"
        "Coin     Qty   Balance\n"
        "-------- --- ---------\n");
    printf("%22.4lf\n", (double)incTaxTotal / 100);

    coins = incTaxTotal / 200,
    incTaxTotal = incTaxTotal % 200,
        printf("Toonies  %3d %9.4lf\n",
            coins,
            (double)incTaxTotal / 100);

    coins = incTaxTotal / 100,
        incTaxTotal = incTaxTotal % 100,
        printf("Loonies  %3d %9.4lf\n",
            coins,
            (double)incTaxTotal / 100);

    coins = incTaxTotal / 25,
        incTaxTotal = incTaxTotal % 25,
        printf("Quarters %3d %9.4lf\n",
            coins,
            (double)incTaxTotal / 100);

    coins = incTaxTotal / 10,
        incTaxTotal = incTaxTotal % 10,
        printf("Dimes  %5d %9.4lf\n",
            coins,
            (double)incTaxTotal / 100);

    coins = incTaxTotal / 5,
        incTaxTotal = incTaxTotal % 5,
        printf("Nickels %4d %9.4lf\n",
            coins,
            (double)incTaxTotal / 100);

    coins = incTaxTotal / 1,
        incTaxTotal = incTaxTotal % 1,
        printf("Pennies %4d %9.4lf\n\n",
            coins,
            (double)incTaxTotal / 100);

    double avgCostIncTax = (((double)totalAll / totalShirt) + 0.005);
    printf("Average cost/shirt: $%7.4lf\n\n", (double)avgCostIncTax / 100);

    return 0;
}