#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <string.h>
#include <ctype.h>
/**
* menu - fonction menu du programme
*
* description: affiche le menu du programme
*
* return: rien;
*/
#define RED "\033[31m"
#define BLUE "\033[34m"
#define RESET "\033[0m"
#define GREEN "\033[32m"


void menu()
{
    printf(BLUE "Bienvenue dans Docteur Reservation\n" RESET);
    sleep(3);
    printf("*******************************************\n");
    printf("1. Ajouter une reservation\n");
    printf("2. Modifier ou supprimer une reservation\n");
    printf("3. Afficher les details d'une reservation\n");
    printf("4. Tri des reservation\n");
    printf("5. Recherche des reservation\n");
    printf("6. Statistiques \n");
    printf("0. Quitter\n");
    printf("*******************************************\n");
    printf("Entrez le numero de l'option que vous souhaitez !\n");
}
/**
* patient - structure pour les infos du patient
* @nom: tableau pour string
* @telephone: tableau pour string
* @telephone: tableau pour string
* @age: int
* @statut: char
* @reference: int
*/
typedef struct infos_patient
{
    char nom[100];
    char prenom[100];
    char telephone[100];
    int age;
    char statut[10];
    char date_reservation[100];
    int reference;
}patient;
int id = 11;
int index_ajout = 10; //PEUT CREER DES PROBLEMES
patient base_patients[100] = 
{
    {"hamideddine", "mouad", "0602030405", 0, "VALIDE", "01-10-2024", 1},
    {"lasfar", "souhail", "0602030406", 18, "REPORTE", "02-10-2024", 2},
    {"benani", "yousra", "0602030407", 45, "ANNULE", "03-10-2024", 3},
    {"saanane", "idriss", "0602030408", 60, "TRAITE", "04-10-2024", 4},
    {"ouarzazi", "hamza", "0602030409", 35, "VALIDE", "05-10-2024", 5},
    {"aitAhmed", "rachid", "0602030410", 50, "REPORTE", "06-10-2024", 6},
    {"zahraoui", "mustapha", "0602030411", 28, "ANNULE", "07-10-2024", 7},
    {"boulahdour", "soufiane", "0602030412", 36, "TRAITE", "08-10-2024", 8},
    {"benjelloun", "anass", "0602030413", 47, "VALIDE", "09-10-2024", 9},
    {"elHachimi", "khadija", "0602030414", 19, "REPORTE", "10-10-2024", 10}
};
/**
 * no_new_line - Retire le caractère de nouvelle ligne '\n'
 * @tableau: adresse du tableau à modifier
 *
 * Description: remplace le caractère '\n' par '\0' pour éviter les problèmes
 *
 * Return: rien
 */
void no_new_line(char *tableau)
{
    int index_no_new_line = 0;

    while (tableau[index_no_new_line] != '\0')
    {
    if (tableau[index_no_new_line] == '\n')
    {
        tableau[index_no_new_line] = '\0';
        break;
    }
    index_no_new_line++;
    }
}
/**
 * tab_null - tableau a '\0'
 * @tableau: adresse tableau a réinitialiser
 *
 * Description: Cette fonction parcourt un tableau et remplace chaque place '\0' pour eviter les problemes
 *
 * return: rien
 */
void tab_null(char* tableau)
{
    int index = 0;

    while (tableau[index])
    {
        tableau[index] = '\0';
        index++;
    }
}
/**
* mon_fgets - fgets personalisé
*
* description: fgets et tab null et new_line appelé a la fois 
*
* return: rien;
*/

int mon_fgets(char* buffer)
{
    if (!buffer)
    {
        printf("erreur 1\n");
        return (-1);
    }
    tab_null(buffer);
    fgets(buffer, 100, stdin);
    no_new_line(buffer);
    return (0);
}

 /**
 * affiche_patient - affiche infos patient par index 
 *
 * description: affiche infos patient par index 
 *
 * return: rien*/

 void affiche_patient(int index_affiche)
 {
    if (base_patients[index_affiche].nom[0] != '\0')
    {
        printf("*******************************************\n");
        printf("nom - %s\n", base_patients[index_affiche].nom);
        printf("prenom - %s\n", base_patients[index_affiche].prenom);
        printf("telephone - %s\n", base_patients[index_affiche].telephone);
        printf("age - %d\n", base_patients[index_affiche].age);
        printf("statut - %s\n", base_patients[index_affiche].statut);
        printf("date de reservation - %s\n", base_patients[index_affiche].date_reservation);
        printf("id - %d\n", base_patients[index_affiche].reference);
        printf("*******************************************\n");
    }
 }
