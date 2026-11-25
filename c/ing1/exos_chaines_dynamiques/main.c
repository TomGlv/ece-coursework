#include "header.h"
int main() {
    int taille_dictionnaire, taille_mots_utilisateur;
    char* phrase_utilisateur = saisir_phrase();
    char** mots_utilisateur = extraire_mots(phrase_utilisateur, &taille_mots_utilisateur);
    char** dictionnaire = charger_dictionnaire("dictionnaire.txt", &taille_dictionnaire);

    verifier_mots_reconnus(mots_utilisateur, taille_mots_utilisateur, dictionnaire, taille_dictionnaire);

    liberer_memoire(phrase_utilisateur, mots_utilisateur, taille_mots_utilisateur, dictionnaire, taille_dictionnaire);

    return 0;
}
