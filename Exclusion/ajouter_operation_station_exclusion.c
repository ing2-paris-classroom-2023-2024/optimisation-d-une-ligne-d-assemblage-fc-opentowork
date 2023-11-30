//
// Created by Yanis Denizot on 23/11/2023.
//
#include "../header.h"


// Cette fonction est destinée à ajouter une opération (identifiée par 'operation') à une station spécifique (pointée par 'station').
void ajouter_operation_station_exclusion(t_station *station, int operation) {
    // Réallocation de la mémoire pour le tableau des opérations de la station.
    // La taille du tableau est augmentée de 1 pour accueillir la nouvelle opération.
    // 'realloc' est utilisé pour ajuster la taille du tableau déjà alloué, et il retourne un nouveau pointeur vers le tableau redimensionné.
    station->operations = realloc(station->operations, (station->taille + 1) * sizeof(int));

    // Ajout de la nouvelle opération à la fin du tableau des opérations de la station.
    // 'station->taille' indique l'index où la nouvelle opération doit être insérée.
    station->operations[station->taille] = operation;

    // Incrémentation de la taille de la station pour refléter l'ajout d'une nouvelle opération.
    station->taille++;
}
