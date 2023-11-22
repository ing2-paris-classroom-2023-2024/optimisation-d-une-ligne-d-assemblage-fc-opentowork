//
// Created by Yanis Denizot on 22/11/2023.
//
#include "header.h"

// Vérifie si un élément est déjà dans le tableau
int est_dans_le_tableau(int *tableau, int taille, int element) {
    for (int i = 0; i < taille; i++) {
        if (tableau[i] == element) {
            return 1; // L'élément est trouvé dans le tableau
        }
    }
    return 0; // L'élément n'est pas dans le tableau
}

int * calculer_ordre(t_graphe *graphe) {  // renvoie un tab qu'on utilise pour créer une station
    int *operations_uniques = calloc(1000, sizeof(int));
    int index = 0;

    for (int i = 0; i < graphe->taille; i++) {
        // Ajoute sommet1 s'il n'est pas déjà dans le tableau
        if (!est_dans_le_tableau(operations_uniques, index, graphe->tab_aretes[i].sommet1)) {
            operations_uniques[index++] = graphe->tab_aretes[i].sommet1;
        }
        // Ajoute sommet2 s'il n'est pas déjà dans le tableau
        if (!est_dans_le_tableau(operations_uniques, index, graphe->tab_aretes[i].sommet2)) {
            operations_uniques[index++] = graphe->tab_aretes[i].sommet2;
        }
    }

    graphe->ordre = index; // L'ordre est le nombre d'opérations uniques
    return operations_uniques;

}


void ajouter_operation_station(t_station *station, int operation) {
    station->operations = realloc(station->operations, (station->taille + 1) * sizeof(int));
    station->operations[station->taille] = operation;
    station->taille++;
}


int est_compatible_avec_station(t_graphe *graphe, t_station *station, int operation) {
    for (int i = 0; i < station->taille; i++) {
        int operation_station = station->operations[i];
        for (int j = 0; j < graphe->taille; j++) {
            if ((graphe->tab_aretes[j].sommet1 == operation && graphe->tab_aretes[j].sommet2 == operation_station) ||
                (graphe->tab_aretes[j].sommet2 == operation && graphe->tab_aretes[j].sommet1 == operation_station)) {
                return 0; // Non compatible
            }
        }
    }
    return 1; // Compatible
}
t_station *creer_stations_compatibles(t_graphe *graphe, int *nb_stations) {
    int * tab_op = calculer_ordre(graphe);
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
            if (est_compatible_avec_station(graphe, &stations[j], tab_op[op])) {
                ajouter_operation_station(&stations[j], tab_op[op]);
                ajoute = 1;
                break;
            }
        }

        if (!ajoute) {
            t_station nouvelle_station = {NULL, 0};
            ajouter_operation_station(&nouvelle_station, tab_op[op]);
            stations[*nb_stations] = nouvelle_station;
            (*nb_stations)++;
        }
    }

    return stations;
}





void afficher_stations(t_station *stations, int nb_stations) {
    for (int i = 0; i < nb_stations; i++) {
        printf("Station %d: ", i + 1);
        for (int j = 0; j < stations[i].taille; j++) {
            printf("%d ", stations[i].operations[j]);
        }
        printf("\n");
    }
}



