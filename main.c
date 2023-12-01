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
    printf("*** CONTRAINTES EXCLUSIONS SEULES *** \n");
    afficher_stations_exclusion(stations, nb_stations_exclusion);
    printf("\n");

    /*for (int i=0; i<liste_exclusions->taille; i++) {

        printf("Paire %d: %d %d \n", i, liste_exclusions->tab_aretes[i].sommet1, liste_exclusions->tab_aretes[i].sommet2);
    }*/

    printf("\n\n");

    /// Tests de guicha (vous pouvez décommenter si vous voulez tester)
    t_graphe * liste_precedences;

    liste_precedences = lire_fichier("precedences/temps");

    t_station * stations_precedence = calcul_precedences(liste_precedences);

    int i = 0;

    printf("*** CONTRAINTES PRECEDENCE/TEMPS DE CYCLE *** \n");
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


    // Contraintes d'exclusions et de précédence
    t_station * stations_precedences_exclusions = calcul_precedences_exclusions(liste_precedences, liste_exclusions);

    printf("*** CONTRAINTE DE PRECEDENCE ET EXCLUSIONS *** \n");
    while (stations_precedences_exclusions != NULL) {

        printf("=== STATION %d: === \n", stations_precedences_exclusions->id);

        for (int j=0; j<stations_precedences_exclusions->taille; j++) {

            printf("%d ", stations_precedences_exclusions->operations[j]);
        }

        stations_precedences_exclusions = stations_precedences_exclusions->next;


        printf("\n");

    }


    printf("\n\n");


    // Multicontraintes
    t_station * stations_multicontraintes = calcul_multicontraintes(liste_precedences, liste_exclusions);

    printf("*** MULTICONTRAINTES (LES 3) *** \n");
    while (stations_multicontraintes != NULL) {

        printf("=== STATION %d: Temps de cycle de %f s === \n", stations_multicontraintes->id, stations_multicontraintes->temps_cycle);

        for (int j=0; j<stations_multicontraintes->taille; j++) {

            printf("%d ", stations_multicontraintes->operations[j]);
        }

        stations_multicontraintes = stations_multicontraintes->next;


        printf("\n");

    }

    printf("\n\n");
    system("pause");

    return 0;
}
