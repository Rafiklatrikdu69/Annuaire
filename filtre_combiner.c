/**<
*\file filtre_combiner.c
*\brief les fonctions si dessous sont faites avec la norme C99 pour plus de simplification.Voir(https://en.cppreference.com/w/c/99)
*\author Rafik BOUCHENNA G4S1B
*\date 08/01/2023
*/
#include <stdio.h>
#include <stdlib.h>
#include<string.h>
#include<assert.h>//teste en boite noire
#include "fonction.h"



/** \brief Cette fonction compare les chaines **valchaine1** et **valchaine2** donnees dans la fonction filtrer_combiner_deux_champs
avec les sous-chaines pour ne garder que les données qui correspondent au filtre donne.\n
*

*\param[in] s1 char* chaine du champ .
*\param[in] sch1 char* sous-chaine pour le champ .
*\param[in] index int la position ou commence la comparaison des caracteres du champ numero 1.
*\param[in] cpt int compteur pour connaitre le nombre de lignes contenues dans l'annuaire.
 * \return  un entier **trouvee** pour la fonction filtrer_combiner_deux_champs
 *
 */
int Filtrer(const char *s1,const char *sch1,int cpt)
{
    int i, j;
    int taille_s1 = strlen(s1);
    int taille_souschaine = strlen(sch1);

    for (i = 0; i < taille_s1 - taille_souschaine + 1; i++)
    {
        for (j = 0; j < taille_souschaine; j++)
        {
            if (s1[i + j] != sch1[j])
            {
                break;
            }
        }
        if (j == taille_souschaine)
        {
            return 1;
        }
    }
    return 0;




}

/** \brief Cette fonction filtre les donnees du fichier annuaire donné en entree
           suivant 2 champs combiner **val_chaine1** et **val_chaine2**.
 *
 * \param[in]
         entrees qui contient les champs suivant :
         nom_p;
         prenom_p;
         code_postal_p;
         ville_p;telephone_p;
         mel_p;
         profession_p;
         val_chaine1;
         val_chaine2;
         nom_champ1;
         nom_champ2;
 *\brief pre-conditions : nom_annuaire est un fichier valide et val_chaine1 et val_chaine2 ne sont pas des chaines vides
 *\param[out] le fichier resultat_filtrer_combiner_deux_champs donné en sortie contient les nouvelles données des clients filtrer
 *
 * \return void
 *
 */
