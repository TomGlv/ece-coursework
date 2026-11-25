#include <stdio.h>
#include <stdlib.h>
#include <string.h>


typedef struct etudiant {
    int numero;
    char nom[50];
    char prenom[50];
    char adresse[100];
    int promotion;
    int groupe;
    struct etudiant *suivant;
} etudiant;

typedef struct t_date {
    int jour;
    int mois;
    int annee;
} t_date;

typedef struct voiture {
    char immatriculation[20];
    char marque[50];
    char modele[50];
    int vitesseMax;
    char carburant;
    t_date miseEnService;
    struct voiture *suivant;
} voiture;

void afficherImmatriculationsParMarque(voiture *liste, char *marque) {
    int trouve = 0;
    while (liste) {
        if (strcmp(liste->marque, marque) == 0) {
            printf("Immatriculation: %s\n", liste->immatriculation);
            trouve = 1;
        }
        liste = liste->suivant;
    }
    if (!trouve) {
        printf("Aucune voiture trouvee pour la marque %s.\n", marque);
    }
}

voiture* supprimerVoiture(voiture *liste, char *immatriculation) {
    voiture *current = liste, *precedent = NULL;

    while (current) {
        if (strcmp(current->immatriculation, immatriculation) == 0) {
            if (precedent) {
                precedent->suivant = current->suivant;
            } else {
                liste = current->suivant;
            }
            free(current);
            printf("Suppression effectuee\n");
            return liste;
        }
        precedent = current;
        current = current->suivant;
    }
    printf("Suppression impossible car voiture inconnue\n");
    return liste;
}

voiture* creerVoiture() {
    voiture *nouvelle = malloc(sizeof(voiture));
    if (!nouvelle) exit(1);

    printf("Immatriculation: ");
    scanf("%s", nouvelle->immatriculation);
    getchar();  // Consomme le '\n' restant après la saisie de l'immatriculation

    printf("Marque: ");
    scanf("%s", nouvelle->marque);
    getchar();  // Consomme le '\n' restant après la saisie de la marque

    printf("Modele: ");
    scanf("%s", nouvelle->modele);
    getchar();  // Consomme le '\n' restant après la saisie du modèle

    printf("Vitesse max: ");
    scanf("%d", &nouvelle->vitesseMax);
    getchar();  // Consomme le '\n' restant après la saisie de la vitesse max

    printf("Carburant (c): ");
    scanf(" %c", &nouvelle->carburant);
    getchar();  // Consomme le '\n' restant après la saisie du carburant

    // Saisie de la date
    printf("Date mise en service (jj mm aaaa): ");
    scanf("%d %d %d", &nouvelle->miseEnService.jour,
          &nouvelle->miseEnService.mois,
          &nouvelle->miseEnService.annee);
    getchar();  // Consomme le '\n' restant après la saisie de la date

    nouvelle->suivant = NULL;
    return nouvelle;
}

void afficherVoitures(voiture *liste) {
    if (!liste) {
        printf("Aucune voiture dans la liste.\n");
        return;
    }

    printf("Liste des voitures disponibles :\n");
    while (liste) {
        printf("Immatriculation: %s, Marque: %s, Modele: %s, Vitesse max: %d, Carburant: %c, Date: %02d/%02d/%04d\n",
               liste->immatriculation, liste->marque, liste->modele, liste->vitesseMax,
               liste->carburant, liste->miseEnService.jour, liste->miseEnService.mois, liste->miseEnService.annee);
        liste = liste->suivant;
    }
}

