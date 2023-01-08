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
    fflush(stdin);
    printf("########################################################################\n");
    printf("#                                                                      #\n");
    printf("#           BIENVENUE DANS L'OPTION  AFFICHAGE DES CLIENTS             #\n");
    printf("#                                                                      #\n");
    printf("#                                                                      #\n");
    printf("########################################################################\n");


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





    system("PAUSE");

    int taille = 0;
    struct Client_*p ;

    p = tabRetourner(&taille,annuaire);

    int size = taille;


    for (int i = 0; i < size; i++)

    {


        printf("%s,%s,%s,%s,%s,%s,%s\n",p[i].nom_p,p[i].prenom_p,p[i].code_postal_p,p[i].ville_p,p[i].telephone_p,p[i].mel_p,p[i].profession_p);

    }

    free(p->nom_p);
    free(p->prenom_p);
    free(p->ville_p);
    free(p->mel_p);
    free(p->profession_p);
    free(p);
//ferme les fichiers


}
/** \brief cette fonction permet d'ajouter des clients a l'annuaire donner en sortie
 * preconditions : nom_annuaire est un fichier valide
 * \param[in] nom_annuaire const char*
 * \param[in] nom_p const char*
 * \param[in] prenom_p const char*
 * \param[in] code_postal_p const char*
 * \param[in] ville_p const char*
 * \param[in] telephone_p const char*
 * \param[in] mel_p const char*
 * \param[in] profession_p const char*
 *\param[out] Sorties : resultat_trier_par_nom.txt
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

    //int verife = 0;
    for (i = 0; i < size; i++)
    {

        if (stricmp(p[i].mel_p, mel_p) == 0)
        {
            printf("l'adresse existe deja ! %s\n",p[i].mel_p);
           for(int j= 0;j<size;j++){
            p[j] = p[j+1];


           }

        }
        else
        {

            //verife = 0;
        }

    }


    sauvegarde_annuaire("resultat_ajouter_client.txt",p,size);
    fseek(ajout,0,SEEK_END);
    fprintf(ajout,"%s,%s,%s,%s,%s,",nom_p,prenom_p,code_postal_p,ville_p,mel_p);
        for(int i = 0;i<strlen(telephone_p);i++){
                    if(i==8){
                        fprintf(ajout,"%c%c,",telephone_p[i],telephone_p[i+1]);
                            break;
                    }
                fprintf(ajout,"%c%c.",telephone_p[i],telephone_p[i+1]);

                i++;
            }


fprintf(ajout,"%s\n",profession_p);

//sauvegarde_annuaire("resultat_ajouter_client.txt",annuaireTXT);

    fclose(ajout);




}

/** \brief cette fonction permet de saisir les differents champs et verifie si l'utilisateur fait une bonne saisie
 *
 * \param ajout Ajout_Client*
 * \return void
 *
 */
void saisie( Ajout_Client *ajout)
{

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
                if((ajout->ville[i]>='a' &&ajout->ville[i]<='z')|| (ajout->ville[i]>='A' && ajout->ville[i]<='Z') || ajout->ville[i]=='-' || ajout->ville[i]==' ')
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
