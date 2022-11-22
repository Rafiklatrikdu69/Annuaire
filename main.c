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
/*
 saisirClient(&r);
 ajoutClient(&r);
*/

//AffichageAnnuaire(&r);
saisirClient(&r);


//ajoutClient(&r);
tri_client(&r);





    
 
/* 
switch(n){
case 1:
        saisirClient(&r);
    break;
default :
    printf("erreur de choix");
    break;
}
*/
}


