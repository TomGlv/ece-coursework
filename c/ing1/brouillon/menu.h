#ifndef TP_EX1_HEADER_H
#define TP_EX1_HEADER_H

#define TAILLE 4

#include <string.h>
#include <stdlib.h>
#include <time.h>
#include <stdio.h>

typedef struct t_joueur {
    char nom[30];
    int score;
} t_joueur;

void initJoueur(t_joueur *joueur, int joueurNum);
void changerScore(t_joueur *j1, int score);
void afficherJoueur(t_joueur *j1);
void initLesJoueurs(t_joueur tab[TAILLE]);
void afficherLesJoueurs(t_joueur tab[TAILLE]);
void jouer(t_joueur tab[TAILLE]);
void sauvegarderLesJoueurs(t_joueur tab[TAILLE]);
void ajouterJoueur();

#endif //TP_EX1_HEADER_
