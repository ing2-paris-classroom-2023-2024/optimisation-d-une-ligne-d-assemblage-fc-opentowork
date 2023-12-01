//
// Created by guych on 26/11/2023.
//

#include "../header.h"

t_station * calcul_precedences(t_graphe * graphe_etudie) {

    // On commence par trier les aretes du graphe en fonction du temps d'opération des sommet2
    tri_tab_aretes(graphe_etudie);

    // Affichage du graphe trié
    /*for (int i=0; i<graphe_etudie->taille; i++) {

        printf("Paire %d: %d %d \n", i, graphe_etudie->tab_aretes[i].sommet1, graphe_etudie->tab_aretes[i].sommet2);
    }*/

    // On cherche à présent les sommets initiaux
    int taille_tab_sommets_initiaux;
    int top_sommets_initiaux = 0;
    int * tab_sommets_initiaux;

    tab_sommets_initiaux = recherche_sommets_initiaux(graphe_etudie, &taille_tab_sommets_initiaux);

    // Algorithme de remplissage des stations
    t_pile * pile_sommets_ajoutes = creer_pile(graphe_etudie->ordre);
    t_pile * pile_sommets_station = creer_pile(graphe_etudie->ordre);

    t_station * head = NULL;
    t_station * station_actuelle = NULL;

    ajouter_station(&head);

    station_actuelle = head;

    int sommet_actuel;

    while (pile_sommets_ajoutes->top < graphe_etudie->ordre-1) {

        if (top_sommets_initiaux < taille_tab_sommets_initiaux) { // On ajoute d'abord les sommets initiaux

            sommet_actuel = tab_sommets_initiaux[top_sommets_initiaux];


        } else { // On ajoute les prochains sommets en fonction des contraintes de précédence

            sommet_actuel = recherche_sommet_suivant(graphe_etudie, pile_sommets_ajoutes);

        }

        if (recherche_temps_operation(graphe_etudie, sommet_actuel) + station_actuelle->temps_cycle <= graphe_etudie->temps_cycle) { // Le nouveau sommet peut etre ajouté a la station car son temps de graphe lui permet de s'intégrer

            empiler(pile_sommets_station, sommet_actuel);
            empiler(pile_sommets_ajoutes, sommet_actuel);

            if (top_sommets_initiaux < taille_tab_sommets_initiaux) {

                top_sommets_initiaux = top_sommets_initiaux + 1;
            }

            station_actuelle->temps_cycle = station_actuelle->temps_cycle + recherche_temps_operation(graphe_etudie, sommet_actuel);

        } else { // La station est pleine : il faut en créer une nouvelle

            // On commence par confirmer la station deja existante
            station_actuelle->taille = pile_sommets_station->top+1;

            station_actuelle->operations = malloc(station_actuelle->taille * sizeof (int));

            for (int i=0; i<station_actuelle->taille; i++) {

                station_actuelle->operations[i] = depiler(pile_sommets_station);
            }

            // On crée la nouvelle station
            ajouter_station(&head);

            station_actuelle = station_actuelle->next;

            pile_sommets_station->top = -1;

        }


        /// AFFICHAGE DE LA PILE STATION
        /*for (int i=0; i<pile_sommets_station->top+1; i++) {

            printf("%d ", pile_sommets_station->tableau[i]);
        }
        printf("\n");*/


    }

    // Configurer les données de la derniere station
    station_actuelle->taille = pile_sommets_station->top+1;

    station_actuelle->operations = malloc(station_actuelle->taille * sizeof (int));

    for (int i=0; i<station_actuelle->taille; i++) {

        station_actuelle->operations[i] = depiler(pile_sommets_station);
    }

    return head;

}