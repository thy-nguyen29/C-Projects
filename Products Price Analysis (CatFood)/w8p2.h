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

// ----------------------------------------------------------------------------
// defines/macros
#define MAX_PRODUCT_NUM 3
#define PER_SERVING 64
#define UNIT 2.20462

// ----------------------------------------------------------------------------
// structures
typedef struct CatFoodInfo
{
    int sku;
    int calories;
    double price;
    double weight;
}CatFoodInfo;

typedef struct ReportData
{
    int sku;
    int calories;
    double price;
    double weight;
    double kg;
    int gram;
    double totalServing;
    double costPerServ;
    double costCalServ;
}ReportData;

// ----------------------------------------------------------------------------
// function prototypes

// PART-1

// 1. Get user input of int type and validate for a positive non-zero number
//    (return the number while also assigning it to the pointer argument)
int getIntPositive(int* number);

// 2. Get user input of double type and validate for a positive non-zero number
//    (return the number while also assigning it to the pointer argument)
double getDoublePositive(double* doubleValue);

// 3. Opening Message (include the number of products that need entering)
void openingMessage(const int numOfProduct, const int serving);

// 4. Get user input for the details of cat food product
struct CatFoodInfo getCatFoodInfo (int sequenceNumber);

// 5. Display the formatted table header
void displayCatFoodHeader(void);

// 6. Display a formatted record of cat food data
void displayCatFoodData(const int sku, const double* price, const double* weight, const int calories);

// ----------------------------------------------------------------------------
// PART-2

// 8. convert lbs: kg
double convertLbsKg(const double* lbs, double* kgResult);

// 9. convert lbs: g
int convertLbsG(const double* lbs, int* gramResult);

// 10. convert lbs: kg / g
void convertLbs(const double* lbs, double* kgResult, int* gramResult);

// 11. calculate: servings based on gPerServ
double calculateServing (const int servSize, const int totalGram, double* servNum);

// 12. calculate: cost per serving
double calculateCostPerServing  (const double* price, const double* totalServNum, double* costPerServ);

// 13. calculate: cost per calorie
double calculateCostPerCal(const double* price, const double* totalCalNum, double* costPerCal);

// 14. Derive a reporting detail record based on the cat food product data
struct ReportData calculateReportData (const CatFoodInfo);

// 15. Display the formatted table header for the analysis results
void displayReportHeader(void);

// 16. Display the formatted data row in the analysis table
void displayReportData (const struct ReportData, const int cheapest);

// 17. Display the findings (cheapest)
void displayFinalAnalysis ();

// ----------------------------------------------------------------------------

// 7. Logic entry point 
void start();
