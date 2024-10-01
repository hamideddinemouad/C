#include <stdio.h>
#include <string.h>
#include <ctype.h>
/**
* struct infos - structure to hold personal infos
* @nom: tableau pour string
* @telephone: tableau pour string
* @mail: tableau pour string
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
typedef struct infos_contact
{
    char nom[100]; // pour determiner la taille du tableau strlen(string) + 1;
    char telephone[100];
    char mail[100];
    int id;
}contact;

contact liste_contacts[300];
char buffer_ajout[100];
char buffer_modifier_contact[100];
char buffer_supprimer_contact[100];
int index_supprimer_contact;
int index_ajout = 0;
int id = 1;

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

int recherche_contact(char* recherche_contact_nom)
{
    int index_recherche_contact;

    for (index_recherche_contact = 0; index_recherche_contact <= index_ajout; index_recherche_contact++)
    {
        if (strcmp(liste_contacts[index_recherche_contact].nom, recherche_contact_nom) == 0)
        {
            // printf("recherche_contact FUNCTION\n");
            index_supprimer_contact = index_recherche_contact;
            return (0); //contact deja existant
        }
    }
    return (-1); // contact non existant
}
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
        if (strcmp(liste_contacts[index_recherche_num].telephone, recherche_contact_num) == 0)
        {
            // printf("recherche_contact FUNCTION\n");
            return (0); //num deja existant
        }
    }
    return (-1); // num non existant
}
int ajout_nom()
{
    char buffer_ajout_nom[100];

    tab_null(buffer_ajout_nom);
    printf("Entrez le nom du contact que vous voulez ajouter !\n");
    fgets(buffer_ajout_nom, sizeof(buffer_ajout_nom), stdin);
    no_new_line(buffer_ajout_nom);
    //strcpy(liste_contacts[index_ajout].nom, buffer_ajout_nom);
    //printf("(recherche_contact(buffer_ajout_nom)) = %d\n", (recherche_contact(buffer_ajout_nom)));
    if (recherche_contact(buffer_ajout_nom) == -1)
    {
        //printf("recherche_contact(buffer_ajout_nom) == -1\n");
        strcpy(liste_contacts[index_ajout].nom, buffer_ajout_nom);
        printf("nom de contact ajoute\n");
        return(0);
    }
    printf("Contact deja existant entrez un nouvel contact\n");
    ajout_nom();
    return (0);
}
int ajout_telephone()
{
    char buffer_ajout_tel[100];

    tab_null(buffer_ajout_tel);
    printf("Entrez le num de telephone de %s\n", liste_contacts[index_ajout].nom);
    fgets(buffer_ajout_tel, sizeof(buffer_ajout_tel), stdin);
    no_new_line(buffer_ajout_tel);
    if (numero_valide(buffer_ajout_tel) == 0)
    {
        ajout_telephone(); //character non num detecte
        return (0);
    }
    if (recherche_num(buffer_ajout_tel) == -1)
    {
        strcpy(liste_contacts[index_ajout].telephone, buffer_ajout_tel);
        printf("numero de telephone ajoute\n");
        return(0);
    }
    printf("numero deja existant\n");
    ajout_telephone();
    return (0);
}
int mail_valide(char* str_mail)
{
    unsigned int mail_valide_index;
    int validity_mail = 0;
    for (mail_valide_index = 0; mail_valide_index < strlen(str_mail); mail_valide_index++)
    {
        if(str_mail[mail_valide_index] == '@' || str_mail[mail_valide_index] == '.')
        {
            validity_mail++; 
        }
    }
    if (validity_mail == 2)
    {
        return(-1); //mail conforme
    }
    printf("entrez une adresse mail valide\n");
    return (0); //mail etrange
}

int recherche_mail(char* recherche_contact_mail)
{
    int index_recherche_mail;

    for (index_recherche_mail = 0; index_recherche_mail <= index_ajout; index_recherche_mail++)
    {
        if (strcmp(liste_contacts[index_recherche_mail].telephone, recherche_contact_mail) == 0)
        {
            // printf("recherche_contact FUNCTION\n");
            return (0); //num deja existant
        }
    }
    return (-1); // num non existant
}
int ajout_mail()
{
    char buffer_ajout_mail[100];

    tab_null(buffer_ajout_mail);
    printf("Entrez l'mail de %s\n", liste_contacts[index_ajout].nom);
    fgets(buffer_ajout_mail, sizeof(buffer_ajout_mail), stdin);
    no_new_line(buffer_ajout_mail);
    if (mail_valide(buffer_ajout_mail) == 0)
    {
        ajout_mail(); //character non num detecte
        return (0);
    }
    if (recherche_mail(buffer_ajout_mail) == -1)
    {
        strcpy(liste_contacts[index_ajout].mail, buffer_ajout_mail);
        printf("mail ajoute\n");
        return(0);
    }
    printf("mail deja existant\n");
    ajout_mail();
    return (0);
}
int ajout_contact()
{
    ajout_nom();
    ajout_telephone();
    ajout_mail();
    liste_contacts[index_ajout].id = id;
    id++;
    index_ajout++;
    printf("contact ajoute\n");
    return (0);
}
int tout_afficher()
{
    int tout_afficher_index;
    for (tout_afficher_index = 0; tout_afficher_index < index_ajout; tout_afficher_index++)
    {
        if (liste_contacts[tout_afficher_index].nom[0] != '\0')
        {
        printf("--------------------------%s---------------------------------\n", liste_contacts[tout_afficher_index].nom);
        
        printf("telephone : %s\n", liste_contacts[tout_afficher_index].telephone);
        printf("mail : %s\n", liste_contacts[tout_afficher_index].mail);
        printf("id : %d\n", liste_contacts[tout_afficher_index].id);
        printf("--------------------------------------------------------------------\n");
        }
    }
}
int modifier_contact()
{
    tab_null(buffer_modifier_contact);
    printf("Entrez le nom  du contact\n");
    fgets(buffer_modifier_contact, sizeof(buffer_modifier_contact), stdin);
    no_new_line(buffer_modifier_contact);
    if (recherche_contact(buffer_modifier_contact) == -1)
    {
        printf("contact introuvable !!\n");
        modifier_contact();
        return (0);
    }
    printf("choisissez ce que vous modifier\npour email entrez 1\npour numero entrez 2\nentrez numero 0 pour revenir en arriere");
    tab_null(buffer_modifier_contact);
    fgets(buffer_modifier_contact, sizeof(buffer_modifier_contact), stdin);
    no_new_line(buffer_modifier_contact);
    switch (buffer_modifier_contact[0])
    {
        case '1':
            ajout_mail();
            break;
        case '2':
            ajout_telephone();
            break;
        case '0':
            return (0);
        default:
            printf("entree invalide\n");
            modifier_contact();
            return(0);
    }
    printf("contact modifie\n");
}
int supprimer_contact_loops()
{
    unsigned int index;

    for (index = 0; index <= strlen(liste_contacts[index_supprimer_contact].nom); index++)
    {
        liste_contacts[index_supprimer_contact].nom[index] = '\0';
    }
    for (index = 0; index <= strlen(liste_contacts[index_supprimer_contact].mail); index++)
    {
        liste_contacts[index_supprimer_contact].mail[index] = '\0';
    }
    for (index = 0; index <= strlen(liste_contacts[index_supprimer_contact].mail); index++)
    {
        liste_contacts[index_supprimer_contact].telephone[index] = '\0';
    }

    liste_contacts[index_supprimer_contact].id = 0;
    //liste_contacts[index_supprimer_contact] = '\0';

    return (0);
}
int supprimer_contact ()
{
    tab_null(buffer_supprimer_contact);
    printf("Entrez le nom  du contact\n");
    fgets(buffer_supprimer_contact, sizeof(buffer_supprimer_contact), stdin);
    no_new_line(buffer_supprimer_contact);
    if (recherche_contact(buffer_supprimer_contact) == -1)
    {
        printf("contact introuvable !!\n");
        supprimer_contact();
        return (0);
    }
    supprimer_contact_loops();
    printf("contact supprime\n");
}
void menu()
{
    printf("1. Ajouter un Contact\n");
    printf("2. Modifier un Contact\n");
    printf("3. Supprimer un Contact\n");
    printf("4. Afficher Tous les Contacts\n");
    printf("5. Rechercher un Contact\n");
}
int recherche_contact_afficher(char* recherche_contact_nom)
{
    int index_recherche_contact;

    for (index_recherche_contact = 0; index_recherche_contact <= index_ajout; index_recherche_contact++)
    {
        if (strcmp(liste_contacts[index_recherche_contact].nom, recherche_contact_nom) == 0)
        {
            // printf("recherche_contact FUNCTION\n");
            printf("contact trouve\n");
            printf("--------------------------%s---------------------------------\n", liste_contacts[index_recherche_contact].nom);
            printf("telephone : %s\n", liste_contacts[index_recherche_contact].telephone);
            printf("mail : %s\n", liste_contacts[index_recherche_contact].mail);
            printf("id : %d\n", liste_contacts[index_recherche_contact].id);
            printf("--------------------------------------------------------------------\n");

            return (0); //contact deja existant
        }
    }
    return (-1); // contact non existant
}
/**
* main - fonction principale
* description: appelle les fonctions du programme
* return: Toujours 0 (succes) 
*/
int main ()
{
    char buffer[100];
    while(1)
    {
        menu();
        printf("choisissez une option\n");
        fgets(buffer, sizeof(buffer), stdin);
        switch (buffer[0])
        {
            case '\n' :
                continue;
            case '\0' :
                continue;
            case '1' :
                ajout_contact();
                break;
                //printf("%s\n", liste_contacts[0].nom);
                //printf("%c lu avec success\n", buffer[0]);
            case '2' :
                modifier_contact();
                break;
            case '3' :
                supprimer_contact();
                break;
            case '4' :
                tout_afficher();
                break;
            case '5' :
                recherche_contact(buffer);
            default:
                continue;
                //printf("buffer[0] = %c\n", buffer[0]);
                //printf("entrer un input valide\n");
    }
    }
}