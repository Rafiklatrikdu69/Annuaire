#include <stdio.h>
#include <stdlib.h>
#include<string.h>
#include "fonction.h"
#define TAILLE 100


/** \brief
 *
 * \param char*annuaireS const
 * \param Client_*p struct
 * \param size int
 * \return void
 *
 */
void sauvegarde_annuaire(const char*annuaireS,struct Client_*p,int size )
{
    FILE*fichier = fopen(annuaireS,"w");

    for (int i = 0; i < size; i++)
    {
        //printf("%s,%s,%s,%s,%s,%s,%s\n",p[i].nom_p,p[i].prenom_p,p[i].code_postal_p,p[i].ville_p,p[i].telephone_p,p[i].mel_p,p[i].profession_p);
        fprintf(fichier,"%s,%s,%s,%s,%s,%s,%s\n",p[i].nom_p,p[i].prenom_p,p[i].code_postal_p,p[i].ville_p,p[i].telephone_p,p[i].mel_p,p[i].profession_p);
    }
    fclose(fichier);
}



/** \brief
 */
struct Client_ *tabRetourner(int *size,const char *nom_annuaire)
{

    struct Client_ *p = calloc(1,sizeof(struct Client_));


    //fgetc(stdin);//cela evite de faire sauter la saisie de l'utilisateur pour le menu
    //FILE*annuaire = fopen("annuaire.csv","r");//ouvre le fichier en lecture

    FILE*annuaire = fopen(nom_annuaire,"r");//ouvre le fichier en ecriture


    if(annuaire == NULL) // si valeur renvoyer est NULL alors le fichier n'existe ou ne peux pas etre ouvert
    {
        perror("Erreur d'ouverture du fichier");
        exit(EXIT_FAILURE);
    }




    int cpt = 0;//compteur de ligne



    // Utilisezr fgetc pour lire chaque caractère du fichier jusqu'à ce que vous atteigniez la fin du fichier

    int c = fgetc(annuaire);

    while(!feof(annuaire))
    {

        p[cpt].nom_p = (char *) calloc (256,sizeof(char));
        p[cpt].prenom_p = (char *) calloc (256,sizeof(char));
        p[cpt].code_postal_p = (char *) calloc (256,sizeof(char));
        p[cpt].ville_p = (char *) calloc (256,sizeof(char));
        p[cpt].mel_p = (char *) calloc (256,sizeof(char));
        p[cpt].profession_p = (char *) calloc (256,sizeof(char));
        for(int j= 0;; j++)
        {
            if(c==',' ||c=='\n')
            {

                c = fgetc(annuaire);
                p[cpt].nom_p = (char*)realloc(p[cpt].nom_p,j+1*sizeof(char));
                break;
            }
            // Insérez le caractère lu dans le tableau et incrémentez le compteur

            p[cpt].nom_p[j] = (char) c;

            //lis le caractere suivant
            c = fgetc(annuaire);
        }





        for(int j= 0;; j++)
        {
            if(c==',' ||c=='\n')
            {

                c = fgetc(annuaire);



                p[cpt].prenom_p = (char*)realloc(p[cpt].prenom_p,j+1*sizeof(char));


                break;
            }
            // Insérez le caractère lu dans le tableau et incrémentez le compteur

            p[cpt].prenom_p[j] = (char) c;
            //lis le caractere suivant
            c = fgetc(annuaire);
        }

        for(int j= 0;; j++)
        {
            if(c==',' ||c=='\n')
            {

                c = fgetc(annuaire);
                p[cpt].code_postal_p = (char*)realloc(p[cpt].code_postal_p,j+1*sizeof(char));
                break;
            }
            // Insérez le caractère lu dans le tableau et incrémentez le compteur

            p[cpt].code_postal_p[j] = (char) c;
            //lis le caractere suivant
            c = fgetc(annuaire);
        }

        for(int j= 0;; j++)
        {
            if(c==',' ||c=='\n')
            {

                c = fgetc(annuaire);
                p[cpt].ville_p = (char*)realloc(p[cpt].ville_p,j+1*sizeof(char));
                break;
            }
            // Insérez le caractère lu dans le tableau et incrémentez le compteur

            p[cpt].ville_p[j] = (char) c;
            //lis le caractere suivant
            c = fgetc(annuaire);
        }

        for(int j= 0;; j++)
        {
            if(c==',' ||c=='\n')
            {

                c = fgetc(annuaire);
                break;
            }
            // Insérez le caractère lu dans le tableau et incrémentez le compteur
           // strtok(p[j].telephone_p,".");
            p[cpt].telephone_p[j] = (char) c;

            //lis le caractere suivant
            c = fgetc(annuaire);
        }


        for(int j= 0;; j++)
        {
            if(c==',' ||c=='\n')
            {

                c = fgetc(annuaire);
                p[cpt].mel_p = (char*)realloc(p[cpt].mel_p,j+1*sizeof(char));
                break;
            }
            // Insérez le caractère lu dans le tableau et incrémentez le compteur

            p[cpt].mel_p[j] = (char) c;
            //lis le caractere suivant
            c = fgetc(annuaire);
        }

        for(int j= 0;; j++)
        {
            if(c==',' ||c=='\n')
            {

                c = fgetc(annuaire);
                p[cpt].profession_p = (char*)realloc(p[cpt].profession_p,j+1*sizeof(char));
                break;
            }
            // Insérez le caractère lu dans le tableau et incrémentez le compteur

            p[cpt].profession_p[j] = (char) c;
            //lis le caractere suivant
            c = fgetc(annuaire);
        }



        cpt++;//incremente le compteur pour passer a la structure suivante
        p = realloc(p,sizeof(struct  Client_)*(cpt+1));





    }
    *size = cpt;

    fclose(annuaire);
    return p;
    free(p);


    //return p;
}

