#include <stdio.h>

/**
* main - entrée du program
* 
* Description: calculer la moyenne pondérée de trois nombres donnés par l'utilisateur  
*
* Return: Toujours 0 (succès)
*/

int main()
{
    double user_num1, user_num2, user_num3, result;
    printf("1 er nombre ?\n");
    scanf("%2lf", &user_num1);
    printf("2 eme nombre ?\n");
    scanf("%2lf", &user_num2);
    printf("3 eme nombre ?\n");
    scanf("%2lf", &user_num3);
    result = (user_num1 * 2 + user_num2 * 3 + user_num3 * 5) / 10;
    printf("la moyenne ponderee est %2lf\n", result);
}