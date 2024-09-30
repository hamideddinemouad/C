#include <stdio.h>
/**
* struct infos - structure to hold personal infos
* @name : tableau pour string
* @prenom : tableau pour string
* @age : int pour stocker l'age
 */
struct infos
{
    char name[7]; // pour determiner la taille du tableau strlen(string) + 1;
    char prenom[15];
    int age;
};
/**
    * main - entree du programme;
    *
    * description : afficher les valeur d'un struct;
    *
    * return: toujours 0 (succès);
*/
int main()
{
    struct infos infos_instance = {"yousra", "hamideddine", 25};
    printf(" -prenom : %s\n -nom: %s\n -age : %d ", infos_instance.name, infos_instance.prenom, infos_instance.age);
    return (0);
}