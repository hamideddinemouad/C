#include <stdio.h>
/*
* struct rectangle - donnee d'un rectangle
* @longeur: longeur rectangle
* @largeur: largeur rectangle
*/
struct rectangle
{
    int longeur;
    int largeur;
};
/*
* calcul_air - fonction calcul
* description : calcul aire de rectangle
* @a : largeur ou longeur
* @b : largeur ou longeur
* return: a X b
*/
int calcul_air(a, b)
{
    return (a*b);
}
/*
* main - entree programme
* description : programme qui calcule l'aire d'un rectangle
* return: toujours 0 (succes)
*/
int main()
{
    struct rectangle rectangle_instance = {2, 5};
    int aire;

    aire = calcul_air(rectangle_instance.longeur, rectangle_instance.largeur);
    printf("aire = %d \n", aire);
    return(0);
}
