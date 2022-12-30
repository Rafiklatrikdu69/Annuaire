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


        MENU:{
            printf("1-> ajout Client\n");
            printf("2-> Afficher annuaire Client\n");
            printf("3-> Verifier la validité de l'annuaire\n");
            printf("4-> trier Client par le nom\n");
            printf("5-> Ecriture annuaire\n");
            printf("6-> filtrer un champs\n");
        printf("entrer votre choix\n");
        scanf("%d",&n);

        switch(n){
        case 1:
           Ecriture_annuaire_clients(&d);
            ajouter_Client(&d);
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
            tri_client_par_nom(&d,1);
        break;
        case 5:
           Ecriture_annuaire_clients(&d);
          Filtrer_combiner_deux_champs(&d);
        break;
        default :
            printf("erreur");

        }
        printf("\nvoulez vous continuer : entrer o ou O\n");
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