/**
 * recherche_contact - recherche un patient par nom
 * @recherche_contact_nom: nom du contact à rechercher
 *
 * Description: parcourt la liste des contacts pour trouver un nom qui correspond
 *
 * Return: 0 si trouvé, -1 si non trouvé
 */
int recherche_patient_nom(char* nom_recherche)
{
    int index_recherche_patient;

    for (index_recherche_patient = 0; index_recherche_patient <= index_ajout; index_recherche_patient++)
    {
        if (strcmp(base_patients[index_recherche_patient].nom, nom_recherche) == 0)
        {
            // printf("recherche_contact FUNCTION\n");
            return (index_recherche_patient); //index contact deja existant
        }
    }
    return (-1); // contact non existant
}
int test_non_alpha(char *str) 
{
    int i = 0;

    while (str[i] != '\0') 
    {
        if (!isalpha(str[i]) && str[i] != ' ') 
        {
            return (-1); // -1 si caractere non alpha detecte
        }
        i++;
    }

    return 1; // 1 si str est valide
}
/**
* ajouter_nom - ajoute nom du patient
*
* description: ajoute nom du patient
*
* return: 0 si succes 1 si echec;
*/
int ajouter_nom()
{
    char buffer_ajout_nom[100];
    
    printf("veuillez ajouter un nom\n");
    mon_fgets(buffer_ajout_nom);
    if (test_non_alpha(buffer_ajout_nom) < 0)
    {
        printf("\033[31mQue des lettres\033[0m\n");
        ajouter_nom();
        return (0);
    }
    if (recherche_patient_nom(buffer_ajout_nom) >= 0) //contact existant et return index
    {
        printf("\033[31mQue des lettres\033[0m\n");
        ajouter_nom();
        return (0);
    }
    strcpy(base_patients[index_ajout].nom, buffer_ajout_nom);
    printf(BLUE "nom ajoute avec succes\n"  RESET);
    return (0);
}

/**
* ajouter_prenom - ajoute nom du patient
*
* description: ajoute nom du patient
*
* return: 0 si succes 1 si echec;
*/

int ajouter_prenom()
{
    char buffer_ajout_prenom[100];
    
    printf("veuillez ajouter un prenom\n");
    mon_fgets(buffer_ajout_prenom);
    if (test_non_alpha(buffer_ajout_prenom) < 0)
    {
        printf("\033[31mQue des lettres\033[0m\n");
        ajouter_prenom();
        return (0);
    }
    strcpy(base_patients[index_ajout].prenom, buffer_ajout_prenom);
    printf(BLUE "prenom ajoute avec succes\n" RESET);
    return (0);
}
/**
 * ajout_telephone - ajoute un numéro de téléphone au contact
 *
 * Description: on rajoute si le numéro est valide et s'il n'existe pas déjà dans la liste des contacts.
 * 
 * Return: rien (void)
 */
int numero_valide(char* str_numero)
{
    unsigned int numero_valide_index;

    for (numero_valide_index = 0; numero_valide_index < strlen(str_numero); numero_valide_index++)
    {
        if(!isdigit(str_numero[numero_valide_index]))
        {
            //printf("\033[31mQue des lettres\033[0m\n");
            printf(RED "que des numero!!\n" RESET);
            return (0); //fonction a detecté un character autre que numero
        }
    }
    return (-1); //que des numero
}
int recherche_num(char* recherche_contact_num)
{
    int index_recherche_num;

    for (index_recherche_num = 0; index_recherche_num <= index_ajout; index_recherche_num++)
    {
        if (strcmp(base_patients[index_recherche_num].telephone, recherche_contact_num) == 0)
        {
            // printf("recherche_contact FUNCTION\n");
            return (0); //num deja existant
        }
    }
    return (-1); // num non existant
}
/**
 * ajout_telephone - ajoute un numéro de téléphone au contact
 *
 * Description: on rajoute si le numéro est valide et s'il n'existe pas déjà dans la liste des contacts.
 * 
 * Return: rien (void)
 */
