//
// Created by guych on 26/11/2023.
//

#include "../header.h"

int recherche_sommet_suivant(t_graphe * graphe_etudie, t_pile * pile_sommets_ajoutes) {

    int sommet_valide;
    int sommet_actuel;
    int compteur_occurences;
    int compteur_paires_valides;



    for (int i=0; i<graphe_etudie->taille; i++) {

        sommet_valide = 1;
        compteur_occurences = 0;
        compteur_paires_valides = 0;
        sommet_actuel = graphe_etudie->tab_aretes[i].sommet2;

        // On teste si le sommet n'est pas deja ajouté
        for (int j=0; j<pile_sommets_ajoutes->top+1; j++) {

            if (sommet_actuel == pile_sommets_ajoutes->tableau[j]) {

                sommet_valide = 0;
            }
        }

        // Si le sommet est valide, on le sélectionne
        if (sommet_valide) {

            for (int k=0; k<graphe_etudie->taille; k++) {

                // On compte le nombre de fois qu'il apparait
                if (sommet_actuel == graphe_etudie->tab_aretes[k].sommet2) {

                    compteur_occurences = compteur_occurences + 1;
                }
            }

            for (int k=0; k<graphe_etudie->taille; k++) {

                // On vérifie que le sommet 1 de la liaison est bien dans les sommets ajoutés (contrainte de précédence)
                if (sommet_actuel == graphe_etudie->tab_aretes[k].sommet2) {

                    for (int l=0; l<pile_sommets_ajoutes->top+1; l++) {

                        if (pile_sommets_ajoutes->tableau[l] == graphe_etudie->tab_aretes[k].sommet1) {

                            compteur_paires_valides = compteur_paires_valides + 1;
                        }
                    }
                }
            }

            if (compteur_paires_valides == compteur_occurences) {

                return sommet_actuel;
            }
        }

    }

}