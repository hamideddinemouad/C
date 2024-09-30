#include <stdio.h>
/**
* struct infos - infos livres
* @auteur: str ;
* @titre: str;
* @annee: int;
*/
struct livre
{
    char *titre;
    char *auteur;
    int annee;
};
/**
 * creation_livre - fonction
 * description : cree une struct livre avec des donnes fourni en parametres
 * return: retourne une variable de struct position avec des valeurs
 * données
*/
struct livre creation_livre(char* _titre, char* _auteur, int annee)
{
    struct livre livre_f = {_titre, _auteur, annee};
    return (livre_f);
}
/*
* main - entree programme
* description: initiation d'une struct livre
* return: toujours 0 (succes)
*/
int main()
{
    struct livre livre_1 = creation_livre("a book ", "an author", 2000);
    printf("titre : %s\n, auteur : %s, annee : %d\n", livre_1.titre, livre_1.auteur, livre_1.annee);
}