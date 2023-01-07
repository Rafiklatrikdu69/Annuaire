/**<
*\file fonction.c
*\brief les fonctions si dessous sont faites avec la norme C99 pour plus de simplification.Voir(https://en.cppreference.com/w/c/99)
*\author Rafik BOUCHENNA G4S1B
*\date 08/01/2023
*/
#include <stdio.h>
#include <stdlib.h>
#include<string.h>//strcmp,strncmp,strstr,stricmp
#include<assert.h>//teste en boite noire
#include "fonction.h"//Séparation en 3 fichiers
#define TAILLE 100



/** \brief la fonction  Afficher_annuaire_clients affiche l'annuaire
           contenant les clients suivant le critere choisie : tri des clients,filtre,etc...
 *
 * \param Id_client const Client*
 * \return void
 *
 */
//fonction a revoir pour plus de lisibilité
void Afficher_annuaire_clients(const Client *Id_client)
{
    fgetc(stdin);
    FILE* fichier;
    FILE *annuaireCSV = fopen("annuaire.csv", "r");
    printf("Voici les differents fichiers que vous pouvez ouvrir : \n");
    puts("resultat_filtrer_combiner_deux_champs.txt\n");
    puts("annuaireValide.txt\n");
    puts("resultat_ajouter.txt\n");
    puts("resultat_trier_par_nom.txt\n");
    puts("annuaire.txt\n");
    puts("annuaire.csv\n");
    char annuaire [50];
    printf("entrer le nom de l'annuaire que vous voulez afficher : \n");
    fgets(annuaire,50,stdin);
    annuaire[strcspn(annuaire,"\r\n")] = '\0';//au cas ou il ya des \n
    fichier = fopen(annuaire,"r");//ouverture du fichier en mode lecture
    if(fichier == NULL)
    {
        perror("Erreur d'ouverture du fichier !");
        exit(EXIT_FAILURE);
    }



    Client r;



    // Vérifiez si le fichier a été ouvert correctement
    if (annuaireCSV == NULL)  // si valeur renvoyer est NULL alors le fichier n'existe ou ne peux pas etre ouvert
    {
        perror("Erreur lors de l'ouverture du fichier");
        exit(EXIT_FAILURE);
    }






    r.donnes= (char**) malloc( (sizeof(char*[1000])));//alloue un tableau de 1000 pointeur -> 1000 char
    if(r.donnes == NULL)
    {
        printf("erreur allocation");
    }
    for(int i=0; i<1000; i++)
    {


        r.donnes[i] = (char*) malloc(sizeof(char*[1000]));//alloue un tableau de 1000 char

    }

    int cpt = 0;
    int ligne =0;
//utilisation d'un tableau a deux dimension pour compter le nombre de ligne
    while(!feof(fichier)&& !ferror(fichier)) //si ferror est vrai alors le fichier n'est pas lu = probleme et que on est pas a la fin du fichier
    {
        if(fgets(r.donnes[ligne],1000,fichier)!= NULL) //lire une chaine de caractere
        {
            ligne++;//incremente le nombre de ligne pour passer d'une ligne a une autre
        }
    }

    printf("le nombre de ligne du fichier : %d\n",ligne);
    /*struct Client_ est une structure qui represente un client,
    et p est un pointeur vers un tableau de  struct Client_
    Calloc initialise tout a zero*/
    struct Client_ *p = (struct Client_*)calloc(ligne+1,sizeof(struct Client_));

    int i = 0;

    // Utilisez fgetc pour lire chaque caractère du fichier jusqu'à ce que vous atteigniez la fin du fichier

    int c = fgetc(fichier);
    rewind(fichier);
    while(cpt<ligne)
    {

        p[cpt].nom_p = (char *) calloc (256,sizeof(char));
        p[cpt].prenom_p = (char *) calloc (256,sizeof(char));
        p[cpt].ville_p = (char *) calloc (256,sizeof(char));
        p[cpt].mel_p = (char *) calloc (256,sizeof(char));
        p[cpt].profession_p = (char *) calloc (256,sizeof(char));
        for(int j= 0;; j++)
        {
            if(c==',' ||c=='\n')
            {

                c = fgetc(fichier);
                strtok(p[cpt].nom_p,"\t");
                p[cpt].nom_p = (char*)realloc(p[cpt].nom_p,j+1*sizeof(char));

                break;
            }
            // Insérez le caractère lu dans le tableau et incrémentez le compteur

            p[cpt].nom_p[j] = (char) c;

            //lis le caractere suivant
            c = fgetc(fichier);
        }

        for(int j= 0;; j++)
        {
            if(c==',' ||c=='\n')
            {

                c = fgetc(fichier);
                strtok(p[cpt].prenom_p,"\t");
                p[cpt].prenom_p = (char*)realloc(p[cpt].prenom_p,j+1*sizeof(char));
                break;
            }
            // Insérez le caractère lu dans le tableau et incrémentez le compteur

            p[cpt].prenom_p[j] = (char) c;
            //lis le caractere suivant
            c = fgetc(fichier);
        }
        for(int j= 0;; j++)
        {
            if(c==',' ||c=='\n')
            {

                c = fgetc(fichier);
                strtok(p[cpt].code_postal_p,"\t");
                break;
            }
            // Insérez le caractère lu dans le tableau et incrémentez le compteur

            p[cpt].code_postal_p[j] = (char) c;
            //lis le caractere suivant
            c = fgetc(fichier);
        }
        for(int j= 0;; j++)
        {
            if(c==',' ||c=='\n')
            {

                c = fgetc(fichier);
                strtok(p[cpt].ville_p,"\t");
                p[cpt].ville_p = (char*)realloc(p[cpt].ville_p,j+1*sizeof(char));
                break;
            }
            // Insérez le caractère lu dans le tableau et incrémentez le compteur

            p[cpt].ville_p[j] = (char) c;
            //lis le caractere suivant
            c = fgetc(fichier);
        }
        for(int j= 0;; j++)
        {
            if(c==',' ||c=='\n')
            {

                c = fgetc(fichier);
                strtok(p[cpt].telephone_p,"\t");
                break;
            }
            // Insérez le caractère lu dans le tableau et incrémentez le compteur

            p[cpt].telephone_p[j] = (char) c;
            //lis le caractere suivant
            c = fgetc(fichier);
        }

        for(int j= 0;; j++)
        {
            if(c==',' ||c=='\n')
            {

                c = fgetc(fichier);

                p[cpt].mel_p = realloc(p[cpt].mel_p,j+1*sizeof(char));
                break;
            }
            // Insérez le caractère lu dans le tableau et incrémentez le compteur

            p[cpt].mel_p[j] = (char) c;
            //lis le caractere suivant
            c = fgetc(fichier);
        }
        for(int j= 0;; j++)
        {
            if(c==',' ||c=='\n')
            {

                c = fgetc(fichier);
                strtok(p[cpt].profession_p,"\t");
                p[cpt].profession_p = (char*)realloc(p[cpt].profession_p,j+1*sizeof(char));
                break;
            }
            // Insérez le caractère lu dans le tableau et incrémentez le compteur

            p[cpt].profession_p[j] = (char) c;
            //lis le caractere suivant
            c = fgetc(fichier);
        }
        cpt++;//incremente le compteur pour passer a la structure suivante

    }
// inspiration du tri a bulle pour trier les donnes en fonction du nom


    for (i = 0; i < cpt; i++)
    {
        for(int i = 0; i<200; i++)
        {
            printf("-");
        }
        printf("\n");
        printf("%-25s |%-25s |%-25s |%-25s |%-25s |%-50s |%-25s\n",p[i].nom_p,p[i].prenom_p,p[i].code_postal_p,p[i].ville_p,p[i].telephone_p,p[i].mel_p,p[i].profession_p);

    }
//libere la memoire
    for(int i=0; i<ligne; i++)
    {


        free(r.donnes[i]);
        r.donnes[i] = NULL;

    }

    free(r.donnes);
    r.donnes = NULL;



    free(p->nom_p);
    free(p->prenom_p);
    free(p->ville_p);
    free(p->mel_p);
    free(p->profession_p);
    free(p);
//ferme les fichiers

    fclose(fichier);
}





