#ifndef HEADER_H
#define HEADER_H

#include <allegro.h>
#include "header.h"
#include <stdio.h>
#include <stdlib.h>

#define CARRELAGE 1
#define PLANCHE 0
#define MARMITE 2
#define INGREDIENT_TOMATE 3
#define INGREDIENT_FROMAGE 4
#define INGREDIENT_FARINE 5
#define INGREDIENT_VIANDE 6
#define ASSIETTE 7
#define POUBELLE 8
#define SORTIE_CUISINE 9
#define VIANDE_CUITE 10
#define TOMATE_MOZZARELLA 11
#define INGREDIENT_OEUF 12
#define INGREDIENT_SAUMON 13
#define PATES 14
#define PATES_SAUMON 15

typedef struct Objet {
    int type;
    int x, y;
    BITMAP *sprite;
    int dispo;
    int isInfinite; // Flag for infinite objects
} Objet;
typedef struct ObjetList {
    Objet *objets;
    int taille;
    int capacite;
} ObjetList;
void menu();
int niveau1();
extern char *player1Name;  // Nom du joueur 1
extern char *player2Name;  // Nom du joueur 2

void saisir_pseudo_j1(char *pseudoJoueur1,char *pseudoJoueur2);
void saisir_pseudo_j2(char *pseudoJoueur1,char * pseudoJoueur2);
void enter_player_names(BITMAP *buffer);  // Fonction pour entrer les noms des joueurs

#endif //PROJET_I

