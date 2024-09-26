#include <stdio.h>

/**
* main - entrée du program
* 
* Description: demande un nombre à l’utilisateur et affiche sa table de multiplication de 1 à 10
*
* Return: Toujours 0 (succès)
*/

int main()
{
    int nombre;
    int multiplicateur = 1;
    int resultat;
    //variable pour multiplier
    //commence de 1 pour ne pas multiplier par 0
    
    printf("Nombre ?\n");
    scanf("%d", &nombre);
    //utiliser une for loop avec multiplicateur pour generer les nombres a multiplier avec
    for (multiplicateur; multiplicateur <= 10; multiplicateur++)
    {
        printf("%d X %d = %d\n", nombre, multiplicateur, (nombre * multiplicateur));
    }
    return (0);
}