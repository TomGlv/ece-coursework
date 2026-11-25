#include <stdio.h>
#include <stdlib.h>
char** allouerMatrice(int lignes, int colonnes) {
    char** matrice = (char**)malloc(lignes * sizeof(char*));
    for (int i = 0; i < lignes; i++) {
        matrice[i] = (char*)malloc(colonnes * sizeof(char));
    }
    return matrice;
}
void remplirMatriceAleatoire(char** matrice, int lignes, int colonnes) {
    for (int i = 0; i < lignes; i++) {
        for (int j = 0; j < colonnes; j++) {
            matrice[i][j] = rand() % 256;
            if (matrice[i][j]<0){
                matrice[i][j] = matrice[i][j]*(-1);
            }
            else;
        }
    }
}
void afficherMatrice(char** matrice, int lignes, int colonnes) {
    for (int i = 0; i < lignes; i++) {
        for (int j = 0; j < colonnes; j++) {
            printf("%d ", matrice[i][j]);
        }
        printf("\n");
    }
}
void libererMatrice(char** matrice, int lignes) {
    for (int i = 0; i < lignes; i++) {
        free(matrice[i]);
    }
    free(matrice);
}
int main() {
    int lignes, colonnes;
    do {
        printf("rentrez le nombre de lignes : ");
        scanf("%d", &lignes);
        printf("rentrez le nombre de colonnes : ");
        scanf("%d", &colonnes);
    }while ( lignes || colonnes < 100 && lignes || colonnes > 0);
        char **matrice = allouerMatrice(lignes, colonnes);
        remplirMatriceAleatoire(matrice, lignes, colonnes);
        afficherMatrice(matrice, lignes, colonnes);
        libererMatrice(matrice, lignes);
    return 0;
}
