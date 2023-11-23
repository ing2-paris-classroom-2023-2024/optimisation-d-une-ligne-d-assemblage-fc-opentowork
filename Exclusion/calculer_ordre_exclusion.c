//
// Created by Yanis Denizot on 23/11/2023.
//
#include "../header.h"


// Cette fonction a pour but de générer et de renvoyer un tableau contenant toutes les opérations uniques d'un graphe.
// Elle prend en entrée un pointeur vers un graphe ('t_graphe *graphe').
int * calculer_ordre_exclusion(t_graphe *graphe) {
    // Allocation d'un tableau pour stocker les opérations uniques.
    // Le tableau est initialisé à 0 pour toutes les valeurs grâce à 'calloc'.
    // 1000 est une valeur arbitraire qui suppose un nombre maximum d'opérations uniques.
    int *operations_uniques = calloc(1000, sizeof(int));
    int index = 0; // Un index pour suivre la position actuelle dans le tableau 'operations_uniques'.

    // Boucle sur chaque arête du graphe
    for (int i = 0; i < graphe->taille; i++) {
        // Vérifie si 'sommet1' de l'arête courante est déjà dans le tableau 'operations_uniques'.
        if (!est_dans_le_tableau_exclusion(operations_uniques, index, graphe->tab_aretes[i].sommet1)) {
            // Si 'sommet1' n'est pas dans le tableau, il est ajouté et l'index est incrémenté.
            operations_uniques[index++] = graphe->tab_aretes[i].sommet1;
        }
        // La même vérification est effectuée pour 'sommet2' de l'arête courante.
        if (!est_dans_le_tableau_exclusion(operations_uniques, index, graphe->tab_aretes[i].sommet2)) {
            operations_uniques[index++] = graphe->tab_aretes[i].sommet2;
        }
    }

    // Mise à jour de l'attribut 'ordre' du graphe pour refléter le nombre total d'opérations uniques trouvées.
    graphe->ordre = index;
    // La fonction renvoie le tableau des opérations uniques.
    return operations_uniques;
}
