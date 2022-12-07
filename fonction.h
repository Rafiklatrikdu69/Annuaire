#pragma once
#define SIZE 256
#define VILLE 100
#define TEL 15
struct Client_{

        char nom_p[SIZE];
        char prenom_p[SIZE];
        char code_postal_p[SIZE];
        char ville_p[VILLE];
        char telephone_p[TEL];
        char mel_p[SIZE];
        char profession_p[SIZE];
        //Variable pour trie des clients
        char RecAdresse[SIZE];
//char nom_pRecherche[SIZE];

/*char recherchenom_p[size];*/

};
typedef struct Client_ Client;
void ajoutClient( const Client *Id_client);
void AffichageAnnuaire(const Client *Id_client);
void verifeClient( Client *Id_client);
void  RechercheClient(const Client *Id_client);
//void tri_client( Client *Id_client, Id_client->nom_p);
void saisirClient(   Client *Id_client);
void CopieAnnuaireFichier(const Client *Id_client);


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
