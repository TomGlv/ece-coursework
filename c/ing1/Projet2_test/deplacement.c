#include "menu.h"

char personnage = 'S';
int positionX = X; /// Position du personnage
int positionY = Y; /// Position du personnage
char plateau[HAUTEUR][LARGEUR];

// Fonction pour effacer l'écran
void effacerEcran() {
    system("cls"); // Utilise la commande "cls" pour effacer l'écran sur Windows
}

// Fonction pour afficher le plateau
void afficherPlateau() {
    effacerEcran();
    ///printf(" %c vies\n",coeur);

    for (int y = 0; y < HAUTEUR; y++) {
        for (int x = 0; x < LARGEUR; x++) {
            if (x == positionX && y == positionY) {
                printf("%c", personnage);
            } else {
                printf("%c", plateau[y][x]);
            }
        }
        printf("\n");
    }

    printf("Appuyez sur 'x' pour quitter le jeu.\n");
}
// Fonction pour gérer le jeu console
void deplacement() {
    // Initialise le plateau de jeu
    for (int y = 0; y < HAUTEUR; y++) {
        for (int x = 0; x < LARGEUR; x++) {
            if (y == 0 || y == HAUTEUR - 1 || x == 0 || x == LARGEUR - 1) {
                plateau[y][x] = '#'; // Bord du plateau
            } else {
                plateau[y][x] = ' ';
            }
        }
    }

    int touche;

    // Boucle jeu
    while (1) { ///while time pas egal a 0 et vie pas egal a 0
        afficherPlateau();

        touche = _getch(); // Récupère une touche du clavier (utilise _getch() sur Windows)

        // Déplace le personnage en fonction de la touche
        switch (touche) {
            case 'z': // Haut
                if (positionY > 1) {
                    positionY--;
                }
                break;
            case 's': // Bas
                if (positionY < HAUTEUR - 2) {
                    positionY++;
                }
                break;
            case 'q': // Gauche
                if (positionX > 1) {
                    positionX--;
                }
                break;
            case 'd': // Droite
                if (positionX < LARGEUR - 2) {
                    positionX++;
                }
                break;
            case 'x': { // Quitter le jeu
                menu_partie_en_cours();
            }
                return;
        }
    }
}