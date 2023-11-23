//
// Created by Yanis Denizot on 23/11/2023.
//
#include "../header.h"
// Définition de la fonction est_compatible_avec_station_exclusion
// Cette fonction vérifie si une opération spécifique ('operation') peut être ajoutée à une station donnée ('station')
// sans violer les contraintes d'exclusion spécifiées dans le graphe ('graphe').
int est_compatible_avec_station_exclusion(t_graphe *graphe, t_station *station, int operation) {
    // Boucle sur chaque opération déjà présente dans la station
    for (int i = 0; i < station->taille; i++) {
        // Récupère l'opération actuelle de la station
        int operation_station = station->operations[i];

        // Boucle sur chaque arête (contrainte d'exclusion) du graphe
        for (int j = 0; j < graphe->taille; j++) {
            // Vérifie si l'opération à ajouter est en conflit avec l'opération actuelle de la station.
            // Un conflit se produit si une paire d'exclusion entre ces deux opérations existe dans le graphe.
            if ((graphe->tab_aretes[j].sommet1 == operation && graphe->tab_aretes[j].sommet2 == operation_station) ||
                (graphe->tab_aretes[j].sommet2 == operation && graphe->tab_aretes[j].sommet1 == operation_station)) {
                return 0; // Retourne 0 si un conflit est trouvé, indiquant que l'opération n'est pas compatible.
            }
        }
    }
    return 1; // Retourne 1 si aucune incompatibilité n'est trouvée, indiquant que l'opération est compatible.
}
