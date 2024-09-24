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
    float vitesse_km = 0, vitesse_ms = 0;

    printf("vitesse en km par heure ?\n");
    scanf("%f", &vitesse_km);
    vitesse_ms = vitesse_km * 0.27778;
    printf("vitesse en metre par seconde :%f\n", vitesse_ms);
    return (0);
}