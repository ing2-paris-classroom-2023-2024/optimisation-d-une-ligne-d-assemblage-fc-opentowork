//
// Created by guych on 26/11/2023.
//

#include "../header.h"

float recherche_temps_operation(t_graphe * graphe_etudie, int numero_operation) {

    float resultat;

    for (int i=0; i<graphe_etudie->ordre; i++) {

        if (graphe_etudie->tab_sommets[i].numero == numero_operation) {

            resultat = graphe_etudie->tab_sommets[i].temps_execution;
        }
    }

    return resultat;
}