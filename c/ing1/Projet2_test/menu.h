
#ifndef PROJET2_TEST_MENU_H
#define PROJET2_TEST_MENU_H
#include <stdio.h>
#include <unistd.h> // pour utiliser la fonction sleep
#include <conio.h> // Pour utiliser la fonction _getch() sur Windows
#include <windows.h> // Pour utiliser les fonctions Windows pour effacer l'écran
// Dimensions du plateau de jeu
#define LARGEUR 22
#define HAUTEUR 12
#define N 10
#define R 2
#define X 2
#define Y 2
#define coeur 0x3
void effacerEcran();
void elements_decors(char tab[N][R]);
extern char plateau[HAUTEUR][LARGEUR];
void timer(int *vie);
char* sauvegarderDisposition(char plateau[HAUTEUR][LARGEUR]);
void menu_principal();
void menu_partie_en_cours();
void deplacement();
#endif //PROJET2_TEST_MENU_H;
