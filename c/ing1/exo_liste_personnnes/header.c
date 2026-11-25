#include "header.h"

t_personne *creerPersonne() {
    t_personne *nouvelle_personne = (t_personne *)malloc(sizeof(t_personne));

    if (nouvelle_personne == NULL) {
        perror("Allocation mémoire échouée");
        exit(EXIT_FAILURE);
    }

    printf("Saisir l'identifiant : ");
    scanf("%d", &nouvelle_personne->identifiant);

    printf("Saisir le nom : ");
    char buffer[100];
    scanf("%s", &buffer);
    nouvelle_personne->nom = strdup(buffer);

    printf("Saisir la date de naissance (jour mois anne) : ");
    scanf("%d %d %d", &nouvelle_personne->date_naissance.jour,
          &nouvelle_personne->date_naissance.mois,
          &nouvelle_personne->date_naissance.annee);

    return nouvelle_personne;
}

t_maillon *creerMaillon(t_personne *une_personne) {
    t_maillon *nouveau_maillon = (t_maillon *)malloc(sizeof(t_maillon));

    if (nouveau_maillon == NULL) {
        perror("Allocation memoire echouee");
        exit(EXIT_FAILURE);
    }

    nouveau_maillon->personne = une_personne;
    nouveau_maillon->suivant = NULL;

    return nouveau_maillon;
}

void insererEnFin(t_liste *liste, t_personne *une_personne) {
    t_maillon *nouveau_maillon = creerMaillon(une_personne);

    if (liste->debut == NULL) {
        liste->debut = liste->fin = nouveau_maillon;
    } else {
        liste->fin->suivant = nouveau_maillon;
        liste->fin = nouveau_maillon;
    }
}

void afficherListe(t_liste *liste) {
    t_maillon *courant = liste->debut;
    while (courant != NULL) {
        printf("%s\n", courant->personne->nom);
        courant = courant->suivant;
    }
}
void afficherListeRecursif(t_liste *liste) {
    t_maillon *courant = liste->debut;
    int nombre = 0;
    int i,j;
    do{
        courant = courant->suivant;
        nombre +=1;
    }while (courant!= NULL);
    printf("%s\n", courant->personne->nom);
    for (j=0; j<nombre;j++){
        for (i=0; i<nombre;i++){
            courant = courant->suivant;
        }
        printf("%s\n", courant->personne->nom);
        nombre = nombre -1;
    }
}

void libererListe(t_liste *liste) {
    t_maillon *courant = liste->debut;
    while (courant != NULL) {
        t_maillon *suivant = courant->suivant;
        free(courant->personne->nom);
        free(courant->personne);
        free(courant);
        courant = suivant;
    }
}
