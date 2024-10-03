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
void menu()
{
    printf("Bienvenue dans Docteur Reservation\n");
    sleep(3);
    printf("1. Ajouter une reservation\n");
    printf("2. Modifier ou supprimer une reservation\n");
    printf("3. Afficher les details d'une reservation\n");
    printf("4. Tri des reservation\n");
    printf("5. Recherche des reservation\n");
    printf("6. Statistiques \n");
    printf("0. Quitter\n");
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
int id = 10;
int index_ajout = 10; //PEUT CREER DES PROBLEMES
patient base_patients[100] = 
{
    {"hamideddine", "mouad", "0602030405", 25, "VALIDE", "01-10-2024", 1},
    {"lasfar", "souhail", "0602030406", 30, "REPORTE", "02-10-2024", 2},
    {"benani", "yousra", "0602030407", 45, "ANNULE", "03-10-2024", 3},
    {"saanane", "idriss", "0602030408", 60, "TRAITE", "04-10-2024", 4},
    {"ouarzazi", "hamza", "0602030409", 35, "VALIDE", "05-10-2024", 5},
    {"ait Ahmed", "rachid", "0602030410", 50, "REPORTE", "06-10-2024", 6},
    {"zahraoui", "mustapha", "0602030411", 28, "ANNULE", "07-10-2024", 7},
    {"boulahdour", "soufiane", "0602030412", 33, "TRAITE", "08-10-2024", 8},
    {"benjelloun", "anass", "0602030413", 47, "VALIDE", "09-10-2024", 9},
    {"el Hachimi", "khadija", "0602030414", 52, "REPORTE", "10-10-2024", 10}
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
    printf("nom - %s\n", base_patients[index_affiche].nom);
    printf("prenom - %s\n", base_patients[index_affiche].prenom);
    printf("telephone - %s\n", base_patients[index_affiche].telephone);
    printf("age - %d\n", base_patients[index_affiche].age);
    printf("statut - %s\n", base_patients[index_affiche].statut);
    printf("date de reservation - %s\n", base_patients[index_affiche].date_reservation);
    printf("id - %d\n", base_patients[index_affiche].reference);
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
    if (recherche_patient_nom(buffer_ajout_nom) >= 0) //contact existant et return index
    {
        printf("nom déja existant\n");
        ajouter_nom();
        return (0);
    }
    strcpy(base_patients[index_ajout].nom, buffer_ajout_nom);
    printf("nom ajoute avec succes\n");
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
    strcpy(base_patients[index_ajout].prenom, buffer_ajout_prenom);
    printf("prenom ajoute avec succes\n");
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
            printf("que des numero!!\n");
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
        printf("numero de telephone ajoute\n");
        return(0);
    }
    printf("numero deja existant\n");
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
        printf("%s n'est pas un age valide\n", buffer_ajout_age);
        sleep(3);
        ajouter_age();
        return (0);
    }
    if (numero_valide(buffer_ajout_age) == 0)
    {
        printf("Charactere autre que numero detecte\n");
        sleep(3);
        ajouter_age();
        return (0);
    }
    age_to_test = atoi(buffer_ajout_age);
    if (age_to_test < 0)
    {
        printf("valeur negative dans l'age detecté entrez une valeur positive\n");
        sleep(3);
        ajouter_age();
        return (0);
    }
    base_patients[index_ajout].age = age_to_test;
    printf("age : %d  est valide et ajoute avec succes\n", base_patients[index_ajout].age);
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
                strcpy(base_patients[index_ajout].statut, "Valide");
                printf("Statut ajoute\n");
                return (0);
            case '2':
                strcpy(base_patients[index_ajout].statut, "Reporte");
                printf("Statut ajoute\n");
                return (0);
            case '3':
                strcpy(base_patients[index_ajout].statut, "Annule");
                printf("Statut ajoute\n");
                return (0);
            case '4':
                strcpy(base_patients[index_ajout].statut, "Traite");
                printf("Statut ajoute\n");
                return (0);
            default :
                printf("choix introuvable Entrez un numero entre 1 et 4\n");
                sleep(3);
                ajouter_statut();
                return (0);
        }
    }
    printf("Entree invalide\n");
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
        printf("que quatre nombres pour lannee par example 2024\n");
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
    if (numero <= 2023 )
    {
        printf("pas de rdv en arriere\n");
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
 int jour_valide(char* str_date)
 {
    int numero;

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
    if (numero > 31 || numero < 1 )
    {
        printf("jour %d existe pas\n", numero);
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
        printf("que deux nombres pour le mois par example 06 ou 6 pour juin\n");
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
    if (numero > 12 || numero < 1 )
    {
        printf("mois %d existe pas\n", numero);
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
 int date_valide(char* str_date)
 {
    if (jour_valide(str_date) < 0 || mois_valide(str_date) < 0 || annee_valide(str_date))
    {
        return (-1);
    }
    return (0);
 }
/**
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
    if (jour_valide(buffer_ajout_jour) < 0)
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
int trouver_reservation_id(int id_recherche)
{
    int index;
    //trouver l'id
    for (index = 0; index <= index_ajout; index++)
    {
        if(base_patients[index].id == id_recherche)
        {
            return(index);
        }
    }
    return (-1);
}
int modifier_reservation()
{
    int index = 0;
    int id_modification;
    char buffer_modification[100];

    printf("Entrez ID que vous voulez modifer\n");
    mon_fgets(buffer_modification);
    if (numero_valide(buffer_modification) == 0)
    {
        modifier_reservation();
        return (0);
    }
    id_modification = atoi(buffer_modification);
    index = trouver_reservation_id(id_modification)
    if (index < 0)
    {
        printf("reference introuvable\n");
        modifer_reservation();
        return (0);
    }
    printf("reference trouvé\n");
    sleep(2);
    affiche_patient(index);
    printf("entrez ce que vous  voulez modifier\n");
    printf("1- pour modifier le nom\n");
    printf("2 - pour modfiier l'age\n");
    printf("3 - pour modifier telephone \n");
    printf("4 - pour modifier statut\n");
    printf("5 - pour modifier la date de reservation \n");
    if (strlen(buffer_main) < 2)
    {
        mon_fgets(buffer_modification);
        switch (buffer_modification[0]):
        {
            case '1':
                ajout
        }
    }
    else
    {
        printf("Entrez un choix valide par exemple 1 et appuyez sur Entrer pour valider\n");
        sleep(2);
    }
}
/**
* modfier_supprimer - ajoute reservation
*
* description: modfier_supprimer une reservation en faisant appel au differente fonction associé
*
* return: 0 si succes 1 si echec;
*/
int modfier_supprimer()
{
    char buffer_modification_suppression[100];

    printf("1 - modifier une reservation entrez 1\n");
    printf("2 - supprimer une reservation\n");
    printf("0 - revenir en arriere")
    mon_fgets(buffer_modification_suppression);

    if (strlen(buffer_main) < 2)
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
                printf("Entrez un choix valide par exemple 1 et appuyez sur Entrer pour valider\n");
                sleep(2);
                modifier_supprimer();
                return (0);
        }
        
    }
    else
    {
        printf("Entrez un choix valide par exemple 1 et appuyez sur Entrer pour valider\n");
        sleep(2);
    }

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
                    modfier_supprimer();
                    break;
                case '3' :
                    printf("case 3\n");
                    break;
                case '4' :
                    printf("case 4\n");
                    break;
                case '5' :
                    printf("case 5\n");
                    break;
                case '6' :
                    printf("case 6\n");
                    break;
                case '0' :
                    printf("Au revoir !\n");
                    sleep(2);
                    return (0);
                default:
                    printf("Entrez un choix valide par exemple 1 et appuyez sur Entrer pour valider\n");
                    sleep(2);
                    break;
            }
        }
        else
        {
            printf("Entrez un choix valide par exemple 1 et appuyez sur Entrer pour valider\n");
            sleep(2);
        }
    }
        return (0);
}