int ajouter_telephone()
{
    char buffer_ajout_tel[100];

    printf("Entrez le num de telephone de %s %s\n", base_patients[index_ajout].nom, base_patients[index_ajout].prenom);
    mon_fgets(buffer_ajout_tel);
    if (numero_valide(buffer_ajout_tel) == 0)
    {
        ajouter_telephone(); //character non num detecte
        return (0);
    }
    if (recherche_num(buffer_ajout_tel) == -1)
    {
        strcpy(base_patients[index_ajout].telephone, buffer_ajout_tel);
        printf(BLUE "numero de telephone ajoute\n" RESET);
        return(0);
    }
    printf(RED "numero deja existant\n" RESET);
    ajouter_telephone();
    return (0);
}
/**
 * ajout_telephone - ajoute un numéro de téléphone au contact
 *
 * Description: on rajoute si le numéro est valide et s'il n'existe pas déjà dans la liste des contacts.
 * 
 * Return: rien (void)
 */
int ajouter_age()
{
    char buffer_ajout_age[100];
    int age_to_test;
    
    printf("ajoutez l'age en numero\n");
    mon_fgets(buffer_ajout_age);
    if (strlen(buffer_ajout_age) > 3)
    {
        printf(RED "%s n'est pas un age valide\n" RESET, buffer_ajout_age);
        sleep(3);
        ajouter_age();
        return (0);
    }
    if (numero_valide(buffer_ajout_age) == 0)
    {
        printf(RED "Charactere autre que numero detecte\n" RESET);
        sleep(3);
        ajouter_age();
        return (0);
    }
    age_to_test = atoi(buffer_ajout_age);
    if (age_to_test < 0)
    {
        printf(RED "valeur negative dans l'age detecté entrez une valeur positive\n" RESET);
        sleep(3);
        ajouter_age();
        return (0);
    }
    if (age_to_test > 130)
    {
        printf(RED "age invalide\n" RESET);
        sleep(3);
        ajouter_age();
        return (0);
    }
    base_patients[index_ajout].age = age_to_test;
    printf(BLUE "age : %d  est valide et ajoute avec succes\n" RESET, base_patients[index_ajout].age);
    return (0);
}
/**
 * ajouter_statut- ajouter_statut
 *
 * Description: ajouter_statut
 * 
 * Return: rien (void)
 */
 int ajouter_statut()
 {
    char buffer_ajout_statut[100];

    printf("*******************************************\n");
    printf("Veuillez choisir une statut\n");
    printf("1 - Valide\n");
    printf("2 - Reporte\n");
    printf("3 - Annule\n");
    printf("4 - Traite\n");
    mon_fgets(buffer_ajout_statut);
    if (strlen(buffer_ajout_statut) < 2)
    {
        switch (buffer_ajout_statut[0])
        {
            case '1':
                strcpy(base_patients[index_ajout].statut, "VALIDE");
                printf(BLUE "Statut ajoute\n" RESET);
                return (0);
            case '2':
                strcpy(base_patients[index_ajout].statut, "REPORTE");
                printf(BLUE "Statut ajoute\n" RESET);
                return (0);
            case '3':
                strcpy(base_patients[index_ajout].statut, "ANNULE");
                printf(BLUE "Statut ajoute\n" RESET);
                return (0);
            case '4':
                strcpy(base_patients[index_ajout].statut, "TRAITE");
                printf(BLUE "Statut ajoute\n" RESET);
                return (0);
            default :
                printf(RED "choix introuvable Entrez un numero entre 1 et 4\n" RESET);
                sleep(3);
                ajouter_statut();
                return (0);
        }
    }
    printf(RED "Entree invalide\n" RESET);
    ajouter_statut();
    return(0);
 }
  /**
 * annee_valide- check si jour est valide
 *
 * Description: ajouter_statut
 * 
 * Return: rien (void)
 */
 int annee_valide(char* str_date)
 {
    int numero;

    if (strlen(str_date) > 4)
    {
        printf(RED "que quatre nombres pour lannee par example 2024\n" RESET);
        sleep (3);
        return (-1);
    }
    if (numero_valide(str_date) == 0)
    {
        printf(RED "Charactere autre que numero detecte\n" RESET);
        sleep (3);
        return (-1);
    }
    numero = atoi(str_date);
    if (numero <= 2023 )
    {
        printf(RED "pas de rdv en arriere\n" RESET);
        sleep (3);
        return (-1);
    }
    return (0);
 }
 /**
 * jour_valide- check si jour est valide
 *
 * Description: ajouter_statut
 * 
 * Return: rien (void)
 */
 int jour_valide(char* str_date,int mois)
 {
    int numero;
    int mois_anne[] = {31, 28, 31, 30, 31, 30, 31, 31, 30, 31, 30, 31};
    int condition = mois_anne[mois - 1];

    if (strlen(str_date) > 2)
    {
        printf("que deux nombres pour le jour par example 24\n");
        sleep (3);
        return (-1);
    }
    if (numero_valide(str_date) == 0)
    {
        printf("Charactere autre que numero detecte\n");
        sleep (3);
        return (-1);
    }
    numero = atoi(str_date);
    if (numero > condition || numero < 1 )
    {
        printf(RED "jour %d existe pas\n" RESET, numero);
        sleep (3);
        return (-1);
    }
    return (0);
 }
