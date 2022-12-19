/**< \file fonction.c */
#include <stdio.h>
#include <stdlib.h>
#include<string.h>
#include "fonction.h"
Client s1;
void AffichageAnnuaire(const Client *Id_client){
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

void CopieAnnuaireFichier(const Client *Id_client){

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




void saisirClient(  Client * Id_client){
//cette fonction permet a l'utilisateur d'entrer ces donnes -> utilsation de fgets pour les chaines de  caracteres

;
            printf("La premiere lettre doit etre en majuscule ! \n");


            printf("Nom\n");
            fgets(Id_client->nom_p,sizeof(Id_client->nom_p),stdin);
            Id_client->nom_p[strcspn(Id_client->nom_p,"\r\n")] = '\0';




            printf("Prenom\n");
            fgets(Id_client->prenom_p,sizeof(Id_client->prenom_p),stdin);
            Id_client->prenom_p[strcspn(Id_client->prenom_p,"\r\n")] = '\0';




            printf("Code postal\n");
            fgets(Id_client->code_postal_p,sizeof(Id_client->code_postal_p),stdin);
            Id_client->code_postal_p[strcspn(Id_client->code_postal_p,"\r\n")] = '\0';




            printf("Ville\n");
            fgets(Id_client->ville_p,sizeof(Id_client->ville_p),stdin);
            Id_client->ville_p[strcspn(Id_client->ville_p,"\r\n")] = '\0';


            printf("Numero de telephone\n");
            fgets(Id_client->telephone_p,sizeof(Id_client->telephone_p),stdin);
            Id_client->telephone_p[strcspn(Id_client->telephone_p,"\r\n")] = '\0';//si la chaine depasse la taille alors le dernier caractere sera un \0





            ajoutClient(&s1);//appel la fonction qui va permetre a l'utilisateur d'entrer son adresse mail en verifiant que l'adresse n'est pas deja prise





            printf("profession_p\n");
            fgets(Id_client->profession_p,sizeof(Id_client->profession_p),stdin);
            Id_client->profession_p[strcspn(Id_client->profession_p,"\r\n")] = '\0';





}

void verifeClient( Client *Id_client){
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




void ajoutClient(  const Client *Id_client){
//cette fonction compare mel_p donner en entrée et verifier si elle est deja présente dans le fichier
FILE*fichier;
fichier = fopen("fichier2.txt","r");//ouverture du fichier en lecture pour lire les adresses mails
char chaine[100];//taille a changer avec l'allocation dynamique...
char temp[256];//cette variable permet de stocker temporairement la chaine -> taille a changer avec l'allocation dynamique...
char chaine2[256];//taille a changer avec l'allocation dynamique...
    printf("Adresse mail\n");
    fgets(chaine,sizeof(chaine),stdin);
            chaine[strcspn(chaine,"\n")] = '\0';//la fonction strcspn permet de gerer le cas ou chaine est egale au nombre de caracteres en prenant en compte \n
    while(!feof(fichier)){

                    fscanf(fichier,"%s",chaine2);//cela permet de scanner le fichier
                //printf("%s",chaine2);
                strcpy(temp,chaine2);//je copie cette chaine qui est scanner dans ma variable temp
                //printf("%s\n",temp);
                    if(strcmp(temp,chaine) == 0){//utilisation strcmp qui permet de comparer deux chaine si les deux chaine sont égales alors la chaine et deja presente donc mel_p n'est pas valide
                        printf("la chaine :%s existe deja\n",chaine);
                        break;//pas prztique mais utile pour le deboggage...
                    }
                    else{


                        //printf("la chaine :%s n' existe pas\n",chaine);
                    }
    }


    fclose(fichier);//je ferme le fichier avec fclose
}
void verif_annuaire(const Client *Id_client){

//fonction a venir



}



void tri_client(const doublons *d){
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
fclose(fichier);
//utilisation du tri bulle en modifiant quelques parametre
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
//trie a bulle -> fonctionnement : si l'élement a l'indice i = 0 est supérieur a l'indice i+1 (l'element suivant) alors on permute les elements jusqu'a le tableau soit trié
   for (i = 0; i < r.ligne; i++){
            for (j = i+1; j < r.ligne; j++){
                      if (stricmp(r.donnes[i], r.donnes[j])> 0)//la fonction stricmp permet de comparer des chaines de caracteres en faisant abstraction des majuscules et miniscules
                        {
                            //permutation des valeurs
                          strcpy(r.temp,r.donnes[i]);//chaine[i]=temp
                          strcpy(r.donnes[i],r.donnes[j]);//chaine[i]=chaine[j]
                          strcpy(r.donnes[j],r.temp);//chaine[j]=temp

                        }
            }
   }

//afficher les valeurs ligne par ligne
        for(i= 0;i<r.ligne;i++){

            printf("%s\n",r.donnes[i]);
        }



}


