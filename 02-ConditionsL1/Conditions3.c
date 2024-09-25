#include <stdio.h>

/**
* main - entrée du program
* 
* Description:  calculer la somme de deux valeurs entières données. 
*               Si les deux valeurs sont identiques, le programme doit 
*               renvoyer le triple de leur somme.
*
* Return: Toujours 0 (succès)
*/

int main()
{
    //if two values given are the same you give triple of their sum else you just return sum of them
    int number1, number2, sum;

    printf("Premier numero ?\n");
    scanf("%d", &number1);
    printf("deuxieme numbero ?\n");
    scanf ("%d", &number2);
    if (number1 == number2)
    {
        sum = (number1 + number2) * 3;
        printf("jackpot %d\n", sum);
        return (0);
    }
    sum = number1 + number2;
    printf("somme = %d\n", sum);
    return (0);
}