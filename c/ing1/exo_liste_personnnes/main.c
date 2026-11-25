#include "header.h"

int main() {
    srand(time(NULL));

    t_liste listeAttente = {NULL, NULL};
    FILE *fichierSorties = fopen("sorties.txt", "w");
    if (fichierSorties == NULL) {
        perror("Erreur lors de l'ouverture du fichier de sorties");
        exit(EXIT_FAILURE);
    }
    char choix;
    do {
        printf("\nAppuyez sur une touche pour simuler l'arrivee/sortie de personnes (Q pour quitter) : ");
        scanf(" %c", &choix);

        if (choix != 'Q') {
            int nombrePersonnes = rand() % 3 + 1;

            for (int i = 0; i < nombrePersonnes; ++i) {
                if (rand() % 2 == 0) {
                    t_personne *nouvellePersonne = creerPersonne();
                    insererEnFin(&listeAttente, nouvellePersonne);
                    printf("%s est arrive(e) dans la file d'attente.\n", nouvellePersonne->nom);
                } else {
                        printf("La file d'attente est vide.\n");
                    }
                }
            printf("\nPersonnes dans la file d'attente :\n");
            afficherListe(&listeAttente);
            afficherListeRecursif(&listeAttente);
        }

    } while (choix != 'Q');

    libererListe(&listeAttente);
    fclose(fichierSorties);

    return 0;
}
