#include "headerd.h"


int main() {
    t_maillon_voiture* liste = NULL;
    char choix;

    do {
        printf("\nMenu:\n");
        printf("1. Insérer une voiture\n");
        printf("2. Afficher les données des voitures d'une marque\n");
        printf("3. Supprimer une voiture par immatriculation\n");
        printf("4. Quitter\n");
        printf("Votre choix : ");
        scanf(" %c", &choix);

        switch (choix) {
            case '1':
                liste = creerMaillon(liste);
                break;
            case '2':
                {
                    char marqueRecherche[50];
                    printf("Saisissez la marque : ");
                    scanf("%s", marqueRecherche);
                    afficherImmatriculationsParMarque(liste, marqueRecherche);
                }
                break;
            case '3':
                {
                    afficherListe(liste);

                }
                break;
            case '4':{
                char immatriculationASupprimer[20];
                printf("Saisissez l'immatriculation à supprimer : ");
                scanf("%s", immatriculationASupprimer);
                liste = supprimerVoitureParImmatriculation(liste, immatriculationASupprimer);
            }
                break;
            default:
                printf("Choix invalide. Veuillez réessayer.\n");
        }
    } while (choix != '4');

    // Libérer les données dynamiques
    while (liste != NULL) {
        t_maillon_voiture* temp = liste;
        liste = liste->suivant;
        free(temp);
    }

    return 0;
}

t_maillon_voiture* creerMaillon(t_maillon_voiture* liste) {
    t_maillon_voiture* nouveauMaillon = (t_maillon_voiture*)malloc(sizeof(t_maillon_voiture));

    printf("Saisir les informations pour la nouvelle voiture :\n");
    printf("Immatriculation : ");
    scanf("%s", nouveauMaillon->immatriculation);
    printf("Marque : ");
    scanf("%s", nouveauMaillon->marque);
    printf("Modèle : ");
    scanf("%s", nouveauMaillon->modele);
    printf("Vitesse maximum : ");
    scanf("%d", &nouveauMaillon->vitesseMax);
    printf("Type de carburant : ");
    scanf(" %c", &nouveauMaillon->carburant);
    printf("Date de mise en service (jj mm aaaa) : ");
    scanf("%d %d %d", &nouveauMaillon->dateMiseEnService.jour, &nouveauMaillon->dateMiseEnService.mois, &nouveauMaillon->dateMiseEnService.annee);

    nouveauMaillon->suivant = liste;

    return nouveauMaillon;
}