void exercice1702() {
    voiture *liste = NULL, *nouvelle;
    int choix;
    char marque[50], immatriculation[20];

    do {
        printf("\nMenu:\n");
        printf("1. Ajouter une voiture\n");
        printf("2. Afficher toutes les voitures\n");
        printf("3. Afficher immatriculations par marque\n");
        printf("4. Supprimer une voiture\n");
        printf("0. Quitter\n");
        printf("Choix: ");
        scanf("%d", &choix);
        getchar();  // Consomme le '\n' restant

        switch (choix) {
            case 1:
                nouvelle = creerVoiture();
                nouvelle->suivant = liste;
                liste = nouvelle;
                break;
            case 2:
                afficherVoitures(liste);
                break;
            case 3:
                printf("Saisir la marque: ");
                scanf("%s", marque);
                afficherImmatriculationsParMarque(liste, marque);
                break;
            case 4:
                printf("Saisir l'immatriculation: ");
                scanf("%s", immatriculation);
                liste = supprimerVoiture(liste, immatriculation);
                break;
            case 0:
                while (liste) {
                    voiture *temp = liste;
                    liste = liste->suivant;
                    free(temp);
                }
                printf("Fin du programme.\n");
                break;
            default:
                printf("Choix invalide.\n");
        }
    } while (choix != 0);
}

int compterEtudiants(etudiant *liste) {
    int count = 0;
    while (liste) {
        count++;
        liste = liste->suivant;
    }
    return count;
}

etudiant* ajouterEtudiant(etudiant *liste, etudiant *nouveau) {
    if (!liste || nouveau->numero < liste->numero) {
        nouveau->suivant = liste;
        return nouveau;
    }
    etudiant *current = liste;
    while (current->suivant && current->suivant->numero < nouveau->numero) {
        current = current->suivant;
    }
    nouveau->suivant = current->suivant;
    current->suivant = nouveau;
    return liste;
}

etudiant* supprimerEtudiantParNumero(etudiant *liste, int numero) {
    etudiant *current = liste, *precedent = NULL;

    while (current) {
        if (current->numero == numero) {
            if (precedent) {
                precedent->suivant = current->suivant;
            } else {
                liste = current->suivant;
            }
            free(current);
            printf("Suppression effectuee\n");
            return liste;
        }
        precedent = current;
        current = current->suivant;
    }
    printf("Suppression impossible car etudiant inconnu\n");
    return liste;
}

void exercice1705() {
    etudiant *liste = NULL, *nouveau;
    int choix, numero;

    do {
        printf("1. Ajouter un etudiant\n2. Afficher le nombre d'etudiants\n3. Supprimer un etudiant\n0. Quitter\nChoix: ");
        scanf("%d", &choix);
        getchar();

        switch (choix) {
            case 1:
                nouveau = malloc(sizeof(etudiant));
                if (!nouveau) exit(1);
                printf("Numero: ");
                scanf("%d", &nouveau->numero);
                getchar();
                printf("Nom: ");
                fgets(nouveau->nom, 50, stdin);
                nouveau->nom[strcspn(nouveau->nom, "\n")] = '\0';
                printf("Prenom: ");
                fgets(nouveau->prenom, 50, stdin);
                nouveau->prenom[strcspn(nouveau->prenom, "\n")] = '\0';
                printf("Adresse: ");
                fgets(nouveau->adresse, 100, stdin);
                nouveau->adresse[strcspn(nouveau->adresse, "\n")] = '\0';
                printf("Promotion: ");
                scanf("%d", &nouveau->promotion);
                printf("Groupe: ");
                scanf("%d", &nouveau->groupe);
                nouveau->suivant = NULL;
                liste = ajouterEtudiant(liste, nouveau);
                break;
            case 2:
                printf("Nombre d'etudiants: %d\n", compterEtudiants(liste));
                break;
            case 3:
                printf("Saisir le numero: ");
                scanf("%d", &numero);
                liste = supprimerEtudiantParNumero(liste, numero);
                break;
            case 0:
                while (liste) {
                    etudiant *temp = liste;
                    liste = liste->suivant;
                    free(temp);
                }
                break;
            default:
                printf("Choix invalide\n");
        }
    } while (choix != 0);
}

int main() {
    int choix;

    do {
        printf("Choisissez un exercice (1702, 1705, 0 pour quitter): ");
        scanf("%d", &choix);
        getchar();

        switch (choix) {
            case 1702:
                exercice1702();
                break;
            case 1705:
                exercice1705();
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