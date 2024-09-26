#include <stdio.h>

/**
* main - entrée du program
* 
* Description: affiche le plus grand élément dans un tableau d'entiers.
*
* Return: toujours 0 (succès)
*/

int main()
{
    int nombre_valeurs, compteur = 0;

    printf("combien d'entree ?\n");
    scanf("%d", &nombre_valeurs);

    int valeurs[nombre_valeurs], plus_grand = 0;

    for (compteur = 0; compteur < nombre_valeurs; compteur++)
    {
        printf("valeur %d ?\n", compteur + 1);
        scanf("%d", &valeurs[compteur]);
    }
    for (compteur = 0; compteur < nombre_valeurs; compteur ++)
    {
        if (plus_grand < valeurs[compteur])
        {
            plus_grand = valeurs[compteur];
        }
    }
    printf(" le plus grand nombre = %d\n", plus_grand);
    return (0);
}