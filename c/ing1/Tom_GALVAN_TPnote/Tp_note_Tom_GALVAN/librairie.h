//
// Created by tomga on 22/11/2023.
//

#ifndef TP_NOTE_TOM_GALVAN_LIBRAIRIE_H
#define TP_NOTE_TOM_GALVAN_LIBRAIRIE_H
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <time.h>
struct t_joueur {
    char nom[30];
    int score;
};
void initJoueur(struct t_joueur *joueur);
void changerScore(struct t_joueur *joueur, int nouveauScore);
void afficherJoueur(struct t_joueur joueur);
void initLesJoueurs(struct t_joueur joueurs[4]);
void afficherLesJoueurs(struct t_joueur joueurs[4]);
void jouer(struct t_joueur joueurs[4]);
#endif //TP_NOTE_TOM_GALVAN_LIBRAIRIE_H