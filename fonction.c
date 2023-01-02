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
void Afficher_annuaire_clients(const Client *Id_client){
fgetc(stdin);
 FILE*fichier;
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
if(fichier == NULL){
    perror("Erreur d'ouverture du fichier !");
    exit(EXIT_FAILURE);
}



    Client r;



    // Vérifiez si le fichier a été ouvert correctement
    if (annuaireCSV == NULL) {// si valeur renvoyer est NULL alors le fichier n'existe ou ne peux pas etre ouvert
        perror("Erreur lors de l'ouverture du fichier");
        exit(EXIT_FAILURE);
    }






r.donnes= (char**) malloc( (sizeof(char*[1000])));//alloue un tableau de 1000 pointeur -> 1000 char
        if(r.donnes == NULL){
            printf("erreur allocation");
        }
        for(int i=0; i<1000; i++){


            r.donnes[i] = (char*) malloc(sizeof(char*[1000]));//alloue un tableau de 1000 char

        }

int cpt = 0;
int ligne =0;
//utilisation d'un tableau a deux dimension pour compter le nombre de ligne
while(!feof(fichier)&& !ferror(fichier)){//si ferror est vrai alors le fichier n'est pas lu = probleme et que on est pas a la fin du fichier
            if(fgets(r.donnes[ligne],1000,fichier)!= NULL){//lire une chaine de caractere
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
while(cpt<ligne){

        p[cpt].nom_p = (char *) calloc (256,sizeof(char));
        p[cpt].prenom_p = (char *) calloc (256,sizeof(char));
        p[cpt].ville_p = (char *) calloc (256,sizeof(char));
        p[cpt].mel_p = (char *) calloc (256,sizeof(char));
        p[cpt].profession_p = (char *) calloc (256,sizeof(char));
    for(int j= 0;;j++){
             if(c==',' ||c=='\n'){

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

      for(int j= 0;;j++){
             if(c==',' ||c=='\n'){

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
        for(int j= 0;;j++){
             if(c==',' ||c=='\n'){

                c = fgetc(fichier);
                strtok(p[cpt].code_postal_p,"\t");
                    break;
            }
        // Insérez le caractère lu dans le tableau et incrémentez le compteur

        p[cpt].code_postal_p[j] = (char) c;
            //lis le caractere suivant
        c = fgetc(fichier);
    }
          for(int j= 0;;j++){
             if(c==',' ||c=='\n'){

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
    for(int j= 0;;j++){
             if(c==',' ||c=='\n'){

                c = fgetc(fichier);
                strtok(p[cpt].telephone_p,"\t");
                    break;
            }
        // Insérez le caractère lu dans le tableau et incrémentez le compteur

        p[cpt].telephone_p[j] = (char) c;
            //lis le caractere suivant
        c = fgetc(fichier);
    }

        for(int j= 0;;j++){
             if(c==',' ||c=='\n'){

                c = fgetc(fichier);

                p[cpt].mel_p = realloc(p[cpt].mel_p,j+1*sizeof(char));
                    break;
            }
        // Insérez le caractère lu dans le tableau et incrémentez le compteur

        p[cpt].mel_p[j] = (char) c;
            //lis le caractere suivant
        c = fgetc(fichier);
    }
         for(int j= 0;;j++){
             if(c==',' ||c=='\n'){

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


  for (i = 0; i < cpt; i++) {
  printf("%-25s %-25s %-25s %-25s %-25s %-50s %-25s\n",p[i].nom_p,p[i].prenom_p,p[i].code_postal_p,p[i].ville_p,p[i].telephone_p,p[i].mel_p,p[i].profession_p);

  }
//libere la memoire
       for(int i=0; i<ligne; i++){


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
 * \param Id_client const Client*
 * \return void
 *
 */
void Rendre_annuaire_valide(const Client *Id_client){
fgetc(stdin);//cela evite de faire sauter la saisie de l'utilisateur pour le menu
FILE*annuaire = fopen("annuaire.csv","r");//ouvre le fichier en lecture
FILE *file = fopen("annuaire.txt", "r");//ouvre le fichier en lecture
FILE*nv = fopen("annuaireValide.txt","w");//ouvre le fichier en ecriture
if(annuaire == NULL){// si valeur renvoyer est NULL alors le fichier n'existe ou ne peux pas etre ouvert
    perror("Erreur d'ouverture du fichier");
    exit(EXIT_FAILURE);
}
if(nv == NULL){// si valeur renvoyer est NULL alors le fichier n'existe ou ne peux pas etre ouvert
    perror("Erreur d'ouverture du fichier");
    exit(EXIT_FAILURE);
}
if(file == NULL){// si valeur renvoyer est NULL alors le fichier n'existe ou ne peux pas etre ouvert
    perror("Erreur d'ouverture du fichier");
    exit(EXIT_FAILURE);
}


char donnes[1000][1000];//tableau 2d pour compter le nombre de lignes

int cpt = 0;//compteur de ligne
int ligne =0;//nombre de ligne du fichier
while(!feof(annuaire)&& !ferror(annuaire)){//si ferror est vrai alors le fichier n'est pas lu = probleme et que on est pas a la fin du fichier
            if(fgets(donnes[ligne],1000,annuaire)!= NULL){//lire une chaine de caractere
                ligne++;//incremente le nombre de ligne pour passer d'une ligne a une autre
            }
}
fclose(annuaire);//ferme le fichier avec fclose

printf("le nombre de ligne du fichier : %d\n",ligne);
        /*struct Client_ est une structure qui represente un client,
          et p est un pointeur vers un tableau de  struct Client_
          Calloc initialise tout a zero*/
struct Client_ *p = (struct Client_*)calloc(ligne+1,sizeof(struct Client_));


// Utilise fgetc pour lire chaque caractère du fichier jusqu'à ce que, l'on atteind la fin du fichier
int c = fgetc(file);

while(cpt<ligne){
        //Preference pour calloc car malloc fait crash le programme en cas de chaine vide
        p[cpt].nom_p = (char *) calloc (256,sizeof(char));
        p[cpt].prenom_p = (char *) calloc (256,sizeof(char));
        p[cpt].ville_p = (char *) calloc (256,sizeof(char));
        p[cpt].mel_p = (char *) calloc (256,sizeof(char));
        p[cpt].profession_p = (char *) calloc (256,sizeof(char));
    for(int j= 0;;j++){
    // Utilise un compteur pour suivre l'emplacement où chaque caractère doit être inséré dans le tableau
             if(c==',' ||c=='\n'){

                c = fgetc(file);//lis le caractere
                //realloue la place avec le compteur j qui represente le nombre de cases du tableau
                p[cpt].nom_p = (char*)realloc(p[cpt].nom_p,j+1*sizeof(char));
                    break;
            }
        // Insérez le caractère lu dans le tableau et incrémentez le compteur

        p[cpt].nom_p[j] = (char) c;

        //lis le caractere suivant
        c = fgetc(file);
    }

      for(int j= 0;;j++){
             if(c==',' ||c=='\n'){

                c = fgetc(file);//lis le caractere
                //realloue la place avec le compteur j qui represente le nombre de cases du tableau
                p[cpt].prenom_p = (char*)realloc(p[cpt].prenom_p,j+1*sizeof(char));
                    break;
            }
        // Insérez le caractère lu dans le tableau et incrémentez le compteur

        p[cpt].prenom_p[j] = (char) c;
            //lis le caractere suivant
        c = fgetc(file);
    }
        for(int j= 0;;j++){
             if(c==',' ||c=='\n'){

                c = fgetc(file);//lis le caractere
                    break;
            }
        // Insérez le caractère lu dans le tableau et incrémentez le compteur

        p[cpt].code_postal_p[j] = (char) c;
            //lis le caractere suivant
        c = fgetc(file);
    }
          for(int j= 0;;j++){
             if(c==',' ||c=='\n'){

                c = fgetc(file);//lis le caractere
                //realloue la place avec le compteur j qui represente le nombre de cases du tableau
                p[cpt].ville_p = (char*)realloc(p[cpt].ville_p,j+1*sizeof(char));
                    break;
            }
        // Insérez le caractère lu dans le tableau et incrémentez le compteur

        p[cpt].ville_p[j] = (char) c;
        //lis le caractere suivant
        c = fgetc(file);
    }
    for(int j= 0;;j++){
             if(c==',' ||c=='\n'){

                c = fgetc(file);//lis le caractere
                    break;
            }
        // Insérez le caractère lu dans le tableau et incrémentez le compteur

        p[cpt].telephone_p[j] = (char) c;
            //lis le caractere suivant
        c = fgetc(file);
    }

        for(int j= 0;;j++){
             if(c==',' ||c=='\n'){

                c = fgetc(file);//lis le caractere
                //realloue la place avec le compteur j qui represente le nombre de cases du tableau
                p[cpt].mel_p = (char*)realloc(p[cpt].mel_p,j+1*sizeof(char));
                    break;
            }
        // Insérez le caractère lu dans le tableau et incrémentez le compteur

        p[cpt].mel_p[j] = (char) c;
            //lis le caractere suivant
        c = fgetc(file);
    }
         for(int j= 0;;j++){
             if(c==',' ||c=='\n'){

                c = fgetc(file);//lis le caractere
                //realloue la place avec le compteur j qui represente le nombre de cases du tableau
                p[cpt].profession_p = (char*)realloc(p[cpt].profession_p,j+1*sizeof(char));
                    break;
            }
        // Insérez le caractère lu dans le tableau et incrémentez le compteur

        p[cpt].profession_p[j] = (char) c;
            //lis le caractere suivant
        c = fgetc(file);
    }
cpt++;//incremente le compteur pour passer au tableau de structure suivant

}
/*inspiration du tri a bulle pour supprimer les doublons
 je tri le tableau puis je supprime les lignes contenant des doublons sur les adresses mails*/
  struct Client_ temp;
  for (int i= 0; i < cpt; i++) {
        for (int j = i+1 ;j < cpt; j++) {
              if (stricmp(p[i].nom_p, p[j].nom_p) > 0) {
                temp = p[i];
                p[i] = p[j];
                p[j] = temp;
              }
        }
  }

  for (int i= 0; i < cpt; i++) {
        //si les adresses a l'indice i et i+1 sont identique alors je vais les deplacer a la fin du tableau
        if (stricmp(p[i].mel_p, p[i+1].mel_p) == 0) {

            for (int j = i+1;j < cpt; j++) {
                    //deplace l'élement a ma fin du tableau
              p[j]=p[j+1];

            }
            cpt--;//decremente le compteur
            i--;//decremente la taille du tableau
        }



  }
  for(int i = 0;i<cpt;i++){
        //affiche le tableau dans le fichier donné en sortie sans les doublons
    fprintf(nv,"%s,%s,%s,%s,%s,%s,%s\n",p[i].nom_p,p[i].prenom_p,p[i].code_postal_p,p[i].ville_p,p[i].telephone_p,p[i].mel_p,p[i].profession_p);
  }

//ferme les fichiers
fclose(nv);
fclose(file);
//libere la memoire
free(p->nom_p);
free(p->prenom_p);
free(p->ville_p);
free(p->mel_p);
free(p->profession_p);
free(p);



}


/** \brief
 *
 * \param Id_client const Client*
 * \return void
 *
 */
void Ecriture_annuaire_clients(const Client *Id_client){
//cette fonction ecrit copie les contenu du fichier annuaire.csv
FILE*fichier;
FILE*fp;

fichier = fopen("annuaire.csv","r");//ouverture du fichier en mode lecture

fp = fopen("annuaire.txt","w");//ouverture du fichier en mode ecriture
if(fichier ==NULL){// si valeur renvoyer est NULL alors le fichier n'existe ou ne peux pas etre ouvert
    perror("Erreur d'ouverture du fichier !");
    exit(EXIT_FAILURE);
}
if(fp ==NULL){// si valeur renvoyer est NULL alors le fichier n'existe ou ne peux pas etre ouvert
    perror("Erreur d'ouverture du fichier !");
    exit(EXIT_FAILURE);
}
   char c;


   while(!feof(fichier)){

//tant qu'on est pas a la fin du fichier on affiche les caracteres
        c =fgetc(fichier);
        fprintf(fp,"%c",c);

   }

fclose(fichier);//ferme le fichier

fclose(fp);//ferme le fichier


}

int saisieNOM(const char * nom){
    int valider = 0;
  if(nom[0]!='\0'){

            //apres que l'utilisateur entre ses coordonees je detecte avec une boucle si chaque caracteres et compris entre a et z ou A et Z en se basant sur le code ascii
            /*Verifie si la saisie de l'utilisateur est bonne */
            for(int i = 0;i<strlen(nom);i++){
                if((nom[i]>='a' && nom[i]<='z') || (nom[i]>='A' && nom[i]<='Z') || nom[i]=='-' ||  nom[0]!=' '){

                        continue;


                }
                else{
                    puts("Caracteres speciaux ,chiffre,lettre avec accents,ESPACES detecter!!!\n");
                    printf("caracteres trouver -> %c \n",nom[i]);
                    valider = 1;
                    break;
                    //l'utilisateur doit resaisir son nom en cas de problemes->robustesse valider


                }
            }

                }
                return valider;
}


int saisiePRENOM(const char * prenom){
    int valider = 0;
if(prenom[0]!='\0'){
            /*Verifie si la saisie de l'utilisateur est bonne */
            for(int i = 0;i<strlen(prenom);i++){
                if((prenom[i]>='a' && prenom[i]<='z') || (prenom[i]>='A' && prenom[i]<='Z') || prenom[i]=='-'){
                        continue;

                }
                else{
                    puts("Caracteres speciaux ,chiffre,lettre avec accents,ESPACES detecter!!!\n");
                    printf(" caracteres trouver -> %c \n",prenom[i]);


                 valider = 1;
                 break;



                }
            }
            return valider;
}


}


int saisieCODEPOSTAL(const char * codepostal){
    int valider = 0;
if(codepostal[0]!='\0'){

            /*Verifie si la saisie de l'utilisateur est bonne */
            for(int i = 0;i<strlen(codepostal);i++){
                if((codepostal[i]>='0' && codepostal[i]<='9')){
                        continue;

                }
                else{
                    puts("Caracteres speciaux ,chiffre,lettre avec accents,ESPACES detecter!!!\n");
                    printf("caracteres trouver -> %c \n",codepostal[i]);
                       valider = 1;
                       break;


                }
            }
            return valider;


}

}


int saisieVILLE(const char * ville){
    int valider = 0;
if(ville[0]!='\0'){

            /*Verifie si la saisie de l'utilisateur est bonne */
            for(int i = 0;i<strlen(ville);i++){
                if((ville[i]>='a' && ville[i]<='z')|| (ville[i]>='A' && ville[i]<='Z') || ville[i]=='-'){
                        continue;

                }
                else{
                    puts("Caracteres speciaux ,chiffre,lettre avec accents,ESPACES detecter!!!\n");
                    printf("caracteres trouver -> %c \n",ville[i]);
                    valider = 1;
                       break;

                }
            }
            return valider;



}

}


int saisieTELEPHONE(const char * telephone){
    int valider = 0;
if(telephone[0]!='\0'){
               assert(strlen(telephone) == 10);//test -> le nombre de chiffre doit etre egale a 10 ->France

            /*Verifie si la saisie de l'utilisateur est bonne */
            for(int i = 0;i<strlen(telephone);i++){
                    //test : le champs telephone doit contenir seulement des chiffre
                    assert((telephone[i]>='0' && telephone[i]<='9'));
                if((telephone[i]>='0' && telephone[i]<='9')){
                        continue;

                }
                else{
                    puts("Caracteres speciaux ,chiffre,lettre avec accents,ESPACES detecter!!!\n");
                    printf("caracteres trouver -> %c \n",telephone[i]);
                    valider = 1;
                       break;

                }
            }
            return valider;


}

}


int saisieMAIL(const char * mail){
occurence d;
int valider = 0;
if(mail[0]!='\0'){
            /*Verifie si la saisie de l'utilisateur est bonne */
            for(int i = 0;i<strlen(mail);i++){
                    //test en boit noire -> l'adresse mail doit contenir un @ et des .
                    assert(strstr(mail,"@"));//l'adresse doit contenir un @
                    assert(strstr(mail,"."));//l'adresse doit contenir au moins un . pour etre valide

                if((mail[i]>='a' && mail[i]<='z')|| (mail[i]>='A' && mail[i]<='Z') || mail[i]=='-'|| strstr(mail,"@")|| strstr(mail,".")){
                        continue;

                }
                else{
                    puts("Caracteres speciaux ,chiffre,lettre avec accents,ESPACES detecter!!!\n");
                    printf("caracteres trouver -> %c \n",mail[i]);
                    valider = 1;
                       return valider;


            }

            }

                d.occurrence1 = 0;
                d.occurrence2 = 0;
                //verification de la validité de l'adresse mail saisie
                        for(int i  = 0; mail[i] != '\0'; i++)
                        {
                               if(mail[i] == '@'){
                                   d.occurrence1++;
                               }
                               if(mail[i] == '.'){
                                   d.occurrence2++;
                               }
                        }
                        switch(d.occurrence1){
                        case 1:
                            break;
                        default:
                            printf("vous pouvez utiliser qu'un seul @ pour votre adresse mail\n");

                        }
                         switch(d.occurrence2){
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
else{
printf("l'adresse doit etre obligatoirement renseigner !!! \n");
    valider = 1;
    return valider;
}

}


int saisiePROFESSION(const char * profession){
  /*Verifie si la saisie de l'utilisateur est bonne */
            for(int i = 0;i<strlen(profession);i++){
            if((profession[i]>='a' && profession[i]<='z') || (profession[i]>='A' && profession[i]<='Z')|| profession[i]=='-'){
                    continue;

            }
            else{
                puts("Caracteres speciaux ,chiffre,lettre avec accents,ESPACES detecter!!!\n");
                printf("caracteres trouver -> %c \n",profession[i]);

            }
        }

}

/** \brief
 *
 * \param Id_client const Client*
 * \return void
 *
 */
int ajouter_Client(const char *annuaireTXT,const char *nom_p,const char *prenom_p,const char *code_postal_p,const char *ville_p,const char *telephone_p,const char *mel_p,const char *profession_p){
//cette fonction compare mel_p donner en entr�e et verifier si elle est deja pr�sente dans le fichier
//cette fonction permet a l'utilisateur d'entrer ces donnes -> utilsation de fgets pour les chaines de  caracteres
Client ptr;
occurence d;
int verif = 0;

//cela evite de faire sauter la saisie de l'utilisateur pour le menu
FILE*resultat_ajouter;
resultat_ajouter = fopen("resultat_ajouter.txt","w");//ouverture du fichier ecriture pour ecrire le nouveau client
FILE *annuaire = fopen("annuaire.csv", "r+");//ouverture du fichier lecture pour  compter le nombre de ligne
FILE *file = fopen(annuaireTXT, "r");//ouverture du fichier en lecture
char *temp = (char *) malloc (100*sizeof(char));//j'alloue une taille de 100 octets etant donnes qu'un char = 1 octet
if(file == NULL){// si valeur renvoyer est NULL alors le fichier n'existe ou ne peux pas etre ouvert
    perror("erreur d'ouverture du fichier !");
    exit(EXIT_FAILURE);
}
if(annuaire == NULL){// si valeur renvoyer est NULL alors le fichier n'existe ou ne peux pas etre ouvert
    perror("erreur d'ouverture du fichier !");
    exit(EXIT_FAILURE);
}
if(resultat_ajouter == NULL){// si valeur renvoyer est NULL alors le fichier n'existe ou ne peux pas etre ouvert
    perror("erreur d'ouverture du fichier !");
    exit(EXIT_FAILURE);
}
ptr.donnes= (char**) malloc( (sizeof(char*[1000])));
        if(ptr.donnes == NULL){
            printf("erreur allocation");
        }
        for(int i=0; i<1000; i++){


            ptr.donnes[i] = (char*) malloc(sizeof(char*[1000]));

        }


int ligne =0;
//cette boucle permet de compter le nombre de ligne dans le fichier annuaire.csv
while(!feof(annuaire)&& !ferror(annuaire)){//si ferror est vrai alors le fichier n'est pas lu = probleme et que on est pas a la fin du fichier
            if(fgets(ptr.donnes[ligne],1000,annuaire)!= NULL){//lire une chaine de caractere
                    fprintf(resultat_ajouter,"%s\n",ptr.donnes[ligne]);//copie les lignes dans le fichier donn� en sortie
                ligne++;//incremente le nombre de ligne pour passer d'une ligne a une autre
            }
}
    for(int i=0; i<ligne; i++){


            free(ptr.donnes[i]);
            ptr.donnes[i] = NULL;

        }

free(ptr.donnes);
ptr.donnes = NULL;

printf("le nombre de ligne du fichier : %d\n",ligne);
 int cpt = 0;
    //p.mel_p = (char *) calloc (256,sizeof(char));//utilisation de l'allocation dynamique avec calloc -> initialise tout a 0

struct Client_ *p = (struct Client_*)calloc(ligne+1,sizeof(struct Client_));
         int c =fgetc(file);
while(cpt<ligne){

        p[cpt].nom_p = (char *) calloc (256,sizeof(char));
        p[cpt].prenom_p = (char *) calloc (256,sizeof(char));
        p[cpt].ville_p = (char *) calloc (256,sizeof(char));
        p[cpt].mel_p = (char *) calloc (256,sizeof(char));
        p[cpt].profession_p = (char *) calloc (256,sizeof(char));
    for(int j= 0;;j++){
             if(c==',' ||c=='\n'){

                c = fgetc(file);//lis le caractere suivant
                //realloue la place avec le compteur j qui represente le nombre de cases du tableau
                p[cpt].nom_p = (char*)realloc(p[cpt].nom_p,j+1*sizeof(char));
                    break;
            }
        // Ins�rez le caract�re lu dans le tableau et incr�mentez le compteur

        p[cpt].nom_p[j] = (char) c;

        //lis le caractere suivant
        c = fgetc(file);
    }

      for(int j= 0;;j++){
             if(c==',' ||c=='\n'){

                c = fgetc(file);//lis le caractere suivant
                //realloue la place avec le compteur j qui represente le nombre de cases du tableau
                p[cpt].prenom_p = (char*)realloc(p[cpt].prenom_p,j+1*sizeof(char));
                    break;
            }
        // Ins�rez le caract�re lu dans le tableau et incr�mentez le compteur

        p[cpt].prenom_p[j] = (char) c;
            //lis le caractere suivant
        c = fgetc(file);
    }
        for(int j= 0;;j++){
             if(c==',' ||c=='\n'){

                c = fgetc(file);//lis le caractere suivant
                    break;
            }
        // Ins�rez le caract�re lu dans le tableau et incr�mentez le compteur

        p[cpt].code_postal_p[j] = (char) c;
            //lis le caractere suivant
        c = fgetc(file);
    }
          for(int j= 0;;j++){
             if(c==',' ||c=='\n'){

                c = fgetc(file);//lis le caractere suivant
                //realloue la place avec le compteur j qui represente le nombre de cases du tableau
                p[cpt].ville_p = (char*)realloc(p[cpt].ville_p,j+1*sizeof(char));
                    break;
            }
        // Ins�rez le caract�re lu dans le tableau et incr�mentez le compteur

        p[cpt].ville_p[j] = (char) c;
        //lis le caractere suivant
        c = fgetc(file);
    }
    for(int j= 0;;j++){
             if(c==',' ||c=='\n'){

                c = fgetc(file);//lis le caractere suivant
                    break;
            }
        // Ins�rez le caract�re lu dans le tableau et incr�mentez le compteur

        p[cpt].telephone_p[j] = (char) c;
            //lis le caractere suivant
        c = fgetc(file);
    }

        for(int j= 0;;j++){
             if(c==',' ||c=='\n'){

                c = fgetc(file);//lis le caractere suivant
                //realloue la place avec le compteur j qui represente le nombre de cases du tableau
                p[cpt].mel_p = (char*)realloc(p[cpt].mel_p,j+1*sizeof(char));
                    break;
            }
        // Ins�rez le caract�re lu dans le tableau et incr�mentez le compteur

        p[cpt].mel_p[j] = (char) c;
            //lis le caractere suivant
        c = fgetc(file);
    }

    assert(stricmp(mel_p, p[cpt].mel_p) != 0);
      if (stricmp(mel_p, p[cpt].mel_p) == 0) {
            printf("l'adresse existe deja !\n");
           // rewind(file);//revient au debut du fichier si l'adresse existe deja
            //goto MEL;//retour a la saisie
            verif = 1;
            return verif;

      }

         for(int j= 0;;j++){
             if(c==',' ||c=='\n'){

                c = fgetc(file);//lis le caractere suivant
                //realloue la place avec le compteur j qui represente le nombre de cases du tableau
                p[cpt].profession_p = (char*)realloc(p[cpt].profession_p,j+1*sizeof(char));
                    break;
            }
        // Ins�rez le caract�re lu dans le tableau et incr�mentez le compteur

        p[cpt].profession_p[j] = (char) c;
            //lis le caractere suivant
        c = fgetc(file);
    }
cpt++;//incremente le compteur pour passer a la structure suivante

}

fprintf(resultat_ajouter,"%s,%s,%s,%s,%s,%s,%s",nom_p,prenom_p,code_postal_p,ville_p,telephone_p,mel_p,profession_p);

fclose(resultat_ajouter);






}








/** \brief La fonction determine si l'annuaire donné en entree est valide suivant differentes contraintes
 *
 * \param[in] Client*d const
 * \param size int
 * \return void
 *
 */
void Verifier_validite_annuaire(const Client*d,int size){
fgetc(stdin);
Client r;
FILE *file = fopen("annuaire.txt", "r");
FILE *annuaire = fopen("annuaire.csv", "r");

    // Vérifiez si le fichier a été ouvert correctement
    if (file == NULL) {// si valeur renvoyer est NULL alors le fichier n'existe ou ne peux pas etre ouvert
        perror("Erreur lors de l'ouverture du fichier");
        exit(EXIT_FAILURE);
    }
     if (annuaire == NULL) {// si valeur renvoyer est NULL alors le fichier n'existe ou ne peux pas etre ouvert
        perror("Erreur lors de l'ouverture du fichier");
        exit(EXIT_FAILURE);
    }



r.donnes= (char**) malloc( (sizeof(char*[1000])));
        if(r.donnes == NULL){
            printf("erreur allocation");
        }
        for(int i=0; i<1000; i++){


            r.donnes[i] = (char*) malloc(sizeof(char*[1000]));

        }
int cpt = 0;
int ligne =0;
while(!feof(annuaire)&& !ferror(annuaire)){//si ferror est vrai alors le fichier n'est pas lu = probleme et que on est pas a la fin du fichier
            if(fgets(r.donnes[ligne],1000,annuaire)!= NULL){//lire une chaine de caractere
                ligne++;//incremente le nombre de ligne pour passer d'une ligne a une autre
            }
}
fclose(annuaire);//ferme le fichier
printf("le nombre de ligne du fichier : %d\n",ligne);
              /*struct Client_ est une structure qui represente un client,
              et p est un pointeur vers un tableau de  struct Client_
              Calloc initialise tout a zero*/
struct Client_ *p = (struct Client_*)calloc(ligne+1,sizeof(struct Client_));

int i = 0;
// Utilise fgetc pour lire chaque caractère du fichier jusqu'à ce que, l'on atteind la fin du fichier
int c = fgetc(file);

while(cpt<ligne){
        //alloue une place de 256 caracteres -> il faut rajouter realloc
        p[cpt].nom_p = (char *) calloc (256,sizeof(char));
        p[cpt].prenom_p = (char *) calloc (256,sizeof(char));
        p[cpt].ville_p = (char *) calloc (256,sizeof(char));
        p[cpt].mel_p = (char *) calloc (256,sizeof(char));
        p[cpt].profession_p = (char *) calloc (256,sizeof(char));
        // j'tilise un compteur pour suivre l'emplacement ou chaque caractère doit etre inserer dans le tableau
    for(int j= 0;;j++){
             if(c==',' ||c=='\n'){

                c = fgetc(file);
                p[cpt].nom_p = (char*)realloc(p[cpt].nom_p,j+1*sizeof(char));
                    break;
            }
        // Insérez le caractère lu dans le tableau et incrémentez le compteur

        p[cpt].nom_p[j] = (char) c;

        //lis le caractere suivant
        c = fgetc(file);
    }

      for(int j= 0;;j++){
             if(c==',' ||c=='\n'){

                c = fgetc(file);
                p[cpt].prenom_p = (char*)realloc(p[cpt].prenom_p,j+1*sizeof(char));
                    break;
            }
        // Insérez le caractère lu dans le tableau et incrémentez le compteur

        p[cpt].prenom_p[j] = (char) c;
            //lis le caractere suivant
        c = fgetc(file);
    }
        for(int j= 0;;j++){
             if(c==',' ||c=='\n'){

                c = fgetc(file);
                    break;
            }
        // Insérez le caractère lu dans le tableau et incrémentez le compteur

        p[cpt].code_postal_p[j] = (char) c;
            //lis le caractere suivant
        c = fgetc(file);
    }
          for(int j= 0;;j++){
             if(c==',' ||c=='\n'){

                c = fgetc(file);
                p[cpt].ville_p = (char*)realloc(p[cpt].ville_p,j+1*sizeof(char));
                    break;
            }
        // Insérez le caractère lu dans le tableau et incrémentez le compteur

        p[cpt].ville_p[j] = (char) c;
        //lis le caractere suivant
        c = fgetc(file);
    }
    for(int j= 0;;j++){
             if(c==',' ||c=='\n'){

                c = fgetc(file);
                    break;
            }
        // Insérez le caractère lu dans le tableau et incrémentez le compteur

        p[cpt].telephone_p[j] = (char) c;
            //lis le caractere suivant
        c = fgetc(file);
    }

        for(int j= 0;;j++){
             if(c==',' ||c=='\n'){

                c = fgetc(file);
                p[cpt].mel_p = (char*)realloc(p[cpt].mel_p,j+1*sizeof(char));
                    break;
            }
        // Insérez le caractère lu dans le tableau et incrémentez le compteur

        p[cpt].mel_p[j] = (char) c;
            //lis le caractere suivant
        c = fgetc(file);
    }
         for(int j= 0;;j++){
             if(c==',' ||c=='\n'){

                c = fgetc(file);
                p[cpt].profession_p = (char*)realloc(p[cpt].profession_p,j+1*sizeof(char));
                    break;
            }
        // Insérez le caractère lu dans le tableau et incrémentez le compteur

        p[cpt].profession_p[j] = (char) c;
            //lis le caractere suivant
        c = fgetc(file);
    }
cpt++;//incremente le compteur pour passer a la structure suivante

}
//inspiration du tri a bulle pour verifier si il ya des doublons d'adresse
   int j = 0;
   i=0;
  for (i = 0; i < cpt; i++) {
    for (j = i+1 ;j < cpt; j++) {
      if (stricmp(p[i].mel_p, p[j].mel_p) == 0) {
        printf("il ya des doublons :");
        printf("%s et %s \n",p[i].mel_p,p[j].mel_p);
      }
    }
  }


//ferme le fichier
fclose(file);
//libere la memoire
       for(int i=0; i<ligne; i++){


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

}



/** \brief la fonction tri_client_par_nom prends en sortie l'annuaire trier en fonction du nom
 *
 * \param[in] le nom_annuaire
 * \param[in] Client*d const
 * \param[in] size un entier correspondant au nombre de ligne du fichier annuaire
 *
 *\param[out]  les donnes sont donné en sortie dans le fichier resultat_afficher_tries_nom
                dans le meme repertoire que l'executable
 * \return void
 *
 */
void tri_client_par_nom(const char *annuaireTRI){
    fgetc(stdin);
    Client r;
    FILE *file = fopen("annuaire.txt", "r");
    FILE *annuaire = fopen("annuaire.csv", "r");
    FILE *Resultat = fopen(annuaireTRI, "w");
    // Vérifiez si le fichier a été ouvert correctement
    if (file == NULL) {// si valeur renvoyer est NULL alors le fichier n'existe ou ne peux pas etre ouvert
        perror("Erreur lors de l'ouverture du fichier");
        exit(EXIT_FAILURE);
    }
if (Resultat == NULL) {// si valeur renvoyer est NULL alors le fichier n'existe ou ne peux pas etre ouvert
        perror("Erreur lors de l'ouverture du fichier");
        exit(EXIT_FAILURE);
    }
    if (annuaire == NULL) {// si valeur renvoyer est NULL alors le fichier n'existe ou ne peux pas etre ouvert
        perror("Erreur lors de l'ouverture du fichier");
        exit(EXIT_FAILURE);
    }




r.donnes= (char**) malloc( (sizeof(char*[1000])));//alloue un tableau de 1000 pointeur -> 1000 char
        if(r.donnes == NULL){
            printf("erreur allocation");
        }
        for(int i=0; i<1000; i++){


            r.donnes[i] = (char*) malloc(sizeof(char*[1000]));//alloue un tableau de 1000 char

        }

int cpt = 0;
int ligne =0;
//utilisation d'un tableau a deux dimension pour compter le nombre de ligne
while(!feof(annuaire)&& !ferror(annuaire)){//si ferror est vrai alors le fichier n'est pas lu = probleme et que on est pas a la fin du fichier
        //au cas ou il ya des \n
            if(fgets(r.donnes[ligne],1000,annuaire)!= NULL){//lire une chaine de caractere

                ligne++;//incremente le nombre de ligne pour passer d'une ligne a une autre

            }

}
fclose(annuaire);
printf("le nombre de ligne du fichier : %d\n",ligne);
              /*struct Client_ est une structure qui represente un client,
              et p est un pointeur vers un tableau de  struct Client_
              Calloc initialise tout a zero*/
struct Client_ *p = (struct Client_*)calloc(ligne+1,sizeof(struct Client_));

    int i = 0;

    // Utilisez fgetc pour lire chaque caractère du fichier jusqu'à ce que vous atteigniez la fin du fichier

    int c = fgetc(file);

while(cpt<ligne){

        p[cpt].nom_p = (char *) calloc (256,sizeof(char));
        p[cpt].prenom_p = (char *) calloc (256,sizeof(char));
        p[cpt].ville_p = (char *) calloc (256,sizeof(char));
        p[cpt].mel_p = (char *) calloc (256,sizeof(char));
        p[cpt].profession_p = (char *) calloc (256,sizeof(char));
    for(int j= 0;;j++){
             if(c==',' ||c=='\n'){

                c = fgetc(file);
                p[cpt].nom_p = (char*)realloc(p[cpt].nom_p,j+1*sizeof(char));
                    break;
            }
        // Insérez le caractère lu dans le tableau et incrémentez le compteur

        p[cpt].nom_p[j] = (char) c;

        //lis le caractere suivant
        c = fgetc(file);
    }

      for(int j= 0;;j++){
             if(c==',' ||c=='\n'){

                c = fgetc(file);
                p[cpt].prenom_p = (char*)realloc(p[cpt].prenom_p,j+1*sizeof(char));
                    break;
            }
        // Insérez le caractère lu dans le tableau et incrémentez le compteur

        p[cpt].prenom_p[j] = (char) c;
            //lis le caractere suivant
        c = fgetc(file);
    }
        for(int j= 0;;j++){
             if(c==',' ||c=='\n'){

                c = fgetc(file);
                    break;
            }
        // Insérez le caractère lu dans le tableau et incrémentez le compteur

        p[cpt].code_postal_p[j] = (char) c;
            //lis le caractere suivant
        c = fgetc(file);
    }
          for(int j= 0;;j++){
             if(c==',' ||c=='\n'){

                c = fgetc(file);
                p[cpt].ville_p = (char*)realloc(p[cpt].ville_p,j+1*sizeof(char));
                    break;
            }
        // Insérez le caractère lu dans le tableau et incrémentez le compteur

        p[cpt].ville_p[j] = (char) c;
        //lis le caractere suivant
        c = fgetc(file);
    }
    for(int j= 0;;j++){
             if(c==',' ||c=='\n'){

                c = fgetc(file);
                    break;
            }
        // Insérez le caractère lu dans le tableau et incrémentez le compteur

        p[cpt].telephone_p[j] = (char) c;
            //lis le caractere suivant
        c = fgetc(file);
    }

        for(int j= 0;;j++){
             if(c==',' ||c=='\n'){

                c = fgetc(file);
                p[cpt].mel_p = (char*)realloc(p[cpt].mel_p,j+1*sizeof(char));
                    break;
            }
        // Insérez le caractère lu dans le tableau et incrémentez le compteur

        p[cpt].mel_p[j] = (char) c;
            //lis le caractere suivant
        c = fgetc(file);
    }
         for(int j= 0;;j++){
             if(c==',' ||c=='\n'){

                c = fgetc(file);
                p[cpt].profession_p = (char*)realloc(p[cpt].profession_p,j+1*sizeof(char));
                    break;
            }
        // Insérez le caractère lu dans le tableau et incrémentez le compteur

        p[cpt].profession_p[j] = (char) c;
            //lis le caractere suivant
        c = fgetc(file);
    }
cpt++;//incremente le compteur pour passer a la structure suivante

}
// inspiration du tri a bulle pour trier les donnes en fonction du nom

   i=0;
   int echange = 1;
   int debut  = 0;
  struct Client_ temp;

      while (echange) {
        echange = 0;

//parcourt le tableau 2 fois-> dans le sens normal et dans le sens inverse
         for (int i = debut; i < cpt-1; i++) {
                for(int j = i+1;j< cpt-1;j++){
                    if (stricmp(p[i].nom_p, p[j].nom_p) > 0) {
                         temp = p[i];
                        p[i] = p[j];
                        p[j] = temp;
                        echange = 1;
                    }
                }

        }
        if (!echange){
            break;
        }
        echange = 0;
        cpt--;
           for (int i = cpt ; i >= debut; i--) {
              for(int j = i+1;j>= debut;j--){
                    if (stricmp(p[i].nom_p, p[j].nom_p) > 0) {
                         temp = p[i];
                        p[i] = p[j];
                        p[j] = temp;
                        echange = 1;
                    }
                }
        }
        debut++;
    }
//affiche les valeurs et ecrit dans le fichier donné en sortie
  for (i = 0; i < cpt; i++) {
  printf("%s,%s,%s,%s,%s,%s,%s\n",p[i].nom_p,p[i].prenom_p,p[i].code_postal_p,p[i].ville_p,p[i].telephone_p,p[i].mel_p,p[i].profession_p);
  fprintf(Resultat,"%s,%s,%s,%s,%s,%s,%s\n",p[i].nom_p,p[i].prenom_p,p[i].code_postal_p,p[i].ville_p,p[i].telephone_p,p[i].mel_p,p[i].profession_p);
  }
//libere la memoire
       for(int i=0; i<ligne; i++){


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
fclose(file);
fclose(Resultat);
}
/** \brief Cette fonction compare les chaines **valchaine1** et  **valchaine2** donné dans la fonction filtrer_combiner_deux_champs
           avec les sous chaines pour ne garder que les donnes qui correspondent au filtre donné.\n
 *
 * \param[in] s1 char* chaine du champs numéro 1.
 * \param[in] sch1 char* sous-chaine  pour le champs numéro 1.
 * \param[in] s2 char* chaine du champs numéro 2.
 * \param[in] sch2 char* sous-chaine  pour le champs numéro 2.
 * \param[in] index int la position ou commence la comparaison des caracteres du champs numéro 1.
 * \param[in] index2 int la position ou commence la comparaison des caracteres du champs numéro 2.
 * \param[in] cpt int  compteur pour connaitre de nombre lignes contenu dans l'annuaire.
 *
 * \return  un entier **trouvee** pour la fonction filtrer_combiner_deux_champs
 *
 */
int Filtrer(char *s1,char *sch1,int index,int cpt){
int i ,j = 0;
int trouvee = 0;

for (i = index-1, j = 0; s1[i] != '\0' && sch1[j] != '\0'; i++, j++) {
    if (s1[i] != sch1[j]) {
        break;
    }
}

if (sch1[j] == '\0') {
         trouvee = 1;

} else {
        trouvee = 2;

}


return trouvee;


}

/** \brief Cette fonction filtre les données du fichier annuaire donné en entrée
           suivant 2 champs combiner **val_chaine1** et **val_chaine2**.
 *
 * \param[in] Id_client const Client* la structure qui contient les champs suivant :
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
 *
 *\param[out] le fichier resultat_filtrer_combiner_deux_champs donné en sortie contient les nouvelles données filtrer
 *
 * \return void
 *
 */
void Filtrer_combiner_deux_champs(const Client *Id_client,const char *annuaireTXT){
Client r;
    FILE *file = fopen(annuaireTXT, "r");
    FILE *annuaire = fopen("annuaire.csv", "r");
    FILE *resultat_filtrer_combiner_deux_champs = fopen("resultat_filtrer_combiner_deux_champs.txt", "w");
    if(file == NULL){// si valeur renvoyer est NULL alors le fichier n'existe ou ne peux pas etre ouvert
        perror("Erreur d'ouverture du fichier !");
        exit(EXIT_FAILURE);
    }
    if (annuaire == NULL) {// si valeur renvoyer est NULL alors le fichier n'existe ou ne peux pas etre ouvert
        perror("Erreur lors de l'ouverture du fichier");
        exit(EXIT_FAILURE);
    }
    if (resultat_filtrer_combiner_deux_champs == NULL) {// si valeur renvoyer est NULL alors le fichier n'existe ou ne peux pas etre ouvert
        perror("Erreur lors de l'ouverture du fichier");
        exit(EXIT_FAILURE);
    }

r.donnes= (char**) malloc( (sizeof(char*[1000])));
        if(r.donnes == NULL){
            printf("erreur allocation");
        }
        for(int i=0; i<1000; i++){


            r.donnes[i] = (char*) malloc(sizeof(char*[1000]));

        }
int cpt = 0;
int ligne =0;
//utilisation d'un tableau a deux dimension pour compter le nombre de ligne
while(!feof(annuaire)&& !ferror(annuaire)){//si ferror est vrai alors le fichier n'est pas lu = probleme et que on est pas a la fin du fichier
            if(fgets(r.donnes[ligne],1000,annuaire)!= NULL){//lire une chaine de caractere
                ligne++;//incremente le nombre de ligne pour passer d'une ligne a une autre
            }
}
fclose(annuaire);
  for(int i=0; i<ligne; i++){


            free(r.donnes[i]);
            r.donnes[i] = NULL;

        }

free(r.donnes);
r.donnes = NULL;

              /*struct Client_ est une structure qui represente un client,
              et p est un pointeur vers un tableau de  struct Client_
              Calloc initialise tout a zero*/
struct Client_ *p = (struct Client_*)calloc(ligne+1,sizeof(struct Client_));
int c = fgetc(file);
while(cpt<ligne){
        //alloue une place de 256 caracteres -> il faut rajouter realloc
        p[cpt].nom_p = (char *) calloc (256,sizeof(char));
        p[cpt].prenom_p = (char *) calloc (256,sizeof(char));
        p[cpt].ville_p = (char *) calloc (256,sizeof(char));
        p[cpt].mel_p = (char *) calloc (256,sizeof(char));
        p[cpt].profession_p = (char *) calloc (256,sizeof(char));
    for(int j= 0;;j++){
             if(c==',' ||c=='\n'){

                c = fgetc(file);
                p[cpt].nom_p = (char*)realloc(p[cpt].nom_p,j+1*sizeof(char));
                    break;
            }
        // Insérez le caractère lu dans le tableau et incrémentez le compteur
            if(c>='A'&& c<='Z'){c=c-'A'+'a';}
        p[cpt].nom_p[j] = (char) c;

        //lis le caractere suivant
        c = fgetc(file);
    }


      for(int j= 0;;j++){
             if(c==',' ||c=='\n'){

                c = fgetc(file);
                p[cpt].prenom_p = (char*)realloc(p[cpt].prenom_p,j+1*sizeof(char));
                    break;
            }
        // Insérez le caractère lu dans le tableau et incrémentez le compteur
            if(c>='A'&& c<='Z'){c=c-'A'+'a';}
        p[cpt].prenom_p[j] = (char) c;
            //lis le caractere suivant
        c = fgetc(file);
    }
        for(int j= 0;;j++){
             if(c==',' ||c=='\n'){

                c = fgetc(file);
                    break;
            }
        // Insérez le caractère lu dans le tableau et incrémentez le compteur

        p[cpt].code_postal_p[j] = (char) c;
            //lis le caractere suivant
        c = fgetc(file);
    }
          for(int j= 0;;j++){
             if(c==',' ||c=='\n'){

                c = fgetc(file);
                p[cpt].ville_p = (char*)realloc(p[cpt].ville_p,j+1*sizeof(char));
                    break;
            }
        // Insérez le caractère lu dans le tableau et incrémentez le compteur
            if(c>='A'&& c<='Z'){c=c-'A'+'a';}
        p[cpt].ville_p[j] = (char) c;
        //lis le caractere suivant
        c = fgetc(file);
    }
    for(int j= 0;;j++){
             if(c==',' ||c=='\n'){

                c = fgetc(file);
                    break;
            }
        // Insérez le caractère lu dans le tableau et incrémentez le compteur

        p[cpt].telephone_p[j] = (char) c;
            //lis le caractere suivant
        c = fgetc(file);
    }

        for(int j= 0;;j++){
             if(c==',' ||c=='\n'){

                c = fgetc(file);
                p[cpt].mel_p = (char*)realloc(p[cpt].mel_p,j+1*sizeof(char));
                    break;
            }
        // Insérez le caractère lu dans le tableau et incrémentez le compteur
            if(c>='A'&& c<='Z'){c=c-'A'+'a';}
        p[cpt].mel_p[j] = (char) c;
            //lis le caractere suivant
        c = fgetc(file);
    }
         for(int j= 0;;j++){
             if(c==',' ||c=='\n'){

                c = fgetc(file);
                p[cpt].profession_p = (char*)realloc(p[cpt].profession_p,j+1*sizeof(char));
                    break;
            }
        // Insérez le caractère lu dans le tableau et incrémentez le compteur
        if(c>='A'&& c<='Z'){c=c-'A'+'a';}
        p[cpt].profession_p[j] = (char) c;
            //lis le caractere suivant
        c = fgetc(file);
    }
cpt++;//incremente le compteur pour passer a la structure suivante

}
int index = 0;
int index2 = 0;
int critere1 = 0;
int critere2 = 0;
printf("le nombre de ligne du fichier : %d\n",ligne);
CRITERE:{
printf("choisissez vos 2 criteres \n");
puts("critere n 1: \n");
scanf("%d",&critere1);
puts("critere n 2: \n");
scanf("%d",&critere2);
}
int choix = 100*critere1 + 10*critere2 ;

switch(choix){
case 110:
    puts("incorrect ! \n");
    goto CRITERE;
break;
case 220:
    puts("incorrect ! \n");
    goto CRITERE;
break;
case 330:
    puts("incorrect ! \n");
    goto CRITERE;
break;
case 440:
    puts("incorrect ! \n");
    goto CRITERE;
break;
case 550:
    puts("incorrect ! \n");
    goto CRITERE;
break;
case 660:
    puts("incorrect ! \n");
    goto CRITERE;
break;
case 770:
    puts("incorrect ! \n");
    goto CRITERE;
break;

}
char ch[256];
char ch2[256];
printf("entrer la position ou commence la chaine 1 : \n");
scanf("%d",&index);
printf("entrer la premiere chaine : \n");
fgetc(stdin);
gets(ch);
assert(ch[0]!='\0');
printf("entrer la position ou commence la chaine 2 : \n");
scanf("%d",&index2);
printf("entrer la deuxieme chaine : \n");
fgetc(stdin);
gets(ch2);
assert(ch2[0]!='\0');

for(int i = 0;ch[i];i++){

    if(ch[i]>='A' && ch[i]<='Z'){
        ch[i] =  ch[i] - 'A' +'a';
    }
}
for(int i = 0;ch[i];i++){

    if(ch2[i]>='A' && ch2[i]<='Z'){
        ch2[i] =  ch2[i] - 'A' +'a';
    }
}
printf("ch = %s\n",ch);
printf("ch = %s\n",ch2);
switch (choix)
{
  case 120:
    printf("nom et prenom\n");
    for(int i = 0;i<cpt;i++){
            if(Filtrer(p[i].nom_p,ch,index,cpt)==1 && Filtrer(p[i].prenom_p,ch2,index2,cpt)==1){
                //printf(" %s et %s  sont  des sous chaine\n",p[i].nom_p,p[i].prenom_p);
                fprintf(resultat_filtrer_combiner_deux_champs,"%s,%s,%s,%s,%s,%s,%s\n",p[i].nom_p,p[i].prenom_p,p[i].code_postal_p,p[i].ville_p,p[i].telephone_p,p[i].mel_p,p[i].profession_p);
            }

    }
    break;
  case 130:
    printf("nom et codePostal\n");
     for(int i = 0;i<cpt;i++){
            if(Filtrer(p[i].nom_p,ch,index,cpt)==1 && Filtrer(p[i].code_postal_p,ch2,index2,cpt)==1){
                //printf(" %s et %s  sont  des sous chaine\n",p[i].nom_p,p[i].prenom_p);
                fprintf(resultat_filtrer_combiner_deux_champs,"%s,%s,%s,%s,%s,%s,%s\n",p[i].nom_p,p[i].prenom_p,p[i].code_postal_p,p[i].ville_p,p[i].telephone_p,p[i].mel_p,p[i].profession_p);
            }
    }
    break;
  case 140 :
    printf("nom et ville\n");
         for(int i = 0;i<cpt;i++){
            if(Filtrer(p[i].nom_p,ch,index,cpt)==1 && Filtrer(p[i].ville_p,ch2,index2,cpt) == 1){
                //printf(" %s et %s  sont  des sous chaine\n",p[i].nom_p,p[i].prenom_p);
                fprintf(resultat_filtrer_combiner_deux_champs,"%s,%s,%s,%s,%s,%s,%s\n",p[i].nom_p,p[i].prenom_p,p[i].code_postal_p,p[i].ville_p,p[i].telephone_p,p[i].mel_p,p[i].profession_p);
            }
          }
    break;
  case 150 :
   printf("nom et telephone\n");
     for(int i = 0;i<cpt;i++){
            if(Filtrer(p[i].nom_p,ch,index,cpt)==1 && Filtrer(p[i].telephone_p,ch2,index2,cpt)==1){
                //printf(" %s et %s  sont  des sous chaine\n",p[i].nom_p,p[i].prenom_p);
                fprintf(resultat_filtrer_combiner_deux_champs,"%s,%s,%s,%s,%s,%s,%s\n",p[i].nom_p,p[i].prenom_p,p[i].code_postal_p,p[i].ville_p,p[i].telephone_p,p[i].mel_p,p[i].profession_p);
            }
    }
    break;
  case 160 :
    printf("nom et mail\n");
       for(int i = 0;i<cpt;i++){
            if(Filtrer(p[i].nom_p,ch,index,cpt)==1 && Filtrer(p[i].mel_p,ch2,index2,cpt)==1){
                //printf(" %s et %s  sont  des sous chaine\n",p[i].nom_p,p[i].prenom_p);
                fprintf(resultat_filtrer_combiner_deux_champs,"%s,%s,%s,%s,%s,%s,%s\n",p[i].nom_p,p[i].prenom_p,p[i].code_postal_p,p[i].ville_p,p[i].telephone_p,p[i].mel_p,p[i].profession_p);
            }
    }
    break;
    case 170 :
    printf("nom et profession\n");
        for(int i = 0;i<cpt;i++){
            if(Filtrer(p[i].nom_p,ch,index,cpt)==1 && Filtrer(p[i].profession_p,ch2,index2,cpt)==1){
                //printf(" %s et %s  sont  des sous chaine\n",p[i].nom_p,p[i].prenom_p);
                fprintf(resultat_filtrer_combiner_deux_champs,"%s,%s,%s,%s,%s,%s,%s\n",p[i].nom_p,p[i].prenom_p,p[i].code_postal_p,p[i].ville_p,p[i].telephone_p,p[i].mel_p,p[i].profession_p);
            }
    }
    break;
  case 230:
      printf("prenom et code postal\n");
    for(int i = 0;i<cpt;i++){
            if(Filtrer(p[i].prenom_p,ch,index,cpt)==1 && Filtrer(p[i].code_postal_p,ch2,index2,cpt)==1){
                //printf(" %s et %s  sont  des sous chaine\n",p[i].nom_p,p[i].prenom_p);
                fprintf(resultat_filtrer_combiner_deux_champs,"%s,%s,%s,%s,%s,%s,%s\n",p[i].nom_p,p[i].prenom_p,p[i].code_postal_p,p[i].ville_p,p[i].telephone_p,p[i].mel_p,p[i].profession_p);
            }
    }
    break;
    case 240:
         printf("prenom et ville\n");
          for(int i = 0;i<cpt;i++){
            if(Filtrer(p[i].prenom_p,ch,index,cpt)==1 && Filtrer(p[i].ville_p,ch2,index2,cpt)==1){
                //printf(" %s et %s  sont  des sous chaine\n",p[i].nom_p,p[i].prenom_p);
                fprintf(resultat_filtrer_combiner_deux_champs,"%s,%s,%s,%s,%s,%s,%s\n",p[i].nom_p,p[i].prenom_p,p[i].code_postal_p,p[i].ville_p,p[i].telephone_p,p[i].mel_p,p[i].profession_p);
            }
    }
    break;
    case 250:
         printf("prenom et telephone\n");
               for(int i = 0;i<cpt;i++){
            if(Filtrer(p[i].prenom_p,ch,index,cpt)==1  && Filtrer(p[i].telephone_p,ch2,index2,cpt)==1 ){
                //printf(" %s et %s  sont  des sous chaine\n",p[i].nom_p,p[i].prenom_p);
                fprintf(resultat_filtrer_combiner_deux_champs,"%s,%s,%s,%s,%s,%s,%s\n",p[i].nom_p,p[i].prenom_p,p[i].code_postal_p,p[i].ville_p,p[i].telephone_p,p[i].mel_p,p[i].profession_p);
            }
    }
    break;
    case 260:
         printf("prenom et mail\n");
    for(int i = 0;i<cpt;i++){
            if(Filtrer(p[i].prenom_p,ch,index,cpt)==1  && Filtrer(p[i].mel_p,ch2,index2,cpt)==1 ){
                //printf(" %s et %s  sont  des sous chaine\n",p[i].nom_p,p[i].prenom_p);
                fprintf(resultat_filtrer_combiner_deux_champs,"%s,%s,%s,%s,%s,%s,%s\n",p[i].nom_p,p[i].prenom_p,p[i].code_postal_p,p[i].ville_p,p[i].telephone_p,p[i].mel_p,p[i].profession_p);
            }
    }
    break;
    case 270:
         printf("prenom et profession\n");
    for(int i = 0;i<cpt;i++){
            if(Filtrer(p[i].prenom_p,ch,index,cpt)==1 && Filtrer(p[i].profession_p,ch2,index2,cpt)==1 ){
                //printf(" %s et %s  sont  des sous chaine\n",p[i].nom_p,p[i].prenom_p);
                fprintf(resultat_filtrer_combiner_deux_champs,"%s,%s,%s,%s,%s,%s,%s\n",p[i].nom_p,p[i].prenom_p,p[i].code_postal_p,p[i].ville_p,p[i].telephone_p,p[i].mel_p,p[i].profession_p);
            }
    }
    break;
    case 340:
        printf("code postal et ville\n");
            for(int i = 0;i<cpt;i++){
            if(Filtrer(p[i].code_postal_p,ch,index,cpt)==1 && Filtrer(p[i].ville_p,ch2,index2,cpt)==1 ){
                //printf(" %s et %s  sont  des sous chaine\n",p[i].nom_p,p[i].prenom_p);
                fprintf(resultat_filtrer_combiner_deux_champs,"%s,%s,%s,%s,%s,%s,%s\n",p[i].nom_p,p[i].prenom_p,p[i].code_postal_p,p[i].ville_p,p[i].telephone_p,p[i].mel_p,p[i].profession_p);
            }
    }
    break;
     case 350:
         printf("code postal et telephone\n");
    for(int i = 0;i<cpt;i++){
            if(Filtrer(p[i].code_postal_p,ch,index,cpt)==1 && Filtrer(p[i].telephone_p,ch2,index2,cpt)==1){
                //printf(" %s et %s  sont  des sous chaine\n",p[i].nom_p,p[i].prenom_p);
                fprintf(resultat_filtrer_combiner_deux_champs,"%s,%s,%s,%s,%s,%s,%s\n",p[i].nom_p,p[i].prenom_p,p[i].code_postal_p,p[i].ville_p,p[i].telephone_p,p[i].mel_p,p[i].profession_p);
            }
    }
    break;
     case 360:
         printf("code postal et mail\n");
    for(int i = 0;i<cpt;i++){
            if(Filtrer(p[i].code_postal_p,ch,index,cpt)==1 && Filtrer(p[i].mel_p,ch2,index2,cpt)==1){
                //printf(" %s et %s  sont  des sous chaine\n",p[i].nom_p,p[i].prenom_p);
                fprintf(resultat_filtrer_combiner_deux_champs,"%s,%s,%s,%s,%s,%s,%s\n",p[i].nom_p,p[i].prenom_p,p[i].code_postal_p,p[i].ville_p,p[i].telephone_p,p[i].mel_p,p[i].profession_p);
            }
    }
    break;
       case 370:
           printf("code postal et profession\n");
    for(int i = 0;i<cpt;i++){
            if(Filtrer(p[i].code_postal_p,ch,index,cpt)==1 && Filtrer(p[i].profession_p,ch2,index2,cpt)==1){
                //printf(" %s et %s  sont  des sous chaine\n",p[i].nom_p,p[i].prenom_p);
                fprintf(resultat_filtrer_combiner_deux_champs,"%s,%s,%s,%s,%s,%s,%s\n",p[i].nom_p,p[i].prenom_p,p[i].code_postal_p,p[i].ville_p,p[i].telephone_p,p[i].mel_p,p[i].profession_p);
            }
    }
    break;
     case 450:
         printf("ville et telephone\n");
    for(int i = 0;i<cpt;i++){
            if(Filtrer(p[i].ville_p,ch,index,cpt)==1 && Filtrer(p[i].telephone_p,ch2,index2,cpt)==1){
                //printf(" %s et %s  sont  des sous chaine\n",p[i].nom_p,p[i].prenom_p);
                fprintf(resultat_filtrer_combiner_deux_champs,"%s,%s,%s,%s,%s,%s,%s\n",p[i].nom_p,p[i].prenom_p,p[i].code_postal_p,p[i].ville_p,p[i].telephone_p,p[i].mel_p,p[i].profession_p);
            }
    }
    break;
    case 460:
        printf("ville et mail\n");
    for(int i = 0;i<cpt;i++){
            if(Filtrer(p[i].ville_p,ch,index,cpt)==1 && Filtrer(p[i].mel_p,ch2,index2,cpt)==1){
                //printf(" %s et %s  sont  des sous chaine\n",p[i].nom_p,p[i].prenom_p);
                fprintf(resultat_filtrer_combiner_deux_champs,"%s,%s,%s,%s,%s,%s,%s\n",p[i].nom_p,p[i].prenom_p,p[i].code_postal_p,p[i].ville_p,p[i].telephone_p,p[i].mel_p,p[i].profession_p);
            }
    }
    break;
    case 470:
        printf("ville et profession\n");
    for(int i = 0;i<cpt;i++){
            if(Filtrer(p[i].ville_p,ch,index,cpt)==1 && Filtrer(p[i].profession_p,ch2,index2,cpt)==1){
                //printf(" %s et %s  sont  des sous chaine\n",p[i].nom_p,p[i].prenom_p);
                fprintf(resultat_filtrer_combiner_deux_champs,"%s,%s,%s,%s,%s,%s,%s\n",p[i].nom_p,p[i].prenom_p,p[i].code_postal_p,p[i].ville_p,p[i].telephone_p,p[i].mel_p,p[i].profession_p);
            }
    }
    break;
    case 560:
        printf("telephone et mail\n");
    for(int i = 0;i<cpt;i++){
            if(Filtrer(p[i].telephone_p,ch,index,cpt)==1 && Filtrer(p[i].mel_p,ch2,index2,cpt)==1){
                //printf(" %s et %s  sont  des sous chaine\n",p[i].nom_p,p[i].prenom_p);
                fprintf(resultat_filtrer_combiner_deux_champs,"%s,%s,%s,%s,%s,%s,%s\n",p[i].nom_p,p[i].prenom_p,p[i].code_postal_p,p[i].ville_p,p[i].telephone_p,p[i].mel_p,p[i].profession_p);
            }
    }
    break;
    case 570:

        printf("telephone et profession\n");
    for(int i = 0;i<cpt;i++){
            if(Filtrer(p[i].telephone_p,ch,index,cpt)==1 && Filtrer(p[i].profession_p,ch2,index2,cpt)==1){
                //printf(" %s et %s  sont  des sous chaine\n",p[i].nom_p,p[i].prenom_p);
                fprintf(resultat_filtrer_combiner_deux_champs,"%s,%s,%s,%s,%s,%s,%s\n",p[i].nom_p,p[i].prenom_p,p[i].code_postal_p,p[i].ville_p,p[i].telephone_p,p[i].mel_p,p[i].profession_p);
            }
    }
    break;
    case 670:
        printf("mail  et profession\n");
          for(int i = 0;i<cpt;i++){
            if(Filtrer(p[i].mel_p,ch,index,cpt)==1 && Filtrer(p[i].profession_p,ch2,index2,cpt)==1){
                //printf(" %s et %s  sont  des sous chaine\n",p[i].nom_p,p[i].prenom_p);
                fprintf(resultat_filtrer_combiner_deux_champs,"%s,%s,%s,%s,%s,%s,%s\n",p[i].nom_p,p[i].prenom_p,p[i].code_postal_p,p[i].ville_p,p[i].telephone_p,p[i].mel_p,p[i].profession_p);
            }
    }
    break;
    default :
        printf("erreur de saisie !\n");
        goto CRITERE;
        break;


}


free(p->nom_p);
free(p->prenom_p);
free(p->ville_p);
free(p->mel_p);
free(p->profession_p);
free(p);
//ferme les fichiers
fclose(file);
fclose(annuaire);
fclose(resultat_filtrer_combiner_deux_champs);

}
