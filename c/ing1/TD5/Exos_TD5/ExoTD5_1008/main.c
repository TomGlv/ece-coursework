#include <stdio.h>
void saisirMatrice(char matrice[4][5]) {
    printf("Saisie de la matrice :\n");
    for (int i = 0; i < 4; i++) {
        for (int j = 0; j < 5; j++) {
            scanf(" %c", &matrice[i][j]);
        }
    }
}
void transformerVoyellesMajuscules(char matrice[4][5]) {
    for (int i = 0; i < 4; i++) {
        for (int j = 0; j < 5; j++) {
            if (matrice[i][j] >= 'a' && matrice[i][j] <= 'z') {
                matrice[i][j] = matrice[i][j] - 32;
            }
        }
    }
}
void afficherMatrice(char matrice[4][5]) {
    printf("Matrice :\n");
    for (int i = 0; i < 4; i++) {
        for (int j = 0; j < 5; j++) {
            printf("%c ", matrice[i][j]);
        }
    }
}
void inverserMatrice(char matrice[4][5]) {
    char temp;
    for (int i = 0; i < 2; i++) {
        for (int j = 0; j < 5; j++) {
            temp = matrice[i][j];
            matrice[i][j] = matrice[3 - i][4-j];
            matrice[3 - i][4-j] = temp;
        }
    }
}

int main() {
    char matrice[4][5];
    saisirMatrice(matrice);
    transformerVoyellesMajuscules(matrice);
    afficherMatrice(matrice);
    inverserMatrice(matrice);
    printf("\n" );
    afficherMatrice(matrice);
    return 0;
}