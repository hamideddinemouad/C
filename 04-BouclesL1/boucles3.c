#include <stdio.h>

/**
* main - entrée du program
* 
* Description: demande un nombre entier n à l’utilisateur et calcule la
* somme des n premiers nombres naturels
* Return: Toujours 0 (succès)
*/

int main()
{
    
    int compteur, nombre, nombre_original;

    printf("entrez un nombre  n pour  avoir la somme ses n premiers nombres naturels\n");
    scanf("%d", &nombre);
    if (nombre <= 0)
    {
        printf("pas de 0 ou nombre negatives\n");
        return (0);
    }
    //pour n = 4, la somme est 1 + 2 + 3 + 4 = 10.
    //compteur retour en arriere
    compteur = nombre -1;
    nombre_original = nombre
    for (compteur; compteur <= 0; compteur--)
    {
        nombre = nombre + compteur;
    }
    //comment print les nombres avant n et du plus petit au grand
    //on peut les stocker dans un tableau ? TROP COMPLIQUE
    //sachant que le compteur diminue avec la boucle comment peut on utiliser ça 
    printf("%d");
}

