#include "menu.h"
void menu_reessayer() {
    effacerEcran();

    printf("=== Tu as perdu ! ===\n");
    printf("Que voulez-vous faire ?\n");
    printf("1. Reessayer\n2. Quitter\n");
    int touche = getchar();

    switch (touche) {
        case '1':
            deplacement();
            break;
        case '2':
            menu_principal();
            break;
        default:
            break;
    }
}

void timer(int *vie) {
    int minutes = 2;
    int secondes = 0;
    char choix = ' ';

    for (int i = 0; i < 120; i++) {
        if (secondes == 0 && minutes == 0) {
            if (*vie == 0) {
                menu_reessayer();
            } else {
                (*vie)--;
            }
        }

        printf("\n%d'%02d''", minutes, secondes);
        sleep(1);

        if (kbhit()) { // Vérifie s'il y a une touche en attente
            choix = _getch();
            switch (choix) {
                case '1':
                    break;
                case '2':
                    timer(vie);
                    break;
            }
        }

        if (secondes == 0) {
            secondes = 59;
            minutes--;
        } else {
            secondes--;
        }
    }
}