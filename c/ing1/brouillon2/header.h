//
// Created by tomga on 13/12/2023.
//

#ifndef BROUILLON2_HEADER_H
#define BROUILLON2_HEADER_H
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
typedef struct {
    char nom[50];
    float hauteur;
} Athlete;

void saisirListeAthletes(Athlete **athletes, int *nbAthletes);
void afficherListeAthletes(Athlete *athletes, int nbAthletes);
void trouverEtAfficherMeilleur(Athlete *athletes, int nbAthletes);
void sauvegarderListeAthletes(Athlete *athletes, int nbAthletes, const char *nomFichier);
void chargerListeAthletes(Athlete **athletes, int *nbAthletes, const char *nomFichier);

#endif //BROUILLON2_HEADER_H
