//
// Created by guych on 26/11/2023.
//

#include "../header.h"

void ajouter_station(t_station ** head) {

    t_station * nouveau = creer_station();

    t_station * dernier = *head;

    if (*head == NULL) {

        *head = nouveau;

        return;
    }

    while (dernier->next != NULL) {


        dernier = dernier->next;
    }


    nouveau->id = dernier->id+1;

    dernier->next = nouveau;

}