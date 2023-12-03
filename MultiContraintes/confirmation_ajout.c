//
// Created by guych on 01/12/2023.
//

#include "../header.h"

int confirmation_ajout(t_station * station_actuelle, t_graphe * liste_precedences, int sommet_actuel) {

    t_station * station_parcourue = station_actuelle;

    t_pile * liste_sommets1 = creer_pile(liste_precedences->ordre);

    int compteur_precedences = 0;
    int compteur_paires = 0;

    for (int i=0; i<liste_precedences->taille; i++) {

        if (liste_precedences->tab_aretes[i].sommet2 == sommet_actuel) {

            empiler(liste_sommets1, liste_precedences->tab_aretes[i].sommet1);
            compteur_precedences = compteur_precedences + 1;

        }
    }

    while (station_parcourue != NULL) {

        for (int i=0; i<station_parcourue->taille; i++) {

            for (int j=0; j<liste_sommets1->top+1; j++) {

                if (station_parcourue->operations[i] == liste_sommets1->tableau[j]) {

                    compteur_paires = compteur_paires + 1;

                    if (compteur_precedences == compteur_paires) {

                        return station_parcourue->id;
                    }
                }
            }
        }

        station_parcourue = station_parcourue->next;
    }

}