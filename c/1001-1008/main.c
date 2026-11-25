#include <stdio.h>
#include <ctype.h>

#define TAILLE_1D 13
#define NB_NOTES 10
#define NB_LIGNES 4
#define NB_COLONNES 5

void remplir_tableau_13(int tableau[]) {
    printf("Entrez 13 entiers :\n");
    for (int i = 0; i < TAILLE_1D; i++) {
        printf("Entrez un entier [%d] : ", i + 1);
        scanf("%d", &tableau[i]);
    }
}

void afficher_tableau_13(int tableau[]) {
    printf("Contenu du tableau :\n");
    for (int i = 0; i < TAILLE_1D; i++) {
        printf("%d\t", tableau[i]);
    }
    printf("\n");
}

void remplir_notes(float notes[]) {
    for (int i = 0; i < NB_NOTES; i++) {
        do {
            printf("Entrez la note [%d] (entre 0.0 et 20.0) : ", i + 1);
            scanf("%f", &notes[i]);
        } while (notes[i] < 0.0 || notes[i] > 20.0);
    }
}

void afficher_notes(float notes[]) {
    printf("Notes :\n");
    for (int i = 0; i < NB_NOTES; i++) {
        printf("%.2f\n", notes[i]);
    }
}

float calculer_moyenne(float notes[]) {
    float somme = 0.0;
    for (int i = 0; i < NB_NOTES; i++) {
        somme += notes[i];
    }
    return somme / NB_NOTES;
}

void trouver_min_max(float notes[], float *min, float *max) {
    *min = *max = notes[0];
    for (int i = 1; i < NB_NOTES; i++) {
        if (notes[i] < *min) *min = notes[i];
        if (notes[i] > *max) *max = notes[i];
    }
}

void saisir_matrice(char matrice[NB_LIGNES][NB_COLONNES]) {
    printf("Entrez les valeurs de la matrice 4x5 (caracteres) :\n");
    for (int i = 0; i < NB_LIGNES; i++) {
        for (int j = 0; j < NB_COLONNES; j++) {
            printf("Entrez un caractere [%d][%d] : ", i + 1, j + 1);
            scanf(" %c", &matrice[i][j]);
        }
    }
}

void transformer_voyelles(char matrice[NB_LIGNES][NB_COLONNES]) {
    int decalage = 'A' - 'a';
    for (int i = 0; i < NB_LIGNES; i++) {
        for (int j = 0; j < NB_COLONNES; j++) {
            if (matrice[i][j] == 'a' || matrice[i][j] == 'e' || matrice[i][j] == 'i' || matrice[i][j] == 'o' || matrice[i][j] == 'u') {
                matrice[i][j] = matrice[i][j] + decalage;
            }
        }
    }
}

void afficher_matrice(char matrice[NB_LIGNES][NB_COLONNES]) {
    printf("Matrice :\n");
    for (int i = 0; i < NB_LIGNES; i++) {
        for (int j = 0; j < NB_COLONNES; j++) {
            printf("%c ", matrice[i][j]);
        }
        printf("\n");
    }
}

void inverser_matrice(char matrice[NB_LIGNES][NB_COLONNES]) {
    for (int i = 0; i < NB_LIGNES * NB_COLONNES / 2; i++) {
        int x1 = i / NB_COLONNES, y1 = i % NB_COLONNES;
        int x2 = (NB_LIGNES * NB_COLONNES - 1 - i) / NB_COLONNES;
        int y2 = (NB_LIGNES * NB_COLONNES - 1 - i) % NB_COLONNES;
        char temp = matrice[x1][y1];
        matrice[x1][y1] = matrice[x2][y2];
        matrice[x2][y2] = temp;
    }
}

int main() {
    int tableau[TAILLE_1D];
    float notes[NB_NOTES];
    char matrice[NB_LIGNES][NB_COLONNES];
    float min, max;

    printf("Choisissez un exercice :\n 1. Exercice 1001\n 2. Exercice 1003\n 3. Exercice 1008\n");
    char choix;
    scanf(" %c", &choix);

    switch (choix) {
        case '1':
            // Exercice 1001
            remplir_tableau_13(tableau);
            afficher_tableau_13(tableau);
            break;

        case '2':
            // Exercice 1003
            remplir_notes(notes);
            afficher_notes(notes);
            printf("Moyenne des notes : %.2f\n", calculer_moyenne(notes));
            trouver_min_max(notes, &min, &max);
            printf("Note minimum : %.2f, Note maximum : %.2f\n", min, max);
            break;

        case '3':
            // Exercice 1008
            saisir_matrice(matrice);
            printf("Matrice saisie :\n");
            afficher_matrice(matrice);

            transformer_voyelles(matrice);
            printf("Matrice transforme :\n");
            afficher_matrice(matrice);

            inverser_matrice(matrice);
            printf("Matrice inverse :\n");
            afficher_matrice(matrice);
            break;

        default:
            printf("Choix invalide.\n");
    }

    return 0;
}
