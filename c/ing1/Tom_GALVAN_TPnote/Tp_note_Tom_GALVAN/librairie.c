#include "librairie.h"
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <time.h>

void initJoueur(struct t_joueur *joueur) {///initialistaion des joueurs
    printf("Entrez le nom du joueur : ");
    scanf("%s", joueur->nom);
    joueur->score = 0;}
void changerScore(struct t_joueur *joueur, int nouveauScore) {///change les scores des joueurs si leurs nouveaux scores est superieur a l'ancien
    if (nouveauScore > joueur->score) {
        joueur->score = nouveauScore;}}
void afficherJoueur(struct t_joueur joueur) { /// affich les caracteristiqyues des joueurs, leurs scores et leurs nom
    printf("Nom du joueur : %s\nScore : %d\n", joueur.nom, joueur.score);}
void initLesJoueurs(struct t_joueur joueurs[4]) {/// initilaise un tableau avec les caracteristiques des joueurs
    for (int i = 0; i < 4; i++) {
        initJoueur(&joueurs[i]);}}
void afficherLesJoueurs(struct t_joueur joueurs[4]) {/// affiche les caracteristiques des joueurs
    for (int i = 0; i < 4; i++) {
        afficherJoueur(joueurs[i]);
        printf("\n");}}
void jouer(struct t_joueur joueurs[4]) {  /// initialise 3 tentatives avec des scores diffferents a chaque fois pour tous les joueurs
    srand(time(NULL));
    for (int tentative = 1; tentative <= 3; tentative++) {
        printf("Tentative %d :\n", tentative);
        for (int i = 0; i < 4; i++) {
            int nouveauScore = rand() % 21;
            changerScore(&joueurs[i], nouveauScore);}
        afficherLesJoueurs(joueurs);}}


