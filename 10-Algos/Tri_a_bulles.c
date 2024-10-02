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
}
/*
* main - entree du programme
*
* description - implementation de tri à bulles
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
    for (index2 = 0; index2 < taille_tableau; index2++)
    {
        for (index1 = 0; index1 < taille_tableau; index1++)
        {
            if (tableau[index1] > tableau[index1 + 1])
            {
                temp = tableau[index1];
                tableau[index1] = tableau[index1 + 1];
                tableau[index1 + 1] = temp;
            }
        }
    }
    printf("apres:");
    print_tableau_int(taille_tableau, tableau);
    return (0);
}
