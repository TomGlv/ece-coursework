#include"Sousprog.h"

int main() {
    int nb_elements;
    struct Entree* tableau_dynamique = NULL;
    construire_fichier_notes();
    tableau_dynamique = construire_tableau_dynamique(&nb_elements);
    printf("Tableau initial :\n");
    for (int i = 0; i < nb_elements; ++i) {
        printf("%s %d\n", tableau_dynamique[i].nom, tableau_dynamique[i].note);
    }
    remplacer_note(tableau_dynamique, nb_elements);
    trier(tableau_dynamique, nb_elements);
    printf("Tableau apres remplacement de la note minimale :\n");
    for (int i = 0; i < nb_elements; ++i) {
        printf("%s %d\n", tableau_dynamique[i].nom, tableau_dynamique[i].note);
    }
    printf("Fichier trie : DonneesTriees.txt\n");
    int identique = veriftableaux(tableau_dynamique, nb_elements);
    if (identique == 1) {
        printf("Les tableaux sont identiques.\n");
    } else {
        printf("Les tableaux ne sont pas identiques.\n");
    }
    free(tableau_dynamique);
    return 0;
}

