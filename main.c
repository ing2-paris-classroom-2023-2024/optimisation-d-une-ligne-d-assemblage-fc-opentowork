#include "header.h"

int main() {

    printf("Projet d'algo :: Branche main ! \n\n");

    /// Tests de Yanis
    t_graphe * liste_exclusions;

    liste_exclusions = lire_fichier("exclusions");


    // Création des stations compatibles
    int nb_stations_exclusion;
    t_station * stations = creer_stations_compatibles_exclusion(liste_exclusions, &nb_stations_exclusion);

    // Affichage des stations
    afficher_stations_exclusion(stations, nb_stations_exclusion);

    for (int i=0; i<liste_exclusions->taille; i++) {

        printf("Paire %d: %d %d \n", i, liste_exclusions->tab_aretes[i].sommet1, liste_exclusions->tab_aretes[i].sommet2);
    }

    printf("\n\n");

    /// Tests de guicha (vous pouvez décommenter si vous voulez tester)
    t_graphe * liste_precedences;

    liste_precedences = lire_fichier("precedences/temps");

    t_station * stations_precedence = calcul_precedences(liste_precedences);

    int alive = 1;
    int i = 0;


    while (stations_precedence != NULL) {

        printf("=== STATION %d: Temps de cycle de %f s === \n", i, stations_precedence->temps_cycle);

        for (int j=0; j<stations_precedence->taille; j++) {

            printf("%d ", stations_precedence->operations[j]);
        }

        stations_precedence = stations_precedence->next;
        i++;

        printf("\n");

    }



    printf("\n\n");


    // Tri du tableau d'exclusion
    liste_exclusions->tab_sommets = liste_precedences->tab_sommets;

    tri_tab_aretes(liste_exclusions);

    for (int m=0; m<liste_exclusions->taille; m++) {

        printf("Paire %d: %d %d \n", m, liste_exclusions->tab_aretes[m].sommet1, liste_exclusions->tab_aretes[m].sommet2);
    }

    printf("\n\n");
    system("pause");

    return 0;
}
