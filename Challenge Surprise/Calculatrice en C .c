#include <stdio.h>
#include <stdlib.h>
#include <math.h>
/**
* menu - fonction pour calculatrice
* 
* Description: affiche le menu de la calculatrice
*
* Return: rien
*/
void menu()
{
    printf("1.Addition : Ajouter deux ou plusieurs nombres.\n");
    printf("2.Soustraction : Soustraire deux nombres.\n");
    printf("3.Multiplication : Multiplier deux ou plusieurs nombres.\n");
    printf("4.Division : Diviser deux nombres, avec gestion de la division par zero.\n");
    printf("5.Moyenne : Calculer la moyenne dune serie de nombres.\n");
    printf("6.Valeur absolue : Calculer la valeur absolue dun nombre.\n");
    printf("7.Exponentiation : Calculer un nombre a une certaine puissance.\n");
    printf("8.Racine carree : Calculer la racine carree dun nombre positif.\n");
    printf("Choisissez une option en entrant le nombre loperation! ou entrez 0 pour quitter\n");
}
/**
* addition - 
* 
* Description: addition de 2 ou plusieurs nombre
*
* Return: 0 (succes)
*/
int addition()
{
     int nombre_operation, resultat  = 0, nombre_entre;
     
     printf("entrez combien de nombre vous voulez additioner!\n");
     scanf("%d", &nombre_operation);
     //tu additionne combien de fois according to nombe_operation
     for (; nombre_operation > 0; nombre_operation--)
     {
         printf("entrez un nombre \n");
         scanf("%d", &nombre_entre);
         resultat += nombre_entre;
     }
     printf("resultat = %d\n", resultat);
     return (0);
}
/**
* soustraction - soustracttion
* 
* Description: affiche le menu de la calculatrice
*
* Return: rien
*/
int soustraction()
{
     int a, b, resultat;
     
     printf("soutraction\nEntrez nombre A (a-b)\n");
     scanf("%d", &a);
     printf("entrez nombre b\n");
     scanf("%d", &b);
     resultat = a - b;
     printf("resultat = %d\n", resultat);
     return (0);
}
/**
* menu - affichage
* 
* Description: affiche le menu de la calculatrice
*
* Return: rien
*/
int mutliplication()
{
     int nombre_operation, resultat  = 1, nombre_entre;
     
     printf("entrez combien de nombre vous voulez multiplier!\n");
     scanf("%d", &nombre_operation);
     //tu additionne combien de fois according to nombe_operation
     for (; nombre_operation > 0; nombre_operation--)
     {
         printf("entrez un nombre \n");
         scanf("%d", &nombre_entre);
         resultat = resultat * nombre_entre;
     }
     printf("resultat = %d\n", resultat);
     return (0);
}
/**
* division - fonction pour calculatrice.C
* 
* Description: divise les nombres
*
* Return:  Toujours 0 (succès)
*/
int division()
{
    int nominateur, denominateur, resultat;

    printf("entrez nominateur\n");
    scanf("%d", &nominateur);
    printf("entrez denominateur\n");
    scanf("%d", &denominateur);
    if (denominateur == 0)
    {
        printf("division par zero impossible\n");
        return (0);
    }
    resultat = nominateur / denominateur;
    printf("%d\n", resultat);
    return (0);
}
/**
* moyenne - moyenne
* 
* Description: affiche la moyenne d'un groupe de nombre
*
* Return: toujours 0
*/
int moyenne()
{
     int nombre_operation, resultat  = 0, nombre_entre, nombre_entre_copie;
     
     printf("entrez combien de nombre vous voulez leur moyenne!\n");
     scanf("%d", &nombre_operation);
     //tu additionne combien de fois according to nombe_operation
     nombre_entre_copie = nombre_operation;
     for (; nombre_operation > 0; nombre_operation--)
     {
         printf("entrez un nombre \n");
         scanf("%d", &nombre_entre);
         resultat = resultat + nombre_entre;
     }
     //printf("nombre_operation %d\n", nombre_operation);
     resultat = resultat / nombre_entre_copie;
     printf("resultat = %d\n", resultat);
     return (0);
}
/**
* valeur_absolue - valeur absolue
* 
* Description: valeur_absolue d'un nombre
*
* Return: Toujours 0 (succès)
*/
int valeur_absolue()
{
    int valeur;

    printf("entrez une valeur\n");
    scanf("%d", &valeur);
    if (valeur > 0)
    {
        printf("valeur absolue = %d\n", valeur);
        return (0);
    }
    valeur = valeur * -1;
    printf("valeur absolue = %d\n", valeur);
    return (0);
}
/**
* exponentiation - exponentiation
* 
* Description: expononente un nombre
*
* Return:Toujours 0 (succès)
*/
int exponentiation()
{
    int result, number, exponent;

    printf("entrez un numero\n");
    scanf("%d", &number);
    printf("entrez un exponent\n");
    scanf("%d", &exponent);
    result = pow(number, exponent);
    printf("numero %d a l'exponent %d = %d\n", number, exponent, result);
    return (0);
}
/**
* racine_carre - racine carré
* 
* Description: racine carré d'un nombre
*
* Return: Toujours 0 (succès)
*/
int racine_carre()
{
    int resultat, numero;
    printf("entrez un nombre positif pour calculer son racine carré\n");
    scanf("%d", &numero);
    if (numero < 0)
    {
        printf("que les numero positive\n");
        return (0);
    }
    resultat = sqrt(numero);
    printf("racine carre de %d est %d\n", numero, resultat);
    return (0);
}
/**
* main - entrée du program
* 
* Description: calculatrice
*
* Return: Toujours 0 (succès)
*/
int main()
{
    //creation du menu
    int choix;
    while (1)
    {
    menu();
    scanf("%d", &choix);
    switch (choix)
    {
        case 0:
            return(0);
        case 1:
            addition();
            break;
        case 2:
            soustraction();
            break;
        case 3:
            mutliplication();
            break;
        case 4:
            division();
            break;
        case 5:
            moyenne();
            break;
        case 6:
            valeur_absolue();
            break;
        case 7:
            exponentiation();
            break;
        case 8:
            racine_carre();
            break;
    }
    }
    return (0);
}