//
// Created by guych on 13/11/2023.
//

#ifndef OPTIMISATION_D_UNE_LIGNE_D_ASSEMBLAGE_FC_OPENTOWORK_HEADER_H
#define OPTIMISATION_D_UNE_LIGNE_D_ASSEMBLAGE_FC_OPENTOWORK_HEADER_H

#include <stdio.h>
#include <stdlib.h>
#include <string.h>
typedef struct {
    int operation1;
    int operation2;
} Exclusion;

typedef struct {
    Exclusion* exclusions;
    int nombreExclusions;
} ListeExclusions;

ListeExclusions* LireExclusions(char* nomFichier);
void AfficherExclusions(ListeExclusions* liste);

/// === STRUCTURES ===

// Structure de sommet
typedef struct sommet {

    int numero;
    int temps_execution;

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
    int poids;

} t_arete;

// Structure d'un graphe
typedef struct graphe {

    int ordre;
    int taille;
    int temps_cycle;
    t_sommet * tab_sommets;
    t_arete * tab_aretes;

} t_graphe;



/// === PROTOTYPES ===

// Sous-programmes généraux
t_graphe * lire_fichier(char * type_lecture);

#endif //OPTIMISATION_D_UNE_LIGNE_D_ASSEMBLAGE_FC_OPENTOWORK_HEADER_H
