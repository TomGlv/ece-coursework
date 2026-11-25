#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>
#include <stdlib.h>

// Définition de la structure Personne
typedef struct {
    char nom[50];
    int age;
    float taille;
} Personne;

Personne* allouerPersonnes(int n) {
    return (Personne*)malloc(n * sizeof(Personne));  // Allocation dynamique
}
void remplirPersonnes(Personne* tab, int n) {
    for (int i = 0; i < n; i++) {
        printf("Entrez le nom de la personne %d : ", i + 1);
        scanf("%s", tab[i].nom);
        printf("Entrez l'âge de %s : ", tab[i].nom);
        scanf("%d", &tab[i].age);
        printf("Entrez la taille de %s : ", tab[i].nom);
        scanf("%f", &tab[i].taille);
    }
}
void afficherPersonnes(Personne* tab, int n) {
    for (int i = 0; i < n; i++) {
        printf("Personne %d : Nom = %s, Age = %d, Taille = %.2f\n",
            i + 1, tab[i].nom, tab[i].age, tab[i].taille);
    }
}
void trierParAge(Personne* tab, int n) {
    Personne temp;
    for (int i = 0; i < n - 1; i++) {
        for (int j = i + 1; j < n; j++) {
            if (tab[i].age > tab[j].age) {
                // Échange de personnes
                temp = tab[i];
                tab[i] = tab[j];
                tab[j] = temp;
            }
        }
    }
}
void sauvegarderDansFichier(Personne* tab, int n) {
    FILE* fichier = fopen("personnes.txt", "w");
    if (fichier == NULL) {
        printf("Erreur lors de l'ouverture du fichier.\n");
        return;
    }
    for (int i = 0; i < n; i++) {
        fprintf(fichier, "Nom: %s, Age: %d, Taille: %.2f\n",
            tab[i].nom, tab[i].age, tab[i].taille);
    }
    fclose(fichier);
}
void lireDepuisFichier() {
    FILE* fichier = fopen("personnes.txt", "r");
    if (fichier == NULL) {
        printf("Erreur lors de l'ouverture du fichier.\n");
        return;
    }
    char ligne[100];
    while (fgets(ligne, sizeof(ligne), fichier)) {
        printf("%s", ligne);
    }
    fclose(fichier);
}
int main() {
    int n;
    printf("Combien de personnes voulez-vous enregistrer ? ");
    scanf("%d", &n);

    // Allocation dynamique
    Personne* personnes = allouerPersonnes(n);

    // Remplissage des informations des personnes
    remplirPersonnes(personnes, n);

    // Affichage des informations avant le tri
    printf("\nListe des personnes avant tri :\n");
    afficherPersonnes(personnes, n);

    // Tri des personnes par âge
    trierParAge(personnes, n);

    // Affichage des informations après le tri
    printf("\nListe des personnes après tri :\n");
    afficherPersonnes(personnes, n);

    // Sauvegarde dans un fichier
    sauvegarderDansFichier(personnes, n);

    // Lecture et affichage des informations depuis le fichier
    printf("\nDonnées lues depuis le fichier :\n");
    lireDepuisFichier();

    // Libération de la mémoire allouée
    free(personnes);

    return 0;
}

