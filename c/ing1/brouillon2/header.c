
#include "header.h"
void saisirListeAthletes(Athlete **athletes, int *nbAthletes) {
    printf("Entrez le nombre d'athlètes : ");
    scanf("%d", nbAthletes);

    *athletes = (Athlete *)malloc(*nbAthletes * sizeof(Athlete));

    for (int i = 0; i < *nbAthletes; ++i) {
        printf("Athlète %d\n", i + 1);
        printf("Nom : ");
        scanf("%s", (*athletes)[i].nom);
        printf("Hauteur : ");
        scanf("%f", &(*athletes)[i].hauteur);
    }
}

void afficherListeAthletes(Athlete *athletes, int nbAthletes) {
    if (nbAthletes == 0) {
        printf("Aucun athlète à afficher.\n");
        return;
    }
    printf("Liste des athlètes :\n");
    for (int i = 0; i < nbAthletes; ++i) {
        printf("Athlète %d : %s, Hauteur : %.2f\n", i + 1, athletes[i].nom, athletes[i].hauteur);
    }
}

void trouverEtAfficherMeilleur(Athlete *athletes, int nbAthletes) {
    if (nbAthletes == 0) {
        printf("Aucun athlète à évaluer.\n");
        return;
    }
    int indiceMeilleur = 0;
    for (int i = 1; i < nbAthletes; ++i) {
        if (athletes[i].hauteur > athletes[indiceMeilleur].hauteur) {
            indiceMeilleur = i;
        }
    }

    printf("Le meilleur athlète est : %s, Hauteur : %.2f\n", athletes[indiceMeilleur].nom, athletes[indiceMeilleur].hauteur);
}

void sauvegarderListeAthletes(Athlete *athletes, int nbAthletes, const char *nomFichier) {
    FILE *fichier = fopen(nomFichier, "w");
    if (fichier == NULL) {
        fprintf(stderr, "Erreur lors de l'ouverture du fichier pour la sauvegarde.\n");
        return;
    }
    fprintf(fichier, "%d\n", nbAthletes);
    for (int i = 0; i < nbAthletes; ++i) {
        fprintf(fichier, "%s\n%f\n", athletes[i].nom, athletes[i].hauteur);
    }
    fclose(fichier);
    printf("Liste des athlètes sauvegardée dans %s.\n", nomFichier);
}

void chargerListeAthletes(Athlete **athletes, int *nbAthletes, const char *nomFichier) {
    FILE *fichier = fopen(nomFichier, "r");
    if (fichier == NULL) {
        fprintf(stderr, "Erreur lors de l'ouverture du fichier pour le chargement.\n");
        return;
    }
    fscanf(fichier, "%d", nbAthletes);
    *athletes = (Athlete *)malloc(*nbAthletes * sizeof(Athlete));
    for (int i = 0; i < *nbAthletes; ++i) {
        fscanf(fichier, "%s%f", (*athletes)[i].nom, &(*athletes)[i].hauteur);
    }
    fclose(fichier);
    printf("Liste des athlètes chargée depuis %s.\n", nomFichier);
}
