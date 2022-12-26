
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
    Separation_mel_p(&r);
    Verifier_validite_annuaire(&d);
break;
case 4:

    //tri_client(&d);
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
{/*
 FILE *fichier = fopen("fichier.txt", "r");
  if (fichier == NULL) {
    perror("Erreur lors de l'ouverture du fichier");
    return 1;
  }

  // Lisez les données du fichier et stockez-les dans un tableau de structures
  struct personne_ personnes[3];
  for (int i = 0; i < 3; i++) {
    fscanf(fichier, "%s,%s,%s,%s,%s,%s,%s\n", personnes[i].nom,  personnes[i].prenom,   personnes[i].code ,   personnes[i].ville,   personnes[i].tel,  personnes[i].adresse,personnes[i].prof);
  }

  // Fermez le fichier
  fclose(fichier);

  // Triez le tableau de structures en fonction du nom avec l'algorithme de tri à bulle
  tri_client(personnes);
for (int i = 0; i < 3; i++) {
   printf("%s %s %s %s %s %s %s\n",personnes[i].nom,  personnes[i].prenom,   personnes[i].code ,   personnes[i].ville,   personnes[i].tel,  personnes[i].adresse,personnes[i].prof);
  }
  // Ouvrez le fichier
*/
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

}




 return 0;
}
}











