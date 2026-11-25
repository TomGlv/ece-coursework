#include "header.h"
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

char* saisir_phrase() {
    char buffer[1000];
    printf("Saisissez une phrase : ");
    fgets(buffer, sizeof(buffer), stdin);

    // Supprimer le saut de ligne à la fin de la chaîne
    buffer[strcspn(buffer, "\n")] = '\0';

    // Allouer dynamiquement de la mémoire pour la phrase
    char* phrase = malloc(strlen(buffer) + 1);
    strcpy(phrase, buffer);

    return phrase;
}

char** extraire_mots(char* phrase, int* taille) {
    char** mots = NULL;
    char* token = strtok(phrase, " ");
    *taille = 0;

    while (token != NULL) {
        mots = realloc(mots, (*taille + 1) * sizeof(char*));
        mots[*taille] = malloc(strlen(token) + 1);
        strcpy(mots[*taille], token);

        (*taille)++;
        token = strtok(NULL, " ");
    }

    return mots;
}

char** charger_dictionnaire(const char* filename, int* taille) {
    FILE* fichier = fopen(filename, "r");
    if (fichier == NULL) {
        perror("Erreur lors de l'ouverture du fichier");
        exit(EXIT_FAILURE);
    }

    char buffer[100];
    char** dictionnaire = NULL;
    *taille = 0;

    while (fgets(buffer, sizeof(buffer), fichier) != NULL) {
        buffer[strcspn(buffer, "\n")] = '\0';

        dictionnaire = realloc(dictionnaire, (*taille + 1) * sizeof(char*));
        dictionnaire[*taille] = malloc(strlen(buffer) + 1);
        strcpy(dictionnaire[*taille], buffer);

        (*taille)++;
    }

    fclose(fichier);
    return dictionnaire;
}

int recherche_mot_dans_dictionnaire(char* mot, char** dictionnaire, int taille) {
    for (int i = 0; i < taille; i++) {
        if (strcmp(mot, dictionnaire[i]) == 0) {
            return 1;  // Mot trouvé dans le dictionnaire
        }
    }
    return 0;  // Mot non trouvé dans le dictionnaire
}

void verifier_mots_reconnus(char** mots_utilisateur, int taille_utilisateur, char** dictionnaire, int taille_dictionnaire) {
    printf("Mots non reconnus : ");
    for (int i = 0; i < taille_utilisateur; i++) {
        if (!recherche_mot_dans_dictionnaire(mots_utilisateur[i], dictionnaire, taille_dictionnaire)) {
            printf("%s ", mots_utilisateur[i]);
        }
    }
    printf("\n");
}

void liberer_memoire(char* phrase, char** mots, int taille_mots, char** dictionnaire, int taille_dictionnaire) {
    free(phrase);

    for (int i = 0; i < taille_mots; i++) {
        free(mots[i]);
    }
    free(mots);

    for (int i = 0; i < taille_dictionnaire; i++) {
        free(dictionnaire[i]);
    }
    free(dictionnaire);
}
