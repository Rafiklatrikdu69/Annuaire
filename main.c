
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

//int m  =sizeof((&r)->nom)/256;

    printf("/*******************Annuaire Client*******************\n");
    //Preparation du fichier texte et affichage de l'annuaire
//verifeClient(&r);
//ajoutClient(&r);

//saisirClient(&r);
/*
verifeClient(&r);
ajoutClient(&r);
*/



tri_client(&d);

/*
for(int i = 0;i<ligne;i++){
    printf("%s",donnes[i]);
}
*/
 //printf("%s",donnes[280]);
// doublons(donnes, ligne);
//verif_annuaire(&r);








 return 0;
}












