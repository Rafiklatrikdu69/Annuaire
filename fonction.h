#pragma once
#define SIZE 256
#define VILLE 100
#define TEL 15
struct Client_{
        char NomAnnuaire[SIZE];
        char Nom[SIZE];
        char prenom[SIZE];
        char codePostal[SIZE];
        char Ville[VILLE];
        char NumTel[TEL];
        char Adresse_mail[SIZE];
        char profession[SIZE];
        //Variable pour trie des clients
        char RecNom[SIZE];
//char NomRecherche[SIZE];

/*char rechercheNom[size];*/

};
typedef struct Client_ Client;
void ajoutClient(Client *Id_client);
void AffichageAnnuaire(const Client *Id_client);
void  RechercheClient(const Client *Id_client);
void tri_client( Client *Id_client);
void saisirClient(  Client *Id_client);


//int CompareChaine(const  void  *a,const  void  *b);
//return strcmp(pa,pb);












/*#ifndef _MYFUNCTIONS_H_
#define _MYFUNCCTIONS_H_*/
/**
*
*
*
*/
/*unsigned long int factorielle(int n);*/
/*int RechercheClient(int Id_client);*/
/** \brief
 *
 * \return void
 *
 */
/*void AjouterClient();*/
/*
#endif


*/
