/**< \file fonction.c */
#include <stdio.h>
#include <stdlib.h>
#include<string.h>
#include<assert.h>
#include "fonction.h"
#define TAILLE 100

void Afficher_annuaire_clients(const Client *Id_client){
 FILE*fichier;
   fichier = fopen("fichier.txt","r");//ouverture du fichier en mode lecture
   char c;
   char ch;
   int i = 0;

   while(!feof(fichier)){

        for(i = 0;i!='\n';i++){
        c =fgetc(fichier);
                    if (c == ','){
                            printf("\n\n");
                            printf("-----------------------");
                            ch=fgetc(fichier);
                            fseek(fichier,1,SEEK_CUR);
                            if(ch == ','){
                                     ch=fgetc(fichier);
                                fseek(fichier,-1,SEEK_CUR);
                            fseek(fichier,-2,SEEK_CUR);
                            break;
                            }
                            fseek(fichier,-2,SEEK_CUR);
                    }
                    else
                    {
                            printf("%c",c);
                    }
        }
   }

   fclose(fichier);//ferme le fichier


}

void Ecriture_annuaire_clients(const Client *Id_client){

    FILE*fichier;
    FILE*fichier2;
    fichier= fopen("Annuaire.csv","r");//ouverture du fichier en mode lecture
    fichier2= fopen("fichier.txt","w");//ouverture du fichier en mode ecriture
    char c;

    while(!feof(fichier)){
        c=fgetc(fichier);

        fprintf(fichier2,"%c",c);//copie des caracteres un par un dans un fichier texte
    }

    fclose(fichier);//ferme le fichier
    fclose(fichier2);//ferme le fichier

}



void Separation_mel_p( Client *Id_client){
//cette fonction permet de séparer les emails dans un fichier a part pour par la suite verifier si la chaine mel_p est présente
FILE*fichier;
FILE*fichier2;
   fichier = fopen("fichier.txt","r");//ouverture du fichier en mode lecture
   fichier2 = fopen("fichier2.txt","w");//ouverture du fichier en mode écriture
   char c;
   char ch;
   int i = 0;


    while(!feof(fichier)){
        c=fgetc(fichier);

        if(c==','){
            i++;//j'initialise le compteur pour compter les nombre de virgule

        }
        if(i==5){
            //printf("l'element %d qui suit est email\n",i);
            ch =fgetc(fichier);
            fseek(fichier,-1,SEEK_CUR);//deplace le cursor de 1 pour verifier si le caractere est une virgule
            if(ch==','){
                i=0;
                fseek(fichier,1,SEEK_CUR);
                printf("\n");
                fprintf(fichier2,"\n");//j'ecris le caractere "retour a la ligne"
            }
            else {
                printf("%c",ch);
                fprintf(fichier2,"%c",ch);//j'ecris le caractere  dans le fichier
            }

            //i=0;


        }


    }
    fclose(fichier);
    fclose(fichier2);


}




