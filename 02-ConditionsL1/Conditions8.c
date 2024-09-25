#include <stdio.h>
#include <math.h>

/**
* main - entrée du program
* 
* Description: donner une mention a la note
*
* Return: Toujours 0 (succès)
*/

int main()
{
    int moyenne;

    printf("entrez une moyenne!\n");
    scanf("%d", &moyenne);

    if (moyenne < 10)
    {
        printf("recale\n");
    }
    else if (moyenne < 12)
    {
        printf("passable\n");
    }
    else if (moyenne < 14)
    {
        printf("assez bien\n");
    }
    else if (moyenne < 16)
    {
        printf("bien\n");
    }
    else
    {
        printf("Tres bien\n");
    }
    return (0);
}