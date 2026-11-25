#include <stdio.h>
int histogramme(int notes_de_0_6){ ///Création d'un sous programme pour l'histogramme des notes de 0 à 6
    int i;
    for (i=0;i<notes_de_0_6;i++)    /// boucle permmetant d'afficher un nombre d'* en fonction du nombre de notes entre 0 et 6
        printf("*");}
int histogramme1(int notes_de_7_13){ ///Création d'un sous programme pour l'histogramme des notes de 7 à 13
    int i;
    for (i=0;i<notes_de_7_13;i++)   /// boucle permmetant d'afficher un nombre d'* en fonction du nombre de notes entre 7 et 13
        printf("*");}
int histogramme2(int notes_de_14_20){  ///Création d'un sous programme pour l'histogramme des notes de 14 à 20
    int i;
    for (i=0;i<notes_de_14_20;i++)     /// boucle permmetant d'afficher un nombre d'* en fonction du nombre de notes entre 14 et 20
        printf("*");}
int main() {
    int nombre_de_notes;
    printf("Combien de notes voulez-vous saisir ? ");  /// demande a l'utilisateur le nombre de notes a saisir
    scanf("%d", &nombre_de_notes);

    if (nombre_de_notes < 1) {
        printf("Le nombre de notes doit etre superieur ou egal q 1.\n");  /// blindage du code
        return 1;
    }

    float notes[nombre_de_notes];
    int notes_de_0_6 = 0, notes_de_7_13 = 0, notes_de_14_20 = 0;
    float somme_notes = 0;

    for (int i = 0; i < nombre_de_notes; i++) {
        float note;

        do {
            printf("Saisissez la note %d (entre 0 et 20) : ", i + 1);  ///demande a l'utilisateur de rentrer des notes une par une
            scanf("%f", &note);

            if (note < 0 || note > 20) {                                      ///blindage du code
                printf("La note doit etre comprise entre 0 et 20.\n");
            }
        }
        while (note < 0 || note > 20);

        notes[i] = note;
        somme_notes += note;

        if (note >= 0 && note <= 6) {         ///calcul le nombre de notes entre 0 et 6
            notes_de_0_6++;
        } else if (note >= 7 && note <= 13) { ///calcul le nombre de notes entre 7 et 13
            notes_de_7_13++;
        } else {                             ///calcul le nombre de notes entre 14 et 20
            notes_de_14_20++;
        }
    }

    float moyenne = somme_notes / nombre_de_notes;      ///calcul de la moyenne
    printf("\nLa moyenne des notes est : %.2f\n", moyenne);             ///affichage des moyennes et nombres de notes
    printf("\nNombre de notes entre 0 et 6 est %d l'histogramme  est donc : ", notes_de_0_6);
    histogramme(notes_de_0_6);
    printf("\nNombre de notes entre 7 et 13  est %d l'histogramme  est donc : ", notes_de_7_13);
    histogramme1(notes_de_7_13);
    printf("\nNombre de notes entre 14 et 20  est %d l'histogramme  est donc : ", notes_de_14_20);
    histogramme2(notes_de_14_20);
    return 0;
}