void ajouter_Client(  const Client *Id_client){
//cette fonction compare mel_p donner en entrée et verifier si elle est deja présente dans le fichier
//cette fonction permet a l'utilisateur d'entrer ces donnes -> utilsation de fgets pour les chaines de  caracteres
    Client p;
    occurence c;
FILE*fichier;
fichier = fopen("fichier2.txt","r");//ouverture du fichier en lecture pour lire les adresses mails
FILE*fichier2;
fichier2 = fopen("fichier.txt","a");//ouverture du fichier en lecture pour lire les adresses mails
//char chaine[100];//taille a changer avec l'allocation dynamique...
char *temp = (char *) malloc (50*sizeof(char));//j'alloue une taille de 50 octets etant donnes qu'un char = 1 octet
char *chaine2 = (char *) malloc (50*sizeof(char));
p.nom_p = (char *) malloc (100*sizeof(char));
p.prenom_p = (char *) malloc (100*sizeof(char));
p.ville_p = (char *) malloc (100*sizeof(char));
p.mel_p = (char *) malloc (100*sizeof(char));
p.profession_p = (char *) malloc (100*sizeof(char));
//p.nom_p =   (char *) malloc (1*sizeof(char));
//char caracteres_incompatible[100] =";,%'`~&:}{^¤$<>@àéè[]_-+/*¨#!?²123456789";
   printf("La premiere lettre doit etre en majuscule ! \n");

NOM:{
            printf("Nom\n");
            fgets(p.nom_p,TAILLE,stdin);//fgets->saisie de chaine de caracteres
            p.nom_p[strcspn(p.nom_p,"\r\n")] = '\0';

            if(p.nom_p[0] != '\0'){

                p.nom_p = (char*)realloc(p.nom_p,strlen(p.nom_p)*sizeof(char));

            }
            else{
                fprintf(fichier2,"%s,",p.nom_p);
                goto PRENOM;
            }

            //apres que l'utilisateur entre ses coordonees je detecte avec une boucle si chaque caracteres et compris entre a et z ou A et Z en se basant sur le code ascii
             // je detecte les erreurs possibles lors de la saisie du numero de telephone ou du code postale
            for(int i = 0;i<strlen(p.nom_p);i++){
                if((p.nom_p[i]>='a' && p.nom_p[i]<='z') || (p.nom_p[i]>='A' && p.nom_p[i]<='Z') || p.nom_p[i]=='-'){

                        continue;


                }
                else{
                    puts("Caracteres speciaux ,chiffre,lettre avec accents,ESPACES detecter!!!\n");
                    printf("caracteres trouver -> %c \n",p.nom_p[i]);
                    goto NOM;


                }
            }
            fprintf(fichier2,"%s,",p.nom_p);

}


//puts("les caracteres speciaux ne sont pas acceptees -> prenom !!!\n");
PRENOM:{
            printf("Prenom\n");
            fgets(p.prenom_p,TAILLE,stdin);
            p.prenom_p[strcspn(p.prenom_p,"\r\n")] = '\0';
             if(p.prenom_p[0] != '\0'){
                 p.prenom_p = (char*)realloc(p.prenom_p,strlen(p.prenom_p)*sizeof(char));
            }
            else{
                fprintf(fichier2,"%s,",p.prenom_p);
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
            fprintf(fichier2,"%s,",p.prenom_p);
}
//puts("les caracteres speciaux et les lettres ne sont pas acceptees -> code postal!!!\n");
CODEPOSTAL:{
            printf("Code postal\n");
            fgets(p.code_postal_p,sizeof(p.code_postal_p),stdin);
            p.code_postal_p[strcspn(p.code_postal_p,"\r\n")] = '\0';
            if(p.code_postal_p[0]!='\0'){assert(strlen(p.code_postal_p) == 5);}

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
            fprintf(fichier2,"%s,",p.code_postal_p);
}

VIL:{
            printf("Ville\n");
            fgets(p.ville_p,TAILLE,stdin);
            p.ville_p[strcspn(p.ville_p,"\r\n")] = '\0';
               if(p.ville_p[0] != '\0'){
                   p.ville_p = (char*)realloc(p.ville_p,strlen(p.ville_p)*sizeof(char));
            }
            else{
                    fprintf(fichier2,"%s,",p.ville_p);
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
            fprintf(fichier2,"%s,",p.ville_p);
}
//puts("les caracteres speciaux et les lettre ne sont pas acceptees-> telephone !!!\n");
TELEPHONE:{
            printf("Numero de telephone\n");
            fgets(p.telephone_p,sizeof(p.telephone_p),stdin);
            p.telephone_p[strcspn(p.telephone_p,"\r\n")] = '\0';//si la chaine depasse la taille alors le dernier caractere sera un \0


            for(int i = 0;i<strlen(p.telephone_p);i++){
                if((p.telephone_p[i]>='0' && p.telephone_p[i]<='9')){
                        continue;

                }
                else{
                    puts("Caracteres speciaux ,chiffre,lettre avec accents,ESPACES detecter!!!\n");
                    printf("caracteres trouver -> %c \n",p.telephone_p[i]);
                    goto TELEPHONE;
                }
            }
            fprintf(fichier2,"%s,",p.telephone_p);
}
//puts("les caracteres speciaux ne sont pas acceptees-> adresse mail !!!\n");
MEL:{
            printf("Adresse mail\n");
            fgets( p.mel_p,TAILLE,stdin);
            p.mel_p[strcspn(p.mel_p,"\n")] = '\0';//la fonction strcspn permet de gerer le cas ou chaine est egale au nombre de caracteres en prenant en compte \n

                   if(p.mel_p[0] != '\0'){
                   p.mel_p = (char*)realloc(p.mel_p,strlen(p.mel_p)*sizeof(char));
            }
            else{
                printf("l'adresse mail donne obligatoirement etre renseigner\n");
                goto MEL;
            }

            for(int i = 0;i<strlen(p.mel_p);i++){
                    /*
                    Cette fonction prend deux chaînes chaine 1  et chaine 2 comme argument ,
                    elle trouve la première occurrence de la sous-chaine chaine 2 dans la chaîne chaine 1.
                    */
                    assert(strstr(p.mel_p,"@"));//test en boit noire
                    assert(strstr(p.mel_p,"."));

                if((p.mel_p[i]>='a' && p.mel_p[i]<='z')|| (p.mel_p[i]>='A' && p.mel_p[i]<='Z') || p.mel_p[i]=='-'|| strstr(p.mel_p,"@")|| strstr(p.mel_p,".")){
                        continue;

                }
                else{
                    puts("Caracteres speciaux ,chiffre,lettre avec accents,ESPACES detecter!!!\n");
                    printf("caracteres trouver -> %c \n",p.mel_p[i]);
                    goto MEL;
                }

            }


                c.occurrence1 = 0;
                c.occurrence2 = 0;
                        for(int i  = 0; p.mel_p[i] != '\0'; i++)
                        {
                               if(p.mel_p[i] == '@'){
                                   c.occurrence1++;
                               }
                               if(p.mel_p[i] == '.'){
                                   c.occurrence2++;
                               }
                        }
                        switch(c.occurrence1){
                        case 1:
                            break;
                        default:
                            printf("vous pouvez utiliser qu'un seul @ pour votre adresse mail\n");
                            goto MEL;

                        }
                         switch(c.occurrence2){
                        case 1:
                            break;
                        case 2:
                            break;
                        default:
                            printf("vous pouvez utiliser jusqu'a deux . pour votre adresse mail\n");
                            goto MEL;

                        }

                         printf("Le nombre d’occurrence de @ est %d\n", c.occurrence1);
                         printf("Le nombre d’occurrence de . est %d\n", c.occurrence2);

            while(!feof(fichier)){

                    fscanf(fichier,"%s",chaine2);//cela permet de scanner le fichier
                //printf("%s",chaine2);
                chaine2 = (char*)realloc(chaine2,strlen(chaine2)*sizeof(char));
                temp = (char*)realloc(chaine2,strlen(chaine2)*sizeof(char));
                //printf("%d",strlen(temp));
                strcpy(temp,chaine2);//je copie cette chaine qui est scanner dans ma variable temp
                //printf("%d\n",strlen(temp));
                //printf("%s\n",temp);
                    if(stricmp(temp, p.mel_p) == 0){//utilisation strcmp qui permet de comparer deux chaine si les deux chaine sont égales alors la chaine et deja presente donc mel_p n'est pas valide
                        printf("la chaine :%s existe deja\n",p.mel_p);
                        rewind(fichier);//permet de revenir au tout debut du fichier pour apres recommencer l'instruction
                        goto MEL;//je remplace break par goto si la chaine existe alors je demande indirectement a l'utilisateur de recommencer sa saisie

                        //break;//pas pratique mais utile pour le deboggage...
                    }
                    else{
                        //printf("la chaine :%s n' existe pas\n",chaine);
                    }
            }
fprintf(fichier2,"%s,",p.mel_p);

            fclose(fichier);//je ferme le fichier avec fclose
}
//puts("les caracteres speciaux ne sont pas acceptees -> profession!!!\n");
PROFESSION:{
            printf("profession\n");
            fgets(p.profession_p,TAILLE,stdin);
            p.profession_p[strcspn(p.profession_p,"\r\n")] = '\0';

                    if(p.profession_p[0] != '\0'){
                   p.profession_p = (char*)realloc(p.profession_p,strlen(p.profession_p)*sizeof(char));
                    }
                    else{
                            fprintf(fichier2,"%s,",p.profession_p);
                            exit(1);
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
        fprintf(fichier2,"%s,",p.profession_p);
        fclose(fichier2);
}





free(temp);
free(chaine2);
free(p.prenom_p);
free(p.ville_p);
free(p.mel_p);
free(p.profession_p);

}
void Verifier_validite_annuaire(const doublons *d){
FILE*fichier;
fichier = fopen("fichier2.txt","r");//j'ouvre le fichier en mode lecture pour lire le fichier-> r =read
 int i, j;

doublons r;
r.ligne = 0;//initialisation du nombre de ligne a 0 a l'aide de la structure doublons -> voir fichier "fonction.h"

while(!feof(fichier)&& !ferror(fichier)){//si ferror est vrai alors le fichier n'est pas lu = probleme et que on est pas a la fin du fichier
            if(fgets(r.donnes[r.ligne],1000,fichier)!= NULL){//lire une chaine de caractere
                r.ligne++;//incremente le nombre de ligne pour passer d'une ligne a une autre
            }

}

//utilisation du tri bulle en modifiant quelques parametre,cette fois ci je compare si les chaines sont identiques
  for (i = 0; i < r.ligne; i++){
            for (j = i+1; j < r.ligne; j++){
                      if (stricmp(r.donnes[i], r.donnes[j])== 0)//si les chaines sont identiques alors il y'a des doublons
                        {
                          printf("Annuaire invalide Doublons reperer !!");
                          puts("\n");//puts<->printf
                          printf("Doublons : %s -> %s",r.donnes[i],r.donnes[j]);//affiche les doublons
                        }
            }
   }
   fclose(fichier);


}



void tri_client(const doublons *d){
    //fonction de trie a completer en faisant attention aux clients qui n'ont pas renseigné les leur noms
FILE*fichier;
fichier = fopen("fichier2.txt","r");//j'ouvre le fichier en mode lecture pour lire le fichier-> r =read
 int i, j;

doublons r;
r.ligne = 0;//initialisation du nombre de ligne a 0 a l'aide de la structure doublons -> voir fichier "fonction.h"

while(!feof(fichier)&& !ferror(fichier)){//si ferror est vrai alors le fichier n'est pas lu = probleme et que on est pas a la fin du fichier
            if(fgets(r.donnes[r.ligne],1000,fichier)!= NULL){//lire une chaine de caractere
                r.ligne++;//incremente le nombre de ligne pour passer d'une ligne a une autre
            }

}




//trie a bulle -> fonctionnement : si l'élement a l'indice i = 0 est supérieur a l'indice i+1 (l'element voisin) alors on permute les elements jusqu'a le tableau soit trié
   for (i = 0; i < r.ligne; i++){
            for (j = i+1; j < r.ligne; j++){
                      if (stricmp(r.donnes[i], r.donnes[j])> 0)//la fonction stricmp permet de comparer des chaines de caracteres en faisant abstraction des majuscules et miniscules
                        {
                            //permutation des valeurs avec strcpy-> librairie->string.h
                          strcpy(r.temp,r.donnes[i]);//temp=chaine[i]
                          strcpy(r.donnes[i],r.donnes[j]);//chaine[i]=chaine[j]
                          strcpy(r.donnes[j],r.temp);//chaine[j]=temp

                        }
            }
   }

//afficher les valeurs ligne par ligne
        for(i= 0;i<r.ligne;i++){

            printf("%s\n",r.donnes[i]);
        }

fclose(fichier);

}


