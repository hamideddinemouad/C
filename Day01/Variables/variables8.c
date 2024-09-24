#include <stdio.h>
#include <math.h>

/**
* main - entrée du program
* 
* Description:  trouver la moyenne géométrique de trois nombres saisis par l'utilisateur  
*
* Return: Toujours 0 (succès)
*/

int main()
{
    double user_num1, user_num2, user_num3, result;

    printf("nombre 1?\n");
    scanf("%2lf", &user_num1);
    printf("nombre 2?\n");
    scanf("%2lf", &user_num2);
    printf("nombre 3?\n");
    scanf("%2lf", &user_num3);
    //(a * b * c)^(1/3)
    result = pow((user_num1 * user_num2 * user_num3), 1/3 );
    printf("result = %2lf", result);
    return (0);
}