void Filtrer_combiner_deux_champs(const char *nom_annuaire,const char*nom_champ1,const char*nom_champ2,const char*val_chaine1,const char*val_chaine2)
{



    FILE *resultat_filtrer_combiner_deux_champs = fopen("resultat_filtrer_combiner_deux_champs.txt", "w");


    if (resultat_filtrer_combiner_deux_champs == NULL)  // si valeur renvoyer est NULL alors le fichier n'existe ou ne peux pas etre ouvert
    {
        perror("Erreur lors de l'ouverture du fichier");
        exit(EXIT_FAILURE);
    }

    int taille = 0;
    struct Client_*p ;

    p = tabRetourner(&taille,nom_annuaire);
    int size = taille;

    printf("le nombre de ligne est %d\n",size);

    if(stricmp(nom_champ1,"nom")==0 && stricmp(nom_champ2,"prenom")==0)
    {
        printf("nom et prenom\n");
        for(int i = 0; i<size; i++)
        {
            if(Filtrer(p[i].nom_p,val_chaine1,size)!=1 || Filtrer(p[i].prenom_p,val_chaine2,size)!=1)
            {

                for (int j = i; j < size; j++)
                {
                    //deplace l'élement a ma fin du tableau
                    p[j]=p[j+1];

                }
                size--;//decremente le compteur
                //decremente la taille du tableau

                i--;

            }


            //printf("%s,%s,%s,%s,%s,%s,%s\n",p[i].nom_p,p[i].prenom_p,p[i].code_postal_p,p[i].ville_p,p[i].telephone_p,p[i].mel_p,p[i].profession_p);
        }
        for(int i = 0; i<size; i++)
        {
            printf("%s,%s,%s,%s,%s,%s,%s\n",p[i].nom_p,p[i].prenom_p,p[i].code_postal_p,p[i].ville_p,p[i].telephone_p,p[i].mel_p,p[i].profession_p);
        }
        sauvegarde_annuaire("resultat_filtrer_combiner_deux_champs.txt",p,size);

    }
    if(stricmp(nom_champ1,"prenom")==0 && stricmp(nom_champ2,"nom")==0)
    {
        printf("prenom et nom\n");
        for(int i = 0; i<size; i++)
        {
            if(Filtrer(p[i].prenom_p,val_chaine1,size)!=1 || Filtrer(p[i].nom_p,val_chaine2,size)!=1)
            {

                for (int j = i; j < size; j++)
                {
                    //deplace l'élement a ma fin du tableau
                    p[j]=p[j+1];

                }
                size--;//decremente le compteur
                //decremente la taille du tableau

                i--;

            }


            //printf("%s,%s,%s,%s,%s,%s,%s\n",p[i].nom_p,p[i].prenom_p,p[i].code_postal_p,p[i].ville_p,p[i].telephone_p,p[i].mel_p,p[i].profession_p);
        }
        for(int i = 0; i<size; i++)
        {
            printf("%s,%s,%s,%s,%s,%s,%s\n",p[i].nom_p,p[i].prenom_p,p[i].code_postal_p,p[i].ville_p,p[i].telephone_p,p[i].mel_p,p[i].profession_p);
        }
        sauvegarde_annuaire("resultat_filtrer_combiner_deux_champs.txt",p,size);

    }
    if(stricmp(nom_champ1,"nom")==0 && stricmp(nom_champ2,"postal")==0)
    {
        printf("nom et code postal\n");
        for(int i = 0; i<size; i++)
        {
            if(Filtrer(p[i].nom_p,val_chaine1,size)!=1 || Filtrer(p[i].code_postal_p,val_chaine2,size)!=1)
            {

                for (int j = i; j < size; j++)
                {
                    //deplace l'élement a ma fin du tableau
                    p[j]=p[j+1];

                }
                size--;//decremente le compteur
                //decremente la taille du tableau

                i--;

            }


            //printf("%s,%s,%s,%s,%s,%s,%s\n",p[i].nom_p,p[i].prenom_p,p[i].code_postal_p,p[i].ville_p,p[i].telephone_p,p[i].mel_p,p[i].profession_p);
        }
        for(int i = 0; i<size; i++)
        {
            printf("%s,%s,%s,%s,%s,%s,%s\n",p[i].nom_p,p[i].prenom_p,p[i].code_postal_p,p[i].ville_p,p[i].telephone_p,p[i].mel_p,p[i].profession_p);
        }
        sauvegarde_annuaire("resultat_filtrer_combiner_deux_champs.txt",p,size);

    }
    if(stricmp(nom_champ1,"postal")==0 && stricmp(nom_champ2,"nom")==0)
    {
        printf(" code postal et nom\n");
        for(int i = 0; i<size; i++)
        {
            if(Filtrer(p[i].code_postal_p,val_chaine1,size)!=1 || Filtrer(p[i].nom_p,val_chaine2,size)!=1)
            {

                for (int j = i; j < size; j++)
                {
                    //deplace l'élement a ma fin du tableau
                    p[j]=p[j+1];

                }
                size--;//decremente le compteur
                //decremente la taille du tableau

                i--;

            }


            //printf("%s,%s,%s,%s,%s,%s,%s\n",p[i].nom_p,p[i].prenom_p,p[i].code_postal_p,p[i].ville_p,p[i].telephone_p,p[i].mel_p,p[i].profession_p);
        }
        for(int i = 0; i<size; i++)
        {
            printf("%s,%s,%s,%s,%s,%s,%s\n",p[i].nom_p,p[i].prenom_p,p[i].code_postal_p,p[i].ville_p,p[i].telephone_p,p[i].mel_p,p[i].profession_p);
        }
        sauvegarde_annuaire("resultat_filtrer_combiner_deux_champs.txt",p,size);

    }
    if(stricmp(nom_champ1,"ville")==0 && stricmp(nom_champ2,"nom")==0)
    {
        printf(" ville et nom\n");
        for(int i = 0; i<size; i++)
        {
            if(Filtrer(p[i].ville_p,val_chaine1,size)!=1 || Filtrer(p[i].nom_p,val_chaine2,size)!=1)
            {

                for (int j = i; j < size; j++)
                {
                    //deplace l'élement a ma fin du tableau
                    p[j]=p[j+1];

                }
                size--;//decremente le compteur
                //decremente la taille du tableau

                i--;

            }


            //printf("%s,%s,%s,%s,%s,%s,%s\n",p[i].nom_p,p[i].prenom_p,p[i].code_postal_p,p[i].ville_p,p[i].telephone_p,p[i].mel_p,p[i].profession_p);
        }
        for(int i = 0; i<size; i++)
        {
            printf("%s,%s,%s,%s,%s,%s,%s\n",p[i].nom_p,p[i].prenom_p,p[i].code_postal_p,p[i].ville_p,p[i].telephone_p,p[i].mel_p,p[i].profession_p);
        }
        sauvegarde_annuaire("resultat_filtrer_combiner_deux_champs.txt",p,size);

    }
    if(stricmp(nom_champ1,"tel")==0 && stricmp(nom_champ2,"nom")==0)
    {
        printf("telephone et nom\n");
        for(int i = 0; i<size; i++)
        {
            if(Filtrer(p[i].telephone_p,val_chaine1,size)!=1 || Filtrer(p[i].nom_p,val_chaine2,size)!=1)
            {

                for (int j = i; j < size; j++)
                {
                    //deplace l'élement a ma fin du tableau
                    p[j]=p[j+1];

                }
                size--;//decremente le compteur
                //decremente la taille du tableau

                i--;

            }


            //printf("%s,%s,%s,%s,%s,%s,%s\n",p[i].nom_p,p[i].prenom_p,p[i].code_postal_p,p[i].ville_p,p[i].telephone_p,p[i].mel_p,p[i].profession_p);
        }
        for(int i = 0; i<size; i++)
        {
            printf("%s,%s,%s,%s,%s,%s,%s\n",p[i].nom_p,p[i].prenom_p,p[i].code_postal_p,p[i].ville_p,p[i].telephone_p,p[i].mel_p,p[i].profession_p);
        }
        sauvegarde_annuaire("resultat_filtrer_combiner_deux_champs.txt",p,size);

    }
    if(stricmp(nom_champ1,"mel")==0 && stricmp(nom_champ2,"nom")==0)
    {
        printf("mail et nom\n");
        for(int i = 0; i<size; i++)
        {
            if(Filtrer(p[i].mel_p,val_chaine1,size)!=1 || Filtrer(p[i].nom_p,val_chaine2,size)!=1)
            {

                for (int j = i; j < size; j++)
                {
                    //deplace l'élement a ma fin du tableau
                    p[j]=p[j+1];

                }
                size--;//decremente le compteur
                //decremente la taille du tableau

                i--;

            }


            //printf("%s,%s,%s,%s,%s,%s,%s\n",p[i].nom_p,p[i].prenom_p,p[i].code_postal_p,p[i].ville_p,p[i].telephone_p,p[i].mel_p,p[i].profession_p);
        }
        for(int i = 0; i<size; i++)
        {
            printf("%s,%s,%s,%s,%s,%s,%s\n",p[i].nom_p,p[i].prenom_p,p[i].code_postal_p,p[i].ville_p,p[i].telephone_p,p[i].mel_p,p[i].profession_p);
        }
        sauvegarde_annuaire("resultat_filtrer_combiner_deux_champs.txt",p,size);

    }
    /**PROBLEME **/
    if(stricmp(nom_champ1,"profession")==0 && stricmp(nom_champ2,"nom")==0)
    {
        printf("profession et nom\n");
        for(int i = 0; i<size; i++)
        {
            if(Filtrer(p[i].profession_p,val_chaine1,size)!=1 || Filtrer(p[i].nom_p,val_chaine2,size)!=1)
            {

                for (int j = i; j < size; j++)
                {
                    //deplace l'élement a ma fin du tableau
                    p[j]=p[j+1];

                }
                size--;//decremente le compteur
                //decremente la taille du tableau

                i--;

            }


            //printf("%s,%s,%s,%s,%s,%s,%s\n",p[i].nom_p,p[i].prenom_p,p[i].code_postal_p,p[i].ville_p,p[i].telephone_p,p[i].mel_p,p[i].profession_p);
        }
        for(int i = 0; i<size; i++)
        {
            printf("%s,%s,%s,%s,%s,%s,%s\n",p[i].nom_p,p[i].prenom_p,p[i].code_postal_p,p[i].ville_p,p[i].telephone_p,p[i].mel_p,p[i].profession_p);
        }
        sauvegarde_annuaire("resultat_filtrer_combiner_deux_champs.txt",p,size);

    }
    if(stricmp(nom_champ1,"postal")==0 && stricmp(nom_champ2,"prenom")==0)
    {
        printf("code postal et prenom\n");
        for(int i = 0; i<size; i++)
        {
            if(Filtrer(p[i].code_postal_p,val_chaine1,size)!=1 || Filtrer(p[i].prenom_p,val_chaine2,size)!=1)
            {

                for (int j = i; j < size; j++)
                {
                    //deplace l'élement a ma fin du tableau
                    p[j]=p[j+1];

                }
                size--;//decremente le compteur
                //decremente la taille du tableau

                i--;

            }


            //printf("%s,%s,%s,%s,%s,%s,%s\n",p[i].nom_p,p[i].prenom_p,p[i].code_postal_p,p[i].ville_p,p[i].telephone_p,p[i].mel_p,p[i].profession_p);
        }
        for(int i = 0; i<size; i++)
        {
            printf("%s,%s,%s,%s,%s,%s,%s\n",p[i].nom_p,p[i].prenom_p,p[i].code_postal_p,p[i].ville_p,p[i].telephone_p,p[i].mel_p,p[i].profession_p);
        }
        sauvegarde_annuaire("resultat_filtrer_combiner_deux_champs.txt",p,size);

    }
    if(stricmp(nom_champ1,"ville")==0 && stricmp(nom_champ2,"prenom")==0)
    {
        printf("ville et prenom\n");
        for(int i = 0; i<size; i++)
        {
            if(Filtrer(p[i].ville_p,val_chaine1,size)!=1 || Filtrer(p[i].prenom_p,val_chaine2,size)!=1)
            {

                for (int j = i; j < size; j++)
                {
                    //deplace l'élement a ma fin du tableau
                    p[j]=p[j+1];

                }
                size--;//decremente le compteur
                //decremente la taille du tableau

                i--;

            }


            //printf("%s,%s,%s,%s,%s,%s,%s\n",p[i].nom_p,p[i].prenom_p,p[i].code_postal_p,p[i].ville_p,p[i].telephone_p,p[i].mel_p,p[i].profession_p);
        }
        for(int i = 0; i<size; i++)
        {
            printf("%s,%s,%s,%s,%s,%s,%s\n",p[i].nom_p,p[i].prenom_p,p[i].code_postal_p,p[i].ville_p,p[i].telephone_p,p[i].mel_p,p[i].profession_p);
        }
        sauvegarde_annuaire("resultat_filtrer_combiner_deux_champs.txt",p,size);

    }
    if(stricmp(nom_champ1,"tel")==0 && stricmp(nom_champ2,"prenom")==0)
    {
        printf("telephone et prenom\n");
        for(int i = 0; i<size; i++)
        {
            if(Filtrer(p[i].telephone_p,val_chaine1,size)!=1 || Filtrer(p[i].prenom_p,val_chaine2,size)!=1)
            {

                for (int j = i; j < size; j++)
                {
                    //deplace l'élement a ma fin du tableau
                    p[j]=p[j+1];

                }
                size--;//decremente le compteur
                //decremente la taille du tableau

                i--;

            }


            //printf("%s,%s,%s,%s,%s,%s,%s\n",p[i].nom_p,p[i].prenom_p,p[i].code_postal_p,p[i].ville_p,p[i].telephone_p,p[i].mel_p,p[i].profession_p);
        }
        for(int i = 0; i<size; i++)
        {
            printf("%s,%s,%s,%s,%s,%s,%s\n",p[i].nom_p,p[i].prenom_p,p[i].code_postal_p,p[i].ville_p,p[i].telephone_p,p[i].mel_p,p[i].profession_p);
        }
        sauvegarde_annuaire("resultat_filtrer_combiner_deux_champs.txt",p,size);

    }
    if(stricmp(nom_champ1,"mel")==0 && stricmp(nom_champ2,"prenom")==0)
    {
        printf("mail et prenom\n");
        for(int i = 0; i<size; i++)
        {
            if(Filtrer(p[i].mel_p,val_chaine1,size)!=1 || Filtrer(p[i].prenom_p,val_chaine2,size)!=1)
            {

                for (int j = i; j < size; j++)
                {
                    //deplace l'élement a ma fin du tableau
                    p[j]=p[j+1];

                }
                size--;//decremente le compteur
                //decremente la taille du tableau

                i--;

            }


            //printf("%s,%s,%s,%s,%s,%s,%s\n",p[i].nom_p,p[i].prenom_p,p[i].code_postal_p,p[i].ville_p,p[i].telephone_p,p[i].mel_p,p[i].profession_p);
        }
        for(int i = 0; i<size; i++)
        {
            printf("%s,%s,%s,%s,%s,%s,%s\n",p[i].nom_p,p[i].prenom_p,p[i].code_postal_p,p[i].ville_p,p[i].telephone_p,p[i].mel_p,p[i].profession_p);
        }
        sauvegarde_annuaire("resultat_filtrer_combiner_deux_champs.txt",p,size);

    }
    if(stricmp(nom_champ1,"profession")==0 && stricmp(nom_champ2,"prenom")==0)
    {
        printf("profession et prenom\n");
        for(int i = 0; i<size; i++)
        {
            if(Filtrer(p[i].profession_p,val_chaine1,size)!=1 || Filtrer(p[i].prenom_p,val_chaine2,size)!=1)
            {

                for (int j = i; j < size; j++)
                {
                    //deplace l'élement a ma fin du tableau
                    p[j]=p[j+1];

                }
                size--;//decremente le compteur
                //decremente la taille du tableau

                i--;

            }


            //printf("%s,%s,%s,%s,%s,%s,%s\n",p[i].nom_p,p[i].prenom_p,p[i].code_postal_p,p[i].ville_p,p[i].telephone_p,p[i].mel_p,p[i].profession_p);
        }
        for(int i = 0; i<size; i++)
        {
            printf("%s,%s,%s,%s,%s,%s,%s\n",p[i].nom_p,p[i].prenom_p,p[i].code_postal_p,p[i].ville_p,p[i].telephone_p,p[i].mel_p,p[i].profession_p);
        }
        sauvegarde_annuaire("resultat_filtrer_combiner_deux_champs.txt",p,size);

    }
    if(stricmp(nom_champ1,"ville")==0 && stricmp(nom_champ2,"postal")==0)
    {
        printf(" ville et code postal\n");
        for(int i = 0; i<size; i++)
        {
            if(Filtrer(p[i].ville_p,val_chaine1,size)!=1 || Filtrer(p[i].code_postal_p,val_chaine2,size)!=1)
            {

                for (int j = i; j < size; j++)
                {
                    //deplace l'élement a ma fin du tableau
                    p[j]=p[j+1];

                }
                size--;//decremente le compteur
                //decremente la taille du tableau

                i--;

            }


            //printf("%s,%s,%s,%s,%s,%s,%s\n",p[i].nom_p,p[i].prenom_p,p[i].code_postal_p,p[i].ville_p,p[i].telephone_p,p[i].mel_p,p[i].profession_p);
        }
        for(int i = 0; i<size; i++)
        {
            printf("%s,%s,%s,%s,%s,%s,%s\n",p[i].nom_p,p[i].prenom_p,p[i].code_postal_p,p[i].ville_p,p[i].telephone_p,p[i].mel_p,p[i].profession_p);
        }
        sauvegarde_annuaire("resultat_filtrer_combiner_deux_champs.txt",p,size);

    }
    if(stricmp(nom_champ1,"tel")==0 && stricmp(nom_champ2,"postal")==0)
    {
        printf("telephone et code postal\n");
        for(int i = 0; i<size; i++)
        {
            if(Filtrer(p[i].telephone_p,val_chaine1,size)!=1 || Filtrer(p[i].code_postal_p,val_chaine2,size)!=1)
            {

                for (int j = i; j < size; j++)
                {
                    //deplace l'élement a ma fin du tableau
                    p[j]=p[j+1];

                }
                size--;//decremente le compteur
                //decremente la taille du tableau

                i--;

            }


            //printf("%s,%s,%s,%s,%s,%s,%s\n",p[i].nom_p,p[i].prenom_p,p[i].code_postal_p,p[i].ville_p,p[i].telephone_p,p[i].mel_p,p[i].profession_p);
        }
        for(int i = 0; i<size; i++)
        {
            printf("%s,%s,%s,%s,%s,%s,%s\n",p[i].nom_p,p[i].prenom_p,p[i].code_postal_p,p[i].ville_p,p[i].telephone_p,p[i].mel_p,p[i].profession_p);
        }
        sauvegarde_annuaire("resultat_filtrer_combiner_deux_champs.txt",p,size);

    }
    if(stricmp(nom_champ1,"mel")==0 && stricmp(nom_champ2,"postal")==0)
    {
        printf("mail et code postal\n");
        for(int i = 0; i<size; i++)
        {
            if(Filtrer(p[i].mel_p,val_chaine1,size)!=1 || Filtrer(p[i].code_postal_p,val_chaine2,size)!=1)
            {

                for (int j = i; j < size; j++)
                {
                    //deplace l'élement a ma fin du tableau
                    p[j]=p[j+1];

                }
                size--;//decremente le compteur
                //decremente la taille du tableau

                i--;

            }


            //printf("%s,%s,%s,%s,%s,%s,%s\n",p[i].nom_p,p[i].prenom_p,p[i].code_postal_p,p[i].ville_p,p[i].telephone_p,p[i].mel_p,p[i].profession_p);
        }
        for(int i = 0; i<size; i++)
        {
            printf("%s,%s,%s,%s,%s,%s,%s\n",p[i].nom_p,p[i].prenom_p,p[i].code_postal_p,p[i].ville_p,p[i].telephone_p,p[i].mel_p,p[i].profession_p);
        }
        sauvegarde_annuaire("resultat_filtrer_combiner_deux_champs.txt",p,size);

    }
    if(stricmp(nom_champ1,"profession")==0 && stricmp(nom_champ2,"postal")==0)
    {
        printf(" profession et code postal\n");
        for(int i = 0; i<size; i++)
        {
            if(Filtrer(p[i].profession_p,val_chaine1,size)!=1 || Filtrer(p[i].code_postal_p,val_chaine2,size)!=1)
            {

                for (int j = i; j < size; j++)
                {
                    //deplace l'élement a ma fin du tableau
                    p[j]=p[j+1];

                }
                size--;//decremente le compteur
                //decremente la taille du tableau

                i--;

            }


            //printf("%s,%s,%s,%s,%s,%s,%s\n",p[i].nom_p,p[i].prenom_p,p[i].code_postal_p,p[i].ville_p,p[i].telephone_p,p[i].mel_p,p[i].profession_p);
        }
        for(int i = 0; i<size; i++)
        {
            printf("%s,%s,%s,%s,%s,%s,%s\n",p[i].nom_p,p[i].prenom_p,p[i].code_postal_p,p[i].ville_p,p[i].telephone_p,p[i].mel_p,p[i].profession_p);
        }
        sauvegarde_annuaire("resultat_filtrer_combiner_deux_champs.txt",p,size);

    }
    if(stricmp(nom_champ1,"tel")==0 && stricmp(nom_champ2,"ville")==0)
    {
        printf("telephone et ville\n");
        for(int i = 0; i<size; i++)
        {
            if(Filtrer(p[i].telephone_p,val_chaine1,size)!=1 || Filtrer(p[i].ville_p,val_chaine2,size)!=1)
            {

                for (int j = i; j < size; j++)
                {
                    //deplace l'élement a ma fin du tableau
                    p[j]=p[j+1];

                }
                size--;//decremente le compteur
                //decremente la taille du tableau

                i--;

            }


            //printf("%s,%s,%s,%s,%s,%s,%s\n",p[i].nom_p,p[i].prenom_p,p[i].code_postal_p,p[i].ville_p,p[i].telephone_p,p[i].mel_p,p[i].profession_p);
        }
        for(int i = 0; i<size; i++)
        {
            printf("%s,%s,%s,%s,%s,%s,%s\n",p[i].nom_p,p[i].prenom_p,p[i].code_postal_p,p[i].ville_p,p[i].telephone_p,p[i].mel_p,p[i].profession_p);
        }
        sauvegarde_annuaire("resultat_filtrer_combiner_deux_champs.txt",p,size);

    }
    if(stricmp(nom_champ1,"mel")==0 && stricmp(nom_champ2,"ville")==0)
    {
        printf("mail et ville\n");
        for(int i = 0; i<size; i++)
        {
            if(Filtrer(p[i].mel_p,val_chaine1,size)!=1 || Filtrer(p[i].ville_p,val_chaine2,size)!=1)
            {

                for (int j = i; j < size; j++)
                {
                    //deplace l'élement a ma fin du tableau
                    p[j]=p[j+1];

                }
                size--;//decremente le compteur
                //decremente la taille du tableau

                i--;

            }


            //printf("%s,%s,%s,%s,%s,%s,%s\n",p[i].nom_p,p[i].prenom_p,p[i].code_postal_p,p[i].ville_p,p[i].telephone_p,p[i].mel_p,p[i].profession_p);
        }
        for(int i = 0; i<size; i++)
        {
            printf("%s,%s,%s,%s,%s,%s,%s\n",p[i].nom_p,p[i].prenom_p,p[i].code_postal_p,p[i].ville_p,p[i].telephone_p,p[i].mel_p,p[i].profession_p);
        }
        sauvegarde_annuaire("resultat_filtrer_combiner_deux_champs.txt",p,size);

    }
    if(stricmp(nom_champ1,"profession")==0 && stricmp(nom_champ2,"ville")==0)
    {
        printf("profession et ville\n");
        for(int i = 0; i<size; i++)
        {
            if(Filtrer(p[i].profession_p,val_chaine1,size)!=1 || Filtrer(p[i].ville_p,val_chaine2,size)!=1)
            {

                for (int j = i; j < size; j++)
                {
                    //deplace l'élement a ma fin du tableau
                    p[j]=p[j+1];

                }
                size--;//decremente le compteur
                //decremente la taille du tableau

                i--;

            }


            //printf("%s,%s,%s,%s,%s,%s,%s\n",p[i].nom_p,p[i].prenom_p,p[i].code_postal_p,p[i].ville_p,p[i].telephone_p,p[i].mel_p,p[i].profession_p);
        }
        for(int i = 0; i<size; i++)
        {
            printf("%s,%s,%s,%s,%s,%s,%s\n",p[i].nom_p,p[i].prenom_p,p[i].code_postal_p,p[i].ville_p,p[i].telephone_p,p[i].mel_p,p[i].profession_p);
        }
        sauvegarde_annuaire("resultat_filtrer_combiner_deux_champs.txt",p,size);

    }
    if(stricmp(nom_champ1,"mel")==0 && stricmp(nom_champ2,"tel")==0)
    {
        printf(" mail et telephone\n");
        for(int i = 0; i<size; i++)
        {
            if(Filtrer(p[i].mel_p,val_chaine1,size)!=1 || Filtrer(p[i].telephone_p,val_chaine2,size)!=1)
            {

                for (int j = i; j < size; j++)
                {
                    //deplace l'élement a ma fin du tableau
                    p[j]=p[j+1];

                }
                size--;//decremente le compteur
                //decremente la taille du tableau

                i--;

            }


            //printf("%s,%s,%s,%s,%s,%s,%s\n",p[i].nom_p,p[i].prenom_p,p[i].code_postal_p,p[i].ville_p,p[i].telephone_p,p[i].mel_p,p[i].profession_p);
        }
        for(int i = 0; i<size; i++)
        {
            printf("%s,%s,%s,%s,%s,%s,%s\n",p[i].nom_p,p[i].prenom_p,p[i].code_postal_p,p[i].ville_p,p[i].telephone_p,p[i].mel_p,p[i].profession_p);
        }
        sauvegarde_annuaire("resultat_filtrer_combiner_deux_champs.txt",p,size);

    }
    if(stricmp(nom_champ1,"profession")==0 && stricmp(nom_champ2,"tel")==0)
    {
        printf("profession et telephone\n");
        for(int i = 0; i<size; i++)
        {
            if(Filtrer(p[i].profession_p,val_chaine1,size)!=1 || Filtrer(p[i].telephone_p,val_chaine2,size)!=1)
            {

                for (int j = i; j < size; j++)
                {
                    //deplace l'élement a ma fin du tableau
                    p[j]=p[j+1];

                }
                size--;//decremente le compteur
                //decremente la taille du tableau

                i--;

            }


            //printf("%s,%s,%s,%s,%s,%s,%s\n",p[i].nom_p,p[i].prenom_p,p[i].code_postal_p,p[i].ville_p,p[i].telephone_p,p[i].mel_p,p[i].profession_p);
        }
        for(int i = 0; i<size; i++)
        {
            printf("%s,%s,%s,%s,%s,%s,%s\n",p[i].nom_p,p[i].prenom_p,p[i].code_postal_p,p[i].ville_p,p[i].telephone_p,p[i].mel_p,p[i].profession_p);
        }
        sauvegarde_annuaire("resultat_filtrer_combiner_deux_champs.txt",p,size);

    }
    if(stricmp(nom_champ1,"profession")==0 && stricmp(nom_champ2,"mel")==0)
    {
        printf("profession mail\n");
        for(int i = 0; i<size; i++)
        {
            if(Filtrer(p[i].profession_p,val_chaine1,size)!=1 || Filtrer(p[i].mel_p,val_chaine2,size)!=1)
            {

                for (int j = i; j < size; j++)
                {
                    //deplace l'élement a ma fin du tableau
                    p[j]=p[j+1];

                }
                size--;//decremente le compteur
                //decremente la taille du tableau

                i--;

            }


            //printf("%s,%s,%s,%s,%s,%s,%s\n",p[i].nom_p,p[i].prenom_p,p[i].code_postal_p,p[i].ville_p,p[i].telephone_p,p[i].mel_p,p[i].profession_p);
        }
        for(int i = 0; i<size; i++)
        {
            printf("%s,%s,%s,%s,%s,%s,%s\n",p[i].nom_p,p[i].prenom_p,p[i].code_postal_p,p[i].ville_p,p[i].telephone_p,p[i].mel_p,p[i].profession_p);
        }
        sauvegarde_annuaire("resultat_filtrer_combiner_deux_champs.txt",p,size);

    }


    if(stricmp(nom_champ1,"nom")==0 && stricmp(nom_champ2,"ville")==0)
    {
        printf("nom et ville\n");
        for(int i = 0; i<size; i++)
        {
            if(Filtrer(p[i].nom_p,val_chaine1,size)!=1 || Filtrer(p[i].ville_p,val_chaine2,size)!=1)
            {

                for (int j = i; j < size; j++)
                {
                    //deplace l'élement a ma fin du tableau
                    p[j]=p[j+1];

                }
                size--;//decremente le compteur
                //decremente la taille du tableau

                i--;

            }


            //printf("%s,%s,%s,%s,%s,%s,%s\n",p[i].nom_p,p[i].prenom_p,p[i].code_postal_p,p[i].ville_p,p[i].telephone_p,p[i].mel_p,p[i].profession_p);
        }
        for(int i = 0; i<size; i++)
        {
            printf("%s,%s,%s,%s,%s,%s,%s\n",p[i].nom_p,p[i].prenom_p,p[i].code_postal_p,p[i].ville_p,p[i].telephone_p,p[i].mel_p,p[i].profession_p);
        }
        sauvegarde_annuaire("resultat_filtrer_combiner_deux_champs.txt",p,size);

    }
    if(stricmp(nom_champ1,"nom")==0 && stricmp(nom_champ2,"tel")==0)
    {
        printf("nom et telephone\n");
        for(int i = 0; i<size; i++)
        {
            if(Filtrer(p[i].nom_p,val_chaine1,size)!=1 || Filtrer(p[i].telephone_p,val_chaine2,size)!=1)
            {

                for (int j = i; j < size; j++)
                {
                    //deplace l'élement a ma fin du tableau
                    p[j]=p[j+1];

                }
                size--;//decremente le compteur
                //decremente la taille du tableau

                i--;

            }


            //printf("%s,%s,%s,%s,%s,%s,%s\n",p[i].nom_p,p[i].prenom_p,p[i].code_postal_p,p[i].ville_p,p[i].telephone_p,p[i].mel_p,p[i].profession_p);
        }
        for(int i = 0; i<size; i++)
        {
            printf("%s,%s,%s,%s,%s,%s,%s\n",p[i].nom_p,p[i].prenom_p,p[i].code_postal_p,p[i].ville_p,p[i].telephone_p,p[i].mel_p,p[i].profession_p);
        }
        sauvegarde_annuaire("resultat_filtrer_combiner_deux_champs.txt",p,size);

    }
    if(stricmp(nom_champ1,"nom")==0 && stricmp(nom_champ2,"mel")==0)
    {
        printf("nom et mail\n");
        for(int i = 0; i<size; i++)
        {
            if(Filtrer(p[i].nom_p,val_chaine1,size)!=1 || Filtrer(p[i].mel_p,val_chaine2,size)!=1)
            {

                for (int j = i; j < size; j++)
                {
                    //deplace l'élement a ma fin du tableau
                    p[j]=p[j+1];

                }
                size--;//decremente le compteur
                //decremente la taille du tableau

                i--;

            }


            //printf("%s,%s,%s,%s,%s,%s,%s\n",p[i].nom_p,p[i].prenom_p,p[i].code_postal_p,p[i].ville_p,p[i].telephone_p,p[i].mel_p,p[i].profession_p);
        }
        for(int i = 0; i<size; i++)
        {
            printf("%s,%s,%s,%s,%s,%s,%s\n",p[i].nom_p,p[i].prenom_p,p[i].code_postal_p,p[i].ville_p,p[i].telephone_p,p[i].mel_p,p[i].profession_p);
        }
        sauvegarde_annuaire("resultat_filtrer_combiner_deux_champs.txt",p,size);

    }
    if(stricmp(nom_champ1,"nom")==0 && stricmp(nom_champ2,"profession")==0)
    {
        printf("nom et profession\n");
        for(int i = 0; i<size; i++)
        {
            if(Filtrer(p[i].nom_p,val_chaine1,size)!=1 || Filtrer(p[i].profession_p,val_chaine2,size)!=1)
            {

                for (int j = i; j < size; j++)
                {
                    //deplace l'élement a ma fin du tableau
                    p[j]=p[j+1];

                }
                size--;//decremente le compteur
                //decremente la taille du tableau

                i--;

            }


            //printf("%s,%s,%s,%s,%s,%s,%s\n",p[i].nom_p,p[i].prenom_p,p[i].code_postal_p,p[i].ville_p,p[i].telephone_p,p[i].mel_p,p[i].profession_p);
        }
        for(int i = 0; i<size; i++)
        {
            printf("%s,%s,%s,%s,%s,%s,%s\n",p[i].nom_p,p[i].prenom_p,p[i].code_postal_p,p[i].ville_p,p[i].telephone_p,p[i].mel_p,p[i].profession_p);
        }
        sauvegarde_annuaire("resultat_filtrer_combiner_deux_champs.txt",p,size);

    }
    if(stricmp(nom_champ1,"prenom")==0 && stricmp(nom_champ2,"postal")==0)
    {
        printf("prenom et code postal\n");
        for(int i = 0; i<size; i++)
        {
            if(Filtrer(p[i].prenom_p,val_chaine1,size)!=1 || Filtrer(p[i].code_postal_p,val_chaine2,size)!=1)
            {

                for (int j = i; j < size; j++)
                {
                    //deplace l'élement a ma fin du tableau
                    p[j]=p[j+1];

                }
                size--;//decremente le compteur
                //decremente la taille du tableau

                i--;

            }


            //printf("%s,%s,%s,%s,%s,%s,%s\n",p[i].nom_p,p[i].prenom_p,p[i].code_postal_p,p[i].ville_p,p[i].telephone_p,p[i].mel_p,p[i].profession_p);
        }
        for(int i = 0; i<size; i++)
        {
            printf("%s,%s,%s,%s,%s,%s,%s\n",p[i].nom_p,p[i].prenom_p,p[i].code_postal_p,p[i].ville_p,p[i].telephone_p,p[i].mel_p,p[i].profession_p);
        }
        sauvegarde_annuaire("resultat_filtrer_combiner_deux_champs.txt",p,size);

    }
    if(stricmp(nom_champ1,"prenom")==0 && stricmp(nom_champ2,"ville")==0)
    {
        printf("prenom et ville\n");
        for(int i = 0; i<size; i++)
        {
            if(Filtrer(p[i].prenom_p,val_chaine1,size)!=1 || Filtrer(p[i].ville_p,val_chaine2,size)!=1)
            {

                for (int j = i; j < size; j++)
                {
                    //deplace l'élement a ma fin du tableau
                    p[j]=p[j+1];

                }
                size--;//decremente le compteur
                //decremente la taille du tableau

                i--;

            }


            //printf("%s,%s,%s,%s,%s,%s,%s\n",p[i].nom_p,p[i].prenom_p,p[i].code_postal_p,p[i].ville_p,p[i].telephone_p,p[i].mel_p,p[i].profession_p);
        }
        for(int i = 0; i<size; i++)
        {
            printf("%s,%s,%s,%s,%s,%s,%s\n",p[i].nom_p,p[i].prenom_p,p[i].code_postal_p,p[i].ville_p,p[i].telephone_p,p[i].mel_p,p[i].profession_p);
        }
        sauvegarde_annuaire("resultat_filtrer_combiner_deux_champs.txt",p,size);

    }
    if(stricmp(nom_champ1,"prenom")==0 && stricmp(nom_champ2,"tel")==0)
    {
        printf("prenom et telephone\n");
        for(int i = 0; i<size; i++)
        {
            if(Filtrer(p[i].prenom_p,val_chaine1,size)!=1 || Filtrer(p[i].telephone_p,val_chaine2,size)!=1)
            {

                for (int j = i; j < size; j++)
                {
                    //deplace l'élement a ma fin du tableau
                    p[j]=p[j+1];

                }
                size--;//decremente le compteur
                //decremente la taille du tableau

                i--;

            }


            //printf("%s,%s,%s,%s,%s,%s,%s\n",p[i].nom_p,p[i].prenom_p,p[i].code_postal_p,p[i].ville_p,p[i].telephone_p,p[i].mel_p,p[i].profession_p);
        }
        for(int i = 0; i<size; i++)
        {
            printf("%s,%s,%s,%s,%s,%s,%s\n",p[i].nom_p,p[i].prenom_p,p[i].code_postal_p,p[i].ville_p,p[i].telephone_p,p[i].mel_p,p[i].profession_p);
        }
        sauvegarde_annuaire("resultat_filtrer_combiner_deux_champs.txt",p,size);

    }
    if(stricmp(nom_champ1,"prenom")==0 && stricmp(nom_champ2,"mel")==0)
    {
        printf("prenom et mail\n");
        for(int i = 0; i<size; i++)
        {
            if(Filtrer(p[i].prenom_p,val_chaine1,size)!=1 || Filtrer(p[i].mel_p,val_chaine2,size)!=1)
            {

                for (int j = i; j < size; j++)
                {
                    //deplace l'élement a ma fin du tableau
                    p[j]=p[j+1];

                }
                size--;//decremente le compteur
                //decremente la taille du tableau

                i--;

            }


            //printf("%s,%s,%s,%s,%s,%s,%s\n",p[i].nom_p,p[i].prenom_p,p[i].code_postal_p,p[i].ville_p,p[i].telephone_p,p[i].mel_p,p[i].profession_p);
        }
        for(int i = 0; i<size; i++)
        {
            printf("%s,%s,%s,%s,%s,%s,%s\n",p[i].nom_p,p[i].prenom_p,p[i].code_postal_p,p[i].ville_p,p[i].telephone_p,p[i].mel_p,p[i].profession_p);
        }
        sauvegarde_annuaire("resultat_filtrer_combiner_deux_champs.txt",p,size);

    }
    if(stricmp(nom_champ1,"prenom")==0 && stricmp(nom_champ2,"profession")==0)
    {
        printf("prenom et profession\n");
        for(int i = 0; i<size; i++)
        {
            if(Filtrer(p[i].prenom_p,val_chaine1,size)!=1 || Filtrer(p[i].profession_p,val_chaine2,size)!=1)
            {

                for (int j = i; j < size; j++)
                {
                    //deplace l'élement a ma fin du tableau
                    p[j]=p[j+1];

                }
                size--;//decremente le compteur
                //decremente la taille du tableau

                i--;

            }


            //printf("%s,%s,%s,%s,%s,%s,%s\n",p[i].nom_p,p[i].prenom_p,p[i].code_postal_p,p[i].ville_p,p[i].telephone_p,p[i].mel_p,p[i].profession_p);
        }
        for(int i = 0; i<size; i++)
        {
            printf("%s,%s,%s,%s,%s,%s,%s\n",p[i].nom_p,p[i].prenom_p,p[i].code_postal_p,p[i].ville_p,p[i].telephone_p,p[i].mel_p,p[i].profession_p);
        }
        sauvegarde_annuaire("resultat_filtrer_combiner_deux_champs.txt",p,size);

    }
    if(stricmp(nom_champ1,"postal")==0 && stricmp(nom_champ2,"ville")==0)
    {
        printf("code postal et ville\n");
        for(int i = 0; i<size; i++)
        {
            if(Filtrer(p[i].code_postal_p,val_chaine1,size)!=1 || Filtrer(p[i].ville_p,val_chaine2,size)!=1)
            {

                for (int j = i; j < size; j++)
                {
                    //deplace l'élement a ma fin du tableau
                    p[j]=p[j+1];

                }
                size--;//decremente le compteur
                //decremente la taille du tableau

                i--;

            }


            //printf("%s,%s,%s,%s,%s,%s,%s\n",p[i].nom_p,p[i].prenom_p,p[i].code_postal_p,p[i].ville_p,p[i].telephone_p,p[i].mel_p,p[i].profession_p);
        }
        for(int i = 0; i<size; i++)
        {
            printf("%s,%s,%s,%s,%s,%s,%s\n",p[i].nom_p,p[i].prenom_p,p[i].code_postal_p,p[i].ville_p,p[i].telephone_p,p[i].mel_p,p[i].profession_p);
        }
        sauvegarde_annuaire("resultat_filtrer_combiner_deux_champs.txt",p,size);

    }
    if(stricmp(nom_champ1,"postal")==0 && stricmp(nom_champ2,"tel")==0)
    {
        printf("code postal  et telephone\n");
        for(int i = 0; i<size; i++)
        {
            if(Filtrer(p[i].code_postal_p,val_chaine1,size)!=1 || Filtrer(p[i].telephone_p,val_chaine2,size)!=1)
            {

                for (int j = i; j < size; j++)
                {
                    //deplace l'élement a ma fin du tableau
                    p[j]=p[j+1];

                }
                size--;//decremente le compteur
                //decremente la taille du tableau

                i--;

            }


            //printf("%s,%s,%s,%s,%s,%s,%s\n",p[i].nom_p,p[i].prenom_p,p[i].code_postal_p,p[i].ville_p,p[i].telephone_p,p[i].mel_p,p[i].profession_p);
        }
        for(int i = 0; i<size; i++)
        {
            printf("%s,%s,%s,%s,%s,%s,%s\n",p[i].nom_p,p[i].prenom_p,p[i].code_postal_p,p[i].ville_p,p[i].telephone_p,p[i].mel_p,p[i].profession_p);
        }
        sauvegarde_annuaire("resultat_filtrer_combiner_deux_champs.txt",p,size);

    }
    if(stricmp(nom_champ1,"postal")==0 && stricmp(nom_champ2,"mel")==0)
    {
        printf("code postal  et mail\n");
        for(int i = 0; i<size; i++)
        {
            if(Filtrer(p[i].code_postal_p,val_chaine1,size)!=1 || Filtrer(p[i].mel_p,val_chaine2,size)!=1)
            {

                for (int j = i; j < size; j++)
                {
                    //deplace l'élement a ma fin du tableau
                    p[j]=p[j+1];

                }
                size--;//decremente le compteur
                //decremente la taille du tableau

                i--;

            }


            //printf("%s,%s,%s,%s,%s,%s,%s\n",p[i].nom_p,p[i].prenom_p,p[i].code_postal_p,p[i].ville_p,p[i].telephone_p,p[i].mel_p,p[i].profession_p);
        }
        for(int i = 0; i<size; i++)
        {
            printf("%s,%s,%s,%s,%s,%s,%s\n",p[i].nom_p,p[i].prenom_p,p[i].code_postal_p,p[i].ville_p,p[i].telephone_p,p[i].mel_p,p[i].profession_p);
        }
        sauvegarde_annuaire("resultat_filtrer_combiner_deux_champs.txt",p,size);

    }
    if(stricmp(nom_champ1,"postal")==0 && stricmp(nom_champ2,"profession")==0)
    {
        printf("code postal  et profession\n");
        for(int i = 0; i<size; i++)
        {
            if(Filtrer(p[i].code_postal_p,val_chaine1,size)!=1 || Filtrer(p[i].profession_p,val_chaine2,size)!=1)
            {

                for (int j = i; j < size; j++)
                {
                    //deplace l'élement a ma fin du tableau
                    p[j]=p[j+1];

                }
                size--;//decremente le compteur
                //decremente la taille du tableau

                i--;

            }


            //printf("%s,%s,%s,%s,%s,%s,%s\n",p[i].nom_p,p[i].prenom_p,p[i].code_postal_p,p[i].ville_p,p[i].telephone_p,p[i].mel_p,p[i].profession_p);
        }
        for(int i = 0; i<size; i++)
        {
            printf("%s,%s,%s,%s,%s,%s,%s\n",p[i].nom_p,p[i].prenom_p,p[i].code_postal_p,p[i].ville_p,p[i].telephone_p,p[i].mel_p,p[i].profession_p);
        }
        sauvegarde_annuaire("resultat_filtrer_combiner_deux_champs.txt",p,size);

    }
    if(stricmp(nom_champ1,"ville")==0 && stricmp(nom_champ2,"tel")==0)
    {
        printf("ville  et telephone\n");
        for(int i = 0; i<size; i++)
        {
            if(Filtrer(p[i].ville_p,val_chaine1,size)!=1 || Filtrer(p[i].telephone_p,val_chaine2,size)!=1)
            {

                for (int j = i; j < size; j++)
                {
                    //deplace l'élement a ma fin du tableau
                    p[j]=p[j+1];

                }
                size--;//decremente le compteur
                //decremente la taille du tableau

                i--;

            }


            //printf("%s,%s,%s,%s,%s,%s,%s\n",p[i].nom_p,p[i].prenom_p,p[i].code_postal_p,p[i].ville_p,p[i].telephone_p,p[i].mel_p,p[i].profession_p);
        }
        for(int i = 0; i<size; i++)
        {
            printf("%s,%s,%s,%s,%s,%s,%s\n",p[i].nom_p,p[i].prenom_p,p[i].code_postal_p,p[i].ville_p,p[i].telephone_p,p[i].mel_p,p[i].profession_p);
        }
        sauvegarde_annuaire("resultat_filtrer_combiner_deux_champs.txt",p,size);

    }
    if(stricmp(nom_champ1,"ville")==0 && stricmp(nom_champ2,"mel")==0)
    {
        printf("ville  et mail\n");
        for(int i = 0; i<size; i++)
        {
            if(Filtrer(p[i].ville_p,val_chaine1,size)!=1 || Filtrer(p[i].mel_p,val_chaine2,size)!=1)
            {

                for (int j = i; j < size; j++)
                {
                    //deplace l'élement a ma fin du tableau
                    p[j]=p[j+1];

                }
                size--;//decremente le compteur
                //decremente la taille du tableau

                i--;

            }


            //printf("%s,%s,%s,%s,%s,%s,%s\n",p[i].nom_p,p[i].prenom_p,p[i].code_postal_p,p[i].ville_p,p[i].telephone_p,p[i].mel_p,p[i].profession_p);
        }
        for(int i = 0; i<size; i++)
        {
            printf("%s,%s,%s,%s,%s,%s,%s\n",p[i].nom_p,p[i].prenom_p,p[i].code_postal_p,p[i].ville_p,p[i].telephone_p,p[i].mel_p,p[i].profession_p);
        }
        sauvegarde_annuaire("resultat_filtrer_combiner_deux_champs.txt",p,size);

    }
    if(stricmp(nom_champ1,"ville")==0 && stricmp(nom_champ2,"profession")==0)
    {
        printf("ville  et profession\n");
        for(int i = 0; i<size; i++)
        {
            if(Filtrer(p[i].ville_p,val_chaine1,size)!=1 || Filtrer(p[i].profession_p,val_chaine2,size)!=1)
            {

                for (int j = i; j < size; j++)
                {
                    //deplace l'élement a ma fin du tableau
                    p[j]=p[j+1];

                }
                size--;//decremente le compteur
                //decremente la taille du tableau

                i--;

            }


            //printf("%s,%s,%s,%s,%s,%s,%s\n",p[i].nom_p,p[i].prenom_p,p[i].code_postal_p,p[i].ville_p,p[i].telephone_p,p[i].mel_p,p[i].profession_p);
        }
        for(int i = 0; i<size; i++)
        {
            printf("%s,%s,%s,%s,%s,%s,%s\n",p[i].nom_p,p[i].prenom_p,p[i].code_postal_p,p[i].ville_p,p[i].telephone_p,p[i].mel_p,p[i].profession_p);
        }
        sauvegarde_annuaire("resultat_filtrer_combiner_deux_champs.txt",p,size);

    }
    if(stricmp(nom_champ1,"tel")==0 && stricmp(nom_champ2,"mel")==0)
    {
        printf("telephone et mail\n");
        for(int i = 0; i<size; i++)
        {
            if(Filtrer(p[i].telephone_p,val_chaine1,size)!=1 || Filtrer(p[i].mel_p,val_chaine2,size)!=1)
            {

                for (int j = i; j < size; j++)
                {
                    //deplace l'élement a ma fin du tableau
                    p[j]=p[j+1];

                }
                size--;//decremente le compteur
                //decremente la taille du tableau

                i--;

            }


            //printf("%s,%s,%s,%s,%s,%s,%s\n",p[i].nom_p,p[i].prenom_p,p[i].code_postal_p,p[i].ville_p,p[i].telephone_p,p[i].mel_p,p[i].profession_p);
        }
        for(int i = 0; i<size; i++)
        {
            printf("%s,%s,%s,%s,%s,%s,%s\n",p[i].nom_p,p[i].prenom_p,p[i].code_postal_p,p[i].ville_p,p[i].telephone_p,p[i].mel_p,p[i].profession_p);
        }
        sauvegarde_annuaire("resultat_filtrer_combiner_deux_champs.txt",p,size);

    }
    if(stricmp(nom_champ1,"tel")==0 && stricmp(nom_champ2,"profession")==0)
    {
        printf("tel  et profession\n");
        for(int i = 0; i<size; i++)
        {
            if(Filtrer(p[i].telephone_p,val_chaine1,size)!=1 || Filtrer(p[i].profession_p,val_chaine2,size)!=1)
            {

                for (int j = i; j < size; j++)
                {
                    //deplace l'élement a ma fin du tableau
                    p[j]=p[j+1];

                }
                size--;//decremente le compteur
                //decremente la taille du tableau

                i--;

            }


            //printf("%s,%s,%s,%s,%s,%s,%s\n",p[i].nom_p,p[i].prenom_p,p[i].code_postal_p,p[i].ville_p,p[i].telephone_p,p[i].mel_p,p[i].profession_p);
        }
        for(int i = 0; i<size; i++)
        {
            printf("%s,%s,%s,%s,%s,%s,%s\n",p[i].nom_p,p[i].prenom_p,p[i].code_postal_p,p[i].ville_p,p[i].telephone_p,p[i].mel_p,p[i].profession_p);
        }
        sauvegarde_annuaire("resultat_filtrer_combiner_deux_champs.txt",p,size);

    }
    if(stricmp(nom_champ1,"mel")==0 && stricmp(nom_champ2,"profession")==0)
    {
        printf("mail  et profession\n");
        for(int i = 0; i<size; i++)
        {
            if(Filtrer(p[i].mel_p,val_chaine1,size)!=1 || Filtrer(p[i].profession_p,val_chaine2,size)!=1)
            {

                for (int j = i; j < size; j++)
                {
                    //deplace l'élement a ma fin du tableau
                    p[j]=p[j+1];

                }
                size--;//decremente le compteur
                //decremente la taille du tableau

                i--;

            }


            //printf("%s,%s,%s,%s,%s,%s,%s\n",p[i].nom_p,p[i].prenom_p,p[i].code_postal_p,p[i].ville_p,p[i].telephone_p,p[i].mel_p,p[i].profession_p);
        }
        for(int i = 0; i<size; i++)
        {
            printf("%s,%s,%s,%s,%s,%s,%s\n",p[i].nom_p,p[i].prenom_p,p[i].code_postal_p,p[i].ville_p,p[i].telephone_p,p[i].mel_p,p[i].profession_p);
        }
        sauvegarde_annuaire("resultat_filtrer_combiner_deux_champs.txt",p,size);

    }








    fclose(resultat_filtrer_combiner_deux_champs);
    free(p->nom_p);
    free(p->prenom_p);
    free(p->ville_p);
    free(p->mel_p);
    free(p->profession_p);
    free(p);
    fflush(stdin);
//ferme les fichiers



}
/** \brief cette fonction permet la saisie des filtre et des champs sur lequel il s'applique
 *
 * \param[in] Client*filtre
 * \return void
 *
 */
