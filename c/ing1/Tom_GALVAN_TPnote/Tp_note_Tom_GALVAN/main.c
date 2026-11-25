#include "librairie.h"

// Sous-programme principal
int main() {
    struct t_joueur joueurs[4];
    initLesJoueurs(joueurs);
    printf("Les joueurs initialises :\n");
    afficherLesJoueurs(joueurs);
    jouer(joueurs);
    return 0;
}