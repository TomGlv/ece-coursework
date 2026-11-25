#include "menu.h"

int main() {
    srand(time(NULL));
    t_joueur joueurs[TAILLE];
    initLesJoueurs(joueurs);
    printf("\nJoueurs avant le tournoi :\n");
    afficherLesJoueurs(joueurs);
    jouer(joueurs);
    printf("\nResultats finaux apres le tournoi :\n");
    afficherLesJoueurs(joueurs);
    sauvegarderLesJoueurs(joueurs);

    return 0;
}
