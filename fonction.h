/**< \file fonction.h */
#pragma once
#define SIZE 100
#define VILLE 50
#define TEL 15
/** \brief
 *
 * \param
 * \param
 * \return
 *
 */
//attention au warning
//declaration de la structure client
struct Client_{

        char nom_p[SIZE];//taille a changer avec l'allocation dynamique...
        char prenom_p[SIZE];//taille a changer avec l'allocation dynamique...
        char code_postal_p[SIZE];//taille a changer avec l'allocation dynamique...
        char ville_p[VILLE];//taille a changer avec l'allocation dynamique...
        char telephone_p[TEL];//taille a changer avec l'allocation dynamique...
        char mel_p[SIZE];//taille a changer avec l'allocation dynamique...
        char profession_p[SIZE];//taille a changer avec l'allocation dynamique...

};
typedef struct Client_ Client;//notation moins lourde
void ajoutClient(const  Client *Id_client);
void AffichageAnnuaire(const Client *Id_client);
void verifeClient( Client *Id_client);
void  RechercheClient(const Client *Id_client);
void saisirClient(   Client *Id_client);
void CopieAnnuaireFichier(const Client *Id_client);

void verif_annuaire(const Client *Id_client);
//int CompareChaine(const  void  *a,const  void  *b);
//return strcmp(pa,pb);
//déclaration de la structure doublons pour tester la validité de l'annuaire
struct doublons_{
char temp[1000];//taille a changer avec l'allocation dynamique...
char donnes[1000][1000];//taille a changer avec l'allocation dynamique...
int ligne;


 };

 typedef struct doublons_ doublons;//notation moins lourde
void tri_client(const doublons *d);










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
