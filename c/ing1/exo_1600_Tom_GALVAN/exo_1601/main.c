#include <stdio.h>
void saisirTableau(float tableau[], int i) {
    if (i < 20) {
        printf("Entrez les valeurs du tableau %d : ", i);
        scanf("%f", &tableau[i]);
        saisirTableau(tableau, i + 1);
    }
}
void afficherTableau(float tableau[], int i) {
    if (i< 20) {
        printf("%.2f ", tableau[i]);
        afficherTableau(tableau, i + 1);
    } else {
        printf("\n");
    }
}

int main() {
    float tableau[20];
    saisirTableau(tableau, 0);
    printf("Le tableau saisi est : ");
    afficherTableau(tableau, 0);

    return 0;
}
