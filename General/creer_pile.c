//
// Created by guych on 26/11/2023.
//

#include "../header.h"

t_pile * creer_pile(int taille) {

    t_pile * temp = malloc(sizeof (t_pile));

    temp->top = -1;
    temp->tableau = malloc(taille * sizeof(int));

    return temp;
}