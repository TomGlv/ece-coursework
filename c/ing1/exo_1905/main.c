#include <stdio.h>
#include <stdlib.h>
#include "pile.h"

// Prototypes de fonctions
void enfiler10Elements();
void afficherElementsDefiles(Element** front, Element** rear);

int main() {
    int choix;

    do {
        printf("1. Enfiler 10 elements\n");
        printf("2. Quitter\n");
        printf("Choix : ");
        scanf("%d", &choix);

        switch (choix) {
            case 1:
                enfiler10Elements();
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

// Fonction pour enfiler 10 éléments dans la file
void enfiler10Elements() {
    Element* front = NULL;
    Element* rear = NULL;
    int valeur;
    printf("Enfilez 10 elements :\n");
    for (int i = 0; i < 10; i++) {
        printf("Element %d : ", i + 1);
        scanf("%d", &valeur);
        enfiler(&rear, valeur);
        if (front == NULL) {
            front = rear;
        }
    }
    afficherElementsDefiles(&front, &rear);
}

// Fonction pour afficher les éléments de la file en les défilant un par un
void afficherElementsDefiles(Element** front, Element** rear) {
    printf("Affichage des elements defiles :\n");
    while (!isEmpty(*front)) {
        int element = defiler(front);
        printf("%d\n", element);
    }
    *rear = NULL; // Réinitialisation du pointeur arrière après défiler tous les éléments
}
