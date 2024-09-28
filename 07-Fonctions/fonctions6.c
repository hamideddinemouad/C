#include <stdio.h>
/*
* fibonacci -  prendre un entier en paramètre et retourner le n-ième terme
* @a : numero
* return: la fibonacci nombre
*/
int fibonacci(int a)
{
    int i;
    int fibonacci = 2;
    int fibonacci_prec = 1;
    int temp;

    for (i = 0; i < a - 2; i++)
    {
        temp = fibonacci; //
        fibonacci = fibonacci_prec + fibonacci; 
        fibonacci_prec = temp;
    }
    return (fibonacci);
}
/*
*   main - entree du programme
*   return: fibonacci des deux parametres
*/
int main()
{
    int a = 5;
    printf("le nombre  %d de la suite fibonacci = %d\n", a, fibonacci(a));
    return (0);
}