void SaisieFiltre(Client*filtre)
{

    int choixFiltre = 0;
    printf("########################################################################\n");
    printf("#                                                                      #\n");
    printf("#     BIENVENUE DANS L'OPTION FILTRE ICI VOUS POUVEZ                   #\n");
    printf("#     PERSONNALISEZ VOS RECHERCHES SUIVANT LE FILTRE CHOISI            #\n");
    printf("#                                                                      #\n");
    printf("########################################################################\n");
    printf("Choisissez votre filtre de preference : \n");
    printf("1) Filtre Simple....................\n");
    printf("2) Filtre Avancer...................\n");
    do
    {
        printf("Choisissez votre filtre : \n");
        scanf("%d",&filtre->choixFiltre);
    }
    while(filtre->choixFiltre<1 || filtre->choixFiltre>2);
    printf("Voici les champs ou vous pouvez appliquer votre filtre : \n");
    printf("1)Nom\n");
    printf("2)Prenom\n");
    printf("3)Code postal\n");
    printf("4)Ville\n");
    printf("5)Telephone\n");
    printf("6)Mail\n");
    printf("7)Profession\n");

    if(filtre->choixFiltre == 2)
    {

        printf("########################################################################\n");
        printf("#                                                                      #\n");
        printf("#     BIENVENUE DANS L'OPTION FILTRE AVANCER ICI VOUS POUVEZ           #\n");
        printf("#     COMMENCER VOTRE RECHERCHE A PARTIR D'UNE POSITION CHOISI         #\n");
        printf("########################################################################\n");
        printf("Exemple : prenons le Nom : Rafik , avec ce filtre vous pouvez choisir a partir de quelle lettre votre filtre s'applique\n\nsi vous la position 2 alors le filtre s'appliquera a partir de la lettre a et non a la premiere !\n\n");
            do{
        printf("entrer la position ou vous voulez commencer votre filtre sur le champs numero 1 : \n");
        scanf("%d",&filtre->index);
        printf("entrer la position ou vous voulez commencer votre filtre sur le champs numero 2 : \n");
        scanf("%d",&filtre->index2);
    }while(filtre->index <=0 || filtre->index2<=0);
    }

    printf("Choisissez votre champs numero 1 : ");
    scanf("%d",&filtre->critere1);
    printf("Chosissez votre champs numero 2 : ");
    scanf("%d",&filtre->critere2);

    int choix = 100*filtre->critere1 + 10*filtre->critere2;
    switch(choix)
    {
    case 120:
        strcpy(filtre->nom_champ1,"nom");
        strcpy(filtre->nom_champ2,"prenom");
        break;
    case 210:
        strcpy(filtre->nom_champ1,"prenom");
        strcpy(filtre->nom_champ2,"nom");
        break;
    case 130:
        strcpy(filtre->nom_champ1,"nom");
        strcpy(filtre->nom_champ2,"postal");
        break;
    case 310:
        strcpy(filtre->nom_champ1,"postal");
        strcpy(filtre->nom_champ2,"nom");
        break;
    case 140:
        strcpy(filtre->nom_champ1,"nom");
        strcpy(filtre->nom_champ2,"ville");
        break;
    case 410:
        strcpy(filtre->nom_champ1,"ville");
        strcpy(filtre->nom_champ2,"nom");
        break;
    case 150:
        strcpy(filtre->nom_champ1,"nom");
        strcpy(filtre->nom_champ2,"tel");
        break;
    case 510:
        strcpy(filtre->nom_champ1,"tel");
        strcpy(filtre->nom_champ2,"nom");
        break;

    case 160:
        strcpy(filtre->nom_champ1,"nom");
        strcpy(filtre->nom_champ2,"mel");
        break;
    case 610:
        strcpy(filtre->nom_champ1,"mel");
        strcpy(filtre->nom_champ2,"nom");
        break;
    case 170:
        strcpy(filtre->nom_champ1,"nom");
        strcpy(filtre->nom_champ2,"profession");
        break;
    case 710:
        strcpy(filtre->nom_champ1,"profession");
        strcpy(filtre->nom_champ2,"nom");
        break;
    case 230:
        strcpy(filtre->nom_champ1,"prenom");
        strcpy(filtre->nom_champ2,"postal");
        break;
    case 320:
        strcpy(filtre->nom_champ1,"postal");
        strcpy(filtre->nom_champ2,"prenom");
        break;

    case 240:
        strcpy(filtre->nom_champ1,"prenom");
        strcpy(filtre->nom_champ2,"ville");
        break;
    case 420:
        strcpy(filtre->nom_champ1,"ville");
        strcpy(filtre->nom_champ2,"prenom");
        break;

    case 250:
        strcpy(filtre->nom_champ1,"prenom");
        strcpy(filtre->nom_champ2,"tel");
        break;
    case 520:
        strcpy(filtre->nom_champ1,"tel");
        strcpy(filtre->nom_champ2,"prenom");
        break;

    case 260:
        strcpy(filtre->nom_champ1,"prenom");
        strcpy(filtre->nom_champ2,"mel");
        break;
    case 620:
        strcpy(filtre->nom_champ1,"prenom");
        strcpy(filtre->nom_champ2,"mel");
        break;


    case 270:
        strcpy(filtre->nom_champ1,"prenom");
        strcpy(filtre->nom_champ2,"profession");
        break;
    case 720:
        strcpy(filtre->nom_champ1,"profession");
        strcpy(filtre->nom_champ2,"prenom");
        break;


    case 340:
        strcpy(filtre->nom_champ1,"postal");
        strcpy(filtre->nom_champ2,"ville");
        break;
    case 430:
        strcpy(filtre->nom_champ1,"ville");
        strcpy(filtre->nom_champ2,"postal");
        break;
    case 350:
        strcpy(filtre->nom_champ1,"postal");
        strcpy(filtre->nom_champ2,"tel");
        break;
    case 530:
        strcpy(filtre->nom_champ1,"tel");
        strcpy(filtre->nom_champ2,"postal");
        break;

    case 360:
        strcpy(filtre->nom_champ1,"postal");
        strcpy(filtre->nom_champ2,"mel");
        break;

    case 630:
        strcpy(filtre->nom_champ1,"mel");
        strcpy(filtre->nom_champ2,"postal");
        break;
    case 370:
        strcpy(filtre->nom_champ1,"postal");
        strcpy(filtre->nom_champ2,"profession");
        break;
    case 730:
        strcpy(filtre->nom_champ1,"profession");
        strcpy(filtre->nom_champ2,"postal");
        break;
    case 450:
        strcpy(filtre->nom_champ1,"ville");
        strcpy(filtre->nom_champ2,"tel");
        break;
    case 540:
        strcpy(filtre->nom_champ1,"tel");
        strcpy(filtre->nom_champ2,"ville");
        break;
    case 460:
        strcpy(filtre->nom_champ1,"ville");
        strcpy(filtre->nom_champ2,"mel");
        break;
    case 640:
        strcpy(filtre->nom_champ1,"mel");
        strcpy(filtre->nom_champ2,"ville");
        break;
    case 470:
        strcpy(filtre->nom_champ1,"ville");
        strcpy(filtre->nom_champ2,"profession");
        break;
    case 740:
        strcpy(filtre->nom_champ1,"profession");
        strcpy(filtre->nom_champ2,"ville");
        break;
    case 560:
        strcpy(filtre->nom_champ1,"tel");
        strcpy(filtre->nom_champ2,"mel");
        break;
    case 650:
        strcpy(filtre->nom_champ1,"mel");
        strcpy(filtre->nom_champ2,"tel");
        break;
    case 570:
        strcpy(filtre->nom_champ1,"tel");
        strcpy(filtre->nom_champ2,"profession");
        break;
    case 750:
        strcpy(filtre->nom_champ1,"profession");
        strcpy(filtre->nom_champ2,"tel");
        break;
    case 670:
        strcpy(filtre->nom_champ1,"mel");
        strcpy(filtre->nom_champ2,"profession");
        break;
    case 760:
        strcpy(filtre->nom_champ1,"profession");
        strcpy(filtre->nom_champ2,"mel");
        break;
    default :
        printf("erreur de saisie !");
        exit(1);
        break;



    }
    printf("attention les points qui sont presents dans l'annuaire pour le champs telephone doivent etre pris en compte lors de la saisie !!! \n");
    fflush(stdin);
        printf("entrer valchaine1 : \n");
        fgets(filtre->val_chaine1,sizeof(filtre->val_chaine1),stdin);
        filtre->val_chaine1[strcspn(filtre->val_chaine1,"\r\n")] = '\0';
        assert(filtre->val_chaine1[0]!='\0');
fflush(stdin);
    printf("entrer valchaine2 : \n");
    fgets(filtre->val_chaine2,sizeof(filtre->val_chaine2),stdin);
    filtre->val_chaine2[strcspn(filtre->val_chaine2,"\r\n")] = '\0';
            assert(filtre->val_chaine2[0]!='\0');




}
/** \brief Cette fonction filtre les donnees du fichier annuaire donne en entree avec cette fois ci quelques ameliorations

 *
 * \param[in]
         entrees qui contient les champs suivant :
         nom_p;
         prenom_p;
         code_postal_p;
         ville_p;telephone_p;
         mel_p;
         profession_p;
         val_chaine1;
         val_chaine2;
         nom_champ1;
         nom_champ2;
         Client*filtre;
 *\brief pre-conditions : nom_annuaire est un fichier valide et **val_chaine1** et **val_chaine2** ne sont pas des chaines vides
 *\param[out] le fichier resultat_filtrer_combiner_deux_champs donne en sortie contient les nouvelles données des clients filtrer
 *
 * \return void
 *
 */
