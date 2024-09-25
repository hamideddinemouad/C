#include <stdio.h>

/**
* main - entrée du program
* 
* Description: vérifie si un caractère saisi par l'utilisateur est une voyelle ou non
*
* Return: Toujours 0 (succès)
*/

int main()
{
    char letter;
    printf("entrez une lettre!\n");
    scanf("%c", &letter);
    //printf("letter = %c", letter);*
    // vowels : a, e, i, o, u
    switch (letter)
    {
        case 'a':
        case 'e':
        case 'i':
        case 'o':
        case 'u':
            printf("Voyelle !!\n");
            break;
        default:
            printf("Lettre !!\n");
        return (0);
    }
}