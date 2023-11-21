//
// Created by Yanis Denizot on 21/11/2023.
//
#include "header.h"
ListeExclusions* LireExclusions( char* nomFichier) {
    FILE* fichier = fopen(nomFichier, "r");
    if (!fichier) {
        perror("Erreur lors de l'ouverture du fichier");
        return NULL;
    }

    ListeExclusions* liste = malloc(sizeof(ListeExclusions));
    liste->nombreExclusions = 0;
    liste->exclusions = NULL;

    int operation1, operation2;
    while (fscanf(fichier, "%d %d", &operation1, &operation2) == 2) {
        liste->nombreExclusions++;
        liste->exclusions = realloc(liste->exclusions, liste->nombreExclusions * sizeof(Exclusion));
        liste->exclusions[liste->nombreExclusions - 1].operation1 = operation1;
        liste->exclusions[liste->nombreExclusions - 1].operation2 = operation2;
    }

    fclose(fichier);
    return liste;
}
