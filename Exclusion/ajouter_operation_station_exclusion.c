//
// Created by Yanis Denizot on 23/11/2023.
//
#include "../header.h"

void ajouter_operation_station_exclusion(t_station *station, int operation) {
    station->operations = realloc(station->operations, (station->taille + 1) * sizeof(int));
    station->operations[station->taille] = operation;
    station->taille++;
}

