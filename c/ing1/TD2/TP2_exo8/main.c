#include <stdio.h>

int menu() {
    int choix;

    do {
        printf("\nMenu :\n");
        printf("1. Ajouter 1\n");
        printf("2. Multiplier par 2\n");
        printf("3. Soustraire 4\n");
        printf("4. Somme de n premiers entiers\n");
        printf("5. Quitter\n");
        printf("Veuillez entrer un choix (1-5) : ");
        scanf("%d", &choix);
    } while (choix < 1 || choix > 5);

    return choix;<<<<<
}

int ajouter1(int valeur) {
    return valeur + 1;
}

int multiplier2(int valeur) {
    return valeur * 2;
}

int soustraire4(int valeur) {
    return valeur - 4;
}

int sommeN(int n) {
    int somme = 0;
    for (int i = 1; i <= n; i++) {
        somme += i;
    }
    return somme;
}

void afficherResultat(int resultat) {
    printf("Le resultat est : %d\n", resultat);
}
int main() {
    int valeur, choix, resultat;

    printf("Veuillez entrer un entier : ");
    scanf("%d", &valeur);

    do {
        choix = menu();

        switch (choix) {
            case 1:
                resultat = ajouter1(valeur);
                break;
            case 2:
                resultat = multiplier2(valeur);
                break;
            case 3:
                resultat = soustraire4(valeur);
                break;
            case 4:
            {
                int n;
                printf("Entrez n pour la somme des n premiers entiers : ");
                scanf("%d", &n);
                resultat = sommeN(n);
            }
                break;
            case 5:
                printf("Au revoir !\n");
                break;
            default:
                printf("Choix invalide. Veuillez reessayer.\n");
                continue;
        }

        if (choix != 5) {
            afficherResultat(resultat);
        }

    } while (choix != 5);

    return 0;
}

