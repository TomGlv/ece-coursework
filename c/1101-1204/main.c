#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <time.h>
void saisirChaine(char *chaine, int taille) {
    printf("Saisir une chaine : ");
    fgets(chaine, taille, stdin);
    chaine[strcspn(chaine, "\n")] = '\0';
}

void analyserChaine(char *chaine, int *nbNumeriques, int *nbMinuscules) {
    int i;
    *nbNumeriques = 0;
    *nbMinuscules = 0;
    for (i = 0; chaine[i] != '\0'; i++) {
        if (chaine[i] >= '0' && chaine[i] <= '9') (*nbNumeriques)++;
        if (chaine[i] >= 'a' && chaine[i] <= 'z') (*nbMinuscules)++;
    }
}

int compterMots(char *chaine) {
    int i, count = 0, inWord = 0;
    for (i = 0; chaine[i] != '\0'; i++) {
        if (chaine[i] != ' ' && chaine[i] != '\n') {
            if (!inWord) {
                count++;
                inWord = 1;
            }
        } else {
            inWord = 0;
        }
    }
    return count;
}

void exercice1101() {
    char chaine1[100], chaine2[200];
    int count1 = 0, count2 = 0, i;

    printf("Saisir une chaine sans espaces : ");
    scanf("%s", chaine1);
    printf("Saisir une phrase : ");
    getchar();
    fgets(chaine2, 200, stdin);

    for (i = 0; chaine1[i] != '\0'; i++) count1++;
    for (i = 0; chaine2[i] != '\0'; i++) count2++;

    printf("Chaine 1: %s, Nombre de caracteres: %d\n", chaine1, count1);
    printf("Chaine 2: %s, Nombre de caracteres: %d\n", chaine2, count2 - 1);
}
char* construireChaine(char *chaine) {
    static char resultat[5];
    int longueur = strlen(chaine);
    if (longueur < 4) {
        printf("Chaine non valable\n");
        resultat[0] = '\0';
    } else {
        resultat[0] = chaine[0];
        resultat[1] = chaine[1];
        resultat[2] = chaine[longueur - 2];
        resultat[3] = chaine[longueur - 1];
        resultat[4] = '\0';
    }
    return resultat;
}

int verifierSousChaine(char *chaine1, char *chaine2) {
    return strstr(chaine1, chaine2) != NULL;
}


void exercice1103() {
    char chaine[200];
    int nbNumeriques, nbMinuscules, nbMots;

    saisirChaine(chaine, 200);
    analyserChaine(chaine, &nbNumeriques, &nbMinuscules);
    nbMots = compterMots(chaine);

    printf("Chaine: %s\n", chaine);
    printf("Numeriques: %d, Minuscules: %d, Mots: %d\n", nbNumeriques, nbMinuscules, nbMots);
}


void exercice1107() {
    char chaine1[100], chaine2[100];
    char *resultat;
    int existe;

    saisirChaine(chaine1, 100);
    saisirChaine(chaine2, 100);

    resultat = construireChaine(chaine1);
    printf("Resultat: %s\n", resultat);

    existe = verifierSousChaine(chaine1, chaine2);
    printf("Sous-chaine trouvee: %d\n", existe);
}

int genererNombre(int borneSuperieure) {
    return rand() % borneSuperieure + 1;
}

void exercice1201() {
    int nombre, essai, essais = 0;

    srand(time(NULL));
    nombre = genererNombre(200);

    do {
        printf("Devinez le nombre : ");
        scanf("%d", &essai);
        essais++;
    } while (essai != nombre);

    printf("Trouve en %d essais\n", essais);
}

void remplirTableau(char tableau[15][20]) {
    int i, j;
    for (i = 0; i < 15; i++) {
        for (j = 0; j < 20; j++) {
            tableau[i][j] = 'a' + rand() % 26;
        }
    }
}

void compterLettres(char tableau[15][20], int compteurs[26]) {
    int i, j;
    for (i = 0; i < 26; i++) compteurs[i] = 0;
    for (i = 0; i < 15; i++) {
        for (j = 0; j < 20; j++) {
            compteurs[tableau[i][j] - 'a']++;
        }
    }
}

void exercice1204() {
    char tableau[15][20];
    int compteurs[26], i;

    srand(time(NULL));
    remplirTableau(tableau);
    compterLettres(tableau, compteurs);

    for (i = 0; i < 26; i++) {
        printf("%c: %d\n", 'a' + i, compteurs[i]);
    }
}

int main() {
    int choix;

    do {
        printf("Choisissez un exercice (1101, 1103, 1107, 1201, 1204, 0 pour quitter): ");
        scanf("%d", &choix);
        getchar();

        switch (choix) {
            case 1101:
                exercice1101();
                break;
            case 1103:
                exercice1103();
                break;
            case 1107:
                exercice1107();
                break;
            case 1201:
                exercice1201();
                break;
            case 1204:
                exercice1204();
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
