#include <stdio.h>
#define N 3 // Constante globale pour la taille des tableaux
#include "saisirTableau.h"
void saisirTableauEntreAB(int tableau[N], int a, int b) {
    for (int i = 0; i < N; i++) {
        printf("Entrez un entier entre %d et %d : ", a, b);
        scanf("%d", &tableau[i]);
        while (tableau[i] < a || tableau[i] > b) {
            printf("La valeur n'est pas dans la plage [%d, %d]. Réessayez : ", a, b);
            scanf("%d", &tableau[i]);
        }
    }
}
void afficherTableau(int tableau[N]) {
    for (int i = 0; i < N; i++) {
        printf("%d ", tableau[i]);
    }
    printf("\n");
}
double calculerMoyenne(int tableau[N]) {
    double somme = 0;
    for (int i = 0; i < N; i++) {
        somme += tableau[i];
    }
    return somme / N;
}
int trouverMinimum(int tableau[N]) {
    int min = tableau[0];
    for (int i = 1; i < N; i++) {
        if (tableau[i] < min) {
            min = tableau[i];
        }
    }
    return min;
}
int trouverMaximum(int tableau[N]) {
    int max = tableau[0];
    for (int i = 1; i < N; i++) {
        if (tableau[i] > max) {
            max = tableau[i];
        }
    }
    return max;
}
int compterValeursPaires(int tableau[N]) {
    int count = 0;
    for (int i = 0; i < N; i++) {
        if (tableau[i] % 2 == 0) {
            count++;
        }
    }
    return count;
}
int comparerTableaux(int tableau1[N], int tableau2[N]) {
    for (int i = 0; i < N; i++) {
        if (tableau1[i] != tableau2[i]) {
            return 0; // Les tableaux sont différents
        }
    }
    return 1; // Les tableaux sont identiques
}
int main() {
    int tableau1[N];
    int tableau2[N];
    int a = 1, b = 100;

    printf("Saisie du premier tableau :\n");
    saisirTableau(tableau1);

    printf("Saisie du deuxieme tableau (valeurs entre %d et %d) :\n", a, b);
    saisirTableauEntreAB(tableau2, a, b);

    printf("Affichage du premier tableau : ");
    afficherTableau(tableau1);

    printf("Affichage du deuxieme tableau : ");
    afficherTableau(tableau2);

    printf("Moyenne du premier tableau : %.2f\n", calculerMoyenne(tableau1));
    printf("Moyenne du deuxieme tableau : %.2f\n", calculerMoyenne(tableau2));

    printf("Minimum du premier tableau : %d\n", trouverMinimum(tableau1));
    printf("Maximum du deuxieme tableau : %d\n", trouverMaximum(tableau2));

    printf("Nombre de valeurs paires dans le premier tableau : %d\n", compterValeursPaires(tableau1));
    printf("Nombre de valeurs paires dans le deuxieme tableau : %d\n", compterValeursPaires(tableau2));

    if (comparerTableaux(tableau1, tableau2)) {
        printf("Les deux tableaux sont identiques.\n");
    } else {
        printf("Les deux tableaux sont differents.\n");
    }

    return 0;
}