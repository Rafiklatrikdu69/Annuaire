/**<
*\file validiter_annuaire.c
*\brief les fonctions si dessous sont faites avec la norme C99 pour plus de simplification.Voir(https://en.cppreference.com/w/c/99)
*\author Rafik BOUCHENNA G4S1B
*\date 08/01/2023
*/
#include <stdio.h>
#include <stdlib.h>
#include<string.h>
#include<assert.h>//teste en boite noire
#include "fonction.h"



/** \brief La fonction determine si l'annuaire donne en entree est valide suivant differentes contraintes
 *
 * \param[in] Client*d const
 * \param size int
 * \return void
 *
 */
int Verifier_validite_annuaire(const char * nom_annuaire)
{
fflush(stdin);
    int verife = 0;
    FILE *annuaire = fopen(nom_annuaire, "r");
    if (annuaire == NULL)  // si valeur renvoyer est NULL alors le fichier n'existe ou ne peux pas etre ouvert
    {
        perror("Erreur lors de l'ouverture du fichier");
        exit(EXIT_FAILURE);
    }

    int taille = 0;
    struct Client_*p ;

    p = tabRetourner(&taille,nom_annuaire);
    int size = taille;

//inspiration du tri a bulle pour verifier si il ya des doublons d'adresse
    int j = 0;
    int i=0;
    for (i = 0; i < size; i++)
    {
        for (j = i+1 ; j < size; j++)
        {
            if (stricmp(p[i].mel_p, p[j].mel_p) == 0)
            {
                printf("il ya des doublons :");
                printf("%s et %s \n",p[i].mel_p,p[j].mel_p);
                exit(1);
            }
        }
    }
    for (int i= 0; i < size; i++)
    {
        if (strlen(p[i].mel_p) == 0 || strcmp(p[i].mel_p," ") == 0|| strcmp(p[i].mel_p,"\t") == 0)
        {
            printf("champs vide !\n");
            printf("%s,%s,%s,%s,%s,%s,%s",p[i].nom_p,p[i].prenom_p,p[i].code_postal_p,p[i].ville_p,p[i].telephone_p,p[i].mel_p,p[i].profession_p);
            exit(1);
        }
    }





//ferme le fichier
    fclose(annuaire);
//libere la memoire


    free(p->nom_p);
    free(p->prenom_p);
    free(p->ville_p);
    free(p->mel_p);
    free(p->profession_p);
    free(p);


}


void Rendre_annuaire_valide(const char*nom_annuaire)
{


    int taille = 0;
    struct Client_*p ;
    if(p==NULL)
    {
        printf("erreur !");
    }
    p = tabRetourner(&taille,nom_annuaire);
    int size = taille;


    struct Client_ temp;
    for (int i = 0; i < size; i++)
    {
        for(int j = i+1; j< size; j++)
        {
            if (stricmp(p[i].nom_p, p[j].nom_p) > 0)
            {
                temp = p[i];
                p[i] = p[j];
                p[j] = temp;

            }
        }

    }
    //pour supprimer les doublons
    int i,j,k;
     for (i = 0; i < size; i++) {
      for (j = i + 1; j < size;) {
         if (stricmp(p[i].mel_p, p[j].mel_p)==0) {
            for (k = j; k < size; k++) {
               p[k] = p[k + 1];
            }
            size--;
         } else
            j++;
      }
   }

    sauvegarde_annuaire("annuaireValide.txt",p,size);




//libere la memoire

    free(p);




}


