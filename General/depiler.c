//
// Created by guych on 26/11/2023.
//

#include "../header.h"

int depiler(t_pile * pile) {

    return pile->tableau[pile->top--];
}