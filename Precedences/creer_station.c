//
// Created by guych on 26/11/2023.
//

#include "../header.h"

t_station * creer_station() {

    t_station * temp = malloc(sizeof (t_station));

    temp->taille = 0;

    temp->operations = NULL;

    temp->temps_cycle = 0;

    temp->next = NULL;

    return temp;
}