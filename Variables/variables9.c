#include <stdio.h>
#include <math.h>

/**
* main - entrée du program
* 
* Description:  trouver la distance entre deux points donnés dans un espace 3D  
*
* Return: Toujours 0 (succès)
*/

int main()
{
    double x1, x2, y1, y2, z1, z2, result, pos_x, pos_y, pos_z;
    printf("x1 ?\n");
    scanf("%2lf", &x1);
    printf("y1 ? \n");
    scanf("%2lf", &y1);
    printf("z1 ? \n");
    scanf("%2lf", &z1);
    printf("x2 ?\n");
    scanf("%2lf", &x2);
    printf("y2 ? \n");
    scanf("%2lf", &y2);
    printf("z2 ? \n");
    scanf("%2lf", &z2); 
    //Distance = √((x2-x1)² + (y2-y1)² + (z2-z1)²)
    //pour faciliter la lecture du code les pos seront calculé separément
    pos_x = (x2 - x1) * (x2 -x1);
    pos_y = (y2 - y1) * (y2 - y1);
    pos_z = (z2 - z1) * (z2 - z1);
    printf("pos_x = %2lf\n", pos_x);
    //printf("%2lf\n", pos_y);
    //printf("%2lf\n,", pos_z);
    result = sqrt((pos_x + pos_y + pos_z));
    printf("distance = %2lf\n", result);
    return 0;
}

    