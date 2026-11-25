#include <stdio.h>
#include <stdlib.h>
#include <string.h>
int sommeTableau(int *tab, int taille) {
    if (taille == 0)
        return 0;
    return tab[0] + sommeTableau(tab + 1, taille - 1);
}
int longueurChaine(const char *chaine) {
    if (*chaine == '\0')
        return 0;
    return 1 + longueurChaine(chaine + 1);
}
int puissance(int base, int exposant) {
    if (exposant == 0)
        return 1;
    return base * puissance(base, exposant - 1);
}
void saisie(float *tab, int n, int i) {
    if (i < n) {
        printf("Entrez le nombre %d : ", i + 1);
        scanf("%f", &tab[i]);
        saisie(tab, n, i + 1);
    }
}

void affiche(float *tab, int n, int i) {
    if (i < n) {
        printf("%f ", tab[i]);
        affiche(tab, n, i + 1);
    }
}

void fusion(float *tab, int debut, int milieu, int fin) {
    int i = debut, j = milieu + 1, k = 0;
    float *temp = (float *)malloc((fin - debut + 1) * sizeof(float));
    while (i <= milieu && j <= fin) {
        if (tab[i] < tab[j])
            temp[k++] = tab[i++];
        else
            temp[k++] = tab[j++];
    }
    while (i <= milieu)
        temp[k++] = tab[i++];
    while (j <= fin)
        temp[k++] = tab[j++];
    for (i = debut, k = 0; i <= fin; i++, k++)
        tab[i] = temp[k];
    free(temp);
}

void triFusion(float *tab, int debut, int fin) {
    if (debut < fin) {
        int milieu = (debut + fin) / 2;
        triFusion(tab, debut, milieu);
        triFusion(tab, milieu + 1, fin);
        fusion(tab, debut, milieu, fin);
    }
}

void hanoi(int n, char source, char destination, char intermediaire) {
    if (n == 1) {
        printf("Deplacer le disque 1 de %c a %c\n", source, destination);
        return;
    }
    hanoi(n - 1, source, intermediaire, destination);
    printf("Deplacer le disque %d de %c a %c\n", n, source, destination);
    hanoi(n - 1, intermediaire, destination, source);
}

void exercice1602() {
    int taille, *tableau, somme;

    printf("\n=== Exercice 1602 ===\n");
    printf("Entrez la taille du tableau : ");
    scanf("%d", &taille);

    tableau = (int *)malloc(taille * sizeof(int));
    if (tableau == NULL) {
        printf("Erreur d'allocation memoire.\n");
        return;
    }

    printf("Entrez les valeurs du tableau :\n");
    for (int i = 0; i < taille; i++) {
        printf("Valeur %d : ", i + 1);
        scanf("%d", &tableau[i]);
    }

    somme = sommeTableau(tableau, taille);
    printf("La somme des valeurs du tableau est : %d\n", somme);

    free(tableau);
}

void exercice1603() {
    char chaine[100];
    printf("\n=== Exercice 1603 ===\n");
    printf("Entrez une chaine de caracteres : ");
    scanf("%s", chaine);

    printf("La longueur de la chaine est : %d\n", longueurChaine(chaine));
}

void exercice1605() {
    int base, exposant;

    printf("\n=== Exercice 1605 ===\n");
    printf("Entrez la base : ");
    scanf("%d", &base);
    printf("Entrez l'exposant : ");
    scanf("%d", &exposant);


    printf("%d^%d = %d\n", base, exposant, puissance(base, exposant));
}

void exercice1606() {
    int n;

    printf("\n=== Exercice 1606 ===\n");
    printf("Entrez la taille du tableau : ");
    scanf("%d", &n);

    float *tableau = (float *)malloc(n * sizeof(float));
    if (tableau == NULL) {
        printf("Erreur d'allocation memoire.\n");
        return;
    }

    saisie(tableau, n, 0);
    triFusion(tableau, 0, n - 1);
    printf("Tableau trie : ");
    affiche(tableau, n, 0);
    printf("\n");

    free(tableau);
}

void exercice1609() {
    int n;

    printf("\n=== Exercice 1609 ===\n");
    printf("Entrez le nombre de disques : ");
    scanf("%d", &n);


    hanoi(n, 'A', 'B', 'C');
}

int main() {
    int choix;

    do {
        printf("\nMenu :\n");
        printf("1. Exercice 1602 - Somme des valeurs d'un tableau dynamique\n");
        printf("2. Exercice 1603 - Longueur d'une chaine de caracteres\n");
        printf("3. Exercice 1605 - Puissance d'un nombre\n");
        printf("4. Exercice 1606 - Tri par fusion d'un tableau\n");
        printf("5. Exercice 1609 - Tours de Hanoi\n");
        printf("0. Quitter\n");
        printf("Votre choix : ");
        scanf("%d", &choix);

        switch (choix) {
            case 1:
                exercice1602();
                break;
            case 2:
                exercice1603();
                break;
            case 3:
                exercice1605();
                break;
            case 4:
                exercice1606();
                break;
            case 5:
                exercice1609();
                break;
            case 0:
                printf("Au revoir !\n");
                break;
            default:
                printf("Choix invalide. Reessayez.\n");
        }
    } while (choix != 0);

    return 0;
}
