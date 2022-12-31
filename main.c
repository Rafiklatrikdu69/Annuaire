/**<
*\file fonction.c
*\brief L'objectif de ce projet etait de concevoir une application
        de gestion d'un annuaire pour une organisation qui possedent un ensemble de données sur ses clients
        des fonctions pour repondre a cette sont donnes si dessous avec des contraintes spécifiques
*\author Rafik BOUCHENNA G4S1B
*\date 08/01/2023
*/

#include <stdio.h>
#include <stdlib.h>
#include<string.h>
#include "fonction.h"

int main()
{

int n;
char c;
Client d;

//definition des constantes pour les fichiers
const char annuaireTXT[50] = "annuaire.txt";

        /************************ LE MENU **********************/
        MENU:{
            printf("1-> Ajout Client\n");
            printf("2-> Afficher annuaire Client\n");
            printf("3-> Verifier la validite de l'annuaire\n");
            printf("4-> Trier Client par le nom\n");
            printf("5-> Ecriture annuaire\n");
            printf("6-> Rendre l'annuaire valide\n");
            printf("7-> Filtrer avec deux champs combiner\n");
            printf("Entrez votre choix\n");
            scanf("%d",&n);

        switch(n){
        case 1:
           Ecriture_annuaire_clients(&d);
            ajouter_Client(&d,annuaireTXT);
        break;
        case 2:
          Afficher_annuaire_clients(&d);
        break;
        case 3:
            Ecriture_annuaire_clients(&d);
            Verifier_validite_annuaire(&d,700);
        break;
        case 4:
            Ecriture_annuaire_clients(&d);
            tri_client_par_nom(&d,1,annuaireTXT);
        break;
        case 5:
           Ecriture_annuaire_clients(&d);
        break;
        case 6:
           Ecriture_annuaire_clients(&d);
          Rendre_annuaire_valide(&d);
        break;
        case 7:
           Ecriture_annuaire_clients(&d);
          Filtrer_combiner_deux_champs(&d,annuaireTXT);
        break;
        default :
            printf("Erreur de choix");

        }
        printf("\nVoulez vous continuer : Entrez o ou O\n");
        scanf("%c",&c);

        if(c=='o' || c=='O'){
            goto MENU;

        }
        else{
            exit(1);
        }

         return 0;
        }
}












