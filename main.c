#include "header.h"

int main() {
    ListeExclusions* liste = LireExclusions("../contrainte_exclusion.txt");
    printf("bvn chez yanis  \n");
    AfficherExclusions(liste);

    printf("\n");
    free(liste->exclusions);
    free(liste);
    system("pause");

    return 0;
}
