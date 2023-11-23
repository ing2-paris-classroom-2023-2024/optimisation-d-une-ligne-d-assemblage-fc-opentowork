//
// Created by Yanis Denizot on 23/11/2023.
//
#include "header.h"
// Vérifie si un élément est déjà dans le tableau
int est_dans_le_tableau_exclusion(int *tableau, int taille, int element) {
    for (int i = 0; i < taille; i++) {
        if (tableau[i] == element) {
            return 1; // L'élément est trouvé dans le tableau
        }
    }
    return 0; // L'élément n'est pas dans le tableau
}
