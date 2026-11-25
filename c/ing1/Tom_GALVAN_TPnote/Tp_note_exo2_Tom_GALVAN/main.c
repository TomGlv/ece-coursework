#include "librairie.h"
int main() {
    int memoire[N];
    int essai[N];
    printf("Remplissez le tableau de la memoire :\n"); ///permet a l'utilisateur de remplir le tableau memoire
    remplirTab(memoire);
    printf("\nRemplissez le tableau d'essai :\n");/// Demander à l'utilisateur de remplir le tableau essai
    remplirTab(essai);
    int resultat = comparerTab(memoire, essai); /// Comparer les deux tableaux
    if (resultat == 1) {/// Afficher le résultat
        printf("BRAVO ! Les tableaux sont identiques.\n");
    } else if (resultat == 2) {
        printf("PRESQUE ! Les valeurs sont les memes mais dans un ordre different.\n");
    } else {
        printf("MEMOIRE DEFECTUEUSE ! Les tableaux sont differents.\n");
    }
    return 0;
}