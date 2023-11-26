#include "header.h"

int main() {

    printf("Projet d'algo : Branche Yanis ! \n");


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

    printf("\n");
   // system("pause");

    return 0;
}
