#include <stdio.h>
#include <string.h>
#define N 10
#define MAX_TITLE 100

void remplir_film(char categorie[], int *note, char titre[]) {
    printf("Entrez la categorie du film : ");
    scanf("%s", categorie);
    printf("Entrez la note du film (0-10) : ");
    scanf("%d", note);
    printf("Entrez le titre du film : ");
    getchar();
    fgets(titre, MAX_TITLE, stdin);
}
void afficher_film(const char categorie[], int note, const char titre[]) {
    printf("Categorie : %s\n", categorie);
    printf("Note : %d\n", note);
    printf("Titre : %s\n", titre);
}
void remplir_tab_films(char categories[N][20], int notes[N], char titres[N][MAX_TITLE]) {
    for (int i = 0; i < N; i++) {
        printf("\nFilm %d:\n", i + 1);
        remplir_film(categories[i], &notes[i], titres[i]);
    }
}
void afficher_tab_films(const char categories[N][20], const int notes[N], const char titres[N][MAX_TITLE]) {
    for (int i = 0; i < N; i++) {
        printf("\nFilm %d:\n", i + 1);
        afficher_film(categories[i], notes[i], titres[i]);
    }
}
int recherche_titre_film(const char titres[N][MAX_TITLE], const char titre[]) {
    for (int i = 0; i < N; i++) {
        if (strcmp(titres[i], titre) == 0) {
            return i;
        }
    }
    return -1;
}
int main() {
    int choix;
    char categorie[20];
    int note;
    char titre[MAX_TITLE];
    char categories[N][20];
    int notes[N];
    char titres[N][MAX_TITLE];
    do {
        printf("Menu:\n");
        printf("1. Remplir et afficher les informations d'un film\n");
        printf("2. Remplir et afficher les informations de 10 films\n");
        printf("3. Rechercher un film par son titre\n");
        printf("4. Quitter\n");
        printf("Entrez votre choix : ");
        scanf("%d", &choix);

        switch (choix) {
            case 1:
                remplir_film(categorie, &note, titre);
                afficher_film(categorie, note, titre);
                break;
            case 2:
                remplir_tab_films(categories, notes, titres);
                afficher_tab_films(categories, notes, titres);
                break;
            case 3:
                printf("Entrez le titre du film a rechercher : ");
                getchar();
                fgets(titre, MAX_TITLE, stdin);
                int index = recherche_titre_film(titres, titre);
                if (index != -1) {
                    printf("Film trouve :\n");
                    afficher_film(categories[index], notes[index], titres[index]);
                } else {
                    printf("Film non trouve.\n");
                }
                break;
            case 4:
                printf("Au revoir !\n");
                break;
            default:
                printf("Option invalide.\n");
        }
    } while (choix != 4);

    return 0;
}

