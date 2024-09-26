#include <stdio.h>

/**
* main - entrée du program
* 
* Description: affiche la somme des éléments d'un tableau d'entiers. Le programme doit demander
* le nombre d'éléments, puis les éléments du tableau, et afficher la somme totale
*
* Return: toujours 0 (succès)
*/

int main()
{
    int nombre_valeurs, compteur = 0;

    printf("combien d'entree ?\n");
    scanf("%d", &nombre_valeurs);

    int valeurs[nombre_valeurs], somme = 0;

    for (compteur = 0; compteur < nombre_valeurs; compteur++)
    {
        printf("valeur %d ?\n", compteur + 1);
        scanf("%d", &valeurs[compteur]);
    }
    for (compteur = 0; compteur < nombre_valeurs; compteur ++)
    {
        somme += valeurs[compteur];
    }
    printf("somme = %d\n", somme);
    return (0);
}