#include "../header.h"

t_station * calcul_exclusion_temps(t_graphe * graphe, int *nb_stations, float tempscycle){
    // Calculer et récupérer un tableau des opérations uniques présentes dans le graphe.

    *nb_stations = 0; // Initialiser le nombre de stations à 0.

    // Allouer de la mémoire pour un tableau de stations basé sur le nombre d'opérations uniques.
    t_station *stations = malloc(graphe->ordre * sizeof(t_station));
    int * tabop= trier_operations_par_exclusion(graphe) ;

    // Initialisation de chaque station dans le tableau
    for (int i = 0; i < graphe->ordre; i++) {
        stations[i].operations = NULL; // Initialiser le tableau des opérations à NULL.
        stations[i].taille = 0; // Initialiser la taille de chaque station à 0.
        stations[i].temps_cycle=0;
    }

    // Sur chaque opération unique dans le tableau 'tab_op'
    for (int op = 0; op <= graphe->ordre-1; op++) {
        int ajoute = 0; // Un indicateur pour savoir si l'opération a été ajoutée à une station existante.

        // Essayer d'ajouter l'opération à une station existante
        for (int j = 0; j < *nb_stations; j++) {
            // Vérifier si l'opération est compatible avec la station actuelle.
            if ((est_compatible_avec_station_exclusion(graphe, &stations[j], tabop[op]))&&(stations[j].temps_cycle+
                    recherche_temps_operation(graphe,tabop[op]<=tempscycle))) {
                // Si compatible, ajouter l'opération à la station et marquer comme ajoutée.
                stations[j].temps_cycle+= recherche_temps_operation(graphe,tabop[op]);
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
            nouvelle_station.temps_cycle= recherche_temps_operation(graphe, tabop[op]);

            // Ajouter la nouvelle station au tableau de stations.
            stations[*nb_stations] = nouvelle_station;
            (*nb_stations)++; // Incrémenter le nombre de stations.
        }


    }

    // Retourner le tableau de stations créé.
    return stations;
}

void afficher_stations_exclusion_temps(t_station *stations, int nb_stations) {
    // Boucle sur chaque station
    for (int i = 0; i < nb_stations; i++) {
        // Affiche le numéro de la station actuelle
        printf("=== STATION %d: === Temps de cycle : %f \n ", i, stations[i].temps_cycle);
        // Boucle sur chaque opération de la station actuelle
        for (int j = 0; j < stations[i].taille; j++) {
            // Affiche le numéro de l'opération
            printf("%d ", stations[i].operations[j]);
        }
        // Passe à la ligne suivante après avoir affiché toutes les opérations de la station
        printf("\n");
    }
}
