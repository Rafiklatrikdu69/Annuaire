/** \brief
 *
 * \param
 * \param
 * \return
 *
 */



#include <stdio.h>
#include <stdlib.h>
#include<string.h>
#include<assert.h>//teste en boite noire
#include "fonction.h"



/** \brief La fonction determine si l'annuaire donné en entree est valide suivant differentes contraintes
 *
 * \param[in] Client*d const
 * \param size int
 * \return void
 *
 */
int Verifier_validite_annuaire(const char * nom_annuaire)
{
    fgetc(stdin);
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
                verife = 1;
                return verife;
            }
        }
    }
    for (int i= 0; i < size; i++)
    {
        if (strlen(p[i].mel_p) == 0 || strcmp(p[i].mel_p," ") == 0|| strcmp(p[i].mel_p,"\t") == 0)
        {
            printf("champs vide !\n");
            printf("%s,%s,%s,%s,%s,%s,%s",p[i].nom_p,p[i].prenom_p,p[i].code_postal_p,p[i].ville_p,p[i].telephone_p,p[i].mel_p,p[i].profession_p);
            verife = 1;
            return verife;
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
    fgetc(stdin);//cela evite de faire sauter la saisie de l'utilisateur pour le menu

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
    for (int i= 0; i < size-1; i++)
    {
        //si les adresses a l'indice i et i+1 sont identique alors je vais les deplacer a la fin du tableau
        if (stricmp(p[i].mel_p, p[i+1].mel_p) == 0)
        {

            for (int j = i+1; j < size-1; j++)
            {
                //deplace l'élement a ma fin du tableau
                p[j]=p[j+1];

            }
            size--;//decremente le compteur
            i--;//decremente la taille du tableau
        }



    }

    sauvegarde_annuaire("annuaireValide.txt",p,size);

//ferme les fichiers


    //fclose(annuaire);
//libere la memoire

    free(p);




}
/** \brief
 *
 * \param Id_client const Client*
 * \return void
 */
void Ecriture_annuaire_clients(const Client *Id_client)
{

}

