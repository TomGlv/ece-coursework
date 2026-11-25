#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <time.h>

typedef struct {
    char numero[15]; // Numéro de téléphone au format international (+33XXXXXXXXX)
    char type[8];    // Type de l'appel (entrant ou sortant)
    char prenom[50];
    char nom[30];    // Nom du correspondant
    int occurrences;
} Appel;

int comparer(void *a, void *b) {
    return strcmp(((Appel*)a)->numero, ((Appel*)b)->numero);
}

void tri_bulle(Appel *appels, int taille) {
    int i, j;
    Appel temp;
    for (i = 0; i < taille - 1; i++) {
        for (j = 0; j < taille - i - 1; j++) {
            if (comparer(&appels[j], &appels[j+1]) > 0) {
                temp = appels[j];
                appels[j] = appels[j+1];
                appels[j+1] = temp;
            }
        }
    }
}

void tri_insertion(Appel *appels, int taille) {
    int i, j;
    Appel cle;
    for (i = 1; i < taille; i++) {
        cle = appels[i];
        j = i - 1;
        while (j >= 0 && comparer(&appels[j], &cle) > 0) {
            appels[j + 1] = appels[j];
            j = j - 1;
        }
        appels[j + 1] = cle;
    }
}
void creerHistogramme(Appel *appels, int taille) {
    struct {
        char numero[15];
        int occurrences;
    } histogramme[1000] = {0};

    for (int i = 0; i < taille; i++) {
        int found = 0;
        for (int j = 0; j < 1000; j++) {
            if (strcmp(appels[i].numero, histogramme[j].numero) == 0) {
                histogramme[j].occurrences++;
                found = 1;
                break;
            } else if (strlen(histogramme[j].numero) == 0) {
                strcpy(histogramme[j].numero, appels[i].numero);
                histogramme[j].occurrences = 1;
                found = 1;
                break;
            }
        }
        if (!found) {
            strcpy(histogramme[taille].numero, appels[i].numero);
            histogramme[taille].occurrences = 1;
        }
    }

    printf("Histogramme des appels telephoniques :\n");
    for (int i = 0; i < 1000; i++) {
        if (strlen(histogramme[i].numero) > 0) {
            printf("Numero : %s, Occurrences : %d\n", histogramme[i].numero, histogramme[i].occurrences);
        }
    }
}

void compterAppelsEntrantsSortants(Appel *appels, int taille) {
    int maxOccurrences = 0;
    int indexMax = 0;

    for (int i = 0; i < taille; i++) {
        if (appels[i].occurrences > maxOccurrences) {
            maxOccurrences = appels[i].occurrences;
            indexMax = i;
        }
    }
    char numeroMaxOccurrences[15];
    strcpy(numeroMaxOccurrences, appels[indexMax].numero);

    int appelsEntrants = 0;
    int appelsSortants = 0;

    for (int i = 0; i < taille; i++) {
        if (strcmp(appels[i].numero, numeroMaxOccurrences) == 0) {
            if (strcmp(appels[i].type, "entrant") == 0) {
                appelsEntrants++;
            } else if (strcmp(appels[i].type, "sortant") == 0) {
                appelsSortants++;
            }
        }
    }
    ///printf("Nombre d'appels entrants pour le numero %s : %d\n", numeroMaxOccurrences, appelsEntrants);
    ///printf("Nombre d'appels sortants pour le numero %s : %d\n", numeroMaxOccurrences, appelsSortants);
}
int triPrint() {
    FILE *fichier;
    Appel appels[1000];
    int i = 0;
    char ligne[100];
    fichier = fopen("telephone.txt", "r");
    if (fichier == NULL) {
        perror("Erreur lors de l'ouverture du fichier");
        return EXIT_FAILURE;
    }

    while (fgets(ligne, sizeof(ligne), fichier) != NULL && i < 1000) {
        sscanf(ligne, "%s %s %s %s", appels[i].numero, appels[i].prenom, appels[i].nom, appels[i].type);
        i++;
    }

    fclose(fichier);

    tri_bulle(appels, i);

    for (int j = 0; j < i; j++) {
        printf("%s %s %s %s\n", appels[j].numero, appels[j].prenom, appels[j].nom, appels[j].type);
    }

    clock_t debut_histogramme, fin_histogramme;
    double temps_ecoule_histogramme;

    debut_histogramme = clock();
    creerHistogramme(appels, i); // Appel de la fonction pour créer l'histogramme
    fin_histogramme = clock();

    temps_ecoule_histogramme = (double)(fin_histogramme - debut_histogramme) / CLOCKS_PER_SEC;
    printf("Temps ecoule pour le calcul de l'histogramme : %.2f secondes\n", temps_ecoule_histogramme);
    compterAppelsEntrantsSortants(appels,i);
    return EXIT_SUCCESS;
}
int triPrint2() {
    FILE *fichier;
    Appel appels[1000];
    int i = 0;
    char ligne[100];
    fichier = fopen("telephone.txt", "r");
    if (fichier == NULL) {
        perror("Erreur lors de l'ouverture du fichier");
        return EXIT_FAILURE;
    }

    while (fgets(ligne, sizeof(ligne), fichier) != NULL && i < 1000) {
        sscanf(ligne, "%s %s %s %s", appels[i].numero, appels[i].prenom, appels[i].nom, appels[i].type);
        i++;
    }

    fclose(fichier);

    tri_insertion(appels, i);

    for (int j = 0; j < i; j++) {
        printf("%s %s %s %s\n", appels[j].numero, appels[j].prenom, appels[j].nom, appels[j].type);
    }
    clock_t debut_histogramme, fin_histogramme;
    double temps_ecoule_histogramme;

    debut_histogramme = clock();
    creerHistogramme(appels, i); // Appel de la fonction pour créer l'histogramme
    fin_histogramme = clock();

    temps_ecoule_histogramme = (double)(fin_histogramme - debut_histogramme) / CLOCKS_PER_SEC;
    printf("Temps ecoule pour le calcul de l'histogramme : %.2f secondes\n", temps_ecoule_histogramme);
    compterAppelsEntrantsSortants(appels,i);
    return EXIT_SUCCESS;
}
int main() {
    int x;
    printf("Bienvenue a la police scientifique : \n1. Tri-bulle \n2. Tri-insertion\n");
    scanf("%d", &x);
    switch (x) {
        case 1: {
            clock_t debut, fin;
            double temps_ecoule;
            debut = clock();
            triPrint();
            fin = clock();
            temps_ecoule = (double)(fin - debut) / CLOCKS_PER_SEC;
            printf("Temps ecoule pour le tri bulle : %.2f secondes\n", temps_ecoule);
        } break;
        case 2: {
            clock_t debut, fin;
            double temps_ecoule;
            debut = clock();
            triPrint2();
            fin = clock();
            temps_ecoule = (double)(fin - debut) / CLOCKS_PER_SEC;
            printf("Temps ecoule pour le tri insertion : %.2f secondes\n", temps_ecoule);
        } break;
        default:
            printf("Choix invalide\n");
    }

    return 0;
}