/**
 * mois_valide- check si mois est valide
 *
 * Description: ajouter_statut
 * 
 * Return: rien (void)
 */
 int mois_valide(char* str_date)
 {
    int numero;

    if (strlen(str_date) > 2)
    {
        printf(RED "que deux nombres pour le mois par example 06 ou 6 pour juin\n" RESET);
        sleep (3);
        return (-1);
    }
    if (numero_valide(str_date) == 0)
    {
        printf(RED "Charactere autre que numero detecte\n" RESET);
        sleep (3);
        return (-1);
    }
    numero = atoi(str_date);
    if (numero > 12 || numero < 1 )
    {
        printf(RED "mois %d existe pas\n" RESET, numero);
        return (-1);
    }
    return (0);
 }
/**
 * ajouter_date- ajouter_date
 *
 * Description: ajouter_statut
 * 
 * Return: rien (void)
 */
 int ajouter_date()
 {
    char buffer_ajout_annee[100];
    char buffer_ajout_mois[100];
    char buffer_ajout_jour[100];
    char date_complete[11];

    printf("choisissez annee de reservation\n");
    mon_fgets(buffer_ajout_annee);
    if (annee_valide(buffer_ajout_annee) < 0)
    {
        ajouter_date();
        return(0);
    }
    printf("choisissez mois de reservation\n");
    mon_fgets(buffer_ajout_mois);
    if (mois_valide(buffer_ajout_mois) < 0)
    {
        ajouter_date();
        return(0);
    }
    printf("choisissez jour de reservation\n");
    mon_fgets(buffer_ajout_jour);
    if (jour_valide(buffer_ajout_jour, atoi(buffer_ajout_mois)) < 0)
    {
        ajouter_date();
        return (0);
    }
    tab_null(date_complete);
    strcat(date_complete, buffer_ajout_jour);
    strcat(date_complete, "-");
    strcat(date_complete, buffer_ajout_mois);
    strcat(date_complete, "-");
    strcat(date_complete, buffer_ajout_annee);
    strcpy(base_patients[index_ajout].date_reservation, date_complete);
    return (0);
 }
