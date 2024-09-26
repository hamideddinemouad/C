#include <stdio.h>

/**
* main - entrée du program
* 
* Description: affiche le plus petit élément dans un tableau d'entiers.
*
* Return: toujours 0 (succès)
*/

int main()
{
    int nombre_valeurs, compteur = 0;

    printf("combien d'entree ?\n");
    scanf("%d", &nombre_valeurs);

    int valeurs[nombre_valeurs], plus_petit = 0;

    for (compteur = 0; compteur < nombre_valeurs; compteur++)
    {
        printf("valeur %d ?\n", compteur + 1);
        scanf("%d", &valeurs[compteur]);
    }
    plus_petit  = valeurs[0];
    for (compteur = 0; compteur < nombre_valeurs; compteur ++)
    {
        if (plus_petit > valeurs[compteur])
        {
            plus_petit = valeurs[compteur];
        }
    }
    printf(" le plus petit nombre = %d\n", plus_petit);
    return (0);
}