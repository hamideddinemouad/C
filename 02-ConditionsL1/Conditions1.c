#include <stdio.h>

/**
* main - entrée du program
* 
* Description: demande un nombre et affiche si ce nombre est pair ou impair
*
* Return: Toujours 0 (succès)
*/

int main()
{
    int number;

    printf("Entrez un numero!!");
    scanf("%d", &number);
    if (number % 2 == 0)
    {
        printf("paire");
    }
    else
    {
        printf("impaire");
    }
    return (0);
}