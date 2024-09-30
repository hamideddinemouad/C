#include <stdio.h>
//Écrivez un programme C qui définit une structure pour représenter un étudiant avec les champs nom,
//prenom, et un tableau d'entiers pour stocker les notes. Assignez des valeurs aux champs et aux notes,
//puis affichez les informations de l'étudiant.

/**
* struct infos - structure to hold personal infos
* @nom : tableau pour string
* @prenom : tableau pour string
* @age : int pour stocker l'age
 */
struct infos
{
    char nom[7]; // pour determiner la taille du tableau strlen(string) + 1;
    char prenom[15];
    int notes[5];
};
/**
    * main - entree du programme;
    *
    * description : afficher les informations de l'étudiant;
    *
    * return: toujours 0 (succès);
*/
int main()
{
    int compteur;
    int taille_tableau;
    struct infos infos_instance = {"yousra", "hamideddine", {5, 10, 15, 17, 20}};

    printf(" -prenom : %s\n -nom: %s\n", infos_instance.nom, infos_instance.prenom);
    //taille_tableau = sizeof(infos_instance.notes)/sizeof(infos_instance.notes[0]);
    taille_tableau = 5;
    for (compteur = 0; compteur < taille_tableau; compteur++)
    {
        printf("note %d: %d\n", compteur + 1, infos_instance.notes[compteur]);
    }
    return (0);
}