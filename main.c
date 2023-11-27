#include "header.h"

int main() {

    printf("Projet d'algo :: Branche main ! \n");

    /// Tests de Yanis

    t_graphe * liste_exclusions;

    liste_exclusions = lire_fichier("exclusions");

    // Création des stations compatibles
    int nb_stations_exclusion;
    t_station *stations = creer_stations_compatibles_exclusion(liste_exclusions, &nb_stations_exclusion);

    // Affichage des stations
    afficher_stations_exclusion(stations, nb_stations_exclusion);

    for (int i=0; i<liste_exclusions->taille; i++) {

        printf("Paire %d: %d %d \n", i, liste_exclusions->tab_aretes[i].sommet1, liste_exclusions->tab_aretes[i].sommet2);
    }


    /// Tests de guicha (vous pouvez décommenter si vous voulez tester)
    /*t_graphe * liste_precedences;

    liste_precedences = lire_fichier("precedences/temps");

    t_station * stations = calcul_precedences(liste_precedences);

    int alive = 1;
    int i = 0;


    while (stations != NULL) {

        printf("=== STATION %d: Temps de cycle de %f s === \n", i, stations->temps_cycle);

        for (int j=0; j<stations->taille; j++) {

            printf("%d ", stations->operations[j]);
        }

        stations = stations->next;
        i++;

        printf("\n");

    }*/

    printf("\n\n");
    system("pause");

    return 0;
}
