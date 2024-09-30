#include <stdio.h>
#include <string.h>
/*
* string_inverse -  prendre un string et l'inverse
* @tableau : string
* return: rien
*/
void string_inverse(char tableau[])
{
    int index;

    printf("size of(tableau) %d= \n", strlen(tableau));

    for (index = strlen(tableau); index >= 0; index--)
    {
        printf("%c", tableau[index]);
    }
}
/*
*   main - entree du programme
*   return: (0) afficher une chaîne inversée
*/
int main()
{
    char caracteres[] = "a, b, c, d, e, f, g, h, i, j, k, l, m, n, o, p, q, r, s, t, u, v, w, x, y, z";
    string_inverse(caracteres);
}