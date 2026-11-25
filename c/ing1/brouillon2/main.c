#include "header.h"
int main() {
    Athlete *athletes = NULL;
    int nbAthletes = 0;
    int choix;

    do {
        printf("\nMenu:\n");
        printf("1. Saisir une nouvelle liste d'athletes\n");
        printf("2. Afficher la liste des athletes\n");
        printf("3. Trouver et afficher le meilleur\n");
        printf("4. Sauvegarder la liste des athleyes\n");
        printf("5. Charger une nouvelle liste d'athetes\n");
        printf("0. Quitter\n");
        printf("Votre choix : ");
        scanf("%d", &choix);

        switch (choix) {
            case 1:
                saisirListeAthletes(&athletes, &nbAthletes);
                break;
            case 2:
                afficherListeAthletes(athletes, nbAthletes);
                break;
            case 3:
                trouverEtAfficherMeilleur(athletes, nbAthletes);
                break;
            case 4:
                sauvegarderListeAthletes(athletes, nbAthletes, "athletes.txt");
                break;
            case 5:
                chargerListeAthletes(&athletes, &nbAthletes, "athletes.txt");
                break;
            case 0:
                printf("Au revoir!\n");
                break;
            default:
                printf("Choix invalide. Veuillez reessayer.\n");
        }

    } while (choix != 0);

    // Libérer la mémoire avant de quitter le programme
    if (athletes != NULL) {
        free(athletes);
    }

    return 0;
}


