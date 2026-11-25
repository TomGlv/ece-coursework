#include "librairie.h"
int saisirEntier() { /// fonction qui permet la saisie d'entier dans l'intervalle 1-99
    int entier;
    do { /// blindage
        printf("Entrez un entier entre 1 et 99 : ");
        scanf("%d", &entier);
    }while (entier < 1 || entier > 99);
    return entier;}

void remplirTab(int tab[N]) {
    for (int i = 0; i < N; i++) {/// permet de remplir le tableau avce des entiers
        int entier;
        do {
            entier = saisirEntier();
            int doublon = 0; /// fonction permettant de savoir s'il y a des doublons dans le tableau
            for (int j = 0; j < i; j++) {
                if (tab[j] == entier) {
                    doublon = 1;
                    break;}
            }
            if (!doublon) { /// fonction qui retourne a l'utilisateur si il y a des valeurs doublons
                tab[i] = entier;
                break;
            } else {
                printf("La valeur existe deja dans le tableau. reessayez.\n");}
        } while (1);}}

int comparerTab(int tab1[N], int tab2[N]) {
    int identiques = 1;
    int ordreDifferent = 0;
    for (int i = 0; i < N; i++) {
        if (tab1[i] != tab2[i]) {
            identiques = 0;
            break;}
    }
    if (!identiques) {
        for (int i = 0; i < N; i++) {
            int x = 0;
            for (int j = 0; j < N; j++) {
                if (tab1[i] == tab2[j]) {
                    x = 1;
                    break;}
            }
            if (!x) {
                ordreDifferent = 1;
                break;}}
    }
    if (identiques) {
        return 1; /// Tableaux identiques
    } else if (ordreDifferent) {
        return 2;} /// Memes valeurs dans un ordre différent
    else {
        return 0;} /// Differentes valeurs}
}
