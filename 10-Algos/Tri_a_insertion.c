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
    int taille_tableau = 11;
    int index = 1;
    int iterations = 0;
    //int index2;
    int temp;

    printf("Avant:");
    print_tableau_int(taille_tableau, tableau);

    while(index < taille_tableau)
    {
        printf("index = %d\n", index);
        if (tableau[index] < tableau[index - 1])
        {
            temp = tableau[index];
            tableau[index] = tableau[index - 1];
            tableau[index - 1] = temp;
            if (index > 1)
            {
                index = index - 2;
            }
        }
        index++;
        iterations++;
    }
    printf("apres:");
    print_tableau_int(taille_tableau, tableau);
    printf("iterations: %d", iterations);
    return (0);
}