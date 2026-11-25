#include "menu.h"
// Fonction pour afficher les règles du jeu

void menu_principal() {
    effacerEcran(); // Efface l'écran

    printf("\n=== LA REVANCHE DE SNOOPY ===\n");
    printf("Que voulez vous faire ?\n");
    printf("1. Regles du jeu\n2. lancer un nouveau jeu a partir du niveau 1\n3. charger une partie \n4.mot de passe\n5. scores\n6. quitter");
    printf("\n");

    char touche;

    touche=_getch();

    switch (touche) {
        case '1' : {
            effacerEcran();
            int i,j;
            j=10;
            for (i=0;i<10;i++){
                printf("\nChaque niveau devra etre resolu en moins de 120 secondes.\nSi le temps est ecoule, le joueur perd une");
                printf("vie et recommence le niveau.\nLe but est de recuperer les 4 oiseaux du niveau sans se faire toucher par ");
                printf("la balle et/ou les ennemis (si presents).\n");
                printf("\n===  Ce menu s'affichera pendant 10 secondes, il reste : ");
                printf("%d",j);
                printf(" secondes  ===");
                j--;
                sleep(1);
                effacerEcran();
            }
            menu_principal();

        }
            break;
        case '2' : /// lancer un nouveau jeu a partir du niveau 1
            printf("lancement du jeu...\n");
            sleep(0.5);
            deplacement();

            break;
        case '3' : {
            ///charger une partie
        }
            break;
        case '4' : {
            ///mot de passe
        }
            break;
        case '5' : {
            ///scores
        }
            break;
        case '6' : {
            break;
        }

        default : {
            printf("veuillez saisir une valeur entre 1 et 6");
            menu_principal();
            break;
        };
    }
}


// Fonction pour scanner le plateau de jeu et sauvegarder la disposition
char* sauvegarderDisposition(char plateau[HAUTEUR][LARGEUR]) {
    // Créez une chaîne de caractères pour stocker la sauvegarde
    char* sauvegarde = (char*)malloc(HAUTEUR * LARGEUR + 1); // +1 pour le caractère de fin de chaîne

    if (sauvegarde == NULL) {
        printf("Erreur d'allocation mémoire.\n");
        exit(1);
    }

    // Parcourez le plateau de jeu et sauvegardez la disposition
    int index = 0;
    for (int y = 0; y < HAUTEUR; y++) {
        for (int x = 0; x < LARGEUR; x++) {
            sauvegarde[index] = plateau[y][x];
            index++;
        }
    }

    sauvegarde[HAUTEUR * LARGEUR] = '\0'; // Ajoutez le caractère de fin de chaîne

    return sauvegarde;}

void menu_partie_en_cours() {
    effacerEcran(); // Efface l'écran

    printf("=== LA REVANCHE DE SNOOPY ===\n");
    printf("Que voulez vous faire ?\n");
    printf("1. Reprendre la partie en cours\n2. Revenir au menu principal\n3. Sauvegarder la partie\n4. Quitter le jeu\n");
    printf("\n");
    int touche;
    touche = _getch();
    switch (touche) {
        case '1' : {
            ///reprendre le jeu
        }
            break;
        case '2' : {
            menu_principal();
        }
            break;
        case '3' : { ///sauvegarder la partie
            // Utilisation de la fonction pour sauvegarder la disposition actuelle du plateau
            char *sauvegarde = sauvegarderDisposition(plateau);

            // Affichez le code de sauvegarde
            printf("Code de sauvegarde : %s\n", sauvegarde);
        }
            break;
        case '4' : {
            ///Quitter le jeu
        }
            break;
    }
}