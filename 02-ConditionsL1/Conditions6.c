#include <stdio.h>
#include <math.h>

/**
* main - entrée du program
* 
* Description: vérifier si le nombre donné est positif, négatif ou nul
*
* Return: Toujours 0 (succès)
*/

int main()
{
    int number;
    printf("entrez un nombre\n");
    scanf("%d", &number);
    if (number > 0)
    {
        printf("positive\n");
    }
    else if (number < 0)
    {
        printf("negative\n");
    }
    else if (number == 0)
    {
        printf("nulle\n");
    }
    return (0);
}