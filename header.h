//
// Created by guych on 13/11/2023.
//

#ifndef OPTIMISATION_D_UNE_LIGNE_D_ASSEMBLAGE_FC_OPENTOWORK_HEADER_H
#define OPTIMISATION_D_UNE_LIGNE_D_ASSEMBLAGE_FC_OPENTOWORK_HEADER_H

#include <stdio.h>
#include <stdlib.h>
#include <string.h>

/// === STRUCTURES ===

// Structure de sommet
typedef struct sommet {

    int numero;
    float temps_execution;

} t_sommet;

// Structure d'une arete
/*
 * INFORMATIONS IMPORTANTES CONCERNANT LA STRUCTURE
 *
 * Bien que s'appelant "arete", cette structure est aussi utilisée pour les contraintes d'exclusions par exemple. Il s'agit d'un choix technique
 * uniquement justifié par une volonté d'uniformiser la programmation. Il ne faut donc pas hésiter à utiliser cette structure pour stocker
 * ces données !!
 *
 * */
typedef struct arete {

    int sommet1;
    int sommet2;

} t_arete;

// Structure d'un graphe
typedef struct graphe {

    int ordre;
    int taille;
    int temps_cycle;
    t_sommet * tab_sommets;
    t_arete * tab_aretes;

} t_graphe;

// Structure de pile
typedef struct pile {

    int * tableau;
    int top;

} t_pile;



typedef struct station {

    int id; // Identifiant de la station
    int * operations; // Tableau d'opérations (sommets)
    int taille;      // Nombre d'opérations dans la station
    float temps_cycle; // Temps de cycle de la station
    struct station * next; // Pointeur vers la station suivante (utilisé dans le calcul de précédences)

} t_station;

typedef struct {
    int operation;
    int occurences;
} t_operation_occurence;



/// === PROTOTYPES ===

// Sous-programmes généraux
t_graphe * lire_fichier(char * type_lecture);
t_pile * creer_pile(int taille);
void empiler(t_pile * pile, int item);
int depiler(t_pile * pile);
int seek(t_pile * pile, int item);
void tri_tab_aretes(t_graphe * graphe_etudie);
void tri_tab_sommets(t_graphe * graphe_etudie);

// Sous-programmes precedences
float recherche_temps_operation(t_graphe * graphe_etudie, int numero_operation);
int * recherche_sommets_initiaux(t_graphe * graphe_etudie, int * taille_tab_sommets_initiaux);
t_station * creer_station();
void ajouter_station(t_station ** head);
int recherche_sommet_suivant(t_graphe * graphe_etudie, t_pile * pile_sommets_ajoutes);
t_station * calcul_precedences(t_graphe * graphe_etudie);


// Sous-programmes exclusions
int est_dans_le_tableau_exclusion(int *tableau, int taille, int element);
int * calculer_ordre_exclusion(t_graphe *graphe);
void ajouter_operation_station_exclusion(t_station *station, int operation);
int est_compatible_avec_station_exclusion(t_graphe *graphe, t_station *station, int operation);
t_station *creer_stations_compatibles_exclusion(t_graphe *graphe, int *nb_stations);
void afficher_stations_exclusion(t_station *stations, int nb_stations);
int *trier_operations_par_exclusion(t_graphe *graphe);

// Sous-programmes exclusions/précédences
t_station * calcul_precedences_exclusions(t_graphe * liste_precedences, t_graphe * liste_exclusions);

// Sous-programmes exclusions/temps
t_station * calcul_exclusion_temps(t_graphe * graphe, int *nb_stations, float tempscycle);
void afficher_stations_exclusion_temps(t_station *stations, int nb_stations);


// Sous-programmes multicontraintes
int est_compatible_avec_station_exclusion_precedence(t_graphe * graphe, t_station * station_actuelle, int operation);
t_station * calcul_multicontraintes(t_graphe * liste_precedences, t_graphe * liste_exclusions);
int confirmation_ajout(t_station * station_actuelle, t_graphe * liste_precedences, int sommet_actuel);

#endif //OPTIMISATION_D_UNE_LIGNE_D_ASSEMBLAGE_FC_OPENTOWORK_HEADER_H
