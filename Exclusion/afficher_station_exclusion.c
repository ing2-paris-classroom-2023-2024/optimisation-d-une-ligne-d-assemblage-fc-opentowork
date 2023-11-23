//
// Created by Yanis Denizot on 23/11/2023.
//

#include "../header.h"
void afficher_stations_exclusion(t_station *stations, int nb_stations) {
    for (int i = 0; i < nb_stations; i++) {
        printf("Station %d: ", i + 1);
        for (int j = 0; j < stations[i].taille; j++) {
            printf("%d ", stations[i].operations[j]);
        }
        printf("\n");
    }
}



