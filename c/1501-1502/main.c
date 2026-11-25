#include <stdio.h>
#include <stdlib.h>
#include <string.h>

char* saisirDeuxPhrases() {
    char buffer1[100], buffer2[100];
    char *phraseDynamique;
    printf("Saisir la premiere phrase : ");
    fgets(buffer1, 100, stdin);
    buffer1[strcspn(buffer1, "\n")] = '\0';

    printf("Saisir la deuxieme phrase : ");
    fgets(buffer2, 100, stdin);
    buffer2[strcspn(buffer2, "\n")] = '\0';

    phraseDynamique = malloc(strlen(buffer1) + strlen(buffer2) + 2);
    if (phraseDynamique == NULL) {
        printf("Erreur d'allocation memoire\n");
        exit(1);
    }

    strcpy(phraseDynamique, buffer1);
    strcat(phraseDynamique, " ");
    strcat(phraseDynamique, buffer2);

    return phraseDynamique;
}

void exercice1501() {
    char *phrase = saisirDeuxPhrases();
    printf("Phrase rendue : %s\n", phrase);
    free(phrase);
}

void remplirTableau(char **tableau, int taille) {
    for (int i = 0; i < taille; i++) {
        char buffer[100];
        printf("Saisir la chaine %d : ", i + 1);
        fgets(buffer, 100, stdin);
        buffer[strcspn(buffer, "\n")] = '\0';
        tableau[i] = malloc(strlen(buffer) + 1);
        if (tableau[i] == NULL) {
            printf("Erreur d'allocation memoire\n");
            exit(1);
        }
        strcpy(tableau[i], buffer);
    }
}

void trierTableau(char **tableau, int taille) {
    for (int i = 0; i < taille - 1; i++) {
        for (int j = i + 1; j < taille; j++) {
            if (strcmp(tableau[i], tableau[j]) > 0) {
                char *temp = tableau[i];
                tableau[i] = tableau[j];
                tableau[j] = temp;
            }
        }
    }
}

char* concatenerTableau(char **tableau, int taille) {
    int longueurTotale = 0;
    for (int i = 0; i < taille; i++) {
        longueurTotale += strlen(tableau[i]) + 1;
    }

    char *unePhrase = malloc(longueurTotale);
    if (unePhrase == NULL) {
        printf("Erreur d'allocation memoire\n");
        exit(1);
    }

    unePhrase[0] = '\0';
    for (int i = 0; i < taille; i++) {
        strcat(unePhrase, tableau[i]);
        if (i < taille - 1) strcat(unePhrase, " ");
        free(tableau[i]);
    }

    return unePhrase;
}

void exercice1502() {
    int taille = 10;
    char *tableau[10];
    char *unePhrase;

    remplirTableau(tableau, taille);
    trierTableau(tableau, taille);
    unePhrase = concatenerTableau(tableau, taille);

    printf("Une phrase : %s\n", unePhrase);
    free(unePhrase);
}

int main() {
    int choix;

    do {
        printf("Choisissez un exercice (1501, 1502, 0 pour quitter) : ");
        scanf("%d", &choix);
        getchar();

        switch (choix) {
            case 1501:
                exercice1501();
                break;
            case 1502:
                exercice1502();
                break;
            case 0:
                printf("Fin du programme\n");
                break;
            default:
                printf("Choix invalide\n");
        }
    } while (choix != 0);

    return 0;
}
