/**<
*\file triAbulle.c
*\brief les fonctions si dessous sont faites avec la norme C99 pour plus de simplification.Voir(https://en.cppreference.com/w/c/99)
*\author Rafik BOUCHENNA G4S1B
*\date 08/01/2023
*/
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "fonction.h"



/** \brief la fonction tri_client_par_nom prend en sortie l'annuaire trié avec un tri a bulle en fonction du nom
 *
 * \param[in] preconditions : nom_annuaire est un annuaire valide donnée en entree
 * \param[in] entree : nom_annuaire est un fichier valide
 *
 *
 *\param[out]  sorties : les donnes sont donné en sortie dans le fichier resultat_afficher_tries_nom
                dans le meme repertoire que l'executable
 * \return void
 *
 */
void tri_clients_par_nom(const char *nom_annuaire)
{



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
    fflush(stdin);

}
