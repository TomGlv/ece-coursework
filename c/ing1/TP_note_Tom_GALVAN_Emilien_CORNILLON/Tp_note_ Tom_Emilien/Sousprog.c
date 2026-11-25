#include "Sousprog.h"
/// Fonction pour construire un fichier de notes
void construire_fichier_notes() {
    int nb_elements;
    /// Demander a l'utilisateur le nombre d'elements
    printf("Entrez le nombre d'elements : ");
    scanf("%d", &nb_elements);
    /// Ouvrir le fichier en mode ecriture
    FILE *fnotes = fopen("Notes.txt", "w");
    if (fnotes == NULL) {
        perror("Erreur d'ouverture");
        exit(EXIT_FAILURE);
    }
    /// Boucle pour saisir le nom et la note et ecrire dans le fichier
    for (int i = 0; i < nb_elements; ++i) {
        char nom[50];
        int note;
        /// Saisir le nom
        printf("Entrez le nom : ");
        scanf("%s", nom);
        /// Saisir la note
        printf("Entrez la note : ");
        scanf("%d", &note);
        /// Ecrire dans le fichier
        fprintf(fnotes, "%s %d\n", nom, note);
    }
    /// Fermer le fichier
    fclose(fnotes);
}
/// Fonction pour construire un tableau dynamique a partir du fichier de notes
struct Entree* construire_tableau_dynamique(int* nb_elements) {
    FILE *fichier_notes = fopen("Notes.txt", "r");
    if (fichier_notes == NULL) {
        perror("Erreur d'ouverture");
        exit(EXIT_FAILURE);
    }
    *nb_elements = 0;
    /// Compter le nombre d'elements dans le fichier
    while (!feof(fichier_notes)) {
        char nom[50];
        int note;
        if (fscanf(fichier_notes, "%s %d", nom, &note) == 2) {
            (*nb_elements)++;
        }
    }
    /// Retablir le curseur au debut du fichier
    fseek(fichier_notes, 0, SEEK_SET);
    /// Allouer de la memoire pour le tableau
    struct Entree* tableau = (struct Entree*)malloc(*nb_elements * sizeof(struct Entree));
    if (tableau == NULL) {
        perror("Erreur lors de l'allocation du tableau dynamique");
        exit(EXIT_FAILURE);
    }
    /// Lire les donnees du fichier et les stocker dans le tableau
    for (int i = 0; i < *nb_elements; ++i) {
        fscanf(fichier_notes, "%s %d", tableau[i].nom, &tableau[i].note);
    }
    /// Fermer le fichier
    fclose(fichier_notes);
    return tableau;
}
/// Fonction pour remplacer une note dans le tableau
void remplacer_note(struct Entree* tableau, int nb_elements) {
    int min = 0;
    /// Trouver l'index de la note minimale
    for (int i = 1; i < nb_elements; ++i) {
        if (tableau[i].note < tableau[min].note) {
            min = i;
        }
    }
    /// Saisir le nouveau nom et la nouvelle note
    printf("Entrez le nouveau nom : ");
    scanf("%s", tableau[min].nom);
    printf("Entrez la nouvelle note : ");
    scanf("%d", &tableau[min].note);
}
/// Fonction pour trier le tableau par ordre decroissant des notes
void trier(struct Entree* tableau, int nb_elements) {
    for (int i = 0; i < nb_elements - 1; ++i) {
        int max = i;
        /// Trouver LES noteS maximales
        for (int j = i + 1; j < nb_elements; ++j) {
            if (tableau[j].note > tableau[max].note) {
                max = j;
            }
        }
        /// Echanger les positions
        struct Entree temp = tableau[i];
        tableau[i] = tableau[max];
        tableau[max] = temp;
    }
    /// Ouvrir un fichier pour ecrire les donnees triees
    FILE *ftrie = fopen("DonneesTriees.txt", "w");
    if (ftrie == NULL) {
        perror("Erreur d'ouverture");
        exit(EXIT_FAILURE);
    }
    /// Ecrire les donnees triees dans le fichier
    for (int i = 0; i < nb_elements; ++i) {
        fprintf(ftrie, "%s %d\n", tableau[i].nom, tableau[i].note);
    }
    /// Fermer le fichier trie
    fclose(ftrie);
}
/// Fonction pour verifier si deux tableaux sont identiques
int veriftableaux(struct Entree* tableau1, int nb_elements1) {
    int nb_elements2;
    /// Saisir le nombre d'elements pour le deuxieme tableau
    printf("Entrez le nombre d'elements pour le deuxieme tableau : ");
    if (scanf("%d", &nb_elements2) != 1 || nb_elements2 <= 0) {
        printf("Erreur : nombre d'elements invalide.\n");
        exit(EXIT_FAILURE);
    }
    /// Allouer de la memoire pour le deuxieme tableau
    struct Entree* tableau2 = (struct Entree*)malloc(nb_elements2 * sizeof(struct Entree));
    if (tableau2 == NULL) {
        perror("Erreur lors de l'allocation du deuxieme tableau");
        exit(EXIT_FAILURE);
    }
    /// Saisir les donnees pour le deuxieme tableau
    for (int i = 0; i < nb_elements2; ++i) {
        printf("Entrez le nom pour le deuxieme tableau : ");
        scanf("%s", tableau2[i].nom);
        printf("Entrez la note pour le deuxieme tableau : ");
        scanf("%d", &tableau2[i].note);
    }
    /// Verifier si les deux tableaux sont identiques
    if (nb_elements1 != nb_elements2) {
        free(tableau2);
        return 0;
    }
    for (int i = 0; i < nb_elements1; ++i) {
        if (strcmp(tableau1[i].nom, tableau2[i].nom) != 0 || tableau1[i].note != tableau2[i].note) {
            free(tableau2);
            return 0;
        }
    }
    /// Liberer la memoire allouee pour le deuxieme tableau
    free(tableau2);
    /// Les tableaux sont identiques
    return 1;
}
