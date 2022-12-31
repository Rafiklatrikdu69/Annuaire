/**
 *\file fonction.h
 *\brief Si dessous vous trouverais les différentes
        fonctions et structures qui ont permis la réalisation de ce projet
 *
 *
 * \return
 *
 */
//attention au warning
//declaration de la structure client
#pragma once//programmation modulaire
#define SIZE 20

typedef struct Client_{

        char *nom_p;
        char *prenom_p;
        char code_postal_p[SIZE];
        char *ville_p;
        char telephone_p[SIZE];
        char *mel_p;
        char *profession_p;
        char **donnes;//tableau 2D allocation dynamique
        char val_chaine1[256];
        char val_chaine2[256];
        char nom_champ1[256];
        char nom_champ2[256];

} Client;

//declaration des fonctions
void ajouter_Client(  const Client *Id_client,const char *annuaireCSV);
void Afficher_annuaire_clients(const Client *Id_client);
void Ecriture_annuaire_clients(const Client *Id_client);
void Filtrer_combiner_deux_champs(const Client *Id_client,const char *annuaireCSV);
int Filtrer(char *s1,char *sch1,int index,int cpt);
void tri_client_par_nom( const Client*d,int size,const char *annuaireCSV);
void Verifier_validite_annuaire(const Client*d,int size);
void Rendre_annuaire_valide(const Client *Id_client);

struct occurence_{

        unsigned occurrence1;
        unsigned occurrence2;

};
typedef struct occurence_ occurence;


