/**< \file fonction.c */
#include <stdio.h>
#include <stdlib.h>
#include<string.h>
#include<assert.h>
#include "fonction.h"
#define TAILLE 100


void Afficher_annuaire_clients(const Client *Id_client){
    fgetc(stdin);
 FILE*fichier;
 FILE*fp;

   fichier = fopen("annuaire.csv","r");//ouverture du fichier en mode lecture

   fp = fopen("annuaire.txt","w");
   char c;


   while(!feof(fichier)){



        c =fgetc(fichier);
        printf("%c",c);

   }

   fclose(fichier);//ferme le fichier

fclose(fp);

}


void Ecriture_annuaire_clients(const Client *Id_client){
//cette fonction ecrit copie les contenu du fichier annuaire.csv
FILE*fichier;
FILE*fp;

fichier = fopen("annuaire.csv","r");//ouverture du fichier en mode lecture

fp = fopen("annuaire.txt","w");//ouverture du fichier en mode lecture
   char c;


   while(!feof(fichier)){

//tant qu'on est pas a la fin du fichier on affiche les caracteres
        c =fgetc(fichier);
        fprintf(fp,"%c",c);

   }

fclose(fichier);//ferme le fichier

fclose(fp);


}







void ajouter_Client(  const Client *Id_client){
//cette fonction compare mel_p donner en entrée et verifier si elle est deja présente dans le fichier
//cette fonction permet a l'utilisateur d'entrer ces donnes -> utilsation de fgets pour les chaines de  caracteres
Client p;
occurence d;
fgetc(stdin);
FILE*resultat_ajouter;
resultat_ajouter = fopen("resultat_ajouter.txt","w");//ouverture du fichier ecriture pour ecrire le nouveau client
FILE *annuaire = fopen("annuaire.csv", "r+");//ouverture du fichier lecture pour  compter le nombre de ligne
FILE *file = fopen("annuaire.txt", "r");
//char chaine[100];//taille a changer avec l'allocation dynamique...
char *temp = (char *) malloc (100*sizeof(char));//j'alloue une taille de 50 octets etant donnes qu'un char = 1 octet
if(file == NULL){
    perror("erreur d'ouverture du fichier !");
    exit(EXIT_FAILURE);
}
if(annuaire == NULL){
    perror("erreur d'ouverture du fichier !");
    exit(EXIT_FAILURE);
}
if(resultat_ajouter == NULL){
    perror("erreur d'ouverture du fichier !");
    exit(EXIT_FAILURE);
}
char donnes[1000][1000];


int ligne =0;
//cette boucle permet de compter le nombre de ligne dans le fichier annuaire.csv
while(!feof(annuaire)&& !ferror(annuaire)){//si ferror est vrai alors le fichier n'est pas lu = probleme et que on est pas a la fin du fichier
            if(fgets(donnes[ligne],1000,annuaire)!= NULL){//lire une chaine de caractere
                    fprintf(resultat_ajouter,"%s\n",donnes[ligne]);//copie les lignes dans le fichier donné en sortie
                ligne++;//incremente le nombre de ligne pour passer d'une ligne a une autre
            }
}

printf("le nombre de ligne du fichier : %d\n",ligne);



printf("La premiere lettre doit etre en majuscule ! \n");
//Probleme avec fgets -> le menu fait sautr ma saisie du nom alors que avec un scanf rien ne saute fgets(p.nom_p,TAILLE,stdin);
//pour empecher que le fgets sur le nom saute
NOM:{
    p.nom_p = (char *) calloc (100,sizeof(char));//utilisation de l'allocation dynamique avec calloc -> initialise tout a 0

            printf("Nom\n");
            fgets(p.nom_p,TAILLE,stdin);//fgets->saisie de chaine de caracteres
            p.nom_p[strcspn(p.nom_p,"\r\n")] = '\0';//au cas ou il ya des \n

            if(p.nom_p[0] != '\0'){
                //si le champ nom est remplie alors je lui réalloue la taille de la chaine->optimisation avec strlen
                p.nom_p = (char*)realloc(p.nom_p,strlen(p.nom_p)*sizeof(char));

            }
            else{
                //sinon si le champ et vide alors j'ecris une virgule dans le fichier de sortie et de l'annuaire pour separer les champs
                fprintf(resultat_ajouter,",");
                fprintf(annuaire,",");
                goto PRENOM;
            }

            //apres que l'utilisateur entre ses coordonees je detecte avec une boucle si chaque caracteres et compris entre a et z ou A et Z en se basant sur le code ascii

            for(int i = 0;i<strlen(p.nom_p);i++){
                if((p.nom_p[i]>='a' && p.nom_p[i]<='z') || (p.nom_p[i]>='A' && p.nom_p[i]<='Z') || p.nom_p[i]=='-' ||  p.nom_p[0]!=' '){

                        continue;


                }
                else{
                    puts("Caracteres speciaux ,chiffre,lettre avec accents,ESPACES detecter!!!\n");
                    printf("caracteres trouver -> %c \n",p.nom_p[i]);
                    goto NOM;//l'utilisateur doit resaisir son nom en cas de problemes->robustesse valider


                }
            }
            fprintf(resultat_ajouter,"%s,",p.nom_p);
            fprintf(annuaire,"%s,",p.nom_p);
            free(p.nom_p);//je libere la memoire

}


//puts("les caracteres speciaux ne sont pas acceptees -> prenom !!!\n");
PRENOM:{
            p.prenom_p =(char *) calloc (100,sizeof(char));
            printf("Prenom\n");
            fgets(p.prenom_p,TAILLE,stdin);//fgets->saisie de chaine de caracteres
            p.prenom_p[strcspn(p.prenom_p,"\r\n")] = '\0';//au cas ou il ya des \n
             if(p.prenom_p[0] != '\0'){
                    //si le champ prenom est remplie alors je lui réalloue la taille de la chaine->optimisation avec strlen
                 p.prenom_p = (char*)realloc(p.prenom_p,strlen(p.prenom_p)*sizeof(char));
            }
            else{
                fprintf(resultat_ajouter,",");
                fprintf(annuaire,",");
                goto CODEPOSTAL;
            }

            for(int i = 0;i<strlen(p.prenom_p);i++){
                if((p.prenom_p[i]>='a' && p.prenom_p[i]<='z') || (p.prenom_p[i]>='A' && p.prenom_p[i]<='Z') || p.prenom_p[i]=='-'){
                        continue;

                }
                else{
                    puts("Caracteres speciaux ,chiffre,lettre avec accents,ESPACES detecter!!!\n");
                    printf(" caracteres trouver -> %c \n",p.prenom_p[i]);
                    goto PRENOM;
                }
            }
            fprintf(resultat_ajouter,"%s,",p.prenom_p);
            fprintf(annuaire,"%s,",p.prenom_p);
            free(p.prenom_p);

}
CODEPOSTAL:{
            printf("Code postal\n");
            fgets(p.code_postal_p,sizeof(p.code_postal_p),stdin);//fgets->saisie de chaine de caracteres
            p.code_postal_p[strcspn(p.code_postal_p,"\r\n")] = '\0';//au cas ou il ya des \n
            if(p.code_postal_p[0]!='\0'){assert(strlen(p.code_postal_p) == 5 || strlen(p.code_postal_p) == 4);}
            else{
                  fprintf(resultat_ajouter,",");
                  fprintf(annuaire,",");
                goto VIL;
            }
            for(int i = 0;i<strlen(p.code_postal_p);i++){
                if((p.code_postal_p[i]>='0' && p.code_postal_p[i]<='9')){
                        continue;

                }
                else{
                    puts("Caracteres speciaux ,chiffre,lettre avec accents,ESPACES detecter!!!\n");
                    printf("caracteres trouver -> %c \n",p.code_postal_p[i]);
                    goto CODEPOSTAL;
                }
            }
            fprintf(resultat_ajouter,"%s,",p.code_postal_p);
            fprintf(annuaire,"%s,",p.code_postal_p);
}

VIL:{
    p.ville_p = (char *) calloc (100,sizeof(char));
            printf("Ville\n");
            fgets(p.ville_p,TAILLE,stdin);//fgets->saisie de chaine de caracteres
            p.ville_p[strcspn(p.ville_p,"\r\n")] = '\0';//au cas ou il ya des \n
               if(p.ville_p[0] != '\0'){
                    //si le champ ville est remplie alors je lui réalloue la taille de la chaine->optimisation avec strlen
                   p.ville_p = (char*)realloc(p.ville_p,strlen(p.ville_p)*sizeof(char));
            }
            else{
                    fprintf(resultat_ajouter,",");
                    fprintf(annuaire,",");
                goto TELEPHONE;
            }


            for(int i = 0;i<strlen(p.ville_p);i++){
                if((p.ville_p[i]>='a' && p.ville_p[i]<='z')|| (p.ville_p[i]>='A' && p.ville_p[i]<='Z') || p.ville_p[i]=='-'){
                        continue;

                }
                else{
                    puts("Caracteres speciaux ,chiffre,lettre avec accents,ESPACES detecter!!!\n");
                    printf("caracteres trouver -> %c \n",p.ville_p[i]);
                    goto VIL;
                }
            }
            fprintf(resultat_ajouter,"%s,",p.ville_p);
            fprintf(annuaire,"%s,",p.ville_p);
            free(p.ville_p);//libere la memoire

}

TELEPHONE:{
            printf("Numero de telephone\n");
            fgets(p.telephone_p,sizeof(p.telephone_p),stdin);//fgets->saisie de chaine de caracteres
            p.telephone_p[strcspn(p.telephone_p,"\r\n")] = '\0';//au cas ou il ya des \n
            if(p.telephone_p[0]=='\0'){fprintf(resultat_ajouter,",");fprintf(annuaire,",");goto MEL;}
            else{
               assert(strlen(p.telephone_p) == 10);//test -> le nombre de chiffre doit etre egale a 10 ->France
            }

            for(int i = 0;i<strlen(p.telephone_p);i++){
                    //test : le champs telephone_p doit contenir seulement des chiffre
                    assert((p.telephone_p[i]>='0' && p.telephone_p[i]<='9'));
                if((p.telephone_p[i]>='0' && p.telephone_p[i]<='9')){
                        continue;

                }
                else{
                    puts("Caracteres speciaux ,chiffre,lettre avec accents,ESPACES detecter!!!\n");
                    printf("caracteres trouver -> %c \n",p.telephone_p[i]);
                    goto TELEPHONE;
                }
            }
            //ecriture du numero en prenant en compte le points present dans l'annuaire
            for(int i = 0;i<strlen(p.telephone_p);i++){
                    if(i==8){
                        fprintf(resultat_ajouter,"%c%c,",p.telephone_p[i],p.telephone_p[i+1]);
                        fprintf(annuaire,"%c%c,",p.telephone_p[i],p.telephone_p[i+1]);
                        goto MEL;
                    }
                fprintf(resultat_ajouter,"%c%c.",p.telephone_p[i],p.telephone_p[i+1]);
                fprintf(annuaire,"%c%c.",p.telephone_p[i],p.telephone_p[i+1]);
                i++;
            }

}
MEL:{
    int cpt = 0;
    p.mel_p = (char *) calloc (256,sizeof(char));//alloue une place de 256
            printf("Adresse mail\n");
            fgets( p.mel_p,TAILLE,stdin);//fgets->saisie de chaine de caracteres
            p.mel_p[strcspn(p.mel_p,"\n")] = '\0';//la fonction strcspn permet de gerer le cas ou chaine est egale au nombre de caracteres en prenant en compte \n

                   if(p.mel_p[0] != '\0'){
                        //si le champ mel est remplie alors je lui réalloue la taille de la chaine->optimisation avec strlen
                   p.mel_p = (char*)realloc(p.mel_p,strlen(p.mel_p)*sizeof(char));
            }
            else{
                    //sinon l'utilisateur doit saisir l'adresse mail
                printf("l'adresse mail donne obligatoirement etre renseigner\n");
                goto MEL;
            }

            for(int i = 0;i<strlen(p.mel_p);i++){
                    //test en boit noire -> l'adresse mail doit contenir un @ et des .
                    assert(strstr(p.mel_p,"@"));//l'adresse doit contenir un @
                    assert(strstr(p.mel_p,"."));//l'adresse doit contenir au moins un . pour etre valide

                if((p.mel_p[i]>='a' && p.mel_p[i]<='z')|| (p.mel_p[i]>='A' && p.mel_p[i]<='Z') || p.mel_p[i]=='-'|| strstr(p.mel_p,"@")|| strstr(p.mel_p,".")){
                        continue;

                }
                else{
                    puts("Caracteres speciaux ,chiffre,lettre avec accents,ESPACES detecter!!!\n");
                    printf("caracteres trouver -> %c \n",p.mel_p[i]);
                    goto MEL;
                }

            }


                d.occurrence1 = 0;
                d.occurrence2 = 0;
                //verification de la validité de l'adresse mail saisie
                        for(int i  = 0; p.mel_p[i] != '\0'; i++)
                        {
                               if(p.mel_p[i] == '@'){
                                   d.occurrence1++;
                               }
                               if(p.mel_p[i] == '.'){
                                   d.occurrence2++;
                               }
                        }
                        switch(d.occurrence1){
                        case 1:
                            break;
                        default:
                            printf("vous pouvez utiliser qu'un seul @ pour votre adresse mail\n");
                            goto MEL;

                        }
                         switch(d.occurrence2){
                        case 1:
                            break;
                        case 2:
                            break;
                        default:
                            printf("vous pouvez utiliser jusqu'a deux . pour votre adresse mail\n");
                            goto MEL;

                        }

                         printf("Le nombre d’occurrence de @ est %d\n", d.occurrence1);
                         printf("Le nombre d’occurrence de . est %d\n", d.occurrence2);
                strcpy(temp,p.mel_p);//copie la chaine saisie si elle est valide pour comparer l'existance de celle ci dans l'annuaire

           struct Client_ *p = (struct Client_*)calloc(1000,sizeof(struct Client_));//allocation dynamique de le structure
           rewind(file);//revient au debut du fichier si l'adresse existe deja
           int c =fgetc(file);
while(cpt<ligne){
        //chaque structure possede les champs suivant  -> calloc pour initialiser a 0 car malloc presente des problemes en cas de champs vides
        p[cpt].nom_p = (char *) calloc (100,sizeof(char));
        p[cpt].prenom_p = (char *) calloc (100,sizeof(char));
        p[cpt].ville_p = (char *) calloc (100,sizeof(char));;
        p[cpt].mel_p = (char *) calloc (100,sizeof(char));
        p[cpt].profession_p = (char *) calloc (100,sizeof(char));
    for(int j= 0;;j++){
             if(c==',' ||c=='\n'){

                c = fgetc(file);
                    break;
            }
        // Insérez le caractère lu dans le tableau et incrémentez le compteur j

        p[cpt].nom_p[j] = (char) c;
        //lis le caracteres suivant
        c = fgetc(file);
    }
      for(int j= 0;;j++){
             if(c==',' ||c=='\n'){

                c = fgetc(file);
                    break;
            }
        // Insérez le caractère lu dans le tableau et incrémentez le compteur

        p[cpt].prenom_p[j] = (char) c;
        //lis le caracteres suivant
        c = fgetc(file);
    }
        for(int j= 0;;j++){
             if(c==',' ||c=='\n'){

                c = fgetc(file);
                //lis le caracteres suivant
                    break;
            }
        // Insérez le caractère lu dans le tableau et incrémentez le compteur

        p[cpt].code_postal_p[j] = (char) c;
        //lis le caracteres suivant
        c = fgetc(file);
    }
          for(int j= 0;;j++){
             if(c==',' ||c=='\n'){

                c = fgetc(file);
                    break;
            }
        // Insérez le caractère lu dans le tableau et incrémentez le compteur

        p[cpt].ville_p[j] = (char) c;
        //lis le caracteres suivant
        c = fgetc(file);
    }
    for(int j= 0;;j++){
             if(c==',' ||c=='\n'){

                c = fgetc(file);
                    break;
            }
        // Insérez le caractère lu dans le tableau et incrémentez le compteur

        p[cpt].telephone_p[j] = (char) c;
        //lis le caracteres suivant
        c = fgetc(file);
    }
        for(int j= 0;;j++){
             if(c==',' ||c=='\n'){

                c = fgetc(file);
                    break;
            }
        // Insérez le caractère lu dans le tableau et incrémentez le compteur

        p[cpt].mel_p[j] = (char) c;
        //lis le caracteres suivant
        c = fgetc(file);
    }
    //si l'adresse est identique a celle de la chaine saisie(temp)alors l'adresse n'est pas valide
    if (stricmp(temp, p[cpt].mel_p) == 0) {
            printf("l'adresse existe deja !\n");

            goto MEL;//retour a la saisie


      }
         for(int j= 0;;j++){
             if(c==',' ||c=='\n'){

                c = fgetc(file);
                    break;
            }
        // Insérez le caractère lu dans le tableau et incrémentez le compteur

        p[cpt].profession_p[j] = (char) c;
        //lis le caracteres suivant
        c = fgetc(file);

        }
cpt++;//incremente le compteur pour passer a la structure suivante




}
fprintf(resultat_ajouter,"%s,",temp);//ajoute l'adresse valide dans le fichier donné en sortie
fprintf(annuaire,"%s,",temp);//ajoute l'adresse valide dans le fichier principale



fclose(file);//fermeture du ficher
//libere la memoire
free(p->nom_p);
free(p->prenom_p);
free(p->ville_p);
free(p->mel_p);
//free(p->profession_p);
free(p);


}
PROFESSION:{
    p.profession_p = (char *) calloc (100,sizeof(char));
            printf("profession\n");
            fgets(p.profession_p,TAILLE,stdin);//fgets->saisie de chaine de caracteres
            p.profession_p[strcspn(p.profession_p,"\r\n")] = '\0';//au cas ou il ya des \n

                    if(p.profession_p[0] != '\0'){
                   p.profession_p = (char*)realloc(p.profession_p,strlen(p.profession_p)*sizeof(char));
                    }
                    else{

                    }
            for(int i = 0;i<strlen(p.profession_p);i++){
            if((p.profession_p[i]>='a' && p.profession_p[i]<='z') || (p.profession_p[i]>='A' && p.profession_p[i]<='Z')|| p.profession_p[i]=='-'){
                    continue;

            }
            else{
                puts("Caracteres speciaux ,chiffre,lettre avec accents,ESPACES detecter!!!\n");
                printf("caracteres trouver -> %c \n",p.profession_p[i]);
                goto PROFESSION;
            }
        }

        fprintf(resultat_ajouter,"%s\n",p.profession_p);
        fprintf(annuaire,"%s\n",p.profession_p);

        free(p.profession_p);//libere la memoire

}
//ferme les fichiers
fclose(resultat_ajouter);
fclose(annuaire);

}






