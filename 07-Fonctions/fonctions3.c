#include <stdio.h>
/*
* maximum - prend deux entiers en paramètres et retourne leur maximum
* @a : numero
* @b : numero
* return: la maximum nombre
*/
int maximum(int a, int b)
{
    if (a > b)
    {
        return (a);
    }
    return (b);
}
/*
*   main - entree du programme
*   return: maximum des deux parametres
*/
int main()
{
    int a = 100, b = 2;
    printf("maximum(a, b) = %d\n", maximum(a, b));
    return (0);
}