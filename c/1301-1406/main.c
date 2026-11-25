
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <time.h>

#define MAX_ARTICLES 20
#define MAX_LIVRES 10
#define MAX_AUTEURS 5
#define MAX_THEMES 5
#define MAX_LEN 50

typedef struct {
    int jour;
    int mois;
    int annee;
} t_date;

typedef struct {
    int numero;
    int categorie;
    t_date peremption;
    int quantite;
    float prix;
} t_article;

typedef struct {
    int identifiant;
    char titre[MAX_LEN];
    char auteurs[MAX_AUTEURS][MAX_LEN];
    char themes[MAX_THEMES][MAX_LEN];
    float prix_ht;
    t_date parution;
} t_livre;

typedef struct {
    char titre[30];
    int annee_realisation;
    char initiale_realisateur;
    int duree;
    char vu;
    int note;
} t_film;


t_date saisirDate() {
    t_date date;
    printf("Entrez une date (jour mois annee) : ");
    scanf("%d %d %d", &date.jour, &date.mois, &date.annee);
    return date;
}


t_article saisirArticle() {
    t_article article;
    printf("Entrez le numero d'article : ");
    scanf("%d", &article.numero);
    printf("Entrez la categorie : ");
    scanf("%d", &article.categorie);
    printf("Entrez la date de peremption :\n");
    article.peremption = saisirDate();
    printf("Entrez la quantite : ");
    scanf("%d", &article.quantite);
    printf("Entrez le prix : ");
    scanf("%f", &article.prix);
    return article;
}

void remplirArticles(t_article articles[], int taille) {
    for (int i = 0; i < taille; i++) {
        printf("\nArticle %d :\n", i + 1);
        articles[i] = saisirArticle();
    }
}

void afficherArticle(t_article article) {
    printf("\nNumero : %d\n", article.numero);
    printf("Categorie : %d\n", article.categorie);
    printf("Date de peremption : %02d/%02d/%04d\n",
           article.peremption.jour, article.peremption.mois, article.peremption.annee);
    printf("Quantite : %d\n", article.quantite);
    printf("Prix : %.2f\n", article.prix);
}

void afficherArticles(t_article articles[], int taille) {
    for (int i = 0; i < taille; i++) {
        afficherArticle(articles[i]);
    }
}

void saisirLivre(t_livre* livre) {
    printf("\nEntrez l'identifiant du livre : ");
    scanf("%d", &livre->identifiant);
    getchar(); // Nettoyer le buffer

    printf("Entrez le titre : ");
    fgets(livre->titre, MAX_LEN, stdin);
    livre->titre[strcspn(livre->titre, "\n")] = '\0';

    for (int i = 0; i < MAX_AUTEURS; i++) {
        printf("Entrez l'auteur %d (ou laissez vide pour arreter) : ", i + 1);
        fgets(livre->auteurs[i], MAX_LEN, stdin);
        livre->auteurs[i][strcspn(livre->auteurs[i], "\n")] = '\0';
        if (strlen(livre->auteurs[i]) == 0) break;
    }

    for (int i = 0; i < MAX_THEMES; i++) {
        printf("Entrez le theme %d (ou laissez vide pour arreter) : ", i + 1);
        fgets(livre->themes[i], MAX_LEN, stdin);
        livre->themes[i][strcspn(livre->themes[i], "\n")] = '\0';
        if (strlen(livre->themes[i]) == 0) break;
    }

    printf("Entrez le prix HT : ");
    scanf("%f", &livre->prix_ht);
    printf("Entrez la date de parution :\n");
    livre->parution = saisirDate();
}


void afficherLivre(t_livre livre) {
    printf("\nIdentifiant : %d\n", livre.identifiant);
    printf("Titre : %s\n", livre.titre);
    printf("Auteurs :\n");
    for (int i = 0; i < MAX_AUTEURS && strlen(livre.auteurs[i]) > 0; i++) {
        printf("  - %s\n", livre.auteurs[i]);
    }
    printf("Themes :\n");
    for (int i = 0; i < MAX_THEMES && strlen(livre.themes[i]) > 0; i++) {
        printf("  - %s\n", livre.themes[i]);
    }
    printf("Prix HT : %.2f\n", livre.prix_ht);
    printf("Date de parution : %02d/%02d/%04d\n",
           livre.parution.jour, livre.parution.mois, livre.parution.annee);
}


t_film saisirFilm() {
    t_film film;
    getchar();
    printf("Entrez le titre du film : ");
    fgets(film.titre, 30, stdin);
    film.titre[strcspn(film.titre, "\n")] = '\0';

    printf("Entrez l'annee de realisation : ");
    scanf("%d", &film.annee_realisation);

    getchar(); // Nettoyer le buffer
    printf("Entrez la premiere lettre du realisateur : ");
    scanf("%c", &film.initiale_realisateur);

    printf("Entrez la dure en minutes : ");
    scanf("%d", &film.duree);

    do {
        printf("Avez-vous vu ce film ? (1 pour oui, 0 pour non) : ");
        scanf(" %c", &film.vu);
    } while (film.vu != '1' && film.vu != '0');

    do {
        printf("Entrez une note sur 10 : ");
        scanf("%d", &film.note);
    } while (film.note < 0 || film.note > 10);

    return film;
}


void afficherFilm(t_film film) {
    printf("\nTitre : %s\n", film.titre);
    printf("Anne de realisation : %d\n", film.annee_realisation);
    printf("Initiale du realisateur : %c\n", film.initiale_realisateur);
    printf("Dure : %d minutes\n", film.duree);
    printf("Vu : %s\n", (film.vu == '1') ? "Oui" : "Non");
    printf("Note : %d/10\n", film.note);
}


int main() {
    t_article articles[MAX_ARTICLES];
    t_livre livres[MAX_LIVRES];
    t_film films[MAX_LIVRES];
    int choix;

    do {
        printf("\nMenu Principal :\n");
        printf("1. Gerer les articles\n");
        printf("2. Gerer les livres\n");
        printf("3. Gerer les films\n");
        printf("4. Quitter\n");
        printf("Entrez votre choix : ");
        scanf("%d", &choix);

        switch (choix) {
            case 1:
                remplirArticles(articles, MAX_ARTICLES);
                afficherArticles(articles, MAX_ARTICLES);
                break;

            case 2:
                for (int i = 0; i < MAX_LIVRES; i++) {
                    printf("\nLivre %d :\n", i + 1);
                    saisirLivre(&livres[i]);
                }
                for (int i = 0; i < MAX_LIVRES; i++) {
                    afficherLivre(livres[i]);
                }
                break;

            case 3:
                for (int i = 0; i < MAX_LIVRES; i++) {
                    printf("\nFilm %d :\n", i + 1);
                    films[i] = saisirFilm();
                }
                for (int i = 0; i < MAX_LIVRES; i++) {
                    afficherFilm(films[i]);
                }
                break;

            case 4:
                printf("Au revoir !\n");
                break;

            default:
                printf("Choix invalide.\n");
        }
    } while (choix != 4);

    return 0;
}
