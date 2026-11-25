#include "menu.h"

void initLesJoueurs(t_joueur tab[TAILLE]) {
    for (int i = 0; i < TAILLE; ++i) {
        initJoueur(&tab[i], i + 1);
    }
}

void initJoueur(t_joueur *joueur, int joueurNum) {
    printf("Entrez le pseudo du joueur %d: ", joueurNum);
    scanf("%s", joueur->nom);
    joueur->score = 0;
}

void changerScore(t_joueur *joueur, int nouveauScore) {
    if (nouveauScore > joueur->score) {
        joueur->score = nouveauScore;
    }
}

void afficherJoueur(t_joueur *joueur) {
    printf("%s : %d\n", joueur->nom, joueur->score);
}

void afficherLesJoueurs(t_joueur tab[TAILLE]) {
    for (int i = 0; i < TAILLE; ++i) {
        afficherJoueur(&tab[i]);
    }
}

void jouer(t_joueur tab[TAILLE]) {
    for (int i = 0; i < 3; ++i) { // 3 tentatives
        for (int j = 0; j < TAILLE; ++j) {
            int scoreAleatoire = rand() % 21; // Score entre 0 et 20
            changerScore(&tab[j], scoreAleatoire);
        }
        afficherLesJoueurs(tab);
    }
}

void sauvegarderLesJoueurs(t_joueur tab[TAILLE]) {
    FILE* fic;
    char nomFic[50];

    printf("Saisir le nom du fichier de sauvegarde : ");
    scanf("%s", nomFic);

    fic = fopen(nomFic, "w");
    if (fic) {
        for (int i = 0; i < TAILLE; ++i) {
            fprintf(fic, "%s\n%d\n", tab[i].nom, tab[i].score);
        }
        fclose(fic);
        printf("Sauvegarde effectuee avec succes.\n");
    } else {
        printf("Erreur d'ouverture du fichier.\n");
    }
}

