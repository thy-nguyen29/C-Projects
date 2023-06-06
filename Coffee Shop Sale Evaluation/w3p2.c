#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>

int main(void)
{
    // You will need this when converting from grams to pounds (lbs)
    const double GRAMS_IN_LBS = 453.5924;
    
    char  c1Type, c2Type, c3Type;                       // Coffee Type
    char  c1GrindSize, c2GrindSize, c3GrindSize;        // Coffee Grind Size
    int   c1BagWeight, c2BagWeight, c3BagWeight;        // Coffee Bag Weight
    char  c1ServedCream, c2ServedCream, c3ServedCream;  // Best served with cream?
    float c1Temp, c2Temp, c3Temp;                       // Ideal serving temperature

    // 4 addtional variables for user's preferences and coffee making equipment
    char coffeeStrength;
    char equipment;
    int  dailyServings;
    char coffeeWithCream;

	// Note:
	// You can convert Celsius to Fahrenheit given the following formula:
	// fahrenheit = (celsius * 1.8) + 32.0);

    printf("Take a Break - Coffee Shop\n"
    "==========================\n\n"
    "Enter the coffee product information being sold today...\n\n"
    "COFFEE-1...\n");                             //coffee 1
    printf("Type ([L]ight,[B]lend): ");
    scanf(" %c", &c1Type);
    printf("Grind size ([C]ourse,[F]ine): ");
    scanf(" %c", &c1GrindSize);
    printf("Bag weight (g): ");
    scanf(" %d", &c1BagWeight);
    printf("Best served with cream ([Y]es,[N]o): ");
    scanf(" %c", &c1ServedCream);   
    printf("Ideal serving temperature (Celsius): ");
    scanf(" %f", &c1Temp);
    printf("\nCOFFEE-2...\n");                   //coffee 2
    printf("Type ([L]ight,[B]lend): ");
    scanf(" %c", &c2Type);
    printf("Grind size ([C]ourse,[F]ine): ");
    scanf(" %c", &c2GrindSize);
    printf("Bag weight (g): ");
    scanf(" %d", &c2BagWeight);
    printf("Best served with cream ([Y]es,[N]o): ");
    scanf(" %c", &c2ServedCream);
    printf("Ideal serving temperature (Celsius): ");
    scanf(" %f", &c2Temp);
    printf("\nCOFFEE-3...\n");                   //coffee 3
    printf("Type ([L]ight,[B]lend): ");
    scanf(" %c", &c3Type);
    printf("Grind size ([C]ourse,[F]ine): ");
    scanf(" %c", &c3GrindSize);
    printf("Bag weight (g): ");
    scanf(" %d", &c3BagWeight);
    printf("Best served with cream ([Y]es,[N]o): ");
    scanf(" %c", &c3ServedCream);
    printf("Ideal serving temperature (Celsius): ");
    scanf(" %f", &c3Temp);  
    printf("\n---+---------------+---------------+---------------+-------+--------------\n"
             "   |    Coffee     |    Coffee     |   Packaged    | Best  |   Serving\n"
             "   |     Type      |  Grind Size   |  Bag Weight   | Served| Temperature\n"
             "   +---------------+---------------+---------------+ With  +--------------\n"
             "ID | Light | Blend | Course | Fine |  (G) | Lbs    | Cream |   (C) |   (F)\n"
             "---+---------------+---------------+---------------+-------+--------------\n");
    printf(" 1 |   %d   |   %d   |    %d   |   %d  | %4d | %6.3lf |   %d   | %5.1lf | %5.1lf\n",
        c1Type == 'L' || c1Type == 'l', c1Type == 'B' || c1Type == 'b', 
        c1GrindSize == 'C'|| c1GrindSize == 'c', c1GrindSize == 'F'|| c1GrindSize == 'f',
        c1BagWeight, c1BagWeight / GRAMS_IN_LBS, c1ServedCream == 'Y'|| c1ServedCream == 'y',
        c1Temp, (c1Temp * 1.8) + 32.0);
    printf(" 2 |   %d   |   %d   |    %d   |   %d  | %4d | %6.3lf |   %d   | %5.1lf | %5.1lf\n",
        c2Type == 'L' || c2Type == 'l', c2Type == 'B' || c2Type == 'b',
        c2GrindSize == 'C' || c2GrindSize == 'c', c2GrindSize == 'F' || c2GrindSize == 'f',
        c2BagWeight, c2BagWeight / GRAMS_IN_LBS, c2ServedCream == 'Y' || c2ServedCream == 'y',
        c2Temp, (c2Temp * 1.8) + 32.0);
    printf(" 3 |   %d   |   %d   |    %d   |   %d  | %4d | %6.3lf |   %d   | %5.1lf | %5.1lf\n\n",
        c3Type == 'L' || c3Type == 'l', c3Type == 'B' || c3Type == 'b',
        c3GrindSize == 'C' || c3GrindSize == 'c', c3GrindSize == 'F' || c3GrindSize == 'f',
        c3BagWeight, c3BagWeight / GRAMS_IN_LBS, c3ServedCream == 'Y' || c3ServedCream == 'y',
        c3Temp, (c3Temp * 1.8) + 32.0);  
    printf("Enter how you like your coffee and the coffee maker equipment you use...\n\n");
    printf("Coffee strength ([M]ild,[R]ich): ");
    scanf(" %c", &coffeeStrength);
    printf("Do you like your coffee with cream ([Y]es,[N]o): ");
    scanf(" %c", &coffeeWithCream);
    printf("Typical number of daily servings: ");
    scanf(" %d", &dailyServings);
    printf("Maker ([R]esidential,[C]ommercial): ");
    scanf(" %c", &equipment);
    printf("\nThe below table shows how your preferences align to the available products:\n\n"
           "--------------------+--------------------+-------------+-------+--------------\n"
           "  |     Coffee      |       Coffee       |  Packaged   | With  |   Serving\n"
           "ID|      Type       |     Grind Size     | Bag Weight  | Cream | Temperature\n"
           "--+-----------------+--------------------+-------------+-------+--------------\n");
    printf(" 1|       %d         |         %d          |      %d      |   %d   |      %d\n",
        ((coffeeStrength == 'm'|| coffeeStrength == 'M') && (c1Type == 'l'|| c1Type == 'L')) ||     
        ((coffeeStrength == 'r'|| coffeeStrength == 'R') && (c1Type == 'b'|| c1Type == 'B')),
        ((equipment == 'r' || equipment == 'R') && (c1GrindSize == 'c' || c1GrindSize == 'C')) ||   
        ((equipment == 'c' || equipment == 'C') && (c1GrindSize == 'f' || c1GrindSize == 'F')),
        (dailyServings <= 4 && c1BagWeight <= 250) ||                                               
        (dailyServings >= 5 && dailyServings <= 9 && c1BagWeight == 500) ||
        (dailyServings >= 10 && c1BagWeight == 1000),
        ((coffeeWithCream == 'y' || coffeeWithCream == 'Y') && (c1ServedCream == 'Y' || c1ServedCream == 'y')) ||
        ((coffeeWithCream == 'n' || coffeeWithCream == 'N') && (!c1ServedCream == 'N' || !c1ServedCream == 'n')),
        ((equipment == 'r' || equipment == 'R') && (c1Temp >= 60.0 && c1Temp < 70)) ||                       
        ((equipment == 'c' || equipment == 'C') && (c1Temp >= 70.0)));
   printf(" 2|       %d         |         %d          |      %d      |   %d   |      %d\n",
        ((coffeeStrength == 'm' || coffeeStrength == 'M') && (c2Type == 'l' || c2Type == 'L')) ||     
        ((coffeeStrength == 'r' || coffeeStrength == 'R') && (c2Type == 'b' || c2Type == 'B')),
        ((equipment == 'r' || equipment == 'R') && (c2GrindSize == 'c' || c2GrindSize == 'C')) ||   
        ((equipment == 'c' || equipment == 'C') && (c2GrindSize == 'f' || c2GrindSize == 'F')),
        (dailyServings <= 4 && c2BagWeight <= 250) ||                                               
        (dailyServings >= 5 && dailyServings <= 9 && c2BagWeight == 500) ||
        (dailyServings >= 10 && c2BagWeight == 1000),
        ((coffeeWithCream == 'y' || coffeeWithCream == 'Y') && (c2ServedCream == 'Y' || c2ServedCream == 'y')) ||
        ((coffeeWithCream == 'n' || coffeeWithCream == 'N') && (c2ServedCream == 'N' || c2ServedCream == 'n')),
        ((equipment == 'r' || equipment == 'R') && (c2Temp >= 60.0 && c2Temp < 70)) ||
        ((equipment == 'c' || equipment == 'C') && (c2Temp >= 70.0)));
    printf(" 3|       %d         |         %d          |      %d      |   %d   |      %d\n\n",
        ((coffeeStrength == 'm' || coffeeStrength == 'M') && (c3Type == 'l' || c3Type == 'L')) ||    
        ((coffeeStrength == 'r' || coffeeStrength == 'R') && (c3Type == 'b' || c3Type == 'B')),
        ((equipment == 'r' || equipment == 'R') && (c3GrindSize == 'c' || c3GrindSize == 'C')) ||   
        ((equipment == 'c' || equipment == 'C') && (c3GrindSize == 'f' || c3GrindSize == 'F')),
        (dailyServings <= 4 && c3BagWeight <= 250) ||                                               
        (dailyServings >= 5 && dailyServings <= 9 && c3BagWeight == 500) ||
        (dailyServings >= 10 && c3BagWeight == 1000),
        ((coffeeWithCream == 'y' || coffeeWithCream == 'Y') && (c3ServedCream == 'Y' || c3ServedCream == 'y')) ||
        ((coffeeWithCream == 'n' || coffeeWithCream == 'N') && (c3ServedCream == 'N' || c3ServedCream == 'n')),
        ((equipment == 'r' || equipment == 'R') && (c3Temp >= 60.0 && c3Temp < 70)) ||
        ((equipment == 'c' || equipment == 'C') && (c3Temp >= 70.0)));
    printf("Enter how you like your coffee and the coffee maker equipment you use...\n\n");
    printf("Coffee strength ([M]ild,[R]ich): ");
    scanf(" %c", &coffeeStrength);
    printf("Do you like your coffee with cream ([Y]es,[N]o): ");
    scanf(" %c", &coffeeWithCream);
    printf("Typical number of daily servings: ");
    scanf(" %d", &dailyServings);
    printf("Maker ([R]esidential,[C]ommercial): ");
    scanf(" %c", &equipment);
    printf("\nThe below table shows how your preferences align to the available products:\n\n"
        "--------------------+--------------------+-------------+-------+--------------\n"
        "  |     Coffee      |       Coffee       |  Packaged   | With  |   Serving\n"
        "ID|      Type       |     Grind Size     | Bag Weight  | Cream | Temperature\n"
        "--+-----------------+--------------------+-------------+-------+--------------\n");
     printf(" 1|       %d         |         %d          |      %d      |   %d   |      %d\n",
        ((coffeeStrength == 'm'|| coffeeStrength == 'M') && (c1Type == 'l'|| c1Type == 'L')) ||     
        ((coffeeStrength == 'r'|| coffeeStrength == 'R') && (c1Type == 'b'|| c1Type == 'B')),
        ((equipment == 'r' || equipment == 'R') && (c1GrindSize == 'c' || c1GrindSize == 'C')) ||   
        ((equipment == 'c' || equipment == 'C') && (c1GrindSize == 'f' || c1GrindSize == 'F')),
        (dailyServings <= 4 && c1BagWeight <= 250) ||                                               
        (dailyServings >= 5 && dailyServings <= 9 && c1BagWeight == 500) ||
        (dailyServings >= 10 && c1BagWeight == 1000),
        ((coffeeWithCream == 'y' || coffeeWithCream == 'Y') && (c1ServedCream == 'Y' || c1ServedCream == 'y')) ||
        ((coffeeWithCream == 'n' || coffeeWithCream == 'N') && (c1ServedCream == 'N' || c1ServedCream == 'n')),
        ((equipment == 'r' || equipment == 'R') && (c1Temp >= 60.0 && c1Temp < 70)) ||
        ((equipment == 'c' || equipment == 'C') && (c1Temp >= 70.0)));
    printf(" 2|       %d         |         %d          |      %d      |   %d   |      %d\n",
        ((coffeeStrength == 'm' || coffeeStrength == 'M') && (c2Type == 'l' || c2Type == 'L')) ||   
        ((coffeeStrength == 'r' || coffeeStrength == 'R') && (c2Type == 'b' || c2Type == 'B')),
        ((equipment == 'r' || equipment == 'R') && (c2GrindSize == 'c' || c2GrindSize == 'C')) ||   
        ((equipment == 'c' || equipment == 'C') && (c2GrindSize == 'f' || c2GrindSize == 'F')),
        (dailyServings <= 4 && c2BagWeight <= 250) ||                                               
        (dailyServings >= 5 && dailyServings <= 9 && c2BagWeight == 500) ||
        (dailyServings >= 10 && c2BagWeight == 1000),
        ((coffeeWithCream == 'y' || coffeeWithCream == 'Y') && (c2ServedCream == 'Y' || c2ServedCream == 'y')) ||
        ((coffeeWithCream == 'n' || coffeeWithCream == 'N') && (c2ServedCream == 'N' || c2ServedCream == 'n')),
        ((equipment == 'r' || equipment == 'R') && (c2Temp >= 60.0 && c2Temp < 70)) ||
        ((equipment == 'c' || equipment == 'C') && (c2Temp >= 70.0)));
    printf(" 3|       %d         |         %d          |      %d      |   %d   |      %d\n\n",
        ((coffeeStrength == 'm' || coffeeStrength == 'M') && (c3Type == 'l' || c3Type == 'L')) ||   
        ((coffeeStrength == 'r' || coffeeStrength == 'R') && (c3Type == 'b' || c3Type == 'B')),
        ((equipment == 'r' || equipment == 'R') && (c3GrindSize == 'c' || c3GrindSize == 'C')) ||   
        ((equipment == 'c' || equipment == 'C') && (c3GrindSize == 'f' || c3GrindSize == 'F')),
        (dailyServings <= 4 && c3BagWeight <= 250) ||                                               
        (dailyServings >= 5 && dailyServings <= 9 && c3BagWeight == 500) ||
        (dailyServings >= 10 && c3BagWeight == 1000),
        ((coffeeWithCream == 'y' || coffeeWithCream == 'Y') && (c3ServedCream == 'Y' || c3ServedCream == 'y')) ||
        ((coffeeWithCream == 'n' || coffeeWithCream == 'N') && (c3ServedCream == 'N' || c3ServedCream == 'n')),
        ((equipment == 'r' || equipment == 'R') && (c3Temp >= 60.0 && c3Temp < 70)) ||
        ((equipment == 'c' || equipment == 'C') && (c3Temp >= 70.0)));   
   printf("Hope you found a product that suits your likes!\n");
    return 0;
}
