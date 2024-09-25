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
    switch ()
    {
        case moyenne < 10:
            printf("recalé\n");
            break;
        case moyenne < 12:
            printf("passable\n");
            break;
        case moyenne < 14:
            printf("assez bien\n");
            break;
        case moyenne < 16:
            printf("bien\n");
            break;
        default:
            printf("tres bien\n");
            break;
    }
    return (0);
}