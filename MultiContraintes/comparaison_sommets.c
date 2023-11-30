//
// Created by guych on 30/11/2023.
//

#include "../header.h"

int compter_predecesseurs(int sommet, t_graphe *liste_precedences) {
    int compteur = 0;
    for (int i = 0; i < liste_precedences->taille; i++) {
        if (liste_precedences->tab_aretes[i].sommet1 == sommet) {
            compteur = compteur + 1 + compter_predecesseurs(liste_precedences->tab_aretes[i].sommet2, liste_precedences);
        }
    }
    return compteur;
}

int comparer_sommet( int sommet1, int sommet2, t_graphe *liste_precedences){
    int compteur_sommet1 = compter_predecesseurs(sommet1, liste_precedences);
    int compteur_sommet2 = compter_predecesseurs(sommet2, liste_precedences);

    if(compteur_sommet2< compteur_sommet1){
        return compteur_sommet2;
    }
    else{
        return compteur_sommet1;
    }

}



int est_compatible_avec_station_exclusion_precedence(t_graphe *graphe, t_pile * pile, int operation) {
    // Boucle sur chaque opération déjà présente dans la station
    for (int i = 0; i < pile->top+1; i++) {
        // Récupère l'opération actuelle de la station
        int operation_station = pile->tableau[i];

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
