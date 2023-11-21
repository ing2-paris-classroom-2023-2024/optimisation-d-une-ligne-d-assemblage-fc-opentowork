//
// Created by guych on 13/11/2023.
//

#ifndef OPTIMISATION_D_UNE_LIGNE_D_ASSEMBLAGE_FC_OPENTOWORK_HEADER_H
#define OPTIMISATION_D_UNE_LIGNE_D_ASSEMBLAGE_FC_OPENTOWORK_HEADER_H

#include <stdio.h>
#include <stdlib.h>
#include <string.h>
typedef struct {
    int operation1;
    int operation2;
} Exclusion;

typedef struct {
    Exclusion* exclusions;
    int nombreExclusions;
} ListeExclusions;

ListeExclusions* LireExclusions(char* nomFichier);
void AfficherExclusions(ListeExclusions* liste);

#endif //OPTIMISATION_D_UNE_LIGNE_D_ASSEMBLAGE_FC_OPENTOWORK_HEADER_H
