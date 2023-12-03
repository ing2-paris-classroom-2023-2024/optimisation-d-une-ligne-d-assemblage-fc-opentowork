//
// Created by guych on 30/11/2023.
//

#include "../header.h"

int seek(t_pile * pile, int item) {

    int resultat = 0;

    if (pile->top != -1) {

        for (int i=0; i<pile->top+1; i++) {

            if (pile->tableau[i] == item) {

                resultat = 1;
            }
        }

    }

    return resultat;
}