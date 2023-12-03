//
// Created by guych on 26/11/2023.
//

#include "../header.h"

int * recherche_sommets_initiaux(t_graphe * graphe_etudie, int * taille_tab_sommets_initiaux) {

    // Initialisation du tableau final
    int * tab_final;

    // Initialisation du compteur de sommets initiaux
    int compteur_sommets_initiaux = 0;

    // Initialisation de la variable de stockage du sommet actuel et de detection de paire
    int sommet_actuel;
    int detection_sommet;

    for (int i=0; i<graphe_etudie->taille; i++) {

        sommet_actuel = graphe_etudie->tab_aretes[i].sommet1;

        detection_sommet = 0;

        for (int j=0; j<graphe_etudie->taille; j++) {

            if (sommet_actuel == graphe_etudie->tab_aretes[j].sommet2) {

                detection_sommet = 1;
            }

        }

        if (detection_sommet == 0) {

            compteur_sommets_initiaux = compteur_sommets_initiaux + 1;
        }
    }

    // Allocation du tableau final contenant les sommets initiaux
    *taille_tab_sommets_initiaux = compteur_sommets_initiaux;

    tab_final = malloc(compteur_sommets_initiaux * sizeof (int));

    // Remplissage du tableau final
    int k = 0;

    for (int i=0; i<graphe_etudie->taille; i++) {

        sommet_actuel = graphe_etudie->tab_aretes[i].sommet1;

        detection_sommet = 0;

        for (int j=0; j<graphe_etudie->taille; j++) {

            if (sommet_actuel == graphe_etudie->tab_aretes[j].sommet2) {

                detection_sommet = 1;
            }

        }

        if (detection_sommet == 0) {

            tab_final[k] = sommet_actuel;
            k = k + 1;
        }
    }

    return tab_final;

}