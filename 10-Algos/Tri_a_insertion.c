#include <stdio.h>
/*
* print_tableau_int - fonction pour main
* @taille: taille du tableau
*
* description: printf tableau d'entiers
*
* return: Toujours 0 succes
*/
int print_tableau_int(int taille, int tableau[])
{
    int i;
    printf("[");
    for (i = 0; i < taille; i++)
    {
        if (i != taille - 1)
        {
            printf("%d, ", tableau[i]);
        }
        else if (i == taille -1)
        {
            printf("%d]\n", tableau[i]);
        }
    }
    return (0);
}
/*
* main - entree du programme
*
* description - implementation de tri à insertion
*
* return:  toujours 0;
*/
int main()
{
    int tableau[] = {1, 5, 0, 9, 4, 7, 2, 5, -1};
    int taille_tableau = 9;
    int index1;
    int index2;
    int temp;
    printf("Avant:");
    print_tableau_int(taille_tableau, tableau);
    temp = tableau[0];
    for (index1 = 0; index1 < taille_tableau; index1++)
    {
        for (index2 = 0; index2 < taille_tableau; index2++)
        {
            if (tableau[index2] > tableau[index2 + 1])
            {
                temp = tableau[index2];
            }
        }
    }
    printf("apres:");
    print_tableau_int(taille_tableau, tableau);
    return (0);
}
