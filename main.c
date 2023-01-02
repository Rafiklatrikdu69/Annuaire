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
#define TAILLE 100
int main()
{

int n;
char c;
 Client d;

//definition des constantes pour les fichiers
const char annuaireTXT[50] = "annuaire.txt";
const char annuaireTRI[50] = "resultat_trier_par_nom.txt";
char nom[256];
char prenom[256];
char codepostal[256];
char ville[256];
char telephone[256];
char mail[256];
char profession[256];



//saisie_ajout_client(&d);

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
           goto AJOUT;
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
            tri_client_par_nom(annuaireTRI);
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


AJOUT:{


                NOM:{
                    fgetc(stdin);
        printf("nom\n");
        fgets(nom,TAILLE,stdin);
        nom[strcspn(nom,"\r\n")] = '\0';
        if(saisieNOM(nom)){goto NOM;}
        }

        PRENOM:{
        printf("prenom\n");
        fgets(prenom,TAILLE,stdin);
        prenom[strcspn(prenom,"\r\n")] = '\0';
        if(saisiePRENOM(prenom)==1){goto PRENOM;}
        }
        CODE:{
        printf("codepostal\n");
        fgets(codepostal,TAILLE,stdin);
        codepostal[strcspn(codepostal,"\r\n")] = '\0';
        if(saisieCODEPOSTAL(codepostal)==1){goto CODE;}
        }
        VILLE:{
        printf("ville\n");
        fgets(ville,TAILLE,stdin);
        ville[strcspn(ville,"\r\n")] = '\0';
        if(saisieVILLE(ville)==1){goto VILLE;}
        }
        TELEPHONE:{
        printf("telephone\n");
        fgets(telephone,TAILLE,stdin);
        telephone[strcspn(telephone,"\r\n")] = '\0';
        if(saisieTELEPHONE(telephone)==1){goto TELEPHONE;}
        }
        MAIL:{
        printf("mail\n");
        fgets(mail,TAILLE,stdin);
        mail[strcspn(mail,"\r\n")] = '\0';
        if(saisieMAIL(mail)==1){goto MAIL;}
        }
        PROFESSION:{
        printf("profession\n");
        fgets(profession,TAILLE,stdin);
        profession[strcspn(profession,"\r\n")] = '\0';
        if(saisiePROFESSION(profession)==1){goto PROFESSION;}
        }
        if(ajouter_Client(annuaireTXT,nom,prenom,codepostal,ville,telephone,mail,profession)==1){
            goto MAIL;
        }
}
        return 0;
}












