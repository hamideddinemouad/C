#include <stdio.h>
#include <math.h>

/**
* main - entrée du program
* 
* Description: vérifier si le caractère donné est un alphabet majuscule ou non
*
* Return: Toujours 0 (succès)
*/

int main()
{
    char letter;
    
    printf("Entrez une lettre\n");
    scanf("%c", &letter);

    if (letter >= 65 && letter <= 90)
    {
        printf("Majuscule\n");
    }
    else
    {
        printf("Miniscule ou pas une lettre\n");
    }
    return (0);
}