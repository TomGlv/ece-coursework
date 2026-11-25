#include "saisirTableau.h"
void saisirTableau(int tableau[N]) {
    for (int i = 0; i < N; i++) {
        printf("Entrez un entier : ");
        scanf("%d", &tableau[i]);
    }
}
