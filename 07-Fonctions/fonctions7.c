#include <stdio.h>
/*
* fibonacci -  prendre un entier en paramètre et retourner le n-ième terme
* @a : numero
* return: la fibonacci nombre
*/
int fibonacci(int a)
{
    int i;
    int fibonacci = 1;
    int fibonacci_prec = 0;
    int temp;

    for (i = 0; i < a; i++)
    {
        temp = fibonacci; //
        fibonacci = fibonacci_prec + fibonacci; 
        fibonacci_prec = temp;
        printf("fibonaaci = %d", fibonacci);
    }
    return (fibonacci);
}
/*
*   main - entree du programme
*   return: fibonacci des deux parametres
*/
int main()
{
    int a = 10;
    printf("le nombre  %d de la suite fibonacci = %d\n", a, fibonacci(a));
    return (0);
}