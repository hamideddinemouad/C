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
    float distance_km = 0, distance_yards = 0;

    printf("distance en km ?\n");
    scanf("%f", &distance_km);
    distance_yards = distance_km * 1093.61;
    printf("distance en yards :%f\n", distance_yards);
    return (0);
}