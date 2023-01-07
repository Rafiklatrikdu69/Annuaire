/** \brief
 *
 * \param
 * \param
 * \return
 *
 */


#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "fonction.h"



/** \brief la fonction tri_client_par_nom prend en sortie l'annuaire trié avec un tri cocktail en fonction du nom
 *
 * \param[in] le nom_annuaire
 * \param[in] annuaireTRI
 * \param[in] size un entier correspondant au nombre de ligne du fichier annuaire
 *
 *\param[out]  les donnes sont donné en sortie dans le fichier resultat_afficher_tries_nom
                dans le meme repertoire que l'executable
 * \return void
 *
 */
void tri_client_par_nom(const char *nom_annuaire)
{
    fgetc(stdin);


    FILE *annuaire = fopen(nom_annuaire, "r");

    // Vérifiez si le fichier a été ouvert correctement

    if (annuaire == NULL)  // si valeur renvoyer est NULL alors le fichier n'existe ou ne peux pas etre ouvert
    {
        perror("Erreur lors de l'ouverture du fichier");
        exit(EXIT_FAILURE);
    }



    int taille = 0;
    struct Client_*p ;

    p = tabRetourner(&taille,nom_annuaire);
    int size = taille;




// inspiration du tri a bulle pour trier les donnes en fonction du nom

    int i =0;

    struct Client_ temp;



//parcourt le tableau 2 fois-> dans le sens normal et dans le sens inverse
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



//affiche les valeurs et ecrit dans le fichier donné en sortie
    for (i = 0; i < size; i++)
    {
        printf("%s,%s,%s,%s,%s,%s,%s\n",p[i].nom_p,p[i].prenom_p,p[i].code_postal_p,p[i].ville_p,p[i].telephone_p,p[i].mel_p,p[i].profession_p);
        //fprintf(Resultat,"%s,%s,%s,%s,%s,%s,%s\n",p[i].nom_p,p[i].prenom_p,p[i].code_postal_p,p[i].ville_p,p[i].telephone_p,p[i].mel_p,p[i].profession_p);
    }
    sauvegarde_annuaire("resultat_trier_par_nom.txt",p,size);
//libere la memoire



    free(p->nom_p);
    free(p->prenom_p);
    free(p->ville_p);
    free(p->mel_p);
    free(p->profession_p);
    free(p);
//ferme les fichiers

    fclose(annuaire);

}