void Filtre_avancer(const char *nom_annuaire,const char*nom_champ1,const char*nom_champ2,const char*val_chaine1,const char*val_chaine2,Client*filtre)
{


    int taille = 0;
    struct Client_*p ;

    p = tabRetourner(&taille,nom_annuaire);
    int size = taille;

    printf("le nombre de ligne est %d\n",size);
    if(stricmp(nom_champ1,"nom")==0 && stricmp(nom_champ2,"prenom")==0)
    {
        printf("nom et prenom\n");
        for(int i = 0; i<size; i++)
        {
            if(Filtrer_avancer(p[i].nom_p,val_chaine1,filtre->index,0)!=1 || Filtrer_avancer(p[i].prenom_p,val_chaine2,filtre->index2,0)!=1)
            {

                for (int j = i; j < size; j++)
                {
                    //deplace l'élement a ma fin du tableau
                    p[j]=p[j+1];

                }
                size--;//decremente le compteur
                //decremente la taille du tableau

                i--;

            }


            //printf("%s,%s,%s,%s,%s,%s,%s\n",p[i].nom_p,p[i].prenom_p,p[i].code_postal_p,p[i].ville_p,p[i].telephone_p,p[i].mel_p,p[i].profession_p);
        }
        for(int i = 0; i<size; i++)
        {
            printf("%s,%s,%s,%s,%s,%s,%s\n",p[i].nom_p,p[i].prenom_p,p[i].code_postal_p,p[i].ville_p,p[i].telephone_p,p[i].mel_p,p[i].profession_p);
        }
        sauvegarde_annuaire("resultat_filtrer_combiner_deux_champs.txt",p,size);

    }
    if(stricmp(nom_champ1,"prenom")==0 && stricmp(nom_champ2,"nom")==0)
    {
        printf("prenom et nom\n");
        for(int i = 0; i<size; i++)
        {
            if(Filtrer_avancer(p[i].prenom_p,val_chaine1,filtre->index,size)!=1 || Filtrer_avancer(p[i].nom_p,val_chaine2,filtre->index2,size)!=1)
            {

                for (int j = i; j < size; j++)
                {
                    //deplace l'élement a ma fin du tableau
                    p[j]=p[j+1];

                }
                size--;//decremente le compteur
                //decremente la taille du tableau

                i--;

            }


            //printf("%s,%s,%s,%s,%s,%s,%s\n",p[i].nom_p,p[i].prenom_p,p[i].code_postal_p,p[i].ville_p,p[i].telephone_p,p[i].mel_p,p[i].profession_p);
        }
        for(int i = 0; i<size; i++)
        {
            printf("%s,%s,%s,%s,%s,%s,%s\n",p[i].nom_p,p[i].prenom_p,p[i].code_postal_p,p[i].ville_p,p[i].telephone_p,p[i].mel_p,p[i].profession_p);
        }
        sauvegarde_annuaire("resultat_filtrer_combiner_deux_champs.txt",p,size);

    }
    if(stricmp(nom_champ1,"nom")==0 && stricmp(nom_champ2,"postal")==0)
    {
        printf("nom et code postal\n");
        for(int i = 0; i<size; i++)
        {
            if(Filtrer_avancer(p[i].nom_p,val_chaine1,filtre->index,size)!=1 || Filtrer_avancer(p[i].code_postal_p,val_chaine2,filtre->index2,size)!=1)
            {

                for (int j = i; j < size; j++)
                {
                    //deplace l'élement a ma fin du tableau
                    p[j]=p[j+1];

                }
                size--;//decremente le compteur
                //decremente la taille du tableau

                i--;

            }


            //printf("%s,%s,%s,%s,%s,%s,%s\n",p[i].nom_p,p[i].prenom_p,p[i].code_postal_p,p[i].ville_p,p[i].telephone_p,p[i].mel_p,p[i].profession_p);
        }
        for(int i = 0; i<size; i++)
        {
            printf("%s,%s,%s,%s,%s,%s,%s\n",p[i].nom_p,p[i].prenom_p,p[i].code_postal_p,p[i].ville_p,p[i].telephone_p,p[i].mel_p,p[i].profession_p);
        }
        sauvegarde_annuaire("resultat_filtrer_combiner_deux_champs.txt",p,size);

    }
    if(stricmp(nom_champ1,"postal")==0 && stricmp(nom_champ2,"nom")==0)
    {
        printf(" code postal et nom\n");
        for(int i = 0; i<size; i++)
        {
            if(Filtrer_avancer(p[i].code_postal_p,val_chaine1,filtre->index,size)!=1 || Filtrer_avancer(p[i].nom_p,val_chaine2,filtre->index2,size)!=1)
            {

                for (int j = i; j < size; j++)
                {
                    //deplace l'élement a ma fin du tableau
                    p[j]=p[j+1];

                }
                size--;//decremente le compteur
                //decremente la taille du tableau

                i--;

            }


            //printf("%s,%s,%s,%s,%s,%s,%s\n",p[i].nom_p,p[i].prenom_p,p[i].code_postal_p,p[i].ville_p,p[i].telephone_p,p[i].mel_p,p[i].profession_p);
        }
        for(int i = 0; i<size; i++)
        {
            printf("%s,%s,%s,%s,%s,%s,%s\n",p[i].nom_p,p[i].prenom_p,p[i].code_postal_p,p[i].ville_p,p[i].telephone_p,p[i].mel_p,p[i].profession_p);
        }
        sauvegarde_annuaire("resultat_filtrer_combiner_deux_champs.txt",p,size);

    }
    if(stricmp(nom_champ1,"ville")==0 && stricmp(nom_champ2,"nom")==0)
    {
        printf(" ville et nom\n");
        for(int i = 0; i<size; i++)
        {
            if(Filtrer_avancer(p[i].ville_p,val_chaine1,filtre->index,size)!=1 || Filtrer_avancer(p[i].nom_p,val_chaine2,filtre->index2,size)!=1)
            {

                for (int j = i; j < size; j++)
                {
                    //deplace l'élement a ma fin du tableau
                    p[j]=p[j+1];

                }
                size--;//decremente le compteur
                //decremente la taille du tableau

                i--;

            }


            //printf("%s,%s,%s,%s,%s,%s,%s\n",p[i].nom_p,p[i].prenom_p,p[i].code_postal_p,p[i].ville_p,p[i].telephone_p,p[i].mel_p,p[i].profession_p);
        }
        for(int i = 0; i<size; i++)
        {
            printf("%s,%s,%s,%s,%s,%s,%s\n",p[i].nom_p,p[i].prenom_p,p[i].code_postal_p,p[i].ville_p,p[i].telephone_p,p[i].mel_p,p[i].profession_p);
        }
        sauvegarde_annuaire("resultat_filtrer_combiner_deux_champs.txt",p,size);

    }
    if(stricmp(nom_champ1,"tel")==0 && stricmp(nom_champ2,"nom")==0)
    {
        printf("telephone et nom\n");
        for(int i = 0; i<size; i++)
        {
            if(Filtrer_avancer(p[i].telephone_p,val_chaine1,filtre->index,size)!=1 || Filtrer_avancer(p[i].nom_p,val_chaine2,filtre->index2,size)!=1)
            {

                for (int j = i; j < size; j++)
                {
                    //deplace l'élement a ma fin du tableau
                    p[j]=p[j+1];

                }
                size--;//decremente le compteur
                //decremente la taille du tableau

                i--;

            }


            //printf("%s,%s,%s,%s,%s,%s,%s\n",p[i].nom_p,p[i].prenom_p,p[i].code_postal_p,p[i].ville_p,p[i].telephone_p,p[i].mel_p,p[i].profession_p);
        }
        for(int i = 0; i<size; i++)
        {
            printf("%s,%s,%s,%s,%s,%s,%s\n",p[i].nom_p,p[i].prenom_p,p[i].code_postal_p,p[i].ville_p,p[i].telephone_p,p[i].mel_p,p[i].profession_p);
        }
        sauvegarde_annuaire("resultat_filtrer_combiner_deux_champs.txt",p,size);

    }
    if(stricmp(nom_champ1,"mel")==0 && stricmp(nom_champ2,"nom")==0)
    {
        printf("mail et nom\n");
        for(int i = 0; i<size; i++)
        {
            if(Filtrer_avancer(p[i].mel_p,val_chaine1,filtre->index,size)!=1 || Filtrer_avancer(p[i].nom_p,val_chaine2,filtre->index2,size)!=1)
            {

                for (int j = i; j < size; j++)
                {
                    //deplace l'élement a ma fin du tableau
                    p[j]=p[j+1];

                }
                size--;//decremente le compteur
                //decremente la taille du tableau

                i--;

            }


            //printf("%s,%s,%s,%s,%s,%s,%s\n",p[i].nom_p,p[i].prenom_p,p[i].code_postal_p,p[i].ville_p,p[i].telephone_p,p[i].mel_p,p[i].profession_p);
        }
        for(int i = 0; i<size; i++)
        {
            printf("%s,%s,%s,%s,%s,%s,%s\n",p[i].nom_p,p[i].prenom_p,p[i].code_postal_p,p[i].ville_p,p[i].telephone_p,p[i].mel_p,p[i].profession_p);
        }
        sauvegarde_annuaire("resultat_filtrer_combiner_deux_champs.txt",p,size);

    }
    if(stricmp(nom_champ1,"profession")==0 && stricmp(nom_champ2,"nom")==0)
    {
        printf("profession et nom\n");
        for(int i = 0; i<size; i++)
        {
            if(Filtrer_avancer(p[i].profession_p,val_chaine1,filtre->index,size)!=1 || Filtrer_avancer(p[i].nom_p,val_chaine2,filtre->index2,size)!=1)
            {

                for (int j = i; j < size; j++)
                {
                    //deplace l'élement a ma fin du tableau
                    p[j]=p[j+1];

                }
                size--;//decremente le compteur
                //decremente la taille du tableau

                i--;

            }


            //printf("%s,%s,%s,%s,%s,%s,%s\n",p[i].nom_p,p[i].prenom_p,p[i].code_postal_p,p[i].ville_p,p[i].telephone_p,p[i].mel_p,p[i].profession_p);
        }
        for(int i = 0; i<size; i++)
        {
            printf("%s,%s,%s,%s,%s,%s,%s\n",p[i].nom_p,p[i].prenom_p,p[i].code_postal_p,p[i].ville_p,p[i].telephone_p,p[i].mel_p,p[i].profession_p);
        }
        sauvegarde_annuaire("resultat_filtrer_combiner_deux_champs.txt",p,size);

    }
    if(stricmp(nom_champ1,"postal")==0 && stricmp(nom_champ2,"prenom")==0)
    {
        printf("code postal et prenom\n");
        for(int i = 0; i<size; i++)
        {
            if(Filtrer_avancer(p[i].code_postal_p,val_chaine1,filtre->index,size)!=1 || Filtrer_avancer(p[i].prenom_p,val_chaine2,filtre->index2,size)!=1)
            {

                for (int j = i; j < size; j++)
                {
                    //deplace l'élement a ma fin du tableau
                    p[j]=p[j+1];

                }
                size--;//decremente le compteur
                //decremente la taille du tableau

                i--;

            }


            //printf("%s,%s,%s,%s,%s,%s,%s\n",p[i].nom_p,p[i].prenom_p,p[i].code_postal_p,p[i].ville_p,p[i].telephone_p,p[i].mel_p,p[i].profession_p);
        }
        for(int i = 0; i<size; i++)
        {
            printf("%s,%s,%s,%s,%s,%s,%s\n",p[i].nom_p,p[i].prenom_p,p[i].code_postal_p,p[i].ville_p,p[i].telephone_p,p[i].mel_p,p[i].profession_p);
        }
        sauvegarde_annuaire("resultat_filtrer_combiner_deux_champs.txt",p,size);

    }
    if(stricmp(nom_champ1,"ville")==0 && stricmp(nom_champ2,"prenom")==0)
    {
        printf("ville et prenom\n");
        for(int i = 0; i<size; i++)
        {
            if(Filtrer_avancer(p[i].ville_p,val_chaine1,filtre->index,size)!=1 || Filtrer_avancer(p[i].prenom_p,val_chaine2,filtre->index2,size)!=1)
            {

                for (int j = i; j < size; j++)
                {
                    //deplace l'élement a ma fin du tableau
                    p[j]=p[j+1];

                }
                size--;//decremente le compteur
                //decremente la taille du tableau

                i--;

            }


            //printf("%s,%s,%s,%s,%s,%s,%s\n",p[i].nom_p,p[i].prenom_p,p[i].code_postal_p,p[i].ville_p,p[i].telephone_p,p[i].mel_p,p[i].profession_p);
        }
        for(int i = 0; i<size; i++)
        {
            printf("%s,%s,%s,%s,%s,%s,%s\n",p[i].nom_p,p[i].prenom_p,p[i].code_postal_p,p[i].ville_p,p[i].telephone_p,p[i].mel_p,p[i].profession_p);
        }
        sauvegarde_annuaire("resultat_filtrer_combiner_deux_champs.txt",p,size);

    }
    if(stricmp(nom_champ1,"tel")==0 && stricmp(nom_champ2,"prenom")==0)
    {
        printf("telephone et prenom\n");
        for(int i = 0; i<size; i++)
        {
            if(Filtrer_avancer(p[i].telephone_p,val_chaine1,filtre->index,size)!=1 || Filtrer_avancer(p[i].prenom_p,val_chaine2,filtre->index2,size)!=1)
            {

                for (int j = i; j < size; j++)
                {
                    //deplace l'élement a ma fin du tableau
                    p[j]=p[j+1];

                }
                size--;//decremente le compteur
                //decremente la taille du tableau

                i--;

            }


            //printf("%s,%s,%s,%s,%s,%s,%s\n",p[i].nom_p,p[i].prenom_p,p[i].code_postal_p,p[i].ville_p,p[i].telephone_p,p[i].mel_p,p[i].profession_p);
        }
        for(int i = 0; i<size; i++)
        {
            printf("%s,%s,%s,%s,%s,%s,%s\n",p[i].nom_p,p[i].prenom_p,p[i].code_postal_p,p[i].ville_p,p[i].telephone_p,p[i].mel_p,p[i].profession_p);
        }
        sauvegarde_annuaire("resultat_filtrer_combiner_deux_champs.txt",p,size);

    }
    if(stricmp(nom_champ1,"mel")==0 && stricmp(nom_champ2,"prenom")==0)
    {
        printf("mail et prenom\n");
        for(int i = 0; i<size; i++)
        {
            if(Filtrer_avancer(p[i].mel_p,val_chaine1,filtre->index,size)!=1 || Filtrer_avancer(p[i].prenom_p,val_chaine2,filtre->index2,size)!=1)
            {

                for (int j = i; j < size; j++)
                {
                    //deplace l'élement a ma fin du tableau
                    p[j]=p[j+1];

                }
                size--;//decremente le compteur
                //decremente la taille du tableau

                i--;

            }


            //printf("%s,%s,%s,%s,%s,%s,%s\n",p[i].nom_p,p[i].prenom_p,p[i].code_postal_p,p[i].ville_p,p[i].telephone_p,p[i].mel_p,p[i].profession_p);
        }
        for(int i = 0; i<size; i++)
        {
            printf("%s,%s,%s,%s,%s,%s,%s\n",p[i].nom_p,p[i].prenom_p,p[i].code_postal_p,p[i].ville_p,p[i].telephone_p,p[i].mel_p,p[i].profession_p);
        }
        sauvegarde_annuaire("resultat_filtrer_combiner_deux_champs.txt",p,size);

    }
    if(stricmp(nom_champ1,"profession")==0 && stricmp(nom_champ2,"prenom")==0)
    {
        printf("profession et prenom\n");
        for(int i = 0; i<size; i++)
        {
            if(Filtrer_avancer(p[i].profession_p,val_chaine1,filtre->index,size)!=1 || Filtrer_avancer(p[i].prenom_p,val_chaine2,filtre->index2,size)!=1)
            {

                for (int j = i; j < size; j++)
                {
                    //deplace l'élement a ma fin du tableau
                    p[j]=p[j+1];

                }
                size--;//decremente le compteur
                //decremente la taille du tableau

                i--;

            }


            //printf("%s,%s,%s,%s,%s,%s,%s\n",p[i].nom_p,p[i].prenom_p,p[i].code_postal_p,p[i].ville_p,p[i].telephone_p,p[i].mel_p,p[i].profession_p);
        }
        for(int i = 0; i<size; i++)
        {
            printf("%s,%s,%s,%s,%s,%s,%s\n",p[i].nom_p,p[i].prenom_p,p[i].code_postal_p,p[i].ville_p,p[i].telephone_p,p[i].mel_p,p[i].profession_p);
        }
        sauvegarde_annuaire("resultat_filtrer_combiner_deux_champs.txt",p,size);

    }
    if(stricmp(nom_champ1,"ville")==0 && stricmp(nom_champ2,"postal")==0)
    {
        printf(" ville et code postal\n");
        for(int i = 0; i<size; i++)
        {
            if(Filtrer_avancer(p[i].ville_p,val_chaine1,filtre->index,size)!=1 || Filtrer_avancer(p[i].code_postal_p,val_chaine2,filtre->index2,size)!=1)
            {

                for (int j = i; j < size; j++)
                {
                    //deplace l'élement a ma fin du tableau
                    p[j]=p[j+1];

                }
                size--;//decremente le compteur
                //decremente la taille du tableau

                i--;

            }


            //printf("%s,%s,%s,%s,%s,%s,%s\n",p[i].nom_p,p[i].prenom_p,p[i].code_postal_p,p[i].ville_p,p[i].telephone_p,p[i].mel_p,p[i].profession_p);
        }
        for(int i = 0; i<size; i++)
        {
            printf("%s,%s,%s,%s,%s,%s,%s\n",p[i].nom_p,p[i].prenom_p,p[i].code_postal_p,p[i].ville_p,p[i].telephone_p,p[i].mel_p,p[i].profession_p);
        }
        sauvegarde_annuaire("resultat_filtrer_combiner_deux_champs.txt",p,size);

    }
    if(stricmp(nom_champ1,"tel")==0 && stricmp(nom_champ2,"postal")==0)
    {
        printf("telephone et code postal\n");
        for(int i = 0; i<size; i++)
        {
            if(Filtrer_avancer(p[i].telephone_p,val_chaine1,filtre->index,size)!=1 || Filtrer_avancer(p[i].code_postal_p,val_chaine2,filtre->index2,size)!=1)
            {

                for (int j = i; j < size; j++)
                {
                    //deplace l'élement a ma fin du tableau
                    p[j]=p[j+1];

                }
                size--;//decremente le compteur
                //decremente la taille du tableau

                i--;

            }


            //printf("%s,%s,%s,%s,%s,%s,%s\n",p[i].nom_p,p[i].prenom_p,p[i].code_postal_p,p[i].ville_p,p[i].telephone_p,p[i].mel_p,p[i].profession_p);
        }
        for(int i = 0; i<size; i++)
        {
            printf("%s,%s,%s,%s,%s,%s,%s\n",p[i].nom_p,p[i].prenom_p,p[i].code_postal_p,p[i].ville_p,p[i].telephone_p,p[i].mel_p,p[i].profession_p);
        }
        sauvegarde_annuaire("resultat_filtrer_combiner_deux_champs.txt",p,size);

    }
    if(stricmp(nom_champ1,"mel")==0 && stricmp(nom_champ2,"postal")==0)
    {
        printf("mail et code postal\n");
        for(int i = 0; i<size; i++)
        {
            if(Filtrer_avancer(p[i].mel_p,val_chaine1,filtre->index,size)!=1 || Filtrer_avancer(p[i].code_postal_p,val_chaine2,filtre->index2,size)!=1)
            {

                for (int j = i; j < size; j++)
                {
                    //deplace l'élement a ma fin du tableau
                    p[j]=p[j+1];

                }
                size--;//decremente le compteur
                //decremente la taille du tableau

                i--;

            }


            //printf("%s,%s,%s,%s,%s,%s,%s\n",p[i].nom_p,p[i].prenom_p,p[i].code_postal_p,p[i].ville_p,p[i].telephone_p,p[i].mel_p,p[i].profession_p);
        }
        for(int i = 0; i<size; i++)
        {
            printf("%s,%s,%s,%s,%s,%s,%s\n",p[i].nom_p,p[i].prenom_p,p[i].code_postal_p,p[i].ville_p,p[i].telephone_p,p[i].mel_p,p[i].profession_p);
        }
        sauvegarde_annuaire("resultat_filtrer_combiner_deux_champs.txt",p,size);

    }
    if(stricmp(nom_champ1,"profession")==0 && stricmp(nom_champ2,"postal")==0)
    {
        printf(" profession et code postal\n");
        for(int i = 0; i<size; i++)
        {
            if(Filtrer_avancer(p[i].profession_p,val_chaine1,filtre->index,size)!=1 || Filtrer_avancer(p[i].code_postal_p,val_chaine2,filtre->index2,size)!=1)
            {

                for (int j = i; j < size; j++)
                {
                    //deplace l'élement a ma fin du tableau
                    p[j]=p[j+1];

                }
                size--;//decremente le compteur
                //decremente la taille du tableau

                i--;

            }


            //printf("%s,%s,%s,%s,%s,%s,%s\n",p[i].nom_p,p[i].prenom_p,p[i].code_postal_p,p[i].ville_p,p[i].telephone_p,p[i].mel_p,p[i].profession_p);
        }
        for(int i = 0; i<size; i++)
        {
            printf("%s,%s,%s,%s,%s,%s,%s\n",p[i].nom_p,p[i].prenom_p,p[i].code_postal_p,p[i].ville_p,p[i].telephone_p,p[i].mel_p,p[i].profession_p);
        }
        sauvegarde_annuaire("resultat_filtrer_combiner_deux_champs.txt",p,size);

    }
    if(stricmp(nom_champ1,"tel")==0 && stricmp(nom_champ2,"ville")==0)
    {
        printf("telephone et ville\n");
        for(int i = 0; i<size; i++)
        {
            if(Filtrer_avancer(p[i].telephone_p,val_chaine1,filtre->index,size)!=1 || Filtrer_avancer(p[i].ville_p,val_chaine2,filtre->index2,size)!=1)
            {

                for (int j = i; j < size; j++)
                {
                    //deplace l'élement a ma fin du tableau
                    p[j]=p[j+1];

                }
                size--;//decremente le compteur
                //decremente la taille du tableau

                i--;

            }


            //printf("%s,%s,%s,%s,%s,%s,%s\n",p[i].nom_p,p[i].prenom_p,p[i].code_postal_p,p[i].ville_p,p[i].telephone_p,p[i].mel_p,p[i].profession_p);
        }
        for(int i = 0; i<size; i++)
        {
            printf("%s,%s,%s,%s,%s,%s,%s\n",p[i].nom_p,p[i].prenom_p,p[i].code_postal_p,p[i].ville_p,p[i].telephone_p,p[i].mel_p,p[i].profession_p);
        }
        sauvegarde_annuaire("resultat_filtrer_combiner_deux_champs.txt",p,size);

    }
    if(stricmp(nom_champ1,"mel")==0 && stricmp(nom_champ2,"ville")==0)
    {
        printf("mail et ville\n");
        for(int i = 0; i<size; i++)
        {
            if(Filtrer_avancer(p[i].mel_p,val_chaine1,filtre->index,size)!=1 || Filtrer_avancer(p[i].ville_p,val_chaine2,filtre->index2,size)!=1)
            {

                for (int j = i; j < size; j++)
                {
                    //deplace l'élement a ma fin du tableau
                    p[j]=p[j+1];

                }
                size--;//decremente le compteur
                //decremente la taille du tableau

                i--;

            }


            //printf("%s,%s,%s,%s,%s,%s,%s\n",p[i].nom_p,p[i].prenom_p,p[i].code_postal_p,p[i].ville_p,p[i].telephone_p,p[i].mel_p,p[i].profession_p);
        }
        for(int i = 0; i<size; i++)
        {
            printf("%s,%s,%s,%s,%s,%s,%s\n",p[i].nom_p,p[i].prenom_p,p[i].code_postal_p,p[i].ville_p,p[i].telephone_p,p[i].mel_p,p[i].profession_p);
        }
        sauvegarde_annuaire("resultat_filtrer_combiner_deux_champs.txt",p,size);

    }
    if(stricmp(nom_champ1,"profession")==0 && stricmp(nom_champ2,"ville")==0)
    {
        printf("profession et ville\n");
        for(int i = 0; i<size; i++)
        {
            if(Filtrer_avancer(p[i].profession_p,val_chaine1,filtre->index,size)!=1 || Filtrer_avancer(p[i].ville_p,val_chaine2,filtre->index2,size)!=1)
            {

                for (int j = i; j < size; j++)
                {
                    //deplace l'élement a ma fin du tableau
                    p[j]=p[j+1];

                }
                size--;//decremente le compteur
                //decremente la taille du tableau

                i--;

            }


            //printf("%s,%s,%s,%s,%s,%s,%s\n",p[i].nom_p,p[i].prenom_p,p[i].code_postal_p,p[i].ville_p,p[i].telephone_p,p[i].mel_p,p[i].profession_p);
        }
        for(int i = 0; i<size; i++)
        {
            printf("%s,%s,%s,%s,%s,%s,%s\n",p[i].nom_p,p[i].prenom_p,p[i].code_postal_p,p[i].ville_p,p[i].telephone_p,p[i].mel_p,p[i].profession_p);
        }
        sauvegarde_annuaire("resultat_filtrer_combiner_deux_champs.txt",p,size);

    }
    if(stricmp(nom_champ1,"mel")==0 && stricmp(nom_champ2,"tel")==0)
    {
        printf(" mail et telephone\n");
        for(int i = 0; i<size; i++)
        {
            if(Filtrer_avancer(p[i].mel_p,val_chaine1,filtre->index,size)!=1 || Filtrer_avancer(p[i].telephone_p,val_chaine2,filtre->index2,size)!=1)
            {

                for (int j = i; j < size; j++)
                {
                    //deplace l'élement a ma fin du tableau
                    p[j]=p[j+1];

                }
                size--;//decremente le compteur
                //decremente la taille du tableau

                i--;

            }


            //printf("%s,%s,%s,%s,%s,%s,%s\n",p[i].nom_p,p[i].prenom_p,p[i].code_postal_p,p[i].ville_p,p[i].telephone_p,p[i].mel_p,p[i].profession_p);
        }
        for(int i = 0; i<size; i++)
        {
            printf("%s,%s,%s,%s,%s,%s,%s\n",p[i].nom_p,p[i].prenom_p,p[i].code_postal_p,p[i].ville_p,p[i].telephone_p,p[i].mel_p,p[i].profession_p);
        }
        sauvegarde_annuaire("resultat_filtrer_combiner_deux_champs.txt",p,size);

    }
    if(stricmp(nom_champ1,"profession")==0 && stricmp(nom_champ2,"tel")==0)
    {
        printf("profession et telephone\n");
        for(int i = 0; i<size; i++)
        {
            if(Filtrer_avancer(p[i].profession_p,val_chaine1,filtre->index,size)!=1 || Filtrer_avancer(p[i].telephone_p,val_chaine2,filtre->index2,size)!=1)
            {

                for (int j = i; j < size; j++)
                {
                    //deplace l'élement a ma fin du tableau
                    p[j]=p[j+1];

                }
                size--;//decremente le compteur
                //decremente la taille du tableau

                i--;

            }


            //printf("%s,%s,%s,%s,%s,%s,%s\n",p[i].nom_p,p[i].prenom_p,p[i].code_postal_p,p[i].ville_p,p[i].telephone_p,p[i].mel_p,p[i].profession_p);
        }
        for(int i = 0; i<size; i++)
        {
            printf("%s,%s,%s,%s,%s,%s,%s\n",p[i].nom_p,p[i].prenom_p,p[i].code_postal_p,p[i].ville_p,p[i].telephone_p,p[i].mel_p,p[i].profession_p);
        }
        sauvegarde_annuaire("resultat_filtrer_combiner_deux_champs.txt",p,size);

    }
    if(stricmp(nom_champ1,"profession")==0 && stricmp(nom_champ2,"mel")==0)
    {
        printf("profession mail\n");
        for(int i = 0; i<size; i++)
        {
            if(Filtrer_avancer(p[i].profession_p,val_chaine1,filtre->index,size)!=1 || Filtrer_avancer(p[i].mel_p,val_chaine2,filtre->index2,size)!=1)
            {

                for (int j = i; j < size; j++)
                {
                    //deplace l'élement a ma fin du tableau
                    p[j]=p[j+1];

                }
                size--;//decremente le compteur
                //decremente la taille du tableau

                i--;

            }


            //printf("%s,%s,%s,%s,%s,%s,%s\n",p[i].nom_p,p[i].prenom_p,p[i].code_postal_p,p[i].ville_p,p[i].telephone_p,p[i].mel_p,p[i].profession_p);
        }
        for(int i = 0; i<size; i++)
        {
            printf("%s,%s,%s,%s,%s,%s,%s\n",p[i].nom_p,p[i].prenom_p,p[i].code_postal_p,p[i].ville_p,p[i].telephone_p,p[i].mel_p,p[i].profession_p);
        }
        sauvegarde_annuaire("resultat_filtrer_combiner_deux_champs.txt",p,size);

    }


    if(stricmp(nom_champ1,"nom")==0 && stricmp(nom_champ2,"ville")==0)
    {
        printf("nom et ville\n");
        for(int i = 0; i<size; i++)
        {
            if(Filtrer_avancer(p[i].nom_p,val_chaine1,filtre->index,size)!=1 || Filtrer_avancer(p[i].ville_p,val_chaine2,filtre->index2,size)!=1)
            {

                for (int j = i; j < size; j++)
                {
                    //deplace l'élement a ma fin du tableau
                    p[j]=p[j+1];

                }
                size--;//decremente le compteur
                //decremente la taille du tableau

                i--;

            }


            //printf("%s,%s,%s,%s,%s,%s,%s\n",p[i].nom_p,p[i].prenom_p,p[i].code_postal_p,p[i].ville_p,p[i].telephone_p,p[i].mel_p,p[i].profession_p);
        }
        for(int i = 0; i<size; i++)
        {
            printf("%s,%s,%s,%s,%s,%s,%s\n",p[i].nom_p,p[i].prenom_p,p[i].code_postal_p,p[i].ville_p,p[i].telephone_p,p[i].mel_p,p[i].profession_p);
        }
        sauvegarde_annuaire("resultat_filtrer_combiner_deux_champs.txt",p,size);

    }
    if(stricmp(nom_champ1,"nom")==0 && stricmp(nom_champ2,"tel")==0)
    {
        printf("nom et telephone\n");
        for(int i = 0; i<size; i++)
        {
            if(Filtrer_avancer(p[i].nom_p,val_chaine1,filtre->index,size)!=1 || Filtrer_avancer(p[i].telephone_p,val_chaine2,filtre->index2,size)!=1)
            {

                for (int j = i; j < size; j++)
                {
                    //deplace l'élement a ma fin du tableau
                    p[j]=p[j+1];

                }
                size--;//decremente le compteur
                //decremente la taille du tableau

                i--;

            }


            //printf("%s,%s,%s,%s,%s,%s,%s\n",p[i].nom_p,p[i].prenom_p,p[i].code_postal_p,p[i].ville_p,p[i].telephone_p,p[i].mel_p,p[i].profession_p);
        }
        for(int i = 0; i<size; i++)
        {
            printf("%s,%s,%s,%s,%s,%s,%s\n",p[i].nom_p,p[i].prenom_p,p[i].code_postal_p,p[i].ville_p,p[i].telephone_p,p[i].mel_p,p[i].profession_p);
        }
        sauvegarde_annuaire("resultat_filtrer_combiner_deux_champs.txt",p,size);

    }
    if(stricmp(nom_champ1,"nom")==0 && stricmp(nom_champ2,"mel")==0)
    {
        printf("nom et mail\n");
        for(int i = 0; i<size; i++)
        {
            if(Filtrer_avancer(p[i].nom_p,val_chaine1,filtre->index,size)!=1 || Filtrer_avancer(p[i].mel_p,val_chaine2,filtre->index2,size)!=1)
            {

                for (int j = i; j < size; j++)
                {
                    //deplace l'élement a ma fin du tableau
                    p[j]=p[j+1];

                }
                size--;//decremente le compteur
                //decremente la taille du tableau

                i--;

            }


            //printf("%s,%s,%s,%s,%s,%s,%s\n",p[i].nom_p,p[i].prenom_p,p[i].code_postal_p,p[i].ville_p,p[i].telephone_p,p[i].mel_p,p[i].profession_p);
        }
        for(int i = 0; i<size; i++)
        {
            printf("%s,%s,%s,%s,%s,%s,%s\n",p[i].nom_p,p[i].prenom_p,p[i].code_postal_p,p[i].ville_p,p[i].telephone_p,p[i].mel_p,p[i].profession_p);
        }
        sauvegarde_annuaire("resultat_filtrer_combiner_deux_champs.txt",p,size);

    }
    if(stricmp(nom_champ1,"nom")==0 && stricmp(nom_champ2,"profession")==0)
    {
        printf("nom et profession\n");
        for(int i = 0; i<size; i++)
        {
            if(Filtrer_avancer(p[i].nom_p,val_chaine1,filtre->index,size)!=1 || Filtrer_avancer(p[i].profession_p,val_chaine2,filtre->index2,size)!=1)
            {

                for (int j = i; j < size; j++)
                {
                    //deplace l'élement a ma fin du tableau
                    p[j]=p[j+1];

                }
                size--;//decremente le compteur
                //decremente la taille du tableau

                i--;

            }


            //printf("%s,%s,%s,%s,%s,%s,%s\n",p[i].nom_p,p[i].prenom_p,p[i].code_postal_p,p[i].ville_p,p[i].telephone_p,p[i].mel_p,p[i].profession_p);
        }
        for(int i = 0; i<size; i++)
        {
            printf("%s,%s,%s,%s,%s,%s,%s\n",p[i].nom_p,p[i].prenom_p,p[i].code_postal_p,p[i].ville_p,p[i].telephone_p,p[i].mel_p,p[i].profession_p);
        }
        sauvegarde_annuaire("resultat_filtrer_combiner_deux_champs.txt",p,size);

    }
    if(stricmp(nom_champ1,"prenom")==0 && stricmp(nom_champ2,"postal")==0)
    {
        printf("prenom et code postal\n");
        for(int i = 0; i<size; i++)
        {
            if(Filtrer_avancer(p[i].prenom_p,val_chaine1,filtre->index,size)!=1 || Filtrer_avancer(p[i].code_postal_p,val_chaine2,filtre->index2,size)!=1)
            {

                for (int j = i; j < size; j++)
                {
                    //deplace l'élement a ma fin du tableau
                    p[j]=p[j+1];

                }
                size--;//decremente le compteur
                //decremente la taille du tableau

                i--;

            }


            //printf("%s,%s,%s,%s,%s,%s,%s\n",p[i].nom_p,p[i].prenom_p,p[i].code_postal_p,p[i].ville_p,p[i].telephone_p,p[i].mel_p,p[i].profession_p);
        }
        for(int i = 0; i<size; i++)
        {
            printf("%s,%s,%s,%s,%s,%s,%s\n",p[i].nom_p,p[i].prenom_p,p[i].code_postal_p,p[i].ville_p,p[i].telephone_p,p[i].mel_p,p[i].profession_p);
        }
        sauvegarde_annuaire("resultat_filtrer_combiner_deux_champs.txt",p,size);

    }
    if(stricmp(nom_champ1,"prenom")==0 && stricmp(nom_champ2,"ville")==0)
    {
        printf("prenom et ville\n");
        for(int i = 0; i<size; i++)
        {
            if(Filtrer_avancer(p[i].prenom_p,val_chaine1,filtre->index,size)!=1 || Filtrer_avancer(p[i].ville_p,val_chaine2,filtre->index2,size)!=1)
            {

                for (int j = i; j < size; j++)
                {
                    //deplace l'élement a ma fin du tableau
                    p[j]=p[j+1];

                }
                size--;//decremente le compteur
                //decremente la taille du tableau

                i--;

            }


            //printf("%s,%s,%s,%s,%s,%s,%s\n",p[i].nom_p,p[i].prenom_p,p[i].code_postal_p,p[i].ville_p,p[i].telephone_p,p[i].mel_p,p[i].profession_p);
        }
        for(int i = 0; i<size; i++)
        {
            printf("%s,%s,%s,%s,%s,%s,%s\n",p[i].nom_p,p[i].prenom_p,p[i].code_postal_p,p[i].ville_p,p[i].telephone_p,p[i].mel_p,p[i].profession_p);
        }
        sauvegarde_annuaire("resultat_filtrer_combiner_deux_champs.txt",p,size);

    }
    if(stricmp(nom_champ1,"prenom")==0 && stricmp(nom_champ2,"tel")==0)
    {
        printf("prenom et telephone\n");
        for(int i = 0; i<size; i++)
        {
            if(Filtrer_avancer(p[i].prenom_p,val_chaine1,filtre->index,size)!=1 || Filtrer_avancer(p[i].telephone_p,val_chaine2,filtre->index2,size)!=1)
            {

                for (int j = i; j < size; j++)
                {
                    //deplace l'élement a ma fin du tableau
                    p[j]=p[j+1];

                }
                size--;//decremente le compteur
                //decremente la taille du tableau

                i--;

            }


            //printf("%s,%s,%s,%s,%s,%s,%s\n",p[i].nom_p,p[i].prenom_p,p[i].code_postal_p,p[i].ville_p,p[i].telephone_p,p[i].mel_p,p[i].profession_p);
        }
        for(int i = 0; i<size; i++)
        {
            printf("%s,%s,%s,%s,%s,%s,%s\n",p[i].nom_p,p[i].prenom_p,p[i].code_postal_p,p[i].ville_p,p[i].telephone_p,p[i].mel_p,p[i].profession_p);
        }
        sauvegarde_annuaire("resultat_filtrer_combiner_deux_champs.txt",p,size);

    }
    if(stricmp(nom_champ1,"prenom")==0 && stricmp(nom_champ2,"mel")==0)
    {
        printf("prenom et mail\n");
        for(int i = 0; i<size; i++)
        {
            if(Filtrer_avancer(p[i].prenom_p,val_chaine1,filtre->index,size)!=1 || Filtrer_avancer(p[i].mel_p,val_chaine2,filtre->index2,size)!=1)
            {

                for (int j = i; j < size; j++)
                {
                    //deplace l'élement a ma fin du tableau
                    p[j]=p[j+1];

                }
                size--;//decremente le compteur
                //decremente la taille du tableau

                i--;

            }


            //printf("%s,%s,%s,%s,%s,%s,%s\n",p[i].nom_p,p[i].prenom_p,p[i].code_postal_p,p[i].ville_p,p[i].telephone_p,p[i].mel_p,p[i].profession_p);
        }
        for(int i = 0; i<size; i++)
        {
            printf("%s,%s,%s,%s,%s,%s,%s\n",p[i].nom_p,p[i].prenom_p,p[i].code_postal_p,p[i].ville_p,p[i].telephone_p,p[i].mel_p,p[i].profession_p);
        }
        sauvegarde_annuaire("resultat_filtrer_combiner_deux_champs.txt",p,size);

    }
    if(stricmp(nom_champ1,"prenom")==0 && stricmp(nom_champ2,"profession")==0)
    {
        printf("prenom et profession\n");
        for(int i = 0; i<size; i++)
        {
            if(Filtrer_avancer(p[i].prenom_p,val_chaine1,filtre->index,size)!=1 || Filtrer_avancer(p[i].profession_p,val_chaine2,filtre->index2,size)!=1)
            {

                for (int j = i; j < size; j++)
                {
                    //deplace l'élement a ma fin du tableau
                    p[j]=p[j+1];

                }
                size--;//decremente le compteur
                //decremente la taille du tableau

                i--;

            }


            //printf("%s,%s,%s,%s,%s,%s,%s\n",p[i].nom_p,p[i].prenom_p,p[i].code_postal_p,p[i].ville_p,p[i].telephone_p,p[i].mel_p,p[i].profession_p);
        }
        for(int i = 0; i<size; i++)
        {
            printf("%s,%s,%s,%s,%s,%s,%s\n",p[i].nom_p,p[i].prenom_p,p[i].code_postal_p,p[i].ville_p,p[i].telephone_p,p[i].mel_p,p[i].profession_p);
        }
        sauvegarde_annuaire("resultat_filtrer_combiner_deux_champs.txt",p,size);

    }
    if(stricmp(nom_champ1,"postal")==0 && stricmp(nom_champ2,"ville")==0)
    {
        printf("code postal et ville\n");
        for(int i = 0; i<size; i++)
        {
            if(Filtrer_avancer(p[i].code_postal_p,val_chaine1,filtre->index,size)!=1 || Filtrer_avancer(p[i].ville_p,val_chaine2,filtre->index2,size)!=1)
            {

                for (int j = i; j < size; j++)
                {
                    //deplace l'élement a ma fin du tableau
                    p[j]=p[j+1];

                }
                size--;//decremente le compteur
                //decremente la taille du tableau

                i--;

            }


            //printf("%s,%s,%s,%s,%s,%s,%s\n",p[i].nom_p,p[i].prenom_p,p[i].code_postal_p,p[i].ville_p,p[i].telephone_p,p[i].mel_p,p[i].profession_p);
        }
        for(int i = 0; i<size; i++)
        {
            printf("%s,%s,%s,%s,%s,%s,%s\n",p[i].nom_p,p[i].prenom_p,p[i].code_postal_p,p[i].ville_p,p[i].telephone_p,p[i].mel_p,p[i].profession_p);
        }
        sauvegarde_annuaire("resultat_filtrer_combiner_deux_champs.txt",p,size);

    }
    if(stricmp(nom_champ1,"postal")==0 && stricmp(nom_champ2,"tel")==0)
    {
        printf("code postal  et telephone\n");
        for(int i = 0; i<size; i++)
        {
            if(Filtrer_avancer(p[i].code_postal_p,val_chaine1,filtre->index,size)!=1 || Filtrer_avancer(p[i].telephone_p,val_chaine2,filtre->index2,size)!=1)
            {

                for (int j = i; j < size; j++)
                {
                    //deplace l'élement a ma fin du tableau
                    p[j]=p[j+1];

                }
                size--;//decremente le compteur
                //decremente la taille du tableau

                i--;

            }


            //printf("%s,%s,%s,%s,%s,%s,%s\n",p[i].nom_p,p[i].prenom_p,p[i].code_postal_p,p[i].ville_p,p[i].telephone_p,p[i].mel_p,p[i].profession_p);
        }
        for(int i = 0; i<size; i++)
        {
            printf("%s,%s,%s,%s,%s,%s,%s\n",p[i].nom_p,p[i].prenom_p,p[i].code_postal_p,p[i].ville_p,p[i].telephone_p,p[i].mel_p,p[i].profession_p);
        }
        sauvegarde_annuaire("resultat_filtrer_combiner_deux_champs.txt",p,size);

    }
    if(stricmp(nom_champ1,"postal")==0 && stricmp(nom_champ2,"mel")==0)
    {
        printf("code postal  et mail\n");
        for(int i = 0; i<size; i++)
        {
            if(Filtrer_avancer(p[i].code_postal_p,val_chaine1,filtre->index,size)!=1 || Filtrer_avancer(p[i].mel_p,val_chaine2,filtre->index2,size)!=1)
            {

                for (int j = i; j < size; j++)
                {
                    //deplace l'élement a ma fin du tableau
                    p[j]=p[j+1];

                }
                size--;//decremente le compteur
                //decremente la taille du tableau

                i--;

            }


            //printf("%s,%s,%s,%s,%s,%s,%s\n",p[i].nom_p,p[i].prenom_p,p[i].code_postal_p,p[i].ville_p,p[i].telephone_p,p[i].mel_p,p[i].profession_p);
        }
        for(int i = 0; i<size; i++)
        {
            printf("%s,%s,%s,%s,%s,%s,%s\n",p[i].nom_p,p[i].prenom_p,p[i].code_postal_p,p[i].ville_p,p[i].telephone_p,p[i].mel_p,p[i].profession_p);
        }
        sauvegarde_annuaire("resultat_filtrer_combiner_deux_champs.txt",p,size);

    }
    if(stricmp(nom_champ1,"postal")==0 && stricmp(nom_champ2,"profession")==0)
    {
        printf("code postal  et profession\n");
        for(int i = 0; i<size; i++)
        {
            if(Filtrer_avancer(p[i].code_postal_p,val_chaine1,filtre->index,size)!=1 || Filtrer_avancer(p[i].profession_p,val_chaine2,filtre->index2,size)!=1)
            {

                for (int j = i; j < size; j++)
                {
                    //deplace l'élement a ma fin du tableau
                    p[j]=p[j+1];

                }
                size--;//decremente le compteur
                //decremente la taille du tableau

                i--;

            }


            //printf("%s,%s,%s,%s,%s,%s,%s\n",p[i].nom_p,p[i].prenom_p,p[i].code_postal_p,p[i].ville_p,p[i].telephone_p,p[i].mel_p,p[i].profession_p);
        }
        for(int i = 0; i<size; i++)
        {
            printf("%s,%s,%s,%s,%s,%s,%s\n",p[i].nom_p,p[i].prenom_p,p[i].code_postal_p,p[i].ville_p,p[i].telephone_p,p[i].mel_p,p[i].profession_p);
        }
        sauvegarde_annuaire("resultat_filtrer_combiner_deux_champs.txt",p,size);

    }
    if(stricmp(nom_champ1,"ville")==0 && stricmp(nom_champ2,"tel")==0)
    {
        printf("ville  et telephone\n");
        for(int i = 0; i<size; i++)
        {
            if(Filtrer_avancer(p[i].ville_p,val_chaine1,filtre->index,size)!=1 || Filtrer_avancer(p[i].telephone_p,val_chaine2,filtre->index2,size)!=1)
            {

                for (int j = i; j < size; j++)
                {
                    //deplace l'élement a ma fin du tableau
                    p[j]=p[j+1];

                }
                size--;//decremente le compteur
                //decremente la taille du tableau

                i--;

            }


            //printf("%s,%s,%s,%s,%s,%s,%s\n",p[i].nom_p,p[i].prenom_p,p[i].code_postal_p,p[i].ville_p,p[i].telephone_p,p[i].mel_p,p[i].profession_p);
        }
        for(int i = 0; i<size; i++)
        {
            printf("%s,%s,%s,%s,%s,%s,%s\n",p[i].nom_p,p[i].prenom_p,p[i].code_postal_p,p[i].ville_p,p[i].telephone_p,p[i].mel_p,p[i].profession_p);
        }
        sauvegarde_annuaire("resultat_filtrer_combiner_deux_champs.txt",p,size);

    }
    if(stricmp(nom_champ1,"ville")==0 && stricmp(nom_champ2,"mel")==0)
    {
        printf("ville  et mail\n");
        for(int i = 0; i<size; i++)
        {
            if(Filtrer_avancer(p[i].ville_p,val_chaine1,filtre->index,size)!=1 || Filtrer_avancer(p[i].mel_p,val_chaine2,filtre->index2,size)!=1)
            {

                for (int j = i; j < size; j++)
                {
                    //deplace l'élement a ma fin du tableau
                    p[j]=p[j+1];

                }
                size--;//decremente le compteur
                //decremente la taille du tableau

                i--;

            }


            //printf("%s,%s,%s,%s,%s,%s,%s\n",p[i].nom_p,p[i].prenom_p,p[i].code_postal_p,p[i].ville_p,p[i].telephone_p,p[i].mel_p,p[i].profession_p);
        }
        for(int i = 0; i<size; i++)
        {
            printf("%s,%s,%s,%s,%s,%s,%s\n",p[i].nom_p,p[i].prenom_p,p[i].code_postal_p,p[i].ville_p,p[i].telephone_p,p[i].mel_p,p[i].profession_p);
        }
        sauvegarde_annuaire("resultat_filtrer_combiner_deux_champs.txt",p,size);

    }
    if(stricmp(nom_champ1,"ville")==0 && stricmp(nom_champ2,"profession")==0)
    {
        printf("ville  et profession\n");
        for(int i = 0; i<size; i++)
        {
            if(Filtrer_avancer(p[i].ville_p,val_chaine1,filtre->index,size)!=1 || Filtrer_avancer(p[i].profession_p,val_chaine2,filtre->index2,size)!=1)
            {

                for (int j = i; j < size; j++)
                {
                    //deplace l'élement a ma fin du tableau
                    p[j]=p[j+1];

                }
                size--;//decremente le compteur
                //decremente la taille du tableau

                i--;

            }


            //printf("%s,%s,%s,%s,%s,%s,%s\n",p[i].nom_p,p[i].prenom_p,p[i].code_postal_p,p[i].ville_p,p[i].telephone_p,p[i].mel_p,p[i].profession_p);
        }
        for(int i = 0; i<size; i++)
        {
            printf("%s,%s,%s,%s,%s,%s,%s\n",p[i].nom_p,p[i].prenom_p,p[i].code_postal_p,p[i].ville_p,p[i].telephone_p,p[i].mel_p,p[i].profession_p);
        }
        sauvegarde_annuaire("resultat_filtrer_combiner_deux_champs.txt",p,size);

    }
    if(stricmp(nom_champ1,"tel")==0 && stricmp(nom_champ2,"mel")==0)
    {
        printf("telephone et mail\n");
        for(int i = 0; i<size; i++)
        {
            if(Filtrer_avancer(p[i].telephone_p,val_chaine1,filtre->index,size)!=1 || Filtrer_avancer(p[i].mel_p,val_chaine2,filtre->index2,size)!=1)
            {

                for (int j = i; j < size; j++)
                {
                    //deplace l'élement a ma fin du tableau
                    p[j]=p[j+1];

                }
                size--;//decremente le compteur
                //decremente la taille du tableau

                i--;

            }


            //printf("%s,%s,%s,%s,%s,%s,%s\n",p[i].nom_p,p[i].prenom_p,p[i].code_postal_p,p[i].ville_p,p[i].telephone_p,p[i].mel_p,p[i].profession_p);
        }
        for(int i = 0; i<size; i++)
        {
            printf("%s,%s,%s,%s,%s,%s,%s\n",p[i].nom_p,p[i].prenom_p,p[i].code_postal_p,p[i].ville_p,p[i].telephone_p,p[i].mel_p,p[i].profession_p);
        }
        sauvegarde_annuaire("resultat_filtrer_combiner_deux_champs.txt",p,size);

    }
    if(stricmp(nom_champ1,"tel")==0 && stricmp(nom_champ2,"profession")==0)
    {
        printf("tel  et profession\n");
        for(int i = 0; i<size; i++)
        {
            if(Filtrer_avancer(p[i].telephone_p,val_chaine1,filtre->index,size)!=1 || Filtrer_avancer(p[i].profession_p,val_chaine2,filtre->index2,size)!=1)
            {

                for (int j = i; j < size; j++)
                {
                    //deplace l'élement a ma fin du tableau
                    p[j]=p[j+1];

                }
                size--;//decremente le compteur
                //decremente la taille du tableau

                i--;

            }


            //printf("%s,%s,%s,%s,%s,%s,%s\n",p[i].nom_p,p[i].prenom_p,p[i].code_postal_p,p[i].ville_p,p[i].telephone_p,p[i].mel_p,p[i].profession_p);
        }
        for(int i = 0; i<size; i++)
        {
            printf("%s,%s,%s,%s,%s,%s,%s\n",p[i].nom_p,p[i].prenom_p,p[i].code_postal_p,p[i].ville_p,p[i].telephone_p,p[i].mel_p,p[i].profession_p);
        }
        sauvegarde_annuaire("resultat_filtrer_combiner_deux_champs.txt",p,size);

    }
    if(stricmp(nom_champ1,"mel")==0 && stricmp(nom_champ2,"profession")==0)
    {
        printf("mail  et profession\n");
        for(int i = 0; i<size; i++)
        {
            if(Filtrer_avancer(p[i].mel_p,val_chaine1,filtre->index,size)!=1 || Filtrer_avancer(p[i].profession_p,val_chaine2,filtre->index2,size)!=1)
            {

                for (int j = i; j < size; j++)
                {
                    //deplace l'élement a ma fin du tableau
                    p[j]=p[j+1];

                }
                size--;//decremente le compteur
                //decremente la taille du tableau

                i--;

            }


            //printf("%s,%s,%s,%s,%s,%s,%s\n",p[i].nom_p,p[i].prenom_p,p[i].code_postal_p,p[i].ville_p,p[i].telephone_p,p[i].mel_p,p[i].profession_p);
        }
        for(int i = 0; i<size; i++)
        {
            printf("%s,%s,%s,%s,%s,%s,%s\n",p[i].nom_p,p[i].prenom_p,p[i].code_postal_p,p[i].ville_p,p[i].telephone_p,p[i].mel_p,p[i].profession_p);
        }
        sauvegarde_annuaire("resultat_filtrer_combiner_deux_champs.txt",p,size);

    }









    free(p->nom_p);
    free(p->prenom_p);
    free(p->ville_p);
    free(p->mel_p);
    free(p->profession_p);
    free(p);
    fflush(stdin);
//ferme les fichiers


}
/** \brief Cette fonction compare les chaines **valchaine1** et  **valchaine2** donne dans la fonction filtrer_combiner_deux_champs
           avec les sous chaines pour ne garder que les donnes qui correspondent au filtre donne.\n
 *
 * \param[in] s1 char* chaine du champs.
 * \param[in] sch1 char* sous-chaine.
 * \param[in] index int la position ou commence la comparaison des caracteres du champs numéro 1.
 * \param[in] cpt int  compteur pour connaitre de nombre lignes contenu dans l'annuaire.
 *
 * \return  un entier **trouvee** pour la fonction filtrer_combiner_deux_champs
 *
 */
int Filtrer_avancer(const char *s1,const char *sch1,int index,int cpt)
{

    int i,j = 0;
    int trouvee = 0;

    for (i = index-1, j = 0; s1[i] != '\0' && sch1[j] != '\0'; i++, j++)
    {
        if (s1[i] != sch1[j])
        {
            break;
        }
    }

    if (sch1[j] == '\0')
    {
        trouvee = 1;

    }
    else
    {
        trouvee = 2;

    }


    return trouvee;

}




