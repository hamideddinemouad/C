#include <stdio.h>
/*
* factorielle - prend deux entiers en paramètres et retourne leur factorielle
* @a : numero
* return: la factorielle nombre
*/
int factorielle(int a)
{
    int compteur;
    int factorielle = 1;

    for (compteur = a; compteur > 0 ; compteur--)
    {
        factorielle = factorielle * compteur;
    }
    return (factorielle);
}
/*
*   main - entree du programme
*   return: factorielle des deux parametres
*/
int main()
{
    int a = 5;
    printf("factorielle  de %d = %d\n", a, factorielle(a));
    return (0);
}