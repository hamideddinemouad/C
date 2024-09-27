#include <stdio.h>

/**
* main - entrée du program
* 
* Description: demande à l'utilisateur de saisir un tableau d'entiers, 
* puis affiche le tableau trié en ordre croissant
*
* Return: toujours 0 (succès)
*/



int main ()
{
    int tableau_saisi[10] = {0};
    int compteur = 0, compteur2 = 0;
    int entree, element_actuel, element_suivant, temp;

    //demande à l'utilisateur de saisir un tableau d'entiers
    //puis affiche le tableau trié en ordre croissant
    //enregistrement des donnés entré
    printf("saisissez des nombres\n");
    //remplissage du tableau
    for (compteur; compteur < 10; compteur++)
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
    printf("]\n");
    for (compteur2 = 0; compteur2 < 10; compteur2++)
    {
        for (compteur = 0; compteur < 10; compteur++)
        {
            element_actuel = tableau_saisi[compteur];
            element_suivant = tableau_saisi[compteur + 1];
            if (element_actuel > element_suivant)
            {
                temp = tableau_saisi[compteur + 1];
                tableau_saisi[compteur + 1] = tableau_saisi[compteur];
                tableau_saisi[compteur] = temp;
            }
        }
    }
    printf("tableau modifie\n");
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
    return (5);
}