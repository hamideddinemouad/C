#include <stdio.h>

/**
* main - entrée du program
* 
* Description: demande la température en Celsius et affiche l'état de l'eau à cette température 
*
* Return: Toujours 0 (succès)
*/

int main(void)
{
    float temperature;

    printf("temperature en Celsuis ?\n");
    scanf("%f", &temperature);
    if (temperature >= 0 && temperature < 100)
    {
        printf("liquide\n");
        return (0);
    }
    if (temperature < 0)
    {
        printf("solide\n");
        return (0);
    }
    if (temperature >= 100)
    {
        printf("gaz\n");
        return (0);
    }
    return (0);
}