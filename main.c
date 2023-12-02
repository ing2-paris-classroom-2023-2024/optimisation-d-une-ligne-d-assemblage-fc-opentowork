#include "header.h"

// Fonction pour changer la couleur du texte
void changeTextColor(int color) {
    printf("\033[0;%dm", color);
}

int main() {
    int choix;
    int nb_stations_exclusion;
    t_graphe * liste_exclusions;
    liste_exclusions = lire_fichier("exclusions");
    t_graphe * liste_precedences;
    liste_precedences = lire_fichier("precedences/temps");
    t_station * stations = creer_stations_compatibles_exclusion(liste_exclusions, &nb_stations_exclusion);

    t_station * stations_precedence = calcul_precedences(liste_precedences);

    t_station * stations_precedences_exclusions = calcul_precedences_exclusions(liste_precedences, liste_exclusions);
    int i = 0;

    t_station * station_e_t = calcul_exclusion_temps(liste_exclusions, &nb_stations_exclusion, liste_precedences->temps_cycle);


    t_station * stations_multicontraintes = calcul_multicontraintes(liste_precedences, liste_exclusions);


    while(1) {
        printf("\033[0;32m");
        printf("Bienvenue sur l optimisation d une ligne d assemblage !\n");
        printf("\033[0m");

        printf("Veuillez choisir une option:\n");
        changeTextColor(34);
        printf("1. Contrainte d exclusion \n");
        printf("2. Contrainte de precedence et de temps de cycle\n");
        printf("3. Contrainte de precedence et d exclusion\n");
        printf("4. Contrainte d exclusion et de temps de cycle\n");
        printf("5. Multicontraintes ( les 3 a la fois )\n");
        printf("6. Afficher toutes les contraintes en meme temps\n");
        printf("7. Quitter\n");
        printf("\033[0m");

        printf("Entrez votre choix: ");
        scanf("%d", &choix);

        // Traitement du choix
        switch(choix) {
            case 1:
                printf("*** CONTRAINTES EXCLUSIONS SEULES *** \n");
                afficher_stations_exclusion(stations, nb_stations_exclusion);
                printf("\n");



                printf("\n\n");

                break;
            case 2:


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
                break;
            case 3:



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

                break;
            case 4:
                printf("*** EXCLUSION ET TEMPS  *** \n");
                afficher_stations_exclusion_temps(station_e_t,nb_stations_exclusion);


                break;
            case 5:


                printf("*** MULTICONTRAINTES (LES 3) *** \n");
                while (stations_multicontraintes != NULL) {

                    printf("=== STATION %d: Temps de cycle de %f s === \n", stations_multicontraintes->id, stations_multicontraintes->temps_cycle);

                    for (int j=0; j<stations_multicontraintes->taille; j++) {

                        printf("%d ", stations_multicontraintes->operations[j]);
                    }

                    stations_multicontraintes = stations_multicontraintes->next;


                    printf("\n");

                }

                break;

            case 6:
                printf("*** CONTRAINTES EXCLUSIONS SEULES *** \n");
                afficher_stations_exclusion(stations, nb_stations_exclusion);
                printf("\n\n");

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
                printf("*** EXCLUSION ET TEMPS  *** \n");
                afficher_stations_exclusion_temps(station_e_t,nb_stations_exclusion);

                printf("\n\n");

                printf("*** MULTICONTRAINTES (LES 3) *** \n");

                while (stations_multicontraintes != NULL) {

                    printf("=== STATION %d: Temps de cycle de %f s === \n", stations_multicontraintes->id, stations_multicontraintes->temps_cycle);

                    for (int j=0; j<stations_multicontraintes->taille; j++) {

                        printf("%d ", stations_multicontraintes->operations[j]);
                    }

                    stations_multicontraintes = stations_multicontraintes->next;


                    printf("\n");


                }
                break;





            case 7:
                return 0;

            default:
                printf("Choix invalide\n");
        }

        printf("Appuyez sur une touche pour revenir au menu...\n");
        getchar(); getchar();
    }

}




