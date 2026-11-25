#include <stdio.h>
#include <stdlib.h>

void saisie(float tableau[], int n, int index) {
    if(index < n) {
        printf("Saisir le reel numero %d : ", index + 1);
        scanf("%f", &tableau[index]);
        saisie(tableau, n, index + 1);
    }
}

void affiche(float tableau[], int n, int index) {
    if(index < n) {
        printf("%f ", tableau[index]);
        affiche(tableau, n, index + 1);
    }
}

void fusion(float tableau[], int debut, int milieu, int fin) {
    int taille1 = milieu - debut + 1;
    int taille2 = fin - milieu;

    float gauche[taille1], droite[taille2];

    for(int i = 0; i < taille1; i++)
        gauche[i] = tableau[debut + i];
    for(int j = 0; j < taille2; j++)
        droite[j] = tableau[milieu + 1 + j];

    int i = 0, j = 0, k = debut;

    while(i < taille1 && j < taille2) {
        if(gauche[i] <= droite[j]) {
            tableau[k] = gauche[i];
            i++;
        }
        else {
            tableau[k] = droite[j];
            j++;
        }
        k++;
    }

    while(i < taille1) {
        tableau[k] = gauche[i];
        i++;
        k++;
    }

    while(j < taille2) {
        tableau[k] = droite[j];
        j++;
        k++;
    }
}

void tri_fusion(float tableau[], int debut, int fin) {
    if(debut < fin) {
        int milieu = debut + (fin - debut) / 2;
        tri_fusion(tableau, debut, milieu);
        tri_fusion(tableau, milieu + 1, fin);
        fusion(tableau, debut, milieu, fin);
    }
}

int main() {
    int n;
    printf("Entrez la taille du tableau : ");
    scanf("%d", &n);

    float tableau[n];

    saisie(tableau, n, 0);
    printf("Les reels dans l'ordre d'entree sont : ");
    affiche(tableau, n, 0);
    printf("\n");

    tri_fusion(tableau, 0, n - 1);

    printf("Les reels dans l'ordre croissant sont : ");
    affiche(tableau, n, 0);
    printf("\n");

    return 0;
}
