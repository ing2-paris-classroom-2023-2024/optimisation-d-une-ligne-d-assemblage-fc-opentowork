#include "../header.h"

t_station * calcul_multicontraintes(t_graphe * liste_precedences, t_graphe * liste_exclusions) {

    // Affichage du graphe trié
    /*for (int i=0; i<liste_precedences->taille; i++) {

        printf("Paire %d: %d %d \n", i, liste_precedences->tab_aretes[i].sommet1, liste_precedences->tab_aretes[i].sommet2);
    }*/

    // On cherche à présent les sommets initiaux
    int taille_tab_sommets_initiaux;
    int top_sommets_initiaux = 0;
    int * tab_sommets_initiaux;

    tab_sommets_initiaux = recherche_sommets_initiaux(liste_precedences, &taille_tab_sommets_initiaux);

    // Algorithme de remplissage des stations
    t_pile * pile_sommets_ajoutes = creer_pile(liste_precedences->ordre);

    t_station * head = NULL;
    t_station * station_actuelle = NULL;

    ajouter_station(&head);

    station_actuelle = head;

    // Initialisation des variables de parcours
    int sommet_actuel;
    int recherche_station;
    int station_min = 0;

    while (pile_sommets_ajoutes->top < liste_precedences->ordre-1) {

        recherche_station = 1;

        // Selection du sommet à traiter
        if (top_sommets_initiaux < taille_tab_sommets_initiaux) { // On ajoute d'abord les sommets initiaux

            sommet_actuel = tab_sommets_initiaux[top_sommets_initiaux];


        } else { // On ajoute les prochains sommets en fonction des contraintes de précédence

            sommet_actuel = recherche_sommet_suivant(liste_precedences, pile_sommets_ajoutes);

            // Calcul de la plus petite station dans laquelle peut être ajouté le sommet actuel
            station_min = confirmation_ajout(station_actuelle, liste_precedences, sommet_actuel);
        }


        // On boucle parmi les stations disponibles
        while (station_actuelle != NULL && recherche_station) {

            // Modalité d'ajout du sommet
            if (recherche_temps_operation(liste_precedences, sommet_actuel) + station_actuelle->temps_cycle <= liste_precedences->temps_cycle &&
                    est_compatible_avec_station_exclusion_precedence(liste_exclusions, station_actuelle, sommet_actuel) && station_actuelle->id >= station_min) { // Le nouveau sommet peut etre ajouté a la station car son temps de graphe lui permet de s'intégrer

                station_actuelle->taille = station_actuelle->taille + 1;

                if (station_actuelle->operations == NULL) {

                    station_actuelle->operations = malloc(1 * sizeof (int));

                } else {

                    station_actuelle->operations = realloc(station_actuelle->operations, station_actuelle->taille * sizeof(int));
                }

                station_actuelle->operations[station_actuelle->taille-1] = sommet_actuel;

                empiler(pile_sommets_ajoutes, sommet_actuel);

                if (top_sommets_initiaux < taille_tab_sommets_initiaux) {

                    top_sommets_initiaux = top_sommets_initiaux + 1;
                }

                station_actuelle->temps_cycle = station_actuelle->temps_cycle + recherche_temps_operation(liste_precedences, sommet_actuel);

                recherche_station = 0;

            } else { // La station est incompatible :: on passe à la suivante

                station_actuelle = station_actuelle->next;

            }

        }

        if (station_actuelle == NULL && recherche_station) {

            ajouter_station(&head);

            recherche_station = 0;
        }

        station_actuelle = head;

        /*int k=0;

        t_station * station_temp = station_actuelle;

        /// AFFICHAGE DE LA PILE STATION
        while (station_temp != NULL) {

            printf("=== STATION %d: Temps de cycle de %f s === \n", k, station_temp->temps_cycle);

            for (int j=0; j<station_temp->taille; j++) {

                printf("%d ", station_temp->operations[j]);
            }

            station_temp = station_temp->next;
            k++;

            printf("\n");

        }

        printf("\n\n***************************************\n\n");*/


    }

    return head;

}