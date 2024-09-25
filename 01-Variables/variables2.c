#include <stdio.h>

/**
* main - entrée du program
* 
* Description: demande temperature en c et convertis au kelvin
*
* Return: Toujours 0 (succès)
*/

int main(void)
{
    float temperature;

    printf("Temperature en Celsuis ?\n");
    scanf("%f", &temperature);
    temperature = temperature + 273.15;
    printf("temperature en kelvin :%f\n", temperature);
    return (0);
}