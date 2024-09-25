#include <stdio.h>

/**
* main - entrée du program
* 
* Description: affiche les informations que l'utilisateur a entré
*
* Return: Toujours 0 (succès)
*/

int main(void)
{
    char nom[100], prenom[100], age[100], sexe[100], mail[100];
    printf("Nom ?\n");
    scanf("%s", nom);
    printf("Prenom ?\n", prenom);
    scanf("%s", prenom);
    printf("Age ?\n");
    scanf("%s", age);
    printf("Sexe ?\n");
    scanf("%s", sexe);
    printf("Email ?\n");
    scanf("%s", mail);
    printf("nom :%s\nprenom : %s\nage :%s\nsexe: %s\nemail : %s\n", nom, prenom, age, sexe, mail);
    return (0);
}