/** \brief
 *
 * \param[in] annuaireTXT const char*
 * \param[in] nom_p const char*
 * \param[in] prenom_p const char*
 * \param[in] code_postal_p const char*
 * \param[in] ville_p const char*
 * \param[in] telephone_p const char*
 * \param[in] mel_p const char*
 * \param[in] profession_p const char*
 *\param[out] resultat_trier_par_nom.txt
 * \return int
 *
 */
void ajouter_Client(const char *nom_annuaire,const char *nom_p,const char *prenom_p,const char *code_postal_p,const char *ville_p,const char *telephone_p,const char *mel_p,const char *profession_p)
{




    FILE*ajout = fopen("resultat_ajouter_client.txt","w");
    int taille = 0;
    struct Client_*p ;

    p = tabRetourner(&taille,nom_annuaire);

    int size = taille;



    int i=0;
    sauvegarde_annuaire("resultat_ajouter_client.txt",p,size);
    //int verife = 0;
    for (i = 0; i < size; i++)
    {

        if (stricmp(p[i].mel_p, mel_p) == 0)
        {
            printf("l'adresse existe deja ! %s\n",p[i].mel_p);
            /*verife = 1;*/
            break;


        }
        else
        {

            //verife = 0;
        }

    }


    ;
    fseek(ajout,0,SEEK_END);
    fprintf(ajout,"%s,%s,%s,%s,%s,%s,%s\n",nom_p,prenom_p,code_postal_p,ville_p,telephone_p,mel_p,profession_p);


//sauvegarde_annuaire("resultat_ajouter_client.txt",annuaireTXT);

    fclose(ajout);




}

