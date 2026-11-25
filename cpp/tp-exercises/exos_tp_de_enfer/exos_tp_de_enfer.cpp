#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>
#include <string.h>

#define MAX_LIVRES 100  // Nombre maximum de livres dans la bibliothèque
#define MAX_CARACTERES 50  // Longueur maximale des chaînes (titre et auteur)

// Déclaration des tableaux pour stocker les informations des livres
char titres[MAX_LIVRES][MAX_CARACTERES];
char auteurs[MAX_LIVRES][MAX_CARACTERES];
int annees[MAX_LIVRES];
int nombre_livres = 0;  // Nombre de livres actuels dans la bibliothèque

// Sous-programme pour ajouter un livre
void ajouter_livre() {
    if (nombre_livres >= MAX_LIVRES) {
        printf("La bibliothèque est pleine !\n");
        return;
    }
    printf("Titre du livre : ");
    scanf(" %[^\n]", titres[nombre_livres]);  // Lecture de la chaîne avec espaces

    printf("Auteur du livre : ");
    scanf(" %[^\n]", auteurs[nombre_livres]);

    printf("Année de publication : ");
    scanf("%d", &annees[nombre_livres]);

    nombre_livres++;
    printf("Livre ajouté avec succès !\n");
}

// Sous-programme pour supprimer un livre
void supprimer_livre() {
    char titre_recherche[MAX_CARACTERES];
    printf("Titre du livre à supprimer : ");
    scanf(" %[^\n]", titre_recherche);

    int index = -1;
    for (int i = 0; i < nombre_livres; i++) {
        if (strcmp(titres[i], titre_recherche) == 0) {
            index = i;
            break;
        }
    }

    if (index == -1) {
        printf("Livre non trouvé !\n");
        return;
    }

    // Décalage des éléments pour supprimer le livre
    for (int i = index; i < nombre_livres - 1; i++) {
        strcpy(titres[i], titres[i + 1]);
        strcpy(auteurs[i], auteurs[i + 1]);
        annees[i] = annees[i + 1];
    }

    nombre_livres--;
    printf("Livre supprimé avec succès !\n");
}

// Sous-programme pour rechercher un livre
void rechercher_livre() {
    char recherche[MAX_CARACTERES];
    printf("Entrez un titre ou un auteur à rechercher : ");
    scanf(" %[^\n]", recherche);

    int trouve = 0;
    for (int i = 0; i < nombre_livres; i++) {
        if (strcmp(titres[i], recherche) == 0 || strcmp(auteurs[i], recherche) == 0) {
            printf("Livre trouvé :\n");
            printf("Titre : %s\n", titres[i]);
            printf("Auteur : %s\n", auteurs[i]);
            printf("Année de publication : %d\n", annees[i]);
            trouve = 1;
            break;
        }
    }

    if (!trouve) {
        printf("Livre non trouvé !\n");
    }
}

// Sous-programme pour afficher tous les livres
void afficher_livres() {
    if (nombre_livres == 0) {
        printf("La bibliothèque est vide !\n");
        return;
    }
    printf("Liste des livres disponibles :\n");
    for (int i = 0; i < nombre_livres; i++) {
        printf("Livre %d :\n", i + 1);
        printf("Titre : %s\n", titres[i]);
        printf("Auteur : %s\n", auteurs[i]);
        printf("Année de publication : %d\n", annees[i]);
        printf("\n");
    }
}

// Programme principal avec le menu
int main() {
    int choix;
    do {
        printf("\n--- Bibliothèque ---\n");
        printf("1. Ajouter un livre\n");
        printf("2. Supprimer un livre\n");
        printf("3. Rechercher un livre\n");
        printf("4. Afficher tous les livres\n");
        printf("0. Quitter\n");
        printf("Choisissez une option : ");
        scanf("%d", &choix);

        switch (choix) {
        case 1:
            ajouter_livre();
            break;
        case 2:
            supprimer_livre();
            break;
        case 3:
            rechercher_livre();
            break;
        case 4:
            afficher_livres();
            break;
        case 0:
            printf("Au revoir !\n");
            break;
        default:
            printf("Choix invalide. Veuillez réessayer.\n");
        }
    } while (choix != 0);

    return 0;
}