#include <stdio.h>
#include <math.h>

/**
* main - entrée du program
* 
* Description: calculer les solutions possibles d’une équation du deuxième degré
*
* Return: Toujours 0 (succès)
*/

int main()
{
    int a, b, c, delta, solution, solution1, solution2;

    printf("a ?\n");
    scanf("%d", &a);
    printf("b ?\n");
    scanf("%d", &b);
    printf("c ?\n");
    scanf("%d", &c);
    //calcul delta
    delta = (b*b) - 4*(a*c);
    //solutions
    if (delta < 0)
    {
        printf(" Pas de solution à l'equation\n");
        return (0);
    }
    if (delta == 0)
    {
        solution = -(b/(2*a));
        printf("Solution = %d", solution);
        return (0);
    }
    if (delta > 0)
    {
        solution1 = ((b * (-1))- sqrt(delta))/(2 * a);
        solution2 = ((b * (-1))+ sqrt(delta))/(2 * a);
        printf("Deux solutions approximative possible\nsolution 1 = %d\nsolution2 = %d", solution1, solution2);
        return (0);
    }
}