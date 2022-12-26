
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
//doublons d;
int n;
char c;

struct personne_ p;



//Afficher_annuaire_clients(&r);
//ajouter_Client(&r);
//Verifier_validite_annuaire(&d);
//Ecriture_annuaire_clients(&r);
//Separation_mel_p(&r);
//tri_client(&d);

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
    ajouter_Client(&r);
break;
case 2:
    Afficher_annuaire_clients(&r);
break;
case 3:
    Ecriture_annuaire_clients(&r);
    Verifier_validite_annuaire(&p,700);
break;
case 4:

    client(&p,1);
break;
case 5:
    Ecriture_annuaire_clients(&r);
break;
case 6:
    Filtrer_combiner_deux_champs(&r);
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



  // Ouvrez le fichier

/*
int j = 0;
int i = 0;
char chaine[] = "Leroy";
char c[256];
int res = 0;
printf("entrez l'indice");
scanf("%d",&n);

printf("entrez le filtre : ");
scanf("%s",&c);

for( i = 0;i<strlen(c);i++){

if(chaine[n] == c[j]){
res = 1;
//printf("filtre  = %s\n",chaine);
j++;
n++;
}
else{
    res = 0;
    break;
}

}

if(res==1){
    printf("filtre  = %s\n",chaine);
}
else{
      printf("chaine  inexistante\n");
}



*/


 return 0;
}
}
//}











