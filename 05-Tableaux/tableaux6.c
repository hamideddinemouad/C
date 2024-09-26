#include <stdio.h>

/**
* main - entrée du program
* 
* Description: multiplie chaque élément d'un tableau d'entiers par un facteur donné et affiche le tableau résultant
*
* Return: toujours 0 (succès)
*/

int main()
{
    int nombre_valeurs, compteur = 0, facteur;

    printf("combien d'entree ?\n");
    scanf("%d", &nombre_valeurs);

    int valeurs[nombre_valeurs];

    printf("facteur de multiplication\n");
    scanf("%d", &facteur);

    for (compteur = 0; compteur < nombre_valeurs; compteur++)
    {
        printf("valeur %d ?\n", compteur + 1);
        scanf("%d", &valeurs[compteur]);
    }
    for (compteur = 0; compteur < nombre_valeurs; compteur ++)
    {
         valeurs[compteur] = valeurs[compteur] * facteur;
    }
    printf("tableau apres multiplication:\n");
    for (compteur = 0; compteur < nombre_valeurs; compteur++)
    {
        printf("%d\n",valeurs[compteur]);
    }
    return (0);

}