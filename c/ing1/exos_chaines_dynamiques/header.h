//
// Created by tomga on 12/01/2024.
//

#ifndef EXOS_CHAINES_DYNAMIQUES_HEADER_H
#define EXOS_CHAINES_DYNAMIQUES_HEADER_H
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

char* saisir_phrase();
char** extraire_mots(char* phrase, int* taille);
char** charger_dictionnaire(const char* filename, int* taille);
int recherche_mot_dans_dictionnaire(char* mot, char** dictionnaire, int taille);
void verifier_mots_reconnus(char** mots_utilisateur, int taille_utilisateur, char** dictionnaire, int taille_dictionnaire);
void liberer_memoire(char* phrase, char** mots, int taille_mots, char** dictionnaire, int taille_dictionnaire);
#endif //EXOS_CHAINES_DYNAMIQUES_HEADER_H
