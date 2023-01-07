/**<
*\file fonction.c
*\brief L'objectif de ce projet etait de concevoir une application
        de gestion d'un annuaire pour une organisation qui possedent un ensemble de données sur ses clients
        des fonctions pour repondre a cette sont donner si dessous avec des contraintes spécifiques
*\author Rafik BOUCHENNA G4S1B
*\date 08/01/2023
*/

#include <stdio.h>
#include <stdlib.h>
#include<string.h>
#include "fonction.h"
/** \brief
 *
 * \return int
 *
 */
int main()
{

    int n;
    char c;
    Client d;
    Ajout_Client a;

//definition des constantes pour les fichiers
    char annuaireChoisieEntree[50];




//saisie_ajout_client(&d);

    /************************ LE MENU **********************/


MENU:
    {
        printf("                    ###############################################################\n");
        printf("                    #                                                             #\n");
        printf("                    #        BIENVENUE ET VOICI NOTRE APPLICATION REALISER        #\n");
        printf("                    #         EN PREMIERE ANNEE DE BUT INFORMATIQUE               #\n");
        printf("                    #                                                             #\n");
        printf("                    ###############################################################\n\n");
        printf("Ajouter une personne a l'annuaire ............ 1\n");
        printf("Afficher l'annuaire sans filtre .............. 2\n");
        printf("verifier la validitee de l'annuaire........... 3\n");
        printf("Trier l'annuaire ............................. 4\n");
        printf("Afficher l'annuaire avec filtre .............. 5\n");
        printf("Rendre l'annuaire valide...................... 6\n");
        printf("Sauvegarder l'annuaire........................ 7\n");
        printf("Quitter ...................................... 8\n");
        printf("Entrez l'annuaire : ");

        scanf("%s",&annuaireChoisieEntree);

        printf("Entrez votre choix\n");
        scanf("%d",&n);

        switch(n)
        {
        case 1:
            if(Verifier_validite_annuaire(annuaireChoisieEntree)==1)
            {
                printf("\nAnnuaireInvalide");
                return 0;
            }
            else
            {

                saisie(&a);
                ajouter_Client(annuaireChoisieEntree,a.nom,a.prenom,a.codepostal,a.ville,a.telephone,a.mail,a.profession);
            }
            break;
        case 2:
            Afficher_annuaire_clients(&d);
            break;
        case 3:

            Verifier_validite_annuaire(annuaireChoisieEntree);
            break;
        case 4:
            if(Verifier_validite_annuaire(annuaireChoisieEntree)==1)
            {
                printf("\nAnnuaireInvalide");
                return 0;
            }
            else
            {
                tri_client_par_nom(annuaireChoisieEntree);
            }
            break;

        case 5:
            if(Verifier_validite_annuaire(annuaireChoisieEntree)==1)
            {
                printf("\nAnnuaireInvalide");
                return 0;
            }
            else
            {
                SaisieFiltre(&d);

                Filtrer_combiner_deux_champs(annuaireChoisieEntree,d.nom_champ1,d.nom_champ2,d.val_chaine1,d.val_chaine2);
            }

            break;
        case 6:
            //Ecriture_annuaire_clients(&d);
            Rendre_annuaire_valide(annuaireChoisieEntree);
            break;
        case 7:
//            sauvegarde_annuaire("resultat.txt",annuaireChoisieEntree);
            break;
        case 8:
            exit(1);
            break;
        default :
            printf("Erreur de choix");

        }
        printf("\nVoulez vous continuer : Entrez o ou O\n");
        scanf("%c",&c);

        if(c=='o' || c=='O')
        {

            goto MENU;

        }
        else
        {
            exit(1);
        }

        return 0;
    }


    return 0;
}












