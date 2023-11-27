#include "header.h"

int main() {

    printf("Projet d'algo :: Branche guicha ! \n\n");

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
