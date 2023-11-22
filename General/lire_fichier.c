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

    // Initialisation d'un nouveau graphe
    t_graphe * nouveau_graphe = malloc(sizeof (t_graphe));

    FILE * pf;


    if (strcmp(type_lecture, "exclusions") == 0) {

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

        // On alloue les tableaux de stockage
        nouveau_graphe->taille = compteur_lignes;
        nouveau_graphe->tab_aretes = malloc(compteur_lignes * sizeof (t_arete));

        // On remplit le tableau de paires d'exclusions
        for (int i=0; i<compteur_lignes; i++) {

            fscanf(pf, "%d %d", &operation1, &operation2);

            nouveau_graphe->tab_aretes[i].sommet1 = operation1;
            nouveau_graphe->tab_aretes[i].sommet2 = operation2;

        }

    } else if (strcmp(type_lecture, "precedences/temps") == 0) {



    } else {

        printf("Type d'operation inconnu :/ \n");
        system("pause");
        exit(EXIT_FAILURE);
    }

    return nouveau_graphe;
}
