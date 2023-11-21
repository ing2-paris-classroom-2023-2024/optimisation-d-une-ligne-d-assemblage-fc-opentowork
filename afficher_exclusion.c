//
// Created by Yanis Denizot on 21/11/2023.
//
#include "header.h"
void AfficherExclusions(ListeExclusions* liste) {
    for (int i = 0; i < liste->nombreExclusions; i++) {
        printf("Exclusion: %d  %d\n", liste->exclusions[i].operation1, liste->exclusions[i].operation2);
    }
}