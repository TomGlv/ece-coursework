//
// Created by tomga on 19/12/2023.
//

#ifndef TP_NOTE__TOM_EMILIEN_SOUSPROG_H
#define TP_NOTE__TOM_EMILIEN_SOUSPROG_H
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
struct Entree {
    char nom[50];
    int note;
};
void construire_fichier_notes();
struct Entree* construire_tableau_dynamique(int* nb_elements);
void remplacer_note(struct Entree* tableau, int nb_elements);
int veriftableaux(struct Entree* tableau1, int nb_elements1);
void trier(struct Entree* tableau, int nb_elements);

#endif //TP_NOTE__TOM_EMILIEN_SOUSPROG_H