void Verifier_validite_annuaire(const Client*d,int size){
FILE *file = fopen("annuaire.txt", "r");
    FILE *annuaire = fopen("annuaire.csv", "r");

    // Vérifiez si le fichier a été ouvert correctement
    if (file == NULL) {
        perror("Erreur lors de l'ouverture du fichier");
        exit(EXIT_FAILURE);
    }
     if (annuaire == NULL) {
        perror("Erreur lors de l'ouverture du fichier");
        exit(EXIT_FAILURE);
    }

struct Client_ *p = (struct Client_*)calloc(1000,sizeof(struct Client_));

char donnes[1000][1000];//tableau 2d pour compter le nombre de lignes

int cpt = 0;
int ligne =0;
while(!feof(annuaire)&& !ferror(annuaire)){//si ferror est vrai alors le fichier n'est pas lu = probleme et que on est pas a la fin du fichier
            if(fgets(donnes[ligne],1000,annuaire)!= NULL){//lire une chaine de caractere
                ligne++;//incremente le nombre de ligne pour passer d'une ligne a une autre
            }
}
fclose(annuaire);
printf("le nombre de ligne du fichier : %d\n",ligne);
// Utilise un compteur pour suivre l'emplacement où chaque caractère doit être inséré dans le tableau
int i = 0;
// Utilise fgetc pour lire chaque caractère du fichier jusqu'à ce que, l'on atteind la fin du fichier
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
                    break;
            }
        // Insérez le caractère lu dans le tableau et incrémentez le compteur

        p[cpt].nom_p[j] = (char) c;
        //lis le caratere suivant
        c = fgetc(file);

    }
      for(int j= 0;;j++){
             if(c==',' ||c=='\n'){

                c = fgetc(file);
                    break;
            }
        // Insérez le caractère lu dans le tableau et incrémentez le compteur

        p[cpt].prenom_p[j] = (char) c;
        //lis le caratere suivant
        c = fgetc(file);

    }
        for(int j= 0;;j++){
             if(c==',' ||c=='\n'){

                c = fgetc(file);
                    break;
            }
        // Insérez le caractère lu dans le tableau et incrémentez le compteur

        p[cpt].code_postal_p[j] = (char) c;
        //lis le caratere suivant
        c = fgetc(file);

    }
          for(int j= 0;;j++){
             if(c==',' ||c=='\n'){

                c = fgetc(file);
                    break;
            }
        // Insérez le caractère lu dans le tableau et incrémentez le compteur

        p[cpt].ville_p[j] = (char) c;
        //lis le caratere suivant
        c = fgetc(file);
    }
    for(int j= 0;;j++){
             if(c==',' ||c=='\n'){

                c = fgetc(file);
                    break;
            }
        // Insérez le caractère lu dans le tableau et incrémentez le compteur

        p[cpt].telephone_p[j] = (char) c;
        //lis le caratere suivant
        c = fgetc(file);
    }
        for(int j= 0;;j++){
             if(c==',' ||c=='\n'){

                c = fgetc(file);
                    break;
            }
        // Insérez le caractère lu dans le tableau et incrémentez le compteur

        p[cpt].mel_p[j] = (char) c;
        //lis le caratere suivant
        c = fgetc(file);
    }
         for(int j= 0;;j++){
             if(c==',' ||c=='\n'){

                c = fgetc(file);
                    break;//passe au champs suivant
            }
        // Insérez le caractère lu dans le tableau et incrémentez le compteur

        p[cpt].profession_p[j] = (char) c;
        //lis le caratere suivant
        c = fgetc(file);
    }