/**
* ajouter_res - ajoute reservation
*
* description: ajouter une reservation en faisant appel au differente fonction associé
*
* return: 0 si succes 1 si echec;
*/
int ajouter_reservation()
{

    ajouter_nom();
    ajouter_prenom();
    ajouter_telephone();
    ajouter_age();
    ajouter_statut();
    ajouter_date();
    base_patients[index_ajout].reference = id;
    index_ajout++;
    id++;
    int i = 0;
    for (i = 0; i < index_ajout; i++)
    {
        affiche_patient(i);
    }
    return (0);
}
/**
* main - entree du programme
*
* description: entree du programme et fait appel au fonctions
*
* return: Toujours 0;
*/
int trouver_reservation_id(int id_recherche)
{
    int index;
    //trouver l'id
    for (index = 0; index <= index_ajout; index++)
    {
        if(base_patients[index].reference == id_recherche)
        {
            return(index);
        }
    }
    return (-1);
}
/**
* main - entree du programme
*
* description: entree du programme et fait appel au fonctions
*
* return: Toujours 0;
*/
int supprimer_reservation()
{
    int index = 0;
    int id_suppression;
    char buffer_suppression[100];

    printf("Entrez ID que vous voulez supprimer\n");
    mon_fgets(buffer_suppression);
    if (numero_valide(buffer_suppression) == 0)
    {
        supprimer_reservation();
        return (0);
    }
    id_suppression = atoi(buffer_suppression);
    index = trouver_reservation_id(id_suppression);
    if (index < 0)
    {
        printf(RED "reference introuvable\n" RESET);
        supprimer_reservation();
        return (0);
    }
    printf(RED "reference trouve\n" RESET);
    sleep(2);
    affiche_patient(index);
    sleep(2);
    tab_null(base_patients[index].nom);
    tab_null(base_patients[index].prenom);
    tab_null(base_patients[index].telephone);
    tab_null(base_patients[index].statut);
    tab_null(base_patients[index].date_reservation);
    base_patients[index].reference = 0;
    printf(BLUE "la reference %d a ete supprime avec succes\n" RESET, id_suppression);
    return (0);
}
int modifier_reservation()
{
    int index = 0;
    int id_modification;
    int tmp;
    char buffer_modification[100];

    printf("Entrez ID que vous voulez modifer\n");
    mon_fgets(buffer_modification);
    if (numero_valide(buffer_modification) == 0)
    {
        modifier_reservation();
        return (0);
    }
    id_modification = atoi(buffer_modification);
    index = trouver_reservation_id(id_modification);
    if (index < 0)
    {
        printf(RED "reference introuvable\n" RESET);
        modifier_reservation();
        return (0);
    }
    printf(BLUE "reference trouve\n" RESET);
    sleep(2);
    affiche_patient(index);
    sleep(2);
    printf("*******************************************\n");
    printf("entrez ce que vous  voulez modifier\n");
    printf("1- pour modifier le nom\n");
    printf("2 - pour modfiier l'age\n");
    printf("3 - pour modifier telephone \n");
    printf("4 - pour modifier statut\n");
    printf("5 - pour modifier la date de reservation \n");
    printf("6 - pour modifier le prenom \n");
    printf("*******************************************\n");
    mon_fgets(buffer_modification);
    if (strlen(buffer_modification) < 2)
    {
        switch (buffer_modification[0])
        {
            case '1':
                tmp = index_ajout;
                index_ajout = index;
                ajouter_nom();
                index_ajout = tmp;
                return (0);
            case '2':
                tmp = index_ajout;
                index_ajout = index;
                ajouter_age();
                index_ajout = tmp;
                return (0);
            case '3':
                tmp = index_ajout;
                index_ajout = index;
                ajouter_telephone();
                index_ajout = tmp;
                return (0);
            case '4':
                tmp = index_ajout;
                index_ajout = index;
                ajouter_statut();
                index_ajout = tmp;
                return (0);
            case '5':
                tmp = index_ajout;
                index_ajout = index;
                ajouter_date();
                index_ajout = tmp;
                return (0);
            case '6':
                tmp = index_ajout;
                index_ajout = index;
                ajouter_prenom();
                index_ajout = tmp;
                return (0);
            default:
                printf(RED "Entrez un choix valide par exemple 1 et appuyez sur Entrer pour valider\n" RESET);
                modifier_reservation();
                return(0);
        }
        return (0);
    }
    else
    {
        printf(RED "Entrez un choix valide par exemple 1 et appuyez sur Entrer pour valider\n" RESET);
        sleep(2);
        modifier_reservation();
        return (0);
    }
    return (0);
}
/**
* modfier_supprimer - ajoute reservation
*
* description: modfier_supprimer une reservation en faisant appel au differente fonction associé
*
* return: 0 si succes 1 si echec;
*/
int modifier_supprimer()
{
    char buffer_modification_suppression[100];

    printf("*******************************************\n");
    printf("1 - modifier une reservation entrez 1\n");
    printf("2 - supprimer une reservation\n");
    printf("*******************************************\n");
    mon_fgets(buffer_modification_suppression);

    if (strlen(buffer_modification_suppression) < 2)
    {
        switch(buffer_modification_suppression[0])
        {
            case '1':
                modifier_reservation();
                return(0);
            case '2':
                supprimer_reservation();
                return (0);
            default:
                printf(RED "Entrez un choix valide par exemple 1 et appuyez sur Entrer pour valider\n" RESET);
                sleep(2);
                modifier_supprimer();
                return (0);
        }
        
    }
    else
    {
        printf(RED "Entrez un choix valide par exemple 1 et appuyez sur Entrer pour valider\n" RESET);
        sleep(2);
    }
    return (0);
}
/**
* main - entree du programme
*
* description: entree du programme et fait appel au fonctions
*
* return: Toujours 0;
*/
int afficher_reservation()
{
    int index = 0;
    int id_trouver;
    char buffer_trouver[100];

    printf("Entrez la reference de la reservation que vous voulez afficher\n");
    mon_fgets(buffer_trouver);
    if (numero_valide(buffer_trouver) == 0)
    {
        afficher_reservation();
        return (0);
    }
    id_trouver = atoi(buffer_trouver);
    index = trouver_reservation_id(id_trouver);
    if (index < 0)
    {
        printf(RED "reference introuvable\n" RESET);
        afficher_reservation();
        return (0);
    }
    printf(BLUE "reference trouve\n" RESET);
    sleep(2);
    affiche_patient(index);
    sleep(2);
    return (0);
}
/**
* main - entree du programme
*
* description: entree du programme et fait appel au fonctions
*
* return: Toujours 0;
*/
int afficher_reservation_nom()
{
    char buffer_afficher_nom[100];
    int index;

    printf("*******************************************\n");
    printf("entrez le nom que vous voulez rechercher\n");
    mon_fgets(buffer_afficher_nom);

    if (recherche_patient_nom(buffer_afficher_nom) < 0)
    {
        printf(RED "pas de reservation sous ce nom\n" RESET);
        sleep (3);
        afficher_reservation_nom();
        return (0);
    }
    index = recherche_patient_nom(buffer_afficher_nom);
    printf(BLUE "reservation trouve \n" RESET);
    sleep(2);
    affiche_patient(index);
    return (0);
}
/**
* main - entree du programme
*
* description: entree du programme et fait appel au fonctions
*
* return: Toujours 0;
*/
int recherche_reservation()
{
    char buffer_recherche_reservation[100];

    printf("*******************************************\n");
    printf("1 - recherche par id\n");
    printf("2 - recherche par nom\n");
    printf("*******************************************\n");
    mon_fgets(buffer_recherche_reservation);
    if (strlen(buffer_recherche_reservation) < 2)
        {
            switch (buffer_recherche_reservation[0])
            {
                case '1' :
                    afficher_reservation();
                    return (0);
                case '2' :
                    afficher_reservation_nom();
                    return (0);
                    break;
                default:
                    printf(RED "Entrez un choix valide par exemple 1 et appuyez sur Entrer pour valider\n" RESET);
                    sleep(2);
                    recherche_reservation();
            }
        }
        else
        {
            printf(RED "Entrez un choix valide par exemple 1 et appuyez sur Entrer pour valider\n" RESET);
            sleep(2);
            recherche_reservation();
            return(0);
        }
        return (0);
}
/**
* main - entree du programme
*
* description: entree du programme et fait appel au fonctions
*
* return: Toujours 0;
*/
int afficher_age_moyen()
{
    int i;
    int total_age = 0;

    for (i = 0; i < index_ajout; i++)
    {
        total_age += base_patients[i].age;
    }
    printf("Moyenne dage  des patients = %d\n", total_age/i);
    return (0);
}
/**
* main - entree du programme
*
* description: entree du programme et fait appel au fonctions
*
* return: Toujours 0;
*/
int afficher_par_tranche()
{
    int i;
    int dix_huit = 0;
    int dixneuf_trentecinq = 0;
    int trente_six = 0;

    for (i = 0; i < index_ajout; i++)
    {
        if (base_patients[i].age <= 18)
        {
            dix_huit++;
        }
        else if (base_patients[i].age <= 35)
        {
            dixneuf_trentecinq++;
        }
        else if (base_patients[i].age >= 36)
        {
            trente_six++;
        }
    }
    printf("*******************************************\n");
    printf(" 0-18 ans : %d\n", dix_huit);
    printf("19-35 ans : %d\n", dixneuf_trentecinq);
    printf("36+ ans : %d\n", trente_six);
    printf("*******************************************\n");
    return (0);
}
/**
* main - entree du programme
*
* description: entree du programme et fait appel au fonctions
*
* return: Toujours 0;
*/
int afficher_statut()
{
    int i;
    int valide = 0;
    int reporte = 0;
    int annule = 0;
    int traite = 0;

    for (i = 0; i < index_ajout; i++)
    {
        if(strcmp(base_patients[i].statut, "VALIDE") == 0)
        {
            valide++;
        }
        else if (strcmp(base_patients[i].statut, "REPORTE") == 0)
        {
            reporte++;
        }
        else if (strcmp(base_patients[i].statut, "ANNULE") == 0)
        {
            annule++;   
        }
        else if (strcmp(base_patients[i].statut, "TRAITE") == 0)
        {
            traite++;
        }
    }
    printf("*******************************************\n");
    printf("Total valide : %d\nTotal reporte : %d\nTotal annule : %d\nTotal traite : %d\n",valide, reporte, annule, traite);
    printf("*******************************************\n");
    return (0);
}
/**
* main - entree du programme
*
* description: entree du programme et fait appel au fonctions
*
* return: Toujours 0;
*/
int statistiques()
{
    char buffer_statistique[100];
    printf("*******************************************\n");
    printf("1 - afficher age moyen\n");
    printf("2 - Afficher le nombre de patients par tranche d'age\n");
    printf("3 - connaitre le nombre total de reservations par statut (valide, annule, etc.)\n");
    printf("*******************************************\n");
    
    mon_fgets(buffer_statistique);
    if (strlen(buffer_statistique) < 2)
        {
            switch (buffer_statistique[0])
            {
                case '1' :
                    afficher_age_moyen();
                    return (0);
                case '2' :
                    afficher_par_tranche();
                    return (0);
                case '3' :
                    afficher_statut();
                    return (0);
                default:
                    printf(RED "Entrez un choix valide par exemple 1 et appuyez sur Entrer pour valider\n" RESET);
                    sleep(2);
                    statistiques();
                    return (0);
            }
        }
        else
        {
            printf(RED "Entrez un choix valide par exemple 1 et appuyez sur Entrer pour valider\n" RESET);
            sleep(2);
            statistiques();
            return(0);
        }
    return (0);
}

