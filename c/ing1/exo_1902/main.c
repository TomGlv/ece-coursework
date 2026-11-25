#include <stdio.h>
#include <stdlib.h>
#include "pile.h"

// Prototypes de fonctions
void construirePileStatique();
void afficherPileStatique(Element* top);

int main() {
    int choix;
    do {
        printf("1. Construire une pile d'entiers\n");
        printf("2. Quitter\n");
        printf("Choix : ");
        scanf("%d", &choix);

        switch (choix) {
            case 1:
                construirePileStatique();
                break;
            case 2:
                printf("Au revoir !\n");
                break;
            default:
                printf("Choix invalide. Veuillez entrer 1 ou 2.\n");
        }
    } while (choix != 2);

    return 0;
}

void construirePileStatique() {
    Element* pile = NULL;
    int valeur;
    printf("Entrez au moins 10 entiers pour construire la pile.\n");
    for (int i = 0; i < 10; i++) {
        printf("Entrez l'entier %d : ", i + 1);
        scanf("%d", &valeur);
        push(&pile, valeur);
    }
    printf("Affichage de la pile :\n");
    afficherPileStatique(pile);
}
void afficherPileStatique(Element* top) {
    printf("Elements de la pile dans l'ordre d'empilement :\n");
    while (top != NULL) {
        printf("%d\n", top->data);
        top = top->next;
    }
}
