//
// Created by guych on 21/11/2023.
//

#include "../header.h"

t_graphe * lire_fichier(char * type_lecture) {

    // Variables de parcours
    char ligne[64];
    int compteur_lignes = 0;

    // Variables de lecture
    int operation1;
    int operation2;
    int temps_cycle;
    float temps_operation;

    // Initialisation d'un nouveau graphe
    t_graphe * nouveau_graphe = malloc(sizeof (t_graphe));

    FILE * pf;


    if (strcmp(type_lecture, "exclusions") == 0) {

        ////////////////////////////

        // Ouverture du fichier de temps de cycle
        pf = fopen("../FichiersTxt/temps_cycle.txt", "r");

        if (pf == NULL) {

            printf("Impossible d'ouvrir le fichier de temps de cycle :/\n");
            exit(EXIT_FAILURE);
        }

        // Lecture et stockage du temps de cycle
        fscanf(pf, "%d", &temps_cycle);

        nouveau_graphe->temps_cycle = temps_cycle;

        fclose(pf);
        /////////////////////////////////////

        pf = fopen("../FichiersTxt/exclusions.txt", "r");

        if (pf == NULL) {

            printf("Fichier introuvable ou inaccessible :/ \n");
            system("pause");
            exit(EXIT_FAILURE);
        }

        // On commence par compter le nombre d'entrées afin d'allouer les tableaux de stockage
        while (fgets(ligne, 64, pf)) {

            compteur_lignes = compteur_lignes + 1;
        }

        rewind(pf);

        // On alloue le tableau de stockage
        nouveau_graphe->taille = compteur_lignes;
        nouveau_graphe->tab_aretes = malloc(compteur_lignes * sizeof (t_arete));

        // On remplit le tableau de paires d'exclusions
        for (int i=0; i<compteur_lignes; i++) {

            fscanf(pf, "%d %d", &operation1, &operation2);

            nouveau_graphe->tab_aretes[i].sommet1 = operation1;
            nouveau_graphe->tab_aretes[i].sommet2 = operation2;

        }


    }
    else if (strcmp(type_lecture, "precedences/temps") == 0) {

        // Ouverture du fichier de temps de cycle
        pf = fopen("../FichiersTxt/temps_cycle.txt", "r");

        if (pf == NULL) {

            printf("Impossible d'ouvrir le fichier de temps de cycle :/\n");
            exit(EXIT_FAILURE);
        }

        // Lecture et stockage du temps de cycle
        fscanf(pf, "%d", &temps_cycle);

        nouveau_graphe->temps_cycle = temps_cycle;

        fclose(pf);







        // Ouverture du fichier de precedences
        pf = fopen("../FichiersTxt/precedences.txt", "r");

        if (pf == NULL) {

            printf("Impossible d'ouvrir le fichier de precedences :/ \n");
            exit(EXIT_FAILURE);
        }

        // On commence par compter le nombre d'entrées afin d'allouer les tableaux de stockage
        while (fgets(ligne, 64, pf)) {

            compteur_lignes = compteur_lignes + 1;
        }

        rewind(pf);

        // Allocation du tableau de stockage
        nouveau_graphe->taille = compteur_lignes;
        nouveau_graphe->tab_aretes = malloc(compteur_lignes * sizeof (t_arete));

        // On remplit le tableau de precedences
        for (int i=0; i<compteur_lignes; i++) {

            fscanf(pf, "%d %d", &operation1, &operation2);

            nouveau_graphe->tab_aretes[i].sommet1 = operation1;
            nouveau_graphe->tab_aretes[i].sommet2 = operation2;
        }






    }

    else {

        printf("Type d'operation inconnu :/ \n");
        system("pause");
        exit(EXIT_FAILURE);
    }


    // Ouverture du fichier d'operations
    pf = fopen("../FichiersTxt/operations.txt", "r");

    if (pf == NULL) {

        printf("Impossible d'ouvrir le fichier d'operations :/ \n");
        exit(EXIT_FAILURE);
    }

    // On commence par compter le nombre d'entrées afin d'allouer les tableaux de stockage
    compteur_lignes = 0;

    while (fgets(ligne, 64, pf)) {

        compteur_lignes = compteur_lignes + 1;
    }

    rewind(pf);

    // Allocation du tableau de stockage
    nouveau_graphe->ordre = compteur_lignes;
    nouveau_graphe->tab_sommets = malloc(compteur_lignes * sizeof (t_sommet));

    for (int i=0; i<compteur_lignes; i++) {

        fscanf(pf, "%d %f", &operation1, &temps_operation);

        nouveau_graphe->tab_sommets[i].numero = operation1;
        nouveau_graphe->tab_sommets[i].temps_execution = temps_operation;
    }

    fclose(pf);


    return nouveau_graphe;
}
