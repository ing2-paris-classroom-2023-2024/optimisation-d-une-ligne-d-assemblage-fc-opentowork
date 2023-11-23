//
// Created by Yanis Denizot on 22/11/2023.
//
#include "../header.h"


// Définition de la fonction creer_stations_compatibles_exclusion
// Cette fonction crée et retourne un tableau de structures 't_station' qui contient des opérations compatibles, en tenant compte des exclusions.
t_station *creer_stations_compatibles_exclusion(t_graphe *graphe, int *nb_stations) {
    // Calculer et récupérer un tableau des opérations uniques présentes dans le graphe.
    int * tab_op = calculer_ordre_exclusion(graphe);
    *nb_stations = 0; // Initialiser le nombre de stations à 0.

    // Allouer de la mémoire pour un tableau de stations basé sur le nombre d'opérations uniques.
    t_station *stations = malloc(graphe->ordre * sizeof(t_station));

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
            if (est_compatible_avec_station_exclusion(graphe, &stations[j], tab_op[op])) {
                // Si compatible, ajouter l'opération à la station et marquer comme ajoutée.
                ajouter_operation_station_exclusion(&stations[j], tab_op[op]);
                ajoute = 1; // Marquer comme ajoutée.
                break; // Sortir de la boucle car l'opération a été ajoutée.
            }
        }

        // Si l'opération n'a pas été ajoutée à une station existante, créer une nouvelle station.
        if (!ajoute) {
            t_station nouvelle_station = {NULL, 0}; // Créer une nouvelle station vide.
            // Ajouter l'opération à la nouvelle station.
            ajouter_operation_station_exclusion(&nouvelle_station, tab_op[op]);
            // Ajouter la nouvelle station au tableau de stations.
            stations[*nb_stations] = nouvelle_station;
            (*nb_stations)++; // Incrémenter le nombre de stations.
        }
    }

    // Retourner le tableau de stations créé.
    return stations;
}



