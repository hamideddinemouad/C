#include <stdio.h>

/**
* main - entrée du program
* 
* Description: calcule la factorielle d'un nombre entier positif n entré par l’utilisateur
*
* Return: Toujours 0 (succès)
*/

int main()
{
    
    int compteur, nombre, nombre_original;

    printf("entrez un nombre pour avoir son factorielle!!\n");
    scanf("%d", &nombre);
    if (nombre <= 0)
    {
        printf("pas de factorielle pour les nombres negatives et 0\n");
        return (0);
    }
    nombre_original = nombre;
    compteur = nombre - 1;
    //faut une boucle  qui va a l'envers
    for (compteur; compteur > 0; compteur--)
    {
        //multiplier le nombre par son factorielle
        nombre = compteur * nombre;
    }
    printf("%d! = %d", nombre_original, nombre);
}
