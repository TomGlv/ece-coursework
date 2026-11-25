
#ifndef EXO_LISTE_PERSONNNES_HEADER_H
#define EXO_LISTE_PERSONNNES_HEADER_H
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <time.h>

typedef struct {
    int jour;
    int mois;
    int annee;
} t_date;

typedef struct {
    int identifiant;
    char *nom;
    t_date date_naissance;
} t_personne;

typedef struct maillon {
    t_personne *personne;
    struct maillon *suivant;
} t_maillon;

typedef struct {
    t_maillon *debut;
    t_maillon *fin;
} t_liste;
void afficherListeRecursif(t_liste *liste);
t_personne *creerPersonne();
t_maillon *creerMaillon(t_personne *une_personne);
void insererEnFin(t_liste *liste, t_personne *une_personne);
void afficherListe(t_liste *liste);
void libererListe(t_liste *liste);
#endif //EXO_LISTE_PERSONNNES_HEADER_H
