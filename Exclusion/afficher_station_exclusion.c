//
// Created by Yanis Denizot on 23/11/2023.
//

#include "../header.h"

// Cette fonction prend en entrée un tableau de structures 't_station' et un entier 'nb_stations'
// Elle est utilisée pour afficher le contenu de chaque station, c'est-à-dire les opérations qui y sont assignées.
void afficher_stations_exclusion(t_station *stations, int nb_stations) {
    // Boucle sur chaque station
    for (int i = 0; i < nb_stations; i++) {
        // Affiche le numéro de la station actuelle
        printf("Station %d: ", i + 1);
        // Boucle sur chaque opération de la station actuelle
        for (int j = 0; j < stations[i].taille; j++) {
            // Affiche le numéro de l'opération
            printf("%d ", stations[i].operations[j]);
        }
        // Passe à la ligne suivante après avoir affiché toutes les opérations de la station
        printf("\n");
    }
}