void saisie( Ajout_Client *ajout)
{
    fgetc(stdin);
    printf("########################################################################\n");
    printf("#                                                                      #\n");
    printf("#     BIENVENUE DANS L'OPTION  AJOUT DES CLIENTS ICI VOUS POUVEZ       #\n");
    printf("#       AJOUTER VOTRE CLIENT DANS VOTRE ANNUAIRE                       #\n");
    printf("#                                                                      #\n");
    printf("########################################################################\n");

NOM:
    {

        printf("Entrez votre Nom : \n");
        fgets(ajout->nom,100,stdin);
        ajout->nom[strcspn(ajout->nom,"\r\n")] = '\0';


        if(ajout->nom[0]!='\0')
        {

            //apres que l'utilisateur entre ses coordonees je detecte avec une boucle si chaque caracteres et compris entre a et z ou A et Z en se basant sur le code ascii
            /*Verifie si la saisie de l'utilisateur est bonne */
            for(int i = 0; i<strlen(ajout->nom); i++)
            {
                if((ajout->nom[i]>='a' && ajout->nom[i]<='z') || (ajout->nom[i]>='A' && ajout->nom[i]<='Z') || ajout->nom[i]=='-' ||  ajout->nom[i]==' ')
                {

                    continue;


                }
                else
                {
                    puts("Caracteres speciaux ,chiffre,lettre avec accents,ESPACES detecter!!!\n");
                    printf("caracteres trouver -> %c \n",ajout->nom[i]);
                    goto NOM;
                    //l'utilisateur doit resaisir son nom en cas de problemes->robustesse valider


                }
            }

        }
        else
        {

            goto PRENOM;
        }


    }

PRENOM:
    {

        printf("Entrez votre Prenom : \n");
        fgets(ajout->prenom,TAILLE,stdin);
        ajout->prenom[strcspn(ajout->prenom,"\r\n")] = '\0';


        if(ajout->prenom[0]!='\0')
        {
            /*Verifie si la saisie de l'utilisateur est bonne */
            for(int i = 0; i<strlen(ajout->prenom); i++)
            {
                if((ajout->prenom[i]>='a' && ajout->prenom[i]<='z') || (ajout->prenom[i]>='A' && ajout->prenom[i]<='Z') || ajout->prenom[i]=='-' || ajout->prenom[i]==' ')
                {
                    continue;

                }
                else
                {
                    puts("Caracteres speciaux ,chiffre,lettre avec accents,ESPACES detecter!!!\n");
                    printf(" caracteres trouver -> %c \n",ajout->prenom[i]);
                    goto PRENOM;

                }
            }

        }
        else
        {
            goto CODE;
        }

    }



CODE:
    {

        printf("Entrez votre Code Postal : \n");
        fgets(ajout->codepostal,TAILLE,stdin);
        ajout->codepostal[strcspn(ajout->codepostal,"\r\n")] = '\0';

        if(ajout->codepostal[0]!='\0')
        {

            /*Verifie si la saisie de l'utilisateur est bonne */
            for(int i = 0; i<strlen(ajout->codepostal); i++)
            {
                if((ajout->codepostal[i]>='0' && ajout->codepostal[i]<='9'))
                {
                    continue;

                }
                else
                {
                    puts("Caracteres speciaux ,chiffre,lettre avec accents,ESPACES detecter!!!\n");
                    printf("caracteres trouver -> %c \n",ajout->codepostal[i]);
                    goto CODE;

                }
            }



        }
        else
        {
            goto VILLE;
        }

    }



VILLE:
    {

        printf("Entrez votre Ville : \n");
        fgets(ajout->ville,TAILLE,stdin);
        ajout->ville[strcspn(ajout->ville,"\r\n")] = '\0';

        if(ajout->ville[0]!='\0')
        {

            /*Verifie si la saisie de l'utilisateur est bonne */
            for(int i = 0; i<strlen(ajout->ville); i++)
            {
                if((ajout->ville[i]>='a' &&ajout->ville[i]<='z')|| (ajout->ville[i]>='A' && ajout->ville[i]<='Z') || ajout->ville[i]=='-')
                {
                    continue;

                }
                else
                {
                    puts("Caracteres speciaux ,chiffre,lettre avec accents,ESPACES detecter!!!\n");
                    printf("caracteres trouver -> %c \n",ajout->ville[i]);
                    goto VILLE;

                }
            }

        }
        else
        {
            goto TEL;
        }

    }

TEL:
    {

        printf("Entrez votre numero de telephone : \n");
        fgets(ajout->telephone,20,stdin);
        ajout->telephone[strcspn(ajout->telephone,"\r\n")] = '\0';



        if(ajout->telephone[0]!='\0')
        {
            assert(strlen(ajout->telephone) <= 16);//test -> le nombre de chiffre doit etre egale a 10 ->France

            /*Verifie si la saisie de l'utilisateur est bonne */
            for(int i = 0; i<strlen(ajout->telephone); i++)
            {
                //test : le champs telephone doit contenir seulement des chiffre
                assert((ajout->telephone[i]>='0' && ajout->telephone[i]<='9'));
                if((ajout->telephone[i]>='0' && ajout->telephone[i]<='9'))
                {
                    continue;

                }
                else
                {
                    puts("Caracteres speciaux ,chiffre,lettre avec accents,ESPACES detecter!!!\n");
                    printf("caracteres trouver -> %c \n",ajout->telephone[i]);
                    goto TEL;

                }
            }



        }
        else
        {
            goto MEL;
        }


    }


MEL:
    {

        printf("Entrez votre email : \n");
        fgets(ajout->mail,TAILLE,stdin);
        ajout->mail[strcspn(ajout->mail,"\r\n")] = '\0';


        occurence d;

        if(ajout->mail[0]!='\0')
        {
            /*Verifie si la saisie de l'utilisateur est bonne */
            for(int i = 0; i<strlen(ajout->mail); i++)
            {
                //test en boit noire -> l'adresse mail doit contenir un @ et des .
                assert(strstr(ajout->mail,"@"));//l'adresse doit contenir un @
                assert(strstr(ajout->mail,"."));//l'adresse doit contenir au moins un . pour etre valide

                if((ajout->mail[i]>='a' && ajout->mail[i]<='z')|| (ajout->mail[i]>='A' &&ajout->mail[i]<='Z') || ajout->mail[i]=='-'|| strstr(ajout->mail,"@")|| strstr(ajout->mail,"."))
                {
                    continue;

                }
                else
                {
                    puts("Caracteres speciaux ,chiffre,lettre avec accents,ESPACES detecter!!!\n");
                    printf("caracteres trouver -> %c \n",ajout->mail[i]);


                }

            }

            d.occurrence1 = 0;
            d.occurrence2 = 0;
            //verification de la validité de l'adresse mail saisie
            for(int i  = 0; ajout->mail[i] != '\0'; i++)
            {
                if(ajout->mail[i] == '@')
                {
                    d.occurrence1++;
                }
                if(ajout->mail[i] == '.')
                {
                    d.occurrence2++;
                }
            }
            switch(d.occurrence1)
            {
            case 1:
                break;
            default:
                printf("vous pouvez utiliser qu'un seul @ pour votre adresse mail\n");

            }
            switch(d.occurrence2)
            {
            case 1:
                break;
            case 2:
                break;
            default:
                printf("vous pouvez utiliser jusqu'a deux . pour votre adresse mail\n");

            }

            printf("Le nombre d’occurrence de @ est %d\n", d.occurrence1);
            printf("Le nombre d’occurrence de . est %d\n", d.occurrence2);








        }
        else
        {
            printf("l'adresse doit etre obligatoirement renseigner !!! \n");
            goto MEL;
        }


    }



PROFESSION:
    {

        printf("Entrez votre profession : \n");
        fgets(ajout->profession,TAILLE,stdin);
        ajout->profession[strcspn(ajout->profession,"\r\n")] = '\0';
        if(ajout->profession[0]!='\0')
        {
            for(int i = 0; i<strlen(ajout->profession); i++)
            {
                if((ajout->profession[i]>='a' && ajout->profession[i]<='z') || (ajout->profession[i]>='A' && ajout->profession[i]<='Z')|| ajout->profession[i]==' '  || ajout->profession[i]=='-')
                {
                    continue;

                }
                else
                {
                    puts("Caracteres speciaux ,chiffre,lettre avec accents,ESPACES detecter!!!\n");
                    printf("caracteres trouver -> %c \n",ajout->profession[i]);
                    goto PROFESSION;

                }
            }
        }

    }




}
