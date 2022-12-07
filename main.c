#include <stdio.h>
#include <stdlib.h>
#include<string.h>
#include "fonction.h"



/*void(const afficher  personne)*pp*/



int main()
{


    Client r;

int n = 0;
//int m  =sizeof((&r)->nom)/256;

    printf("/*******************Annuaire Client*******************\n");
    //Preparation du fichier texte et affichage de l'annuaire
AffichageAnnuaire(&r);
CopieAnnuaireFichier(&r);
verifeClient(&r);
//Ajout du client
/*
saisirClient(&r);
verifeClient(&r);
ajoutClient(&r);
*/
//
}


