#include <stdio.h>
/**
* struct position - type de donnée
* @x: position x ;
* @y: position y;
*/
struct position
{
    int x;
    int y;
};
/**
 * modifier_x - modifier x et y a l'aide des pointeurs
 * description : modifier x et y a l'aide des pointeurs
 * @x: position x
 * @y: position y
 * @x_m: valeur pour remplacer x
 * @y_m: valeur pour remplacer y
 * return: rien
*/
void modifier_x_y(int *x, int *y, int x_m , int y_m)
{
    *x = x_m;
    *y = y_m;
}
/*
* main - entree programme
* description : créer une variable 
* de cette structure et modifiez ses valeurs
* return: toujours 0 (succes)
*/
int main()
{
    struct position position_instance = {1, 5};
    modifier_x_y(&position_instance.x,  &position_instance.y, 3, 4);
    printf("x = %d, y = %d\n", position_instance.x, position_instance.y);
}