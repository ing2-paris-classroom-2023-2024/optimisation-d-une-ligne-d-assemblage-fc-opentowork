//
// Created by Yanis Denizot on 22/11/2023.
//
#include "../header.h"

// Fonction de comparaison pour le tri

int compare( void *a, void *b) {
    const t_operation_occurence *op1 = (t_operation_occurence *)a;
    const t_operation_occurence *op2 = (t_operation_occurence *)b;
    return op2->occurences - op1->occurences;  // Tri par ordre décroissant d'occurrences
}

int *trier_operations_par_exclusion(t_graphe *graphe) {
    int max_operation = 100;
    for (int i = 0; i < graphe->taille; i++) {
        if (graphe->tab_aretes[i].sommet1 > max_operation) {
            max_operation = graphe->tab_aretes[i].sommet1;
        }
        if (graphe->tab_aretes[i].sommet2 > max_operation) {
            max_operation = graphe->tab_aretes[i].sommet2;
        }
    }

    t_operation_occurence *occurences = calloc(max_operation + 1, sizeof(t_operation_occurence));
    for (int i = 0; i < graphe->taille; i++) {
        occurences[graphe->tab_aretes[i].sommet1].operation = graphe->tab_aretes[i].sommet1;
        occurences[graphe->tab_aretes[i].sommet2].operation = graphe->tab_aretes[i].sommet2;
        occurences[graphe->tab_aretes[i].sommet1].occurences++;
        occurences[graphe->tab_aretes[i].sommet2].occurences++;
    }

    qsort(occurences, max_operation + 1, sizeof(t_operation_occurence), compare);
    int *tri_operations = malloc(graphe->ordre * sizeof(int));
    int count = 0;  // Compteur pour le nombre d'opérations ajoutées

// Remplir avec les opérations triées
    for (int i = 0; i <= max_operation; i++) {
        if (occurences[i].occurences > 0) {
            tri_operations[count++] = occurences[i].operation;
        }
    }

    free(occurences);

// Ajouter les opérations manquantes
    for (int i = 0; i < graphe->ordre; i++) {
        int operation = graphe->tab_sommets[i].numero;
        int found = 0;
        for (int j = 0; j < count; j++) {
            if (tri_operations[j] == operation) {
                found = 1;
                break;
            }
        }
        if (!found) {
            tri_operations[count++] = operation;
        }
    }

    return tri_operations;
}



// Définition de la fonction creer_stations_compatibles_exclusion
// Cette fonction crée et retourne un tableau de structures 't_station' qui contient des opérations compatibles, en tenant compte des exclusions.
t_station *creer_stations_compatibles_exclusion(t_graphe *graphe, int *nb_stations) {
    // Calculer et récupérer un tableau des opérations uniques présentes dans le graphe.

    *nb_stations = 0; // Initialiser le nombre de stations à 0.

    // Allouer de la mémoire pour un tableau de stations basé sur le nombre d'opérations uniques.
    t_station *stations = malloc(graphe->ordre * sizeof(t_station));
    int * tabop= trier_operations_par_exclusion(graphe) ;

    // Initialisation de chaque station dans le tableau
    for (int i = 0; i < graphe->ordre; i++) {
        stations[i].operations = NULL; // Initialiser le tableau des opérations à NULL.
        stations[i].taille = 0; // Initialiser la taille de chaque station à 0.
    }

    // Sur chaque opération unique dans le tableau 'tab_op'
    for (int op = 0; op <= graphe->ordre-1; op++) {
        int ajoute = 0; // Un indicateur pour savoir si l'opération a été ajoutée à une station existante.

        // Essayer d'ajouter l'opération à une station existante
        for (int j = 0; j < *nb_stations; j++) {
            // Vérifier si l'opération est compatible avec la station actuelle.
            if (est_compatible_avec_station_exclusion(graphe, &stations[j], tabop[op])) {
                // Si compatible, ajouter l'opération à la station et marquer comme ajoutée.
                ajouter_operation_station_exclusion(&stations[j],tabop[op] );
                ajoute = 1; // Marquer comme ajoutée.
                break; // Sortir de la boucle car l'opération a été ajoutée.
            }
        }

        // Si l'opération n'a pas été ajoutée à une station existante, créer une nouvelle station.
        if (!ajoute) {
            t_station nouvelle_station = {0,NULL, 0}; // Créer une nouvelle station vide.
            // Ajouter l'opération à la nouvelle station.
            ajouter_operation_station_exclusion(&nouvelle_station, tabop[op]);
            // Ajouter la nouvelle station au tableau de stations.
            stations[*nb_stations] = nouvelle_station;
            (*nb_stations)++; // Incrémenter le nombre de stations.
        }
    }

    // Retourner le tableau de stations créé.
    return stations;
}



