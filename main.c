
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
//double *p = (double*)malloc(10*sizeof(double));//80 octets
//char *c = (char*)malloc(15*sizeof(char));//15 octets
//calloc : initialise tout a 0 voir -> cppreference


Client r;
doublons d;
int n;
char c;

printf("/*******************Annuaire Client*******************\n");

//Afficher_annuaire_clients(&r);
//ajouter_Client(&r);
//Verifier_validite_annuaire(&d);
//Ecriture_annuaire_clients(&r);
//Separation_mel_p(&r);
//tri_client(&d);
MENU:{
    printf("1-> ajout Client\n");
    printf("2-> Afficher annuaire Client\n");
    printf("3-> trier Client par le nom\n");
printf("entrer votre choix\n");
scanf("%d",&n);

switch(n){
case 1:
    ajouter_Client(&r);
break;
case 2:
    Afficher_annuaire_clients(&r);
break;
case 3:
    tri_client(&d);
break;
default :
    printf("erreur");

}
printf("voulez vous continuer : entrer o ou O\n");
scanf("%c",&c);

if(c=='o' || c=='O'){
    goto MENU;

}
else{
    exit(1);
}
}




 return 0;
}












