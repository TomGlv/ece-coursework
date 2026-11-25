//
// Created by tomga on 17/01/2024.
//

#ifndef EXO_1702_HEADERD_H
#define EXO_1702_HEADERD_H
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
// Structure pour la date
typedef struct {
    int jour;
    int mois;
    int annee;
} t_date;

// Structure pour la voiture
typedef struct maillon_voiture {
    char immatriculation[20];
    char marque[50];
    char modele[50];
    int vitesseMax;
    char carburant;
    t_date dateMiseEnService;
    struct maillon_voiture* suivant;
} t_maillon_voiture;

// Prototypes des sous-programmes
t_maillon_voiture* creerMaillon(t_maillon_voiture* liste);
void afficherListe(t_maillon_voiture* liste);
void afficherImmatriculationsParMarque(t_maillon_voiture* liste, const char* marque);
t_maillon_voiture* supprimerVoitureParImmatriculation(t_maillon_voiture** liste, const char* immatriculation);



#endif //EXO_1702_HEADERD_H
