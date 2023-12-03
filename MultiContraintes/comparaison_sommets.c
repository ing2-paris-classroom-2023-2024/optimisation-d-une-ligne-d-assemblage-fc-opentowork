//
// Created by guych on 30/11/2023.
//

#include "../header.h"


int est_compatible_avec_station_exclusion_precedence(t_graphe * graphe, t_station * station_actuelle, int operation) {
    // Boucle sur chaque opération déjà présente dans la station

    if (station_actuelle->taille == 0) {

        return 1;

    } else {

        for (int i = 0; i < station_actuelle->taille; i++) {
            // Récupère l'opération actuelle de la station
            int operation_station = station_actuelle->operations[i];

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


}
