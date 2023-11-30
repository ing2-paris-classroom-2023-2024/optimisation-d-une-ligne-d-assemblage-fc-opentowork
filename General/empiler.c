//
// Created by guych on 26/11/2023.
//

#include "../header.h"

void empiler(t_pile * pile, int item) {

    pile->tableau[++pile->top] = item;

}