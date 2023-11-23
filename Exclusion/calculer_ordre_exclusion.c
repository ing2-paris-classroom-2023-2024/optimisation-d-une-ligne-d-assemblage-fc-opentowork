//
// Created by Yanis Denizot on 23/11/2023.
//
#include "header.h"


int * calculer_ordre_exclusion(t_graphe *graphe) {  // renvoie un tab qu'on utilise pour créer une station
    int *operations_uniques = calloc(1000, sizeof(int));
    int index = 0;

    for (int i = 0; i < graphe->taille; i++) {
        // Ajoute sommet1 s'il n'est pas déjà dans le tableau
        if (!est_dans_le_tableau_exclusion(operations_uniques, index, graphe->tab_aretes[i].sommet1)) {
            operations_uniques[index++] = graphe->tab_aretes[i].sommet1;
        }
        // Ajoute sommet2 s'il n'est pas déjà dans le tableau
        if (!est_dans_le_tableau_exclusion(operations_uniques, index, graphe->tab_aretes[i].sommet2)) {
            operations_uniques[index++] = graphe->tab_aretes[i].sommet2;
        }
    }

    graphe->ordre = index; // L'ordre est le nombre d'opérations uniques
    return operations_uniques;

}
