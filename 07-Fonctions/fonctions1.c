#include <stdio.h>
/*
* somme - prend deux entiers en paramètres et retourne leur somme
* @a : numero
* @b : numero
* return: la somme de a et b
*/
int somme(int a, int b)
{
    return (a + b);
}
/*
*   main - entree du programme
*   return: somme des deux parametres
*/
int main()
{
    int a = 7, b = 2;
    printf("somme(a, b) = %d\n", somme(a, b));
    return (0);
}