cpt++;//incremente le compteur pour passer a la structure suivante

}
//inspiration du tri a bulle pour verifier si il ya des doublons d'adresse
   int j = 0;
   i=0;
  for (i = 0; i <= cpt; i++) {
    for (j = i+1 ;j <= cpt; j++) {
      if (stricmp(p[i].mel_p, p[j].mel_p) == 0) {
        printf("il ya des doublons :");
        printf("%s et %s \n",p[i].mel_p,p[j].mel_p);
      }
    }
  }

//ferme le fichier
fclose(file);
//libere la memoire
free(p->nom_p);
free(p->prenom_p);
free(p->ville_p);
free(p->mel_p);
free(p->profession_p);
free(p);

}

/** \brief la fonction tri_client_par_nom prends en sortie l'annuaire trier en fonction du nom
 * \brief :entrées : le nom_annuaire n'est pas modifiable
   \brief :pré-conditions : le nom de l'annuaire doit étre valide
   \brief :sorties : les donnes sont donné en sortie dans le fichier resultat_afficher_tries_nom dans le meme repertoire que l'executable
   \brief  :post-conditions
 * \param   const Client*d,int size
 * \param resultat_afficher_tries_nom est un annuaire valide dont le contenu correspond au données des clients trier dans l'ordre alphabétique
 * \return  renvoie l'annuaire en sortie
 *
 */

