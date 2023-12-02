//
// Created by guych on 02/12/2023.
//

#include "../header.h"

void tri_tab_sommets(t_graphe * graphe_etudie) {

    int i, j;
    t_sommet tmp;

    t_sommet * tab_sommets = graphe_etudie->tab_sommets;

    for (i=1 ; i <= graphe_etudie->taille-1; i++) {

        j = i;

        while (j > 0 && recherche_temps_operation(graphe_etudie, tab_sommets[j-1].numero) > recherche_temps_operation(graphe_etudie, tab_sommets[j].numero)) {

            tmp = tab_sommets[j];
            tab_sommets[j] = tab_sommets[j-1];
            tab_sommets[j-1] = tmp;

            j--;
        }
    }
}