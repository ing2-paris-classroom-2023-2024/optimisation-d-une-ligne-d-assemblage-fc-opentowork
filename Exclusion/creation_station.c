//
// Created by Yanis Denizot on 22/11/2023.
//
#include "header.h"



t_station *creer_stations_compatibles_exclusion(t_graphe *graphe, int *nb_stations) {
    int * tab_op = calculer_ordre_exclusion(graphe);
    *nb_stations = 0;
    t_station *stations = malloc(graphe->ordre * sizeof(t_station));

    // Initialiser chaque station
    for (int i = 0; i < graphe->ordre; i++) {
        stations[i].operations = NULL;
        stations[i].taille = 0;
    }


    for (int op = 0; op <= graphe->ordre-1; op++) {
        int ajoute = 0;

        for (int j = 0; j < *nb_stations; j++) {
            if (est_compatible_avec_station_exclusion(graphe, &stations[j], tab_op[op])) {
                ajouter_operation_station_exclusion(&stations[j], tab_op[op]);
                ajoute = 1;
                break;
            }
        }

        if (!ajoute) {
            t_station nouvelle_station = {NULL, 0};
            ajouter_operation_station_exclusion(&nouvelle_station, tab_op[op]);
            stations[*nb_stations] = nouvelle_station;
            (*nb_stations)++;
        }
    }

    return stations;
}




