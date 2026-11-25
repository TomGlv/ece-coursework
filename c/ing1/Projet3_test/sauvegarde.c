#include "menu.h"
void sauvegarde(def_bloc plateau[HAUTEUR][LARGEUR]) {
    char nom [20];
    printf("Quel est le nom de la sauvegarde ?");
    scanf("%s", nom);
    FILE *save;
    save = fopen("./%s.txt", "a+");
    if (save == NULL) {
        printf("Erreur d'ouverture");
        return;
    }
    for (int i = 0; i < HAUTEUR; i++) {
        for (int j = 0; j < LARGEUR; j++) {
            fprintf(save, "%c", plateau[i][j]);
        }
        fprintf(save, "\n");
    }
    fclose(save);
    printf("La partie a ete sauvegardee !");
    sleep(1);
}
void chargerpartie(def_bloc plateau[HAUTEUR][LARGEUR]) {
    char nom[20];
    printf("Quel partie voulez vous charger ?");
    scanf("%s", nom);
    printf("Chargement ....");
    sleep(1);
    FILE *save;
    save = fopen("./%s.txt", "r");
    if (save == NULL) {
        printf("Erreur d'ouverture");
        return;
    }
    for (int i = 0; i < HAUTEUR; i++) {
        for (int j = 0; j < LARGEUR; j++) {
            fscanf(save, "%c", &plateau[i][j]);
            printf("%c", plateau[i][j]);
        }
    }
    fclose(save);
}

void sauvegardeinit(def_bloc plateau[HAUTEUR][LARGEUR]) {
    FILE *save;
    save = fopen("./sauvegardeinit.txt", "w");
    for (int i = 0; i < HAUTEUR; i++) {
        for (int j = 0; j < LARGEUR; j++) {
            fprintf(save, "%c", plateau[i][j]);
        }fprintf(save, "\n");
    }fclose(save);
}
void chargerpartieinit(def_bloc plateau[HAUTEUR][LARGEUR]){
    FILE *save;
    save = fopen("./sauvegardeinit.txt", "r");
    for (int i = 0; i < HAUTEUR; i++) {
        printf(save, "\n");
        for (int j = 0; j < LARGEUR; j++){
            fscanf(save, "%c", &plateau[i][j]);
            printf("%c", plateau[i][j]);
        }
    }fclose(save);
}

void savescore() {
    effacerEcran();
    int tempsRestant;
    sleep(1);
    FILE *score;
    score = fopen("./score.txt", "r");
    if (score== NULL) {
        printf("Erreur d'ouverture");
        return;
    }
    fscanf(score, "%d", &tempsRestant);
    printf("Le dernier score est :");
    printf("%d", tempsRestant);
    sleep(3);
    fclose(score);
}