#include <stdio.h>
#include <unistd.h>

int carre(int n) {
    return n * n;
}

// Exercice 802 - Menu
int menu() {
    int choix;
    do {
        printf("\nMenu:\n");
        printf("1. Exercice 801 - Calculer le carre\n");
        printf("2. Exercice 802 - Menu d'operations\n");
        printf("3. Exercice 803 - Simuler une horloge\n");
        printf("4. Quitter\n");
        printf("Entrez votre choix (1-4): ");
        scanf("%d", &choix);
    } while (choix < 1 || choix > 4);
    return choix;
}

int ajouter1(int n) {
    return n + 1;
}

int multiplierPar2(int n) {
    return n * 2;
}

int soustraire4(int n) {
    return n - 4;
}

int sommeNPremiers(int n) {
    int somme = 0;
    for (int i = 1; i <= n; i++) {
        somme += i;
    }
    return somme;
}

int minuteSuivante(int minute) {
    return (minute + 1) % 60;
}

int heureSuivante(int heure) {
    return (heure + 1) % 24;
}

int main() {
    int choix;

    do {
        choix = menu();

        switch (choix) {
            case 1: {
                // Exercice 801
                int a, b;
                printf("Entrez le premier nombre entier : ");
                scanf("%d", &a);
                printf("Entrez le deuxième nombre entier : ");
                scanf("%d", &b);
                printf("Le carré de %d est %d\n", a, carre(a));
                printf("Le carré de %d est %d\n", b, carre(b));
                break;
            }
            case 2: {
                // Exercice 802
                int nombre, choixOperation, resultat;

                printf("Entrez un entier: ");
                scanf("%d", &nombre);

                do {
                    printf("\nOperations:\n");
                    printf("1. Ajouter 1\n");
                    printf("2. Multiplier par 2\n");
                    printf("3. Soustraire 4\n");
                    printf("4. Somme des n premiers entiers\n");
                    printf("5. Retour au menu principal\n");
                    printf("Entrez votre choix (1-5): ");
                    scanf("%d", &choixOperation);

                    switch (choixOperation) {
                        case 1:
                            resultat = ajouter1(nombre);
                            printf("Resultat: %d\n", resultat);
                            break;
                        case 2:
                            resultat = multiplierPar2(nombre);
                            printf("Resultat: %d\n", resultat);
                            break;
                        case 3:
                            resultat = soustraire4(nombre);
                            printf("Resultat: %d\n", resultat);
                            break;
                        case 4:
                            printf("Entrez n: ");
                            int n;
                            scanf("%d", &n);
                            resultat = sommeNPremiers(n);
                            printf("Somme des %d premiers entiers: %d\n", n, resultat);
                            break;
                    }
                } while (choixOperation != 5);
                break;
            }
            case 3: {
                // Exercice 803
                int heure = 0, minute = 0;
                while (1) {
                    printf("%02d:%02d\n", heure, minute);
                    sleep(1);
                    minute = minuteSuivante(minute);
                    if (minute == 0) {
                        heure = heureSuivante(heure);
                    }
                }
                break;
            }
            case 4:
                printf("Au revoir!\n");
                break;
            default:
                printf("Choix invalide!\n");
        }
    } while (choix != 4);

    return 0;
}
