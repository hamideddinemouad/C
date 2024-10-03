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
 * numero_valide - valide si le numéro est composé uniquement de chiffres
 * @str_numero:  string
 *
 * Description: vérifie que chaque caractère est un chiffre.
 *
 * Return: 0 si non valide (pas de caractere autre que numero), -1 si valide
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
/**
 * recherche_contact - recherche un contact par nom
 * @recherche_contact_nom: nom du contact à rechercher
 *
 * Description: parcourt la liste des contacts pour trouver un nom qui correspond
 *
 * Return: 0 si trouvé, -1 si non trouvé
 */
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