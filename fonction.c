#include <stdio.h>
#include <stdlib.h>
#include<string.h>
#include "fonction.h"
//#include<stdbool.h>
void AffichageAnnuaire(const Client *Id_client){
 FILE*fichier;
   fichier = fopen("fichier.txt","r");
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

   fclose(fichier);
        







        
        
}

void CopieAnnuaireFichier(const Client *Id_client){

    FILE*fichier;
    FILE*fichier2;
    fichier= fopen("Annuaire.csv","r");
    fichier2= fopen("fichier.txt","w");
    char c;

    while(!feof(fichier)){
        c=fgetc(fichier);

        fprintf(fichier2,"%c",c);
    }

    fclose(fichier);
    fclose(fichier2);
    
}




void saisirClient(  Client * Id_client){
//cette fonction permet a l'utilisateur d'entrer ces donnes -> utilsation de fgets pour les chaines de  caracteres


            printf("La premiere lettre doit etre en majuscule ! \n");

            do {
            printf("Nom\n");
            fgets(Id_client->nom_p,sizeof(Id_client->nom_p),stdin);
            Id_client->nom_p[strcspn(Id_client->nom_p,"\r\n")] = '\0';
            }while( Id_client->nom_p[0] <= 'z' && Id_client->nom_p[0]>= 'a');


            do{
            printf("Prenom\n");
            fgets(Id_client->prenom_p,sizeof(Id_client->prenom_p),stdin);
            Id_client->prenom_p[strcspn(Id_client->prenom_p,"\r\n")] = '\0';
            }while(Id_client->prenom_p[0] <= 'z' && Id_client->prenom_p[0]>= 'a');



            printf("Code postal\n");
            fgets(Id_client->code_postal_p,sizeof(Id_client->code_postal_p),stdin);
            Id_client->code_postal_p[strcspn(Id_client->code_postal_p,"\r\n")] = '\0';



            do {
            printf("Ville\n");
            fgets(Id_client->ville_p,sizeof(Id_client->ville_p),stdin);
            Id_client->ville_p[strcspn(Id_client->ville_p,"\r\n")] = '\0';
            }while(Id_client->ville_p[0] <= 'z' && Id_client->ville_p[0]>= 'a');

            printf("Numero de telephone\n");
            fgets(Id_client->telephone_p,sizeof(Id_client->telephone_p),stdin);
            Id_client->telephone_p[strcspn(Id_client->telephone_p,"\r\n")] = '\0';



            do {
            printf("Adresse mail\n");
            fgets(Id_client->mel_p,sizeof(Id_client->mel_p),stdin);
            Id_client->mel_p[strcspn(Id_client->mel_p,"\r\n")] = '\0';
            }while((Id_client->mel_p[0] == '\0') || (Id_client->mel_p[0] <= 'z' && Id_client->mel_p[0]>= 'a'));



            do{
            printf("profession_p\n");
            fgets(Id_client->profession_p,sizeof(Id_client->profession_p),stdin);
            Id_client->profession_p[strcspn(Id_client->profession_p,"\r\n")] = '\0';
            }while(Id_client->profession_p[0] <= 'z' && Id_client->profession_p[0]>= 'a');




}

void verifeClient( Client *Id_client){
//cette fonction permet de séparer les emails dans un fichier a part pour par la suite verifier si la chaine mel_p est présente
FILE*fichier;
FILE*fichier2;
   fichier = fopen("fichier.txt","r");
   fichier2 = fopen("fichier2.txt","w");
   char c;
   char ch;
   int i = 0;
   //char chaine[30] = "rafik@gmail.com";
   //char chaine[30] = "rafik@gmail.com";

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




void ajoutClient( const Client *Id_client){
//cette fonction compare mel_p donner en entrée et verifier si elle est deja présente dans le fichier 
    FILE*fichier;
   fichier = fopen("fichier2.txt","r");//ouverture du fichier en lecture pour lire les adresses mails
   char chaine[256];
   char temp[] = "william.blanchard-foucher@server.fr";//cette variable permet de stocker temporairement la chaine
   char chaine2[256];
                printf("entrer votre chaine:");
                scanf("%s",&chaine);
        while(!feof(fichier)){
                fscanf(fichier,"%s",chaine2);//cela permet de scanner le fichier 
                //printf("%s",chaine2);
                strcpy(temp,chaine2);//je copie cette chaine qui est scanner dans ma variable temp
                //printf("%s\n",temp);
                    if(strcmp(temp,chaine) == 0){//utilisation strcmp qui permet de comparer deux chaine si les deux chaine sont égales alors la chaine et deja presente donc mel_p n'est pas valide
                        printf("la chaine :%s existe deja",chaine);
                        break;
                    }
                    else{
                        //printf("la chaine :%s n' existe pas\n",chaine);
                    }
}
}
   /*
   printf("%s",chaine2);
   printf("%s",chaine);


}
/*
void tri_client(  Client *Id_client, Id_client->nom_p)
 {
   char *temp;
   int i, j;


   for (i =0;i < taille -1; i++){

    for (j = i+1; j <taille; j++){
    if(strcmp(ch[i],ch[j])>0)
    {

     temp = ch[i];
          ch[i] = ch[j];
          ch[j] = temp;

    }

    }
   }


}

*/




        /*
void RechercheClient( const Client *Id_client){


    FILE*fichier;
    fichier = fopen("AnnuaireClient.txt","r");
   // char *compare;

char c;

    while (c = fgetc(fichier),!feof(fichier))//tant que le caractere n'est pas le dernier afficher tout
    {

fscanf(fichier,"%s",&Id_client->nom_p);
fscanf(fichier,"%s",&Id_client->prenom_p);
fscanf(fichier,"%s",&Id_client->code_postal_p);
fscanf(fichier,"%s",&Id_client->ville_p);
fscanf(fichier,"%s",&Id_client->telephone_p);
fscanf(fichier,"%s",&Id_client->mel_p);
fscanf(fichier,"%s",&Id_client->profession_p);

if(strncmp(Id_client->nom_pRecherche,Id_client->nom_p,sizeof(Id_client->nom_pRecherche) !=1)){
     //printf("mot introuvable\n");
}
else{

    printf("%s\t",Id_client->nom_p);
    printf("%s\t",Id_client->prenom_p);
    printf("%s\t",Id_client->code_postal_p);
    printf("%s\t",Id_client->ville_p);
    printf("%s\t",Id_client->telephone_p);
    printf("%s\t",Id_client->mel_p);
    printf("%s\t",Id_client->profession_p);
    printf("\n");
}

    }



fclose(fichier);


}
*/



