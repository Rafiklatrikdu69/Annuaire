/**
 *\file fonction.h
 *\brief Si dessous vous trouverais les différentes
        fonctions et structures qui ont permis la réalisation de ce projet
 *
 *
 * \return
 *
 */

//declaration de la structure client
#pragma once//programmation modulaire
#define SIZE 20
#define TAILLECHAINE 150

typedef struct Client_
{

    char *nom_p;
    char *prenom_p;
    char *code_postal_p;
    char *ville_p;
    char telephone_p[SIZE];
    char *mel_p;
    char *profession_p;
    char val_chaine1[TAILLECHAINE];
    char val_chaine2[TAILLECHAINE];
    char nom_champ1[TAILLECHAINE];
    char nom_champ2[TAILLECHAINE];
    int critere1;
    int critere2;
    int choixFiltre ;
    int index;
    int index2;


} Client;
typedef struct Ajout_Client_ {
  char nom[TAILLECHAINE];
  char prenom[TAILLECHAINE];
  char codepostal[TAILLECHAINE];
  char ville[TAILLECHAINE];
  char telephone[TAILLECHAINE];
  char mail[TAILLECHAINE];
  char profession[TAILLECHAINE];
}Ajout_Client;
//declaration des fonctions
void saisie_ajout_client(const char *nom_annuaire,const char *nom_p,const char *prenom_p,const char *code_postal_p,const char *ville_p,const char *telephone_p,const char *mel_p,const char *profession_p);
void ajouter_Client(const char *nom_annuaire,const char *nom_p,const char *prenom_p,const char *code_postal_p,const char *ville_p,const char *telephone_p,const char *mel_p,const char *profession_p);
void Afficher_annuaire_clients(const Client *Id_client);
void Ecriture_annuaire_clients(const Client *Id_client);
void Filtrer_combiner_deux_champs(const char *nom_annuaire,const char*nom_champ1,const char*nom_champ2,const char*val_chaine1,const char*val_chaine2);
int Filtrer(const char *s1,const char *sch1,int cpt);
void Filtre_avancer(const char *nom_annuaire,const char*nom_champ1,const char*nom_champ2,const char*val_chaine1,const char*val_chaine2,Client*filtre);
int Filtrer_avancer(const char *s1,const char *sch1,int index,int cpt);
void tri_clients_par_nom( const char *nom_annuaire);
int Verifier_validite_annuaire(const char * nom_annuaire);
void Rendre_annuaire_valide(const char *nom_annuaire);
void SaisieFiltre(Client*filtre);
void sauvegarde_annuaire(const char*nom_annuaire,struct Client_*p,int size );
void saisie(Ajout_Client *ajout);
struct occurence_
{

    unsigned occurrence1;
    unsigned occurrence2;

};
typedef struct occurence_ occurence;

struct Client_ *tabRetourner(int *size,const char *nom_annuaire);



