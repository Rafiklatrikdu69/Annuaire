#include <stdio.h>
#include <stdlib.h>
#include<string.h>
#include "fonction.h"

void AffichageAnnuaire(const Client *Id_client){
FILE*fichier;
int i;
char c;


fichier = fopen("AnnuaireClient.txt","r");
        fscanf(fichier,"%s",&Id_client->nom);
        fscanf(fichier,"%s",&Id_client->prenom);
        fscanf(fichier,"%s",&Id_client->codePostal);
        fscanf(fichier,"%s",&Id_client->Ville);
        fscanf(fichier,"%s",&Id_client->NumTel);
        fscanf(fichier,"%s",&Id_client->Adresse_mail);
        fscanf(fichier,"%s",&Id_client->profession);

 c = fgetc(fichier);
    while (c != EOF)//tant que le caractere n'est pas le dernier afficher tout
    {
        printf ("%c", c);
        c = fgetc(fichier);
    }


        printf("%s\t",Id_client->nom);
        printf("%s\t",Id_client->prenom);
        printf("%s\t",Id_client->codePostal);
        printf("%s\t",Id_client->Ville);
        printf("%s\t",Id_client->NumTel);
        printf("%s\t",Id_client->Adresse_mail);
        printf("%s\n",Id_client->profession);

    fclose(fichier);

        }
        

void ajoutClient(Client *Id_client){
    FILE*fichier;
    fichier = fopen("AnnuaireClient.txt","w");

        printf("Nom\n");
  fgets(Id_client->nom,256,stdin);

  printf("prenom\n");
  fgets(Id_client->prenom,256,stdin);


  printf("codePostal\n");
  fgets(Id_client->codePostal,256,stdin);


  printf("Ville\n");
   fgets(Id_client->Ville,256,stdin);


  printf("NumTel\n");
    fgets(Id_client->NumTel,10,stdin);


  printf("Adresse_mail\n");
    fgets(Id_client->Adresse_mail,256,stdin);


    printf("profession\n");
      fgets(Id_client->profession,256,stdin);


fprintf(fichier,"%s\t",Id_client->nom);
fprintf(fichier,"%s\t",Id_client->prenom);
fprintf(fichier,"%s\t",Id_client->codePostal);
fprintf(fichier,"%s\t",Id_client->Ville);
fprintf(fichier,"%s\t",Id_client->NumTel);
fprintf(fichier,"%s\t",Id_client->Adresse_mail);
fprintf(fichier,"%s\t",Id_client->profession);
fprintf(fichier,"\n");

fclose(fichier);

        }
        /*
void RechercheClient( const Client *Id_client){


    FILE*fichier;
    fichier = fopen("AnnuaireClient.txt","r");
   // char *compare;

char c;

    while (c = fgetc(fichier),!feof(fichier))//tant que le caractere n'est pas le dernier afficher tout
    {

fscanf(fichier,"%s",&Id_client->nom);
fscanf(fichier,"%s",&Id_client->prenom);
fscanf(fichier,"%s",&Id_client->codePostal);
fscanf(fichier,"%s",&Id_client->Ville);
fscanf(fichier,"%s",&Id_client->NumTel);
fscanf(fichier,"%s",&Id_client->Adresse_mail);
fscanf(fichier,"%s",&Id_client->profession);

if(strncmp(Id_client->NomRecherche,Id_client->nom,sizeof(Id_client->NomRecherche) !=1)){
     //printf("mot introuvable\n");
}
else{

    printf("%s\t",Id_client->nom);
    printf("%s\t",Id_client->prenom);
    printf("%s\t",Id_client->codePostal);
    printf("%s\t",Id_client->Ville);
    printf("%s\t",Id_client->NumTel);
    printf("%s\t",Id_client->Adresse_mail);
    printf("%s\t",Id_client->profession);
    printf("\n");
}

    }



fclose(fichier);


}
*/