/**
* main - entree du programme
*
* description: entree du programme et fait appel au fonctions
*
* return: Toujours 0;
*/
int tri_par_nom()
{
    char tmp[100][100];
    char cup[100];
    int index = 0;
    int i, j;

    printf("tri par nom a ordre alphabetique : \n");
    //sleep(2);
    //COPY
    for (i = 0; i < index_ajout; i++)
    {
        strcpy(tmp[i], base_patients[i].nom);
    }
    //sort
    for(j = 0; j < index_ajout; j++)
    {
        for (i = 0; i < index_ajout - 1; i++)
        {
            if (strcmp(tmp[i + 1], tmp[i]) < 0)
            {
                strcpy(cup, tmp[i]);
                strcpy(tmp[i], tmp[i + 1]);//i = i + 1
                strcpy(tmp[i + 1], cup);// i + 1 = tmp 
            }
        }
    }
    for (i = 0; i < index_ajout; i++)
    {
        printf("reservation %d par ordre alphabetique\n", i + 1);
        index = recherche_patient_nom(tmp[i]);
        affiche_patient(index);
    }
    return (0);
}

/**
* tri_par_statut - tri_par_statut
*
* description: trier par statut
*
* return: Toujours 0;
*/
int tri_par_statut()
{
    int valide_index[100]; //what if tout est valide
    int annule_index[100];
    int traite_index[100];
    int reporte_index[100];
    int valide_i = 0;
    int annule_i = 0;
    int traite_i = 0;
    int reporte_i = 0;
    int i;
    printf("tri par nom a ordre alphabetique : \n");
    //sleep(2);
    //COPY
    for (i = 0; i < index_ajout; i++)
    {
         if(strcmp(base_patients[i].statut, "VALIDE") == 0)
         {
            valide_index[valide_i] = i;
            valide_i++;
         }
        else if (strcmp(base_patients[i].statut, "REPORTE") == 0)
        {
            reporte_index[reporte_i] = i;
            reporte_i++;
        }
        else if (strcmp(base_patients[i].statut, "ANNULE") == 0)
        {
            annule_index[annule_i] = i;
            annule_i++;
        }
        else if (strcmp(base_patients[i].statut, "TRAITE") == 0)
        {
            traite_index[traite_i] = i;
            traite_i++;
        }
    }
    printf("%d reservation valide\n\n", valide_i);
    
    for (i = 0; i < valide_i; i++)
    {
        affiche_patient(valide_index[i]);
        printf("---------------------------------------------\n");
    }
    printf("---------------------------------------------\n");
    sleep(3);

    
    printf("%d reservationreporte\n\n", reporte_i);
    printf("---------------------------------------------\n");
    for (i = 0; i < reporte_i; i++)
    {
        affiche_patient(reporte_index[i]);
        printf("---------------------------------------------\n");
    }
    printf("---------------------------------------------\n");
    sleep(3);

    printf("%d reservation annule\n\n", annule_i);
    for (i = 0; i < annule_i; i++)
    {
        affiche_patient(annule_index[i]);
        printf("---------------------------------------------\n");
    }
    printf("---------------------------------------------\n");
    sleep(3);

    printf("%d reservation traite\n\n", traite_i);
    for (i = 0; i < traite_i; i++)
    {
        affiche_patient(traite_index[i]);
        printf("---------------------------------------------\n");
    }
    printf("---------------------------------------------\n");
    sleep(3);

    return (0);
}

