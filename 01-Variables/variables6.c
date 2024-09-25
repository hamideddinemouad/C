#include <stdio.h>

/**
* main - entrée du program
* 
* Description: Calculez et affichez a + b, a - b, a * b, et a / b avec précision décimale 
*
* Return: Toujours 0 (succès)
*/

int main()
{
    double a, b, result1, result2, result3, result4;

    printf("a =  ?\n");
    scanf("%2lf", &a);
    printf("b =  ?\n");
    scanf("%2lf", &b);
    result1 = a + b;
    result2 = a - b;
    result3 = a * b;
    result4 = a / b;
    printf("a + b = %2lf\na - b = %2lf\na x b = %2lf\na / b =%2lf", result1, result2, result3, result4);
    return 0;
}