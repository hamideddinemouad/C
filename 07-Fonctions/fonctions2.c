#include <stdio.h>
/*
* mutliplication - prend deux entiers en paramètres et retourne leur mutliplication
* @a : numero
* @b : numero
* return: la mutliplication de a et b
*/
int mutliplication(int a, int b)
{
    return (a*b);
}
/*
*   main - entree du programme
*   return: mutliplication des deux parametres
*/
int main()
{
    int a = 7, b = 2;
    printf("mutliplication(a, b) = %d\n", mutliplication(a, b));
    return (0);
}