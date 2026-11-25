#include <stdio.h>
#include <stdlib.h>
#include <conio.h> // Pour la fonction _getch() sous Windows (pour la saisie sans appuyer sur Enter)
#define X 10
#define R 2
#define N 10 // Taille de la grille
void Modele(char tab[X][R]) {
    int i, j;
    tab[0][0]=0x1;
    tab[1][0]=0x1a;
    tab[2][0]=0xC;
    tab[3][0]=0x3;
    tab[4][0]=0x6;
    tab[5][0]=0xf;
    tab[6][0]=0x1b;
    tab[7][0]=0x1c;
    tab[8][0]=0x1d;
    tab[9][0]=0xe;
    for (i = 0; i < 10; i++) {///Double boucle qui balaye le tableau et qui demande de le remplir
        for (j = 0; j < 1   ; j++) {
            printf("%c", tab[i][j]);
            printf("\n");
        }
    }
}
// Fonction pour afficher la grille
void afficherGrille(char grille[N][N]) {
    for (int i = 0; i < N; i++) {
        for (int j = 0; j < N; j++) {
            printf("%c ", grille[i][j]);
        }
        printf("\n");
    }
}

int main() {
    char tab[X][R];
    Modele (tab);
    char grille[N][N]; // La grille du jeu
    // Initialisation de la grille, où 'S' représente Snoopy et '#' représente un obstacle
    for (int i = 0; i < N; i++) {
        for (int j = 0; j < N; j++) {
            grille[i][j] = '.';
        }
    }
    grille[5][5] = 'S'; // Position initiale de Snoopy
    grille[3][3] = '#'; // Obstacle

    int x = 5; // Position en x de Snoopy
    int y = 5; // Position en y de Snoopy

    char deplacement;
    while (1) {
        system("cls"); // Efface l'écran sous Windows

        afficherGrille(grille);

        // Lire le mouvement de l'utilisateur
        deplacement = _getch();

        int nouvelle_x = x;
        int nouvelle_y = y;

        switch (deplacement) {
            case 'z': // Haut
                nouvelle_x--;
                break;
            case 's': // Bas
                nouvelle_x++;
                break;
            case 'q': // Gauche
                nouvelle_y--;
                break;
            case 'd': // Droite
                nouvelle_y++;
                break;
            default:
                break;
        }

        // Vérifier si le déplacement est valide
        if (nouvelle_x >= 0 && nouvelle_x < N && nouvelle_y >= 0 && nouvelle_y < N && grille[nouvelle_x][nouvelle_y] != '#') {
            // Effacer l'ancienne position de Snoopy
            grille[x][y] = '.';
            x = nouvelle_x;
            y = nouvelle_y;
            grille[x][y] = 'S'; // Mettre à jour la nouvelle position de Snoopy
        }
    }

    return 0;
}
