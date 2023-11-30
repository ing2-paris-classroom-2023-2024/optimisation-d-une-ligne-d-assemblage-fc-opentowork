//
// Created by Yanis Denizot on 23/11/2023.
//
#include "../header.h"

// Définition de la fonction est_dans_le_tableau_exclusion
// Cette fonction vérifie si un élément spécifique ('element') est présent dans un tableau donné ('tableau').
// Elle prend également en entrée la taille du tableau ('taille'), qui est le nombre d'éléments dans le tableau.
int est_dans_le_tableau_exclusion(int *tableau, int taille, int element) {
    // Boucle sur chaque élément du tableau
    for (int i = 0; i < taille; i++) {
        // Vérifie si l'élément actuel du tableau est égal à l'élément recherché
        if (tableau[i] == element) {
            return 1; // Si l'élément est trouvé, retourne 1 (vrai)
        }
    }
    return 0; // Si l'élément n'est pas trouvé après avoir parcouru tout le tableau, retourne 0 (faux)
}
