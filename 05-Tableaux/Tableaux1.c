#include <stdio.h>

/**
* main - entrée du program
* 
* Description: initialise un tableau d'entiers avec des valeurs données et affiche ces valeurs
*
* Return: toujours 0 (succès)
*/

int main ()
{
    int nombre_valeurs, compteur = 0;

    printf("combien d'entree ?\n");
    scanf("%d", &nombre_valeurs);

    int valeurs[nombre_valeurs];

    for (compteur = 0; compteur < nombre_valeurs; compteur++)
    {
        printf("valeur %d ?\n", compteur + 1);
        scanf("%d", &valeurs[compteur]);
    }
    for (compteur = 0; compteur < nombre_valeurs; compteur ++)
    {
        printf("%d\n", valeurs[compteur]);
    }
    return (0);
}
