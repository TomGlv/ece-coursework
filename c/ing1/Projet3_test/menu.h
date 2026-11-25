#ifndef PROJET_SNOOPY_FINALE_MENU_H
#define PROJET_SNOOPY_FINALE_MENU_H
#include <time.h>
#include <string.h>
#include <stdio.h>// necessaire pour permettre d'ouvrir un fichier texte
#include <unistd.h> // Pour utiliser la fonction sleep
#include <conio.h> // Pour utiliser la fonction _getch() sur Windows
#include <windows.h> // Pour utiliser les fonctions Windows pour effacer l'écran
#include "snoopy_struct.h"

// Dimensions du plateau de jeu
#define LARGEUR 22
#define HAUTEUR 12
#define MAX_LINES 7
#define MAX_LINE_LENGTH 256
//position de départ de snoopy
#define X 11
#define Y 6
#define texte 10
#define M 1
#define P 1

// mot de passes

#define mp2 8243
#define mp3 6594


//definition des symboles des blocs
#define Soiseau '~'
#define Sballe 'o'
#define Spoussable 'P'
#define Sincassable '#'
#define Sespace ' '
#define Ssnoopy 'S'
#define Scassable 'C'
#define StapisDroite '>'
#define StapisGauche '<'
#define StapisHaut '^'
#define StapisBas 'v'
#define Sbonus '+'
#define Smort 'x'
/// piege;
// tapis;
// dispap;

//fonctions de menu.c
void effacerEcran();
void choix_menu();
void affichage_menu();
void menu_partie_en_cours(def_bloc plateau[HAUTEUR][LARGEUR]);

//fonctions de deplacements_affichage.c
void creer_plateau_niveau1(def_bloc plateau[HAUTEUR][LARGEUR],def_bloc *snoopy);
void creer_plateau_niveau2(def_bloc plateau[HAUTEUR][LARGEUR],def_bloc *snoopy);
void creer_plateau_niveau3(def_bloc plateau[HAUTEUR][LARGEUR],def_bloc *snoopy);
int autorise_deplacement(def_bloc *snoopy,def_bloc *cellule,def_bloc plateau[HAUTEUR][LARGEUR]);
void maj_position(def_bloc *bloc,def_bloc *bloc2,def_bloc plateau[HAUTEUR][LARGEUR]);
void afficher_plateau(def_bloc plateau[HAUTEUR][LARGEUR]);
void deplacement(def_bloc *snoopy, def_bloc plateau[HAUTEUR][LARGEUR], int *mouvement_effectue,char touche);

//fonctions de bloc.c
void pouss(def_bloc *bloc_poussable,def_bloc plateau[HAUTEUR][LARGEUR]);
void casse(def_bloc *snoopy,def_bloc plateau[HAUTEUR][LARGEUR]);
void tapis(def_bloc *snoopy,def_bloc plateau[HAUTEUR][LARGEUR]);
int conditions_tapis(def_bloc *snoopy,def_bloc *destination,def_bloc plateau[HAUTEUR][LARGEUR]);
void bougeballe(def_bloc *balle,int tab_coord[2],def_bloc plateau[HAUTEUR][LARGEUR]);
void deplacer_balle(def_bloc *balle,def_bloc *snoopy, def_bloc plateau[HAUTEUR][LARGEUR],int tab[2]);


//fonctions de initialisation.c
void initniveau1facile(def_bloc plateau[HAUTEUR][LARGEUR]);
void initniveau1moyen(def_bloc plateau[HAUTEUR][LARGEUR]);
void initniveau1dur(def_bloc plateau[HAUTEUR][LARGEUR]);
void initniveau2facile(def_bloc plateau[HAUTEUR][LARGEUR]);
void initniveau2moyen(def_bloc plateau[HAUTEUR][LARGEUR]);
void initniveau2dur(def_bloc plateau[HAUTEUR][LARGEUR]);
void initniveau3facile(def_bloc plateau[HAUTEUR][LARGEUR]);
void initniveau3moyen(def_bloc plateau[HAUTEUR][LARGEUR]);
void initniveau3dur(def_bloc plateau[HAUTEUR][LARGEUR]);

//fonctions de graphisme.c
void Color(int couleur_texte, int couleur_fond);
void print_text();

//fonctions de sauvegarde.c
void chargerpartie(def_bloc plateau[HAUTEUR][LARGEUR]);
void sauvegarde(def_bloc plateau[HAUTEUR][LARGEUR]);
void chargerpartieinit(def_bloc plateau[HAUTEUR][LARGEUR]);
void sauvegardeinit(def_bloc plateau[HAUTEUR][LARGEUR]);
void sauvegarderTexte(def_bloc plateau[texte]);
void savescore();


#endif //PROJET_SNOOPY_FINALE_MENU_H