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

};
typedef struct Client_ Client;//notation moins lourde
void ajouter_Client(  const Client *Id_client);
void Afficher_annuaire_clients(const Client *Id_client);
void Ecriture_annuaire_clients(const Client *Id_client);
void Separation_mel_p( Client *Id_client);


//déclaration de la structure doublons pour tester la validité de l'annuaire
struct doublons_{

        char temp[1000];//taille a changer avec l'allocation dynamique...
        char donnes[1000][1000];//taille a changer avec l'allocation dynamique...
        unsigned ligne;

};
typedef struct doublons_ doublons;//notation moins lourde
void tri_client(const doublons *d);
void Verifier_validite_annuaire(const doublons *d);




struct occurence_{

        unsigned occurrence1;
        unsigned occurrence2;

};
typedef struct occurence_ occurence;
