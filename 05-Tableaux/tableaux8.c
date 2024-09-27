#include <stdio.h>
/**
* main - entrée du program
* 
* Description: demande à l'utilisateur de saisir un tableau d'entiers, 
* puis affiche le tableau inversé
*
* Return: toujours 0 (succès)
*/
int main()
{
    int tableau_saisi[10] = {0}, compteur, entree, temp, compteur_envers = 10, compteur2;
    printf("saisissez des nombres\n");
    //remplissage du tableau
    for (compteur = 0; compteur < 10; compteur++)
    {
        printf("valeur %d\n", compteur + 1);
        scanf("%d", &entree);
        tableau_saisi[compteur] = entree;
    }
    //print tableau
    printf("tableau original\n");
    printf("[");
    for (compteur = 0; compteur < 10; compteur++)
    {
        printf("%d", tableau_saisi[compteur]);
        if (compteur < 9)
        {
            printf(", ");
        }
    }
    for (compteur = 0; compteur < 4; compteur++)
    {
        compteur_envers--;
        temp = tableau_saisi[compteur];
        tableau_saisi[compteur] = tableau_saisi[compteur_envers];
        tableau_saisi[compteur_envers] = temp;
    }
    printf("]\n");
    printf("tableau a l'envers\n");
    printf("[");
    for (compteur = 0; compteur < 10; compteur++)
    {
        printf("%d", tableau_saisi[compteur]);
        if (compteur < 9)
        {
            printf(", ");
        }
    }
    printf("]\n");
}