void tri_client_par_nom( const Client*d,int size){
    FILE *file = fopen("annuaire.txt", "r");
    FILE *annuaire = fopen("annuaire.csv", "r");
    FILE *Resultat = fopen("resultat_trier_par_nom.txt", "w");
    // Vérifiez si le fichier a été ouvert correctement
    if (file == NULL) {
        perror("Erreur lors de l'ouverture du fichier");
        exit(EXIT_FAILURE);
    }
if (Resultat == NULL) {
        perror("Erreur lors de l'ouverture du fichier");
        exit(EXIT_FAILURE);
    }
    if (annuaire == NULL) {
        perror("Erreur lors de l'ouverture du fichier");
        exit(EXIT_FAILURE);
    }

struct Client_ *p = (struct Client_*)calloc(1000,sizeof(struct Client_));

char donnes[1000][1000];
int cpt = 0;
int ligne =0;
//utilisation d'un tableau a deux dimension pour compter le nombre de ligne
while(!feof(annuaire)&& !ferror(annuaire)){//si ferror est vrai alors le fichier n'est pas lu = probleme et que on est pas a la fin du fichier
            if(fgets(donnes[ligne],1000,annuaire)!= NULL){//lire une chaine de caractere
                ligne++;//incremente le nombre de ligne pour passer d'une ligne a une autre
            }
}
fclose(annuaire);
printf("le nombre de ligne du fichier : %d\n",ligne);
    // Utilisez un compteur pour suivre l'emplacement où chaque caractère doit être inséré dans le tableau
    int i = 0;

    // Utilisez fgetc pour lire chaque caractère du fichier jusqu'à ce que vous atteigniez la fin du fichier



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
                    break;
            }
        // Insérez le caractère lu dans le tableau et incrémentez le compteur

        p[cpt].profession_p[j] = (char) c;
            //lis le caractere suivant
        c = fgetc(file);
    }
