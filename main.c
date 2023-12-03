#include "header.h"

// Fonction pour changer la couleur du texte
void changeTextColor(int color) {
    printf("\033[0;%dm", color);
}

int main() {
    int choix;
    int nb_stations_exclusion;
    int i = 0;

    t_graphe * liste_exclusions;
    liste_exclusions = lire_fichier("exclusions");

    t_graphe * liste_precedences;
    liste_precedences = lire_fichier("precedences/temps");

    t_station * stations = NULL;
    t_station * stations_precedence = NULL;
    t_station * stations_precedences_exclusions = NULL;

    liste_exclusions->ordre = liste_precedences->ordre;
    liste_exclusions->tab_sommets = liste_precedences->tab_sommets;
    t_station * stations_exclusions_temps = NULL;

    t_station * stations_multicontraintes = NULL;


    while(1) {

        system("cls");

        printf("\033[0;32m");
        printf("/=*=*= PROGRAMME D'OPTIMISATION D'UNE LIGNE D'ASSEMBLAGE =*=*=\\ \n");
        printf("\033[0m");

        printf("Veuillez choisir une option:\n");
        changeTextColor(34);
        printf("1. Contrainte d'exclusion \n");
        printf("2. Contrainte de precedence et de temps de cycle\n");
        printf("3. Contrainte de precedence et d'exclusion\n");
        printf("4. Contrainte d'exclusion et de temps de cycle\n");
        printf("5. Multicontraintes (les 3 a la fois)\n");
        printf("6. Afficher toutes les contraintes en meme temps\n");
        printf("7. Quitter\n");
        printf("\033[0m");

        printf("Entrez votre choix: ");
        scanf("%d", &choix);

        printf("\n");

        // Traitement du choix
        switch(choix) {
            case 1:

                stations = creer_stations_compatibles_exclusion(liste_exclusions, &nb_stations_exclusion);

                printf("*** CONTRAINTES EXCLUSIONS SEULES *** \n");
                afficher_stations_exclusion(stations, nb_stations_exclusion);
                printf("\n");



                printf("\n\n");

                break;
            case 2:

                stations_precedence = calcul_precedences(liste_precedences);

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

                stations_precedences_exclusions = calcul_precedences_exclusions(liste_precedences, liste_exclusions);

                printf("*** CONTRAINTES DE PRECEDENCE ET EXCLUSIONS *** \n");
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

                stations_exclusions_temps = calcul_exclusion_temps(liste_exclusions);

                printf("*** CONTRAINTES D'EXCLUSION ET TEMPS  *** \n");
                while (stations_exclusions_temps != NULL) {

                    printf("=== STATION %d: Temps de cycle de %f s === \n", stations_exclusions_temps->id, stations_exclusions_temps->temps_cycle);

                    for (int j=0; j<stations_exclusions_temps->taille; j++) {

                        printf("%d ", stations_exclusions_temps->operations[j]);
                    }

                    stations_exclusions_temps = stations_exclusions_temps->next;


                    printf("\n");
                }


                break;
            case 5:

                stations_multicontraintes = calcul_multicontraintes(liste_precedences, liste_exclusions);

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

                stations = creer_stations_compatibles_exclusion(liste_exclusions, &nb_stations_exclusion);
                stations_precedence = calcul_precedences(liste_precedences);
                stations_precedences_exclusions = calcul_precedences_exclusions(liste_precedences, liste_exclusions);
                stations_exclusions_temps = calcul_exclusion_temps(liste_exclusions);
                stations_multicontraintes = calcul_multicontraintes(liste_precedences, liste_exclusions);


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


                printf("*** CONTRAINTES DE PRECEDENCE ET EXCLUSIONS *** \n");
                while (stations_precedences_exclusions != NULL) {

                    printf("=== STATION %d: === \n", stations_precedences_exclusions->id);

                    for (int j=0; j<stations_precedences_exclusions->taille; j++) {

                        printf("%d ", stations_precedences_exclusions->operations[j]);
                    }

                    stations_precedences_exclusions = stations_precedences_exclusions->next;


                    printf("\n");

                }


                printf("\n\n");
                printf("*** CONTRAINTES D'EXCLUSION ET TEMPS  *** \n");
                while (stations_exclusions_temps != NULL) {

                    printf("=== STATION %d: Temps de cycle de %f s === \n", stations_exclusions_temps->id, stations_exclusions_temps->temps_cycle);

                    for (int j=0; j<stations_exclusions_temps->taille; j++) {

                        printf("%d ", stations_exclusions_temps->operations[j]);
                    }

                    stations_exclusions_temps = stations_exclusions_temps->next;


                    printf("\n");
                }

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

        printf("\n\nAppuyez sur Entree pour revenir au menu...\n");
        getchar(); getchar();
    }

}




