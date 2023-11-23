//
// Created by Yanis Denizot on 23/11/2023.
//
#include "header.h"
int est_compatible_avec_station_exclusion(t_graphe *graphe, t_station *station, int operation) {
    for (int i = 0; i < station->taille; i++) {
        int operation_station = station->operations[i];
        for (int j = 0; j < graphe->taille; j++) {
            if ((graphe->tab_aretes[j].sommet1 == operation && graphe->tab_aretes[j].sommet2 == operation_station) ||
                (graphe->tab_aretes[j].sommet2 == operation && graphe->tab_aretes[j].sommet1 == operation_station)) {
                return 0; // Non compatible
            }
        }
    }
    return 1; // Compatible
}