cpt++;//incremente le compteur pour passer a la structure suivante

}
//tri a bulle pour trier les donnes en fonction du nom
   int j = 0;
   i=0;
  struct Client_ temp;
  for (i = 0; i < cpt; i++) {
        for (j = i+1 ;j < cpt; j++) {
              if (stricmp(p[i].nom_p, p[j].nom_p) > 0) {
                temp = p[i];
                p[i] = p[j];
                p[j] = temp;
              }
        }
  }
//affiche les valeurs et ecrit dans le fichier donné en sortie
  for (i = 0; i < cpt; i++) {
  printf("%s,%s,%s,%s,%s,%s,%s\n",p[i].nom_p,p[i].prenom_p,p[i].code_postal_p,p[i].ville_p,p[i].telephone_p,p[i].mel_p,p[i].profession_p);
  fprintf(Resultat,"%s,%s,%s,%s,%s,%s,%s\n",p[i].nom_p,p[i].prenom_p,p[i].code_postal_p,p[i].ville_p,p[i].telephone_p,p[i].mel_p,p[i].profession_p);
  }
//libere la memoire
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
int Filtrer(char *s1,char *sch1,char *s2,char *sch2,int index,int index2,int cpt){

int len1 = strlen(sch1);
int len2 = strlen(sch2);
int trouvee = 0;
if(sch1[0]=='\0' || sch2[0]=='\0'){trouvee = 2;return trouvee;}
    if(((strncasecmp(s1 + index-1, sch1, len1) == 0) && (strncasecmp(s2 + index2-1, sch2, len2)) == 0)){

            trouvee = 1;
            return trouvee;

       }
       else{

            trouvee = 0;
            return trouvee;
       }



}

