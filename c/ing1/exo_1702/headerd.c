
#include "headerd.h"

void afficherListe(t_maillon_voiture* liste) {
    t_maillon_voiture* courant = liste;

    while (courant != NULL) {
        printf("Immatriculation : %s\n", courant->immatriculation);
        printf("Marque : %s\n", courant->marque);
        printf("Modèle : %s\n", courant->modele);
        printf("Vitesse maximum : %d\n", courant->vitesseMax);
        printf("Type de carburant : %c\n", courant->carburant);
        printf("Date de mise en service : %02d/%02d/%04d\n", courant->dateMiseEnService.jour, courant->dateMiseEnService.mois, courant->dateMiseEnService.annee);
        printf("\n");

        courant = courant->suivant;
    }
}

void afficherImmatriculationsParMarque(t_maillon_voiture* liste, const char* marque) {
    t_maillon_voiture* courant = liste;

    while (courant != NULL) {
        if (strcmp(courant->marque, marque) == 0) {
            printf("Immatriculation : %s\n", courant->immatriculation);
        }

        courant = courant->suivant;
    }
}

t_maillon_voiture* supprimerVoitureParImmatriculation(t_maillon_voiture** liste, const char* immatriculation) {
    t_maillon_voiture* courant = *liste;
    t_maillon_voiture* precedent = NULL;

    while (courant != NULL) {
        if (strcmp(courant->immatriculation, immatriculation) == 0) {
            if (precedent == NULL) {
                // Le maillon à supprimer est en tête de liste
                *liste = courant->suivant;
            } else {
                precedent->suivant = courant->suivant;
            }

            printf("Suppression effectuée.\n");
            free(courant);
            return *liste;
        }

        precedent = courant;
        courant = courant->suivant;
    }

    printf("Suppression impossible car voiture inconnue.\n");
    return *liste;
}
