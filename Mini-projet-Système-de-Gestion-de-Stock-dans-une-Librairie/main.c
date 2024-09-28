#include <stdio.h>
#include <string.h>
#include <stdlib.h>
/**
* menu - entree du programme
* 
* Description: gerer les livres
*
* Return: Toujours 0 (succes)
*/
int main()
{

    char base_titre[100][100];
    char base_auteur[100][100];
    //char titre_entre[];
    char base_prix_s[100];
    char base_quantite_s[100];
    char choix_s[100];
    int base_prix[100] = {0};
    int base_quantite[100] = {0};
    char case4_titre[100];
    char case3_titre[100];
    int is_num = 0;
    int checker;
    int case3_index;
    int case4_index;
    int case5_index;
    int compteur1;
    int nettoyage;
    int choix, position_1 = 0;
    int nouvelle_quantite;
    char case5_titre[100];

    while (1)
    {
    printf("1.Ajouter un livre au stock.\n");
    printf("2.Afficher tous les livres disponibles.\n");
    printf("3.Rechercher un livre par son titre.\n");
    printf("4.Mettre a jour la quantite d'un livre.\n");
    printf("5.Supprimer un livre du stock.\n");
    printf("6.Afficher le nombre total de livres en stock.\n\n");
    printf("faites votre choix:\n");
    //choix_s[0] = '\0';
    // NETTOYER TABLEAU
    for (nettoyage = 0; nettoyage < strlen(choix_s); nettoyage++)
    {
        choix_s[nettoyage] = '/0';
    }
    scanf("%s", choix_s);
    for (checker = 0; checker < strlen(choix_s); checker++)
    {
        if (!isdigit(choix_s[checker]))
        {
            printf("Que des numero !!\n");
            choix = 999;
            is_num = -1;
            break;
        }
        is_num = 0;
    }
    if (is_num == 0)
    {
        choix = atoi(choix_s);
        //printf("atoi(choix_s) = %d", atoi(choix_s));
    }
    //printf("choix = %d", choix);
    switch(choix)
    {
        case 1:
            printf("veuillez entre le titre du livre:\n");
            scanf(" %[^\n]",base_titre[position_1]);
            printf("veuillez entre l'auteur:\n");
            scanf(" %[^\n]", base_auteur[position_1]);
            printf("veuillez entrer le prix du livre:\n");
            for (nettoyage = 0; nettoyage < strlen(base_prix_s); nettoyage++)
            {
                base_prix_s[nettoyage] = '/0';
            }
            scanf("%s", base_prix_s);
            for (checker = 0; checker < strlen(base_prix_s); checker++)
            {
                if (!isdigit(base_prix_s[checker]))
                {
                    printf("Que des numero !!\n");
                    is_num = -1;
                    break;
                }
                is_num = 0;
            }
            if (is_num == 0)
            {
                base_prix[position_1] = atoi(base_prix_s);
                //printf("atoi(choix_s) = %d", atoi(choix_s));
            }
            //scanf("%d", &base_prix[position_1]);
            printf("veuillez entrer la quantite du stock:\n");
            for (nettoyage = 0; nettoyage < strlen(base_quantite_s); nettoyage++)
            {
                base_quantite_s[nettoyage] = '/0';
            }
            scanf("%s", base_quantite_s);
            for (checker = 0; checker < strlen(base_quantite_s); checker++)
            {
                if (!isdigit(base_quantite_s[checker]))
                {
                    printf("Que des numero !!\n");
                    is_num = -1;
                    break;
                }
                is_num = 0;
            }
            if (is_num == 0)
            {
                base_quantite[position_1] = atoi(base_quantite_s);
                //printf("atoi(choix_s) = %d", atoi(choix_s));
            }
            //printf("%s \n", base_titre[position_1]);
            //printf("%s \n", base_auteur[position_1]);
            //printf("%d \n", base_prix[position_1]);
            //printf("%d \n", base_quantite[position_1]);
            position_1++;
            break;
        case 2:
            //Afficher Tous les Livres Disponibles
            for (compteur1 = 0; compteur1 != position_1; compteur1++)
            {
                //printf("case 2\n");
                printf("Titre: %s\n", base_titre[compteur1]);
                printf("auteur: %s\n", base_auteur[compteur1]);
                printf("prix : %d\n", base_prix[compteur1]);
                printf("quantite: %d\n", base_quantite[compteur1]);
            }
            break;
        case 3:
            printf("entrez le nom de livre que vous souhaitez rechercher\n");
            scanf(" %[^\n]", case3_titre);
            for (compteur1 = 0; compteur1 != position_1; compteur1++)
            {
                if (strcmp(case3_titre, base_titre[compteur1]) == 0)
                {
                    case3_index = compteur1;
                    printf("Titre: %s\n", base_titre[case3_index]);
                    printf("auteur: %s\n", base_auteur[case3_index]);
                    printf("prix : %d\n", base_prix[case3_index]);
                    printf("quantite: %d\n", base_quantite[case3_index]);
                    break;
                }
            }
            break;
        case 4:
            //update quantité
            printf("entrez le nom du livre que vous souhaitez changer de quantite\n");
            scanf(" %[^\n]", case4_titre);
            for (compteur1 = 0; compteur1 != position_1; compteur1++)
            {
                if (strcmp(case4_titre, base_titre[compteur1]) == 0)
                {
                    case4_index = compteur1;
                    break;
                }
            }
            printf("Entrez la nouvelle quantité\n");
            scanf("%d", &nouvelle_quantite);
            base_quantite[case4_index] = nouvelle_quantite;
            break;
        case 5:
            //supprimer un livre
            printf("entrez le nom du livre que vous souhaitez supprimer\n");
            scanf(" %[^\n]", case5_titre);
            //trouver titre
            for (compteur1 = 0; compteur1 > position_1; compteur1++)
            {
                if (strcmp(case5_titre, base_titre[compteur1]) == 0)
                {
                    case5_index = compteur1;
                    break;
                    //printf("fonctionalité non disponible\n");
                }
                case5_index = -1;
            }
            //printf("case5_index%d\n", case5_index);
            if (case5_index > 0)
            {
                for (compteur1 = case5_index; compteur1 <= position_1; compteur1++)
                {
                    printf("suppression\n");
                    strcpy(base_titre[compteur1], base_titre[compteur1 + 1]);
                    strcpy(base_auteur[compteur1], base_auteur[compteur1 + 1]);
                    base_prix[compteur1] = base_prix[compteur1 + 1];
                    base_quantite[compteur1] = base_prix[compteur1 + 1];
                }
                position_1 = position_1 - 1;
            }
            else if (case5_index < 0)
            {
                printf("titre introuvable\n");
            }
        case 6:
            printf("nombre total des livres:%d\n", position_1);
            break;
        
    }
    }
}