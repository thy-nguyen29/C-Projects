/*
*****************************************************************************
                          Workshop - #8 (P2)
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
#include "w8p2.h"


// ----------------------------------------------------------------------------
// PART-1

// 1. Get user input of int type and validate for a positive non-zero number
//    (return the number while also assigning it to the pointer argument)
int getIntPositive(int* number)
{
	int value = 0;
	do
	{
		scanf(" %d", &value);
		if (value < 1)
		{
			printf("ERROR: Enter a positive value: ");
		}
	} while (value <= 1);
	if (number != NULL)
	{
		*number = value;
	}
	return value;
}

// 2. Get user input of double type and validate for a positive non-zero number
//    (return the number while also assigning it to the pointer argument)
double getDoublePositive(double* doubleValue)
{
	double value = 0;
	do
	{
		scanf(" %lf", &value);
		if (value < 1)
		{
			printf("ERROR: Enter a positive value: ");
		}
	} while (value <= 1);
	if (doubleValue != NULL)
	{
		*doubleValue = value;
	}
	return value;
}

// 3. Opening Message (include the number of products that need entering)
void openingMessage(const int numberOfProduct, const int serving)
{
	printf("Cat Food Cost Analysis\n");
	printf("======================\n\n");
	printf("Enter the details for %d dry food bags of product data for analysis\n", numberOfProduct);
	printf("NOTE: A 'serving' is %dg\n", PER_SERVING);
}

// 4. Get user input for the details of cat food product
struct CatFoodInfo getCatFoodInfo(int sequenceNumber)
{
	CatFoodInfo food = { 0, };
	printf("\nCat Food Product #%d\n", sequenceNumber + 1);
	printf("--------------------\n");
	printf("SKU           : ");
	food.sku = getIntPositive(NULL);
	printf("PRICE         : $");
	food.price = getDoublePositive(NULL);
	printf("WEIGHT (LBS)  : ");
	food.weight = getDoublePositive(NULL);
	printf("CALORIES/SERV.: ");
	food.calories = getIntPositive(NULL);
	return food;
}

// 5. Display the formatted table header
void displayCatFoodHeader(void)
{
	printf("SKU         $Price    Bag-lbs Cal/Serv\n");
	printf("------- ---------- ---------- --------\n");
}

// 6. Display a formatted record of cat food data
void displayCatFoodData(const int sku, const double* price, const double* weight, const int calories)
{
	printf("%07d %10.2lf %10.1lf %8d\n", sku, *price, *weight, calories);
}

// ----------------------------------------------------------------------------
// PART-2

// 8. convert lbs: kg (divide by 2.20462)
double convertLbsKg(const double* lbs, double* kgResult)
{
	double convert;
	convert = *lbs / UNIT;
	if (kgResult != NULL)
	{
		*kgResult = convert;
	}
	return convert;
}
// 9. convert lbs: g (call convertKG, then * 1000)
int convertLbsG(double* lbs, int* gramResult)
{
	int convert;
	double firstResult, secondResult;
	firstResult = *lbs;
	secondResult = convertLbsKg (&firstResult, &secondResult);
	convert = secondResult * 1000;
	if (gramResult != NULL)
	{
		*gramResult = convert; 
	}
	return convert;
}

// 10. convert lbs: kg and g
void convertLbs(const double* lbs, double* kgResult, int* gramResult)
{
	convertLbsKg (lbs, kgResult);
	convertLbsG (lbs, gramResult);
}

// 11. calculate: servings based on gPerServ
double calculateServing(const int servSize, const int totalGram, double* servNum)
{
	double calculate;
	calculate = (double)totalGram / (double)servSize;
	if (servNum != NULL)
	{
		*servNum = calculate;
	}
	return calculate;
}

// 12. calculate: cost per serving
double calculateCostPerServing(const double* price, const double* totalServNum, double* costPerServ)
{
	double cost, firstResult, secondResult;
	firstResult = *totalServNum;
	secondResult = *price;
	cost = secondResult / firstResult;
	if (costPerServ != NULL)
	{
		*costPerServ = cost;
	}
	return cost;
}

// 13. calculate: cost per calorie
double calculateCostPerCal(const double* price, const double* totalCalNum, double* costPerCal)
{
	double cost = 0.0;
	cost = *price / *totalCalNum;
	if (calculateCostPerCal != NULL)
	{
		*costPerCal = cost;
	}
	return cost;
}

// 14. Derive a reporting detail record based on the cat food product data
struct ReportData calculateReportData(CatFoodInfo food)
{
	ReportData report;
	double calculate;

	report.sku = food.sku;
	report.price = food.price;
	report.weight = food.weight;
	report.calories = food.calories;
	report.kg = convertLbsKg (&food.weight, &report.kg);
	report.gram = convertLbsG (&food.weight, &report.gram);
	report.totalServing = calculateServing (PER_SERVING, report.gram, &report.totalServing);
	report.costPerServ = calculateCostPerServing (&report.price, &report.totalServing, &report.costPerServ);
	calculate = report.calories * report.totalServing;
	report.costCalServ = calculateCostPerCal (&report.price, &calculate, &report.costCalServ);
	return report;
}

// 15. Display the formatted table header for the analysis results
void displayReportHeader(void)
{
	printf("Analysis Report (Note: Serving = %dg)\n", PER_SERVING);
	printf("---------------\n");
	printf("SKU         $Price    Bag-lbs     Bag-kg     Bag-g Cal/Serv Servings  $/Serv   $/Cal\n");
	printf("------- ---------- ---------- ---------- --------- -------- -------- ------- -------\n");
}

// 16. Display the formatted data row in the analysis table
void displayReportData (struct ReportData report, const int cheapest)
{ 
	printf("%07d %10.2lf %10.1lf %10.4lf %9d %8d %8.1lf %7.2lf %7.5lf", report.sku, report.price, report.weight, report.kg, 
		report.gram, report.calories, report.totalServing, report.costPerServ, report.costCalServ);
}

// 17. Display the findings (cheapest)
void displayFinalAnalysis(CatFoodInfo food)
{
	printf("\n");
	printf("Final Analysis\n");
	printf("--------------\n");
	printf("Based on the comparison data, the PURRR-fect economical option is:\n");
	printf("SKU:%07d Price: $%.2lf\n\n", food.sku, food.price);
	printf("Happy shopping!\n");
}
// ----------------------------------------------------------------------------

// 7. Logic entry point
void start(void)
{
	openingMessage(MAX_PRODUCT_NUM, PER_SERVING);
	CatFoodInfo food[MAX_PRODUCT_NUM];
	ReportData report[MAX_PRODUCT_NUM];

	int i = 0;
	int cheapest = 0;
	for (i = 0; i < MAX_PRODUCT_NUM; i++)
	{
		food[i] = getCatFoodInfo(i);
	}
	displayCatFoodHeader();
	for (i = 0; i < MAX_PRODUCT_NUM; i++)
	{
		displayCatFoodData(food[i].sku, &food[i].price, &food[i].weight, food[i].calories);
	}
	printf("\n");
	displayReportHeader();
	for (i = 0; i < MAX_PRODUCT_NUM; i++)
	{
		report[i] = calculateReportData(food[i]);
		if (report[i].costPerServ < report[i - 1].costPerServ)
		{
			cheapest = i;
		}
	}
	for (i = 0; i < MAX_PRODUCT_NUM; i++)
	{
		ReportData finalData;
		finalData = report[i];
		displayReportData (finalData, cheapest);
		if (cheapest == i)
		{
			printf(" ***");
		}
		printf("\n");
	}
	displayFinalAnalysis(food[cheapest]);
	return;

}
