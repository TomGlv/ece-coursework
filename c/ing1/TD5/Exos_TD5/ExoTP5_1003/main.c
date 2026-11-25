#include <stdio.h>
void remplirTableauNotes(float tableau[10]) {
    for (int i = 0; i < 10; i++) {
        do {
            printf("Saisissez la note %d : ", i + 1);
            scanf("%f", &tableau[i]);
        } while (tableau[i] < 0 || tableau[i] > 20);
    }
}
void afficherTableauNotes(float tableau[10]) {
    for (int i = 0; i < 10; i++) {
        printf("Note %d : %.2f\n", i + 1, tableau[i]);
    }
}
float calculerMoyenne(float tableau[10]) {
    float somme = 0;
    for (int i = 0; i < 10; i++) {
        somme += tableau[i];
    }
    return somme / 10;
}
void trouverMaxMin(float tableau[10], float *max, float *min) {
    *max = *min = tableau[0];
    for (int i = 1; i < 10; i++) {
        if (tableau[i] > *max) {
            *max = tableau[i];
        }
        if (tableau[i] < *min) {
            *min = tableau[i];
        }
    }
}
int main() {
    float notes[10];
    float moyenne;
    float maximum, minimum;
    remplirTableauNotes(notes);
    printf("\nTableau de notes :\n");
    afficherTableauNotes(notes);
    moyenne = calculerMoyenne(notes);
    printf("\nMoyenne des notes : %.2f\n", moyenne);
    trouverMaxMin(notes, &maximum, &minimum);
    printf("Note maximale : %.2f\n", maximum);
    printf("Note minimale : %.2f\n", minimum);
    return 0;
}
