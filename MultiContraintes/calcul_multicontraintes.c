#include "../header.h"

t_station * calcul_multicontraintes(t_graphe * liste_exclusion, t_graphe * liste_precedences, t_station * station_precedences) {

    // Initialisation des variables
    t_station * station_actuelle = station_precedences;
    int s1_detecte;
    int s2_detecte;

    // Tri du tableau d'exclusions
    liste_exclusion->tab_sommets = liste_precedences->tab_sommets;
    tri_tab_aretes(liste_exclusion);

    // Parcours des différentes exclusions
    for (int i=0; i<liste_exclusion->taille; i++) {

        // Parcours des différentes stations
        while (station_actuelle != NULL) {

            s1_detecte = 0;
            s2_detecte = 0;

            for (int j=0; j<station_actuelle->taille; j++) {

                if (station_actuelle->operations[j] == liste_exclusion->tab_aretes[i].sommet1) {

                    s1_detecte = 1;
                }


                if (station_actuelle->operations[j] == liste_exclusion->tab_aretes[i].sommet2) {

                    s2_detecte = 1;
                }

                if (s1_detecte && s2_detecte) {

                    // Lancement de l'algorithme
                }
            }

            station_actuelle = station_actuelle->next;
        }
    }


}