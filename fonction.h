/**< \file fonction.h */
#pragma once//programmation modulaire
#define SIZE 20
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
        //char *nom_p;en cours de developpement-> allocation dynamique
        char *nom_p;//taille a changer avec l'allocation dynamique...
        char *prenom_p;//taille a changer avec l'allocation dynamique...
        char code_postal_p[SIZE];//taille a changer avec l'allocation dynamique...
        char *ville_p;//taille a changer avec l'allocation dynamique...
        char telephone_p[SIZE];//taille a changer avec l'allocation dynamique...
        char *mel_p;//taille a changer avec l'allocation dynamique...
        char *profession_p;//taille a changer avec l'allocation dynamique...
        char val_chaine1[256];
        char val_chaine2[256];
        char nom_champ1[256];
        char nom_champ2[256];

};
typedef struct Client_ Client;//notation moins lourde
void ajouter_Client(  const Client *Id_client);
void Afficher_annuaire_clients(const Client *Id_client);
void Ecriture_annuaire_clients(const Client *Id_client);
void Filtrer_combiner_deux_champs(const Client *Id_client);
int Filtrer(char *s1,char *sch1,char *s2,char *sch2,int index,int index2,int cpt);
void tri_client_par_nom( const Client*d,int size);
void Verifier_validite_annuaire(const Client*d,int size);
int sous_chaine(const char *s_ch, const char *ch);

struct occurence_{

        unsigned occurrence1;
        unsigned occurrence2;

};
typedef struct occurence_ occurence;


