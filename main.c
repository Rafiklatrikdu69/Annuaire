#include <stdio.h>
#include <stdlib.h>
#include<string.h>
#include "tempCodeRunnerFile.c"

/*void(const afficher  personne)*pp*/



int main()
{


    Client r;

int n = 0;
//int m  =sizeof((&r)->nom)/256;

    printf("/*******************Annuaire Client*******************\n");
/*printf("\n 1->Afficher Annuaire\n");
printf("\n 2->RechercheClient\n");
*/
    printf("\n 3->Ajout Client\n");

    printf("Entrer votre choix : \n");
 scanf("%d",&n);

switch(n){
case 1:
    AffichageAnnuaire(&r);
    //qsort((&r)->nom,256,256,CompareChaine);
    break;
case 2 :
    /*saisirClient(&r);
    RechercheClient(&r);*/

    //RechercheClient(&r);
    break;
case 3 :
   ajoutClient(&r);
    //RechercheClient(&r);

    break;
default :
    printf("erreur de choix");
    break;
}

}


