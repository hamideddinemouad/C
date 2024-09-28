#include <stdio.h>
/*
* minimum - prend deux entiers en paramètres et retourne leur minimum
* @a : numero
* @b : numero
* return: la minimum nombre
*/
int minimum(int a, int b)
{
    if (a > b)
    {
        return(b);
    }
    return (a);
}
/*
*   main - entree du programme
*   return: minimum des deux parametres
*/
int main()
{
    int a = 100, b = 2;
    printf("minimum(a, b) = %d\n", minimum(a, b));
    return (0);
}