void Filtrer_combiner_deux_champs(const Client *Id_client){
Client f;
    FILE *file = fopen("annuaire.txt", "r");
    FILE *annuaire = fopen("annuaire.csv", "r");
    FILE *resultat_filtrer_combiner_deux_champs = fopen("resultat_filtrer_combiner_deux_champs.txt", "w");
    if(file == NULL){
        perror("Erreur d'ouverture du fichier !");
        exit(EXIT_FAILURE);
    }
     if (annuaire == NULL) {
        perror("Erreur lors de l'ouverture du fichier");
        exit(EXIT_FAILURE);
    }
      if (resultat_filtrer_combiner_deux_champs == NULL) {
        perror("Erreur lors de l'ouverture du fichier");
        exit(EXIT_FAILURE);
    }
    struct Client_ *p = (struct Client_*)calloc(1000,sizeof(struct Client_));

char donnes[1000][1000];
int cpt = 0;
int ligne =0;
int critere1 = 0;
int critere2 = 0;
//utilisation d'un tableau a deux dimension pour compter le nombre de ligne
while(!feof(annuaire)&& !ferror(annuaire)){//si ferror est vrai alors le fichier n'est pas lu = probleme et que on est pas a la fin du fichier
            if(fgets(donnes[ligne],1000,annuaire)!= NULL){//lire une chaine de caractere
                ligne++;//incremente le nombre de ligne pour passer d'une ligne a une autre
            }
}
fclose(annuaire);
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
    //strtok(p[cpt].telephone_p,".");
        for(int j= 0;;j++){
             if(c==',' ||c=='\n'){

                c = fgetc(file);
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
                    break;
            }
        // Insérez le caractère lu dans le tableau et incrémentez le compteur

        p[cpt].profession_p[j] = (char) c;
            //lis le caractere suivant
        c = fgetc(file);
    }


  // Utilisez strncasecmp pour comparer les n premiers caractères de str1 à partir de l'index donné à str2


cpt++;//incremente le compteur pour passer a la structure suivante

}
int index = 0;
int index2 = 0;

printf("le nombre de ligne du fichier : %d\n",ligne);
printf("choisissez vos 2 criteres \n");
puts("critere n 1: \n");
scanf("%d",&critere1);
puts("critere n 2: \n");
scanf("%d",&critere2);
char ch[256];
char ch2[256];
printf("entrer la position ou commence la chaine 1 : \n");
scanf("%d",&index);
printf("entrer la premiere chaine : \n");
fgetc(stdin);
gets(ch);
printf("entrer la position ou commence la chaine 2 : \n");
scanf("%d",&index2);
printf("entrer la deuxieme chaine : \n");
fgetc(stdin);
gets(ch2);
int choix = 100*critere1 + 10*critere2 ;

