
#include <stdio.h>
#include <stdlib.h>
#include<string.h>
#include "fonction.h"


/** \brief
 *
 * \param
 * \param
 * \return
 *
 */

/*void(const afficher  personne)*pp*/

/*
struct A {


char * ad;
char ch[50];

}
typedef struct A A;
void saisie(A*a){

a->ad =   (char *) malloc (20*sizeof(char));
fgets(a->ad,20,stdin);
}
double *p = (double*)malloc(10*sizeof(double));
char *c = (char*)malloc(15*sizeof(char));

*/


int main()
{
    Client d;

    //ajouter_Client(&d);
    //Verifier_validite_annuaire(&d,1);


//double *p = (double*)malloc(10*sizeof(double));//80 octets
//char *c = (char*)malloc(15*sizeof(char));//15 octets
//calloc : initialise tout a 0 voir -> cppreference

//doublons d;
int n;
char c;



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












