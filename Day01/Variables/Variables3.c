#include <stdio.h>

/**
* main - entrée du program
* 
* Description: demande la distance en kilomètres et la transforme en yards
*
* Return: Toujours 0 (succès)
*/

int main(void)
{
    float distance_km;

    printf("distance en km ?\n");
    scanf("%f", &distance_km);
    distance_km += 273.15;
    printf("distance en yards :%f\n", distance_km);
    return (0);
}