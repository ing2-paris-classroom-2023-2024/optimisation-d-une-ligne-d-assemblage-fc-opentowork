//
// Created by guych on 26/11/2023.
//

#include "../header.h"

void tri_tab_aretes(t_graphe * graphe_etudie) {

    int i, j;
    t_arete tmp;

    t_arete * tab_aretes = graphe_etudie->tab_aretes;

    for (i=1 ; i <= graphe_etudie->taille-1; i++) {

        j = i;

        while (j > 0 && recherche_temps_operation(graphe_etudie, tab_aretes[j-1].sommet1) > recherche_temps_operation(graphe_etudie, tab_aretes[j].sommet1)) {

            tmp = tab_aretes[j];
            tab_aretes[j] = tab_aretes[j-1];
            tab_aretes[j-1] = tmp;

            j--;
        }
    }
}