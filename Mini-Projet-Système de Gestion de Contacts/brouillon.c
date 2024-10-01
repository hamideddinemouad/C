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
}