/**
* tri_reservation - tri_reservatio
*
* description: entree du choix de tri et fait appel au fonctions
*
* return: Toujours 0;
*/
int tri_reservation()
{
    char buffer_tri_reservation[100];
    printf("1 - tri par nom\n");
    printf("2 - tri par statut\n");

    mon_fgets(buffer_tri_reservation);
    if (strlen(buffer_tri_reservation) < 2)
        {
            switch (buffer_tri_reservation[0])
            {
                case '1' :
                    tri_par_nom();
                    return (0);
                case '2' :
                    tri_par_statut();
                    return (0);
                default:
                    printf(RED "Entrez un choix valide par exemple 1 et appuyez sur Entrer pour valider\n" RESET);
                    sleep(2);
                    tri_reservation();
                    return (0);
            }
        }
        else
        {
            printf(RED "Entrez un choix valide par exemple 1 et appuyez sur Entrer pour valider\n" RESET);
            sleep(2);
            tri_reservation();
            return(0);
        }
    return (0);
}
/**
* main - entree du programme
*
* description: entree du programme et fait appel au fonctions
*
* return: Toujours 0;
*/

int main ()
{
    char buffer_main[100];

    while (1)
    {
        menu();
        mon_fgets(buffer_main);
        //printf("buffer_main = %s\n", buffer_main);
        if (strlen(buffer_main) < 2)
        {
            switch (buffer_main[0])
            {
                case '1' :
                    ajouter_reservation();
                    //printf("%s\n", base_patients[0].nom);
                    break;
                case '2' :
                    modifier_supprimer();
                    break;
                case '3' :
                    afficher_reservation();
                    break;
                case '4' :
                    tri_reservation();
                    break;
                case '5' :
                    recherche_reservation();
                    break;
                case '6' :
                    statistiques();
                    break;
                case '0' :
                    printf("Au revoir !\n");
                    sleep(2);
                    return (0);
                default:
                    printf(RED "Entrez un choix valide par exemple 1 et appuyez sur Entrer pour valider\n" RESET);
                    sleep(2);
                    break;
            }
        }
        else
        {
            printf(RED "Entrez un choix valide par exemple 1 et appuyez sur Entrer pour valider\n" RESET);
            sleep(2);
        }
    }
    return (0);
}