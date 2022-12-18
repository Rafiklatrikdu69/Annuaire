#include <stdio.h>
#include <stdlib.h>
#include<string.h>
#include "fonction.h"



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
void doublons(char *doub[], int taille)
 {

   int i, j;

   for (i = 0; i < taille; i++)
    for (j = i+1; j < taille; j++)
      if (stricmp(doub[i], doub[j]) == 0)
        {
          printf("\nil ya des doublons\n");
        printf("\nles doublons sont : %s et %s",doub[i], doub[j]);

        }

  }

int main()
{
//double *p = (double*)malloc(10*sizeof(double));//80 octets
//char *c = (char*)malloc(15*sizeof(char));//15 octets
//calloc : initialise tout a 0 voir -> cppreference


    Client r;


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



   char *valeurs[] = {"rafik", "Aziz", "Ras", "walid", "walid"};


   doublons(valeurs, 5);

 return 0;
}