switch (choix)
{
  case 120 :
    printf("nom et prenom\n");
    for(int i = 0;i<cpt;i++){
            if(Filtrer(p[i].nom_p,ch,p[i].prenom_p,ch2,index,index2,cpt)==1){
                //printf(" %s et %s  sont  des sous chaine\n",p[i].nom_p,p[i].prenom_p);
                fprintf(resultat_filtrer_combiner_deux_champs,"%s,%s,%s,%s,%s,%s,%s\n",p[i].nom_p,p[i].prenom_p,p[i].code_postal_p,p[i].ville_p,p[i].telephone_p,p[i].mel_p,p[i].profession_p);
            }

    }
    break;
  case 130 :
    printf("nom et codePostal\n");
     for(int i = 0;i<cpt;i++){
            if(Filtrer(p[i].nom_p,ch,p[i].code_postal_p,ch2,index,index2,cpt)==1){
                //printf(" %s et %s  sont  des sous chaine\n",p[i].nom_p,p[i].prenom_p);
                fprintf(resultat_filtrer_combiner_deux_champs,"%s,%s,%s,%s,%s,%s,%s\n",p[i].nom_p,p[i].prenom_p,p[i].code_postal_p,p[i].ville_p,p[i].telephone_p,p[i].mel_p,p[i].profession_p);
            }
    }
    break;
  case 140 :
    printf("nom et ville\n");
         for(int i = 0;i<cpt;i++){
            if(Filtrer(p[i].nom_p,ch,p[i].ville_p,ch2,index,index2,cpt)==1){
                //printf(" %s et %s  sont  des sous chaine\n",p[i].nom_p,p[i].prenom_p);
                fprintf(resultat_filtrer_combiner_deux_champs,"%s,%s,%s,%s,%s,%s,%s\n",p[i].nom_p,p[i].prenom_p,p[i].code_postal_p,p[i].ville_p,p[i].telephone_p,p[i].mel_p,p[i].profession_p);
            }
          }
    break;
  case 150 :
   printf("nom et telephone\n");
     for(int i = 0;i<cpt;i++){
            if(Filtrer(p[i].nom_p,ch,p[i].telephone_p,ch2,index,index2,cpt)==1){
                //printf(" %s et %s  sont  des sous chaine\n",p[i].nom_p,p[i].prenom_p);
                fprintf(resultat_filtrer_combiner_deux_champs,"%s,%s,%s,%s,%s,%s,%s\n",p[i].nom_p,p[i].prenom_p,p[i].code_postal_p,p[i].ville_p,p[i].telephone_p,p[i].mel_p,p[i].profession_p);
            }
    }
    break;
  case 160 :
    printf("nom et mail\n");
       for(int i = 0;i<cpt;i++){
            if(Filtrer(p[i].nom_p,ch,p[i].mel_p,ch2,index,index2,cpt)==1){
                //printf(" %s et %s  sont  des sous chaine\n",p[i].nom_p,p[i].prenom_p);
                fprintf(resultat_filtrer_combiner_deux_champs,"%s,%s,%s,%s,%s,%s,%s\n",p[i].nom_p,p[i].prenom_p,p[i].code_postal_p,p[i].ville_p,p[i].telephone_p,p[i].mel_p,p[i].profession_p);
            }
    }
    break;
    case 170 :
    printf("nom et profession\n");
        for(int i = 0;i<cpt;i++){
            if(Filtrer(p[i].nom_p,ch,p[i].profession_p,ch2,index,index2,cpt)==1){
                //printf(" %s et %s  sont  des sous chaine\n",p[i].nom_p,p[i].prenom_p);
                fprintf(resultat_filtrer_combiner_deux_champs,"%s,%s,%s,%s,%s,%s,%s\n",p[i].nom_p,p[i].prenom_p,p[i].code_postal_p,p[i].ville_p,p[i].telephone_p,p[i].mel_p,p[i].profession_p);
            }
    }
    break;
  case 230:
      printf("prenom et code postal\n");
    for(int i = 0;i<cpt;i++){
            if(Filtrer(p[i].prenom_p,ch,p[i].code_postal_p,ch2,index,index2,cpt)==1){
                //printf(" %s et %s  sont  des sous chaine\n",p[i].nom_p,p[i].prenom_p);
                fprintf(resultat_filtrer_combiner_deux_champs,"%s,%s,%s,%s,%s,%s,%s\n",p[i].nom_p,p[i].prenom_p,p[i].code_postal_p,p[i].ville_p,p[i].telephone_p,p[i].mel_p,p[i].profession_p);
            }
    }
    break;
    case 240:
         printf("prenom et ville\n");
          for(int i = 0;i<cpt;i++){
            if(Filtrer(p[i].prenom_p,ch,p[i].ville_p,ch2,index,index2,cpt)==1){
                //printf(" %s et %s  sont  des sous chaine\n",p[i].nom_p,p[i].prenom_p);
                fprintf(resultat_filtrer_combiner_deux_champs,"%s,%s,%s,%s,%s,%s,%s\n",p[i].nom_p,p[i].prenom_p,p[i].code_postal_p,p[i].ville_p,p[i].telephone_p,p[i].mel_p,p[i].profession_p);
            }
    }
    break;
    case 250:
         printf("prenom et telephone\n");
               for(int i = 0;i<cpt;i++){
            if(Filtrer(p[i].prenom_p,ch,p[i].telephone_p,ch2,index,index2,cpt)==1){
                //printf(" %s et %s  sont  des sous chaine\n",p[i].nom_p,p[i].prenom_p);
                fprintf(resultat_filtrer_combiner_deux_champs,"%s,%s,%s,%s,%s,%s,%s\n",p[i].nom_p,p[i].prenom_p,p[i].code_postal_p,p[i].ville_p,p[i].telephone_p,p[i].mel_p,p[i].profession_p);
            }
    }
    break;
    case 260:
         printf("prenom et mail\n");
    for(int i = 0;i<cpt;i++){
            if(Filtrer(p[i].prenom_p,ch,p[i].mel_p,ch2,index,index2,cpt)==1){
                //printf(" %s et %s  sont  des sous chaine\n",p[i].nom_p,p[i].prenom_p);
                fprintf(resultat_filtrer_combiner_deux_champs,"%s,%s,%s,%s,%s,%s,%s\n",p[i].nom_p,p[i].prenom_p,p[i].code_postal_p,p[i].ville_p,p[i].telephone_p,p[i].mel_p,p[i].profession_p);
            }
    }
    break;
    case 270:
         printf("prenom et profession\n");
    for(int i = 0;i<cpt;i++){
            if(Filtrer(p[i].prenom_p,ch,p[i].profession_p,ch2,index,index2,cpt)==1){
                //printf(" %s et %s  sont  des sous chaine\n",p[i].nom_p,p[i].prenom_p);
                fprintf(resultat_filtrer_combiner_deux_champs,"%s,%s,%s,%s,%s,%s,%s\n",p[i].nom_p,p[i].prenom_p,p[i].code_postal_p,p[i].ville_p,p[i].telephone_p,p[i].mel_p,p[i].profession_p);
            }
    }
    break;
    case 340:
        printf("code postal et ville\n");
            for(int i = 0;i<cpt;i++){
            if(Filtrer(p[i].code_postal_p,ch,p[i].ville_p,ch2,index,index2,cpt)==1){
                //printf(" %s et %s  sont  des sous chaine\n",p[i].nom_p,p[i].prenom_p);
                fprintf(resultat_filtrer_combiner_deux_champs,"%s,%s,%s,%s,%s,%s,%s\n",p[i].nom_p,p[i].prenom_p,p[i].code_postal_p,p[i].ville_p,p[i].telephone_p,p[i].mel_p,p[i].profession_p);
            }
    }
    break;
     case 350:
         printf("code postal et telephone\n");
    for(int i = 0;i<cpt;i++){
            if(Filtrer(p[i].code_postal_p,ch,p[i].telephone_p,ch2,index,index2,cpt)==1){
                //printf(" %s et %s  sont  des sous chaine\n",p[i].nom_p,p[i].prenom_p);
                fprintf(resultat_filtrer_combiner_deux_champs,"%s,%s,%s,%s,%s,%s,%s\n",p[i].nom_p,p[i].prenom_p,p[i].code_postal_p,p[i].ville_p,p[i].telephone_p,p[i].mel_p,p[i].profession_p);
            }
    }
    break;
     case 360:
         printf("code postal et mail\n");
    for(int i = 0;i<cpt;i++){
            if(Filtrer(p[i].code_postal_p,ch,p[i].mel_p,ch2,index,index2,cpt)==1){
                //printf(" %s et %s  sont  des sous chaine\n",p[i].nom_p,p[i].prenom_p);
                fprintf(resultat_filtrer_combiner_deux_champs,"%s,%s,%s,%s,%s,%s,%s\n",p[i].nom_p,p[i].prenom_p,p[i].code_postal_p,p[i].ville_p,p[i].telephone_p,p[i].mel_p,p[i].profession_p);
            }
    }
    break;
       case 370:
           printf("code postal et profession\n");
    for(int i = 0;i<cpt;i++){
            if(Filtrer(p[i].code_postal_p,ch,p[i].profession_p,ch2,index,index2,cpt)==1){
                //printf(" %s et %s  sont  des sous chaine\n",p[i].nom_p,p[i].prenom_p);
                fprintf(resultat_filtrer_combiner_deux_champs,"%s,%s,%s,%s,%s,%s,%s\n",p[i].nom_p,p[i].prenom_p,p[i].code_postal_p,p[i].ville_p,p[i].telephone_p,p[i].mel_p,p[i].profession_p);
            }
    }
    break;
     case 450:
         printf("ville et telephone\n");
    for(int i = 0;i<cpt;i++){
            if(Filtrer(p[i].ville_p,ch,p[i].telephone_p,ch2,index,index2,cpt)==1){
                //printf(" %s et %s  sont  des sous chaine\n",p[i].nom_p,p[i].prenom_p);
                fprintf(resultat_filtrer_combiner_deux_champs,"%s,%s,%s,%s,%s,%s,%s\n",p[i].nom_p,p[i].prenom_p,p[i].code_postal_p,p[i].ville_p,p[i].telephone_p,p[i].mel_p,p[i].profession_p);
            }
    }
    break;
    case 460:
        printf("ville et mail\n");
    for(int i = 0;i<cpt;i++){
            if(Filtrer(p[i].ville_p,ch,p[i].mel_p,ch2,index,index2,cpt)==1){
                //printf(" %s et %s  sont  des sous chaine\n",p[i].nom_p,p[i].prenom_p);
                fprintf(resultat_filtrer_combiner_deux_champs,"%s,%s,%s,%s,%s,%s,%s\n",p[i].nom_p,p[i].prenom_p,p[i].code_postal_p,p[i].ville_p,p[i].telephone_p,p[i].mel_p,p[i].profession_p);
            }
    }
    break;
    case 470:
        printf("ville et profession\n");
    for(int i = 0;i<cpt;i++){
            if(Filtrer(p[i].ville_p,ch,p[i].profession_p,ch2,index,index2,cpt)==1){
                //printf(" %s et %s  sont  des sous chaine\n",p[i].nom_p,p[i].prenom_p);
                fprintf(resultat_filtrer_combiner_deux_champs,"%s,%s,%s,%s,%s,%s,%s\n",p[i].nom_p,p[i].prenom_p,p[i].code_postal_p,p[i].ville_p,p[i].telephone_p,p[i].mel_p,p[i].profession_p);
            }
    }
    break;
    case 560:
        printf("telephone et mail\n");
    for(int i = 0;i<cpt;i++){
            if(Filtrer(p[i].telephone_p,ch,p[i].mel_p,ch2,index,index2,cpt)==1){
                //printf(" %s et %s  sont  des sous chaine\n",p[i].nom_p,p[i].prenom_p);
                fprintf(resultat_filtrer_combiner_deux_champs,"%s,%s,%s,%s,%s,%s,%s\n",p[i].nom_p,p[i].prenom_p,p[i].code_postal_p,p[i].ville_p,p[i].telephone_p,p[i].mel_p,p[i].profession_p);
            }
    }
    break;
    case 570:

        printf("telephone et profession\n");
    for(int i = 0;i<cpt;i++){
            if(Filtrer(p[i].telephone_p,ch,p[i].profession_p,ch2,index,index2,cpt)==1){
                //printf(" %s et %s  sont  des sous chaine\n",p[i].nom_p,p[i].prenom_p);
                fprintf(resultat_filtrer_combiner_deux_champs,"%s,%s,%s,%s,%s,%s,%s\n",p[i].nom_p,p[i].prenom_p,p[i].code_postal_p,p[i].ville_p,p[i].telephone_p,p[i].mel_p,p[i].profession_p);
            }
    }
    break;
    case 670:
        printf("mail  et profession\n");
          for(int i = 0;i<cpt;i++){
            if(Filtrer(p[i].mel_p,ch,p[i].profession_p,ch2,index,index2,cpt)==1){
                //printf(" %s et %s  sont  des sous chaine\n",p[i].nom_p,p[i].prenom_p);
                fprintf(resultat_filtrer_combiner_deux_champs,"%s,%s,%s,%s,%s,%s,%s\n",p[i].nom_p,p[i].prenom_p,p[i].code_postal_p,p[i].ville_p,p[i].telephone_p,p[i].mel_p,p[i].profession_p);
            }
    }
    break;


}
int choix2 = 100*critere2 + 10*critere1 ;
switch (choix2)
{
  case 120 :
    printf("nom et prenom\n");
    break;
  case 130 :
    printf("nom et codePostal\n");
    break;
  case 140 :
    printf("nom et ville\n");
    break;
  case 150 :
   printf("nom et telephone\n");
    break;
  case 160 :
    printf("nom et mail\n");
    break;
    case 170 :
    printf("nom et profession\n");
    break;
  case 230:
      printf("prenom et code postal\n");
    break;
    case 240:
         printf("prenom et ville\n");
    break;
    case 250:
         printf("prenom et telephone\n");
    break;
    case 260:
         printf("prenom et mail\n");
    break;
    case 270:
         printf("prenom et profession\n");
    break;
    case 340:
        printf("code postal et ville\n");
    break;
     case 350:
         printf("code postal et telephone\n");
    break;
     case 360:
         printf("code postal et mail\n");
    break;
       case 370:
           printf("code postal et profession\n");
    break;
     case 450:
         printf("ville et telephone\n");
    break;
    case 460:
        printf("ville et mail\n");
    break;
    case 470:
        printf("ville et profession\n");
    break;
    case 560:
        printf("telephone et mail\n");
    break;
    case 570:
        printf("telephone et profession\n");
    break;
    case 670:
        printf("mail  et profession\n");
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
