#include <stdio.h>
#include <stdlib.h>
#include "pile.h"

// Prototypes de fonctions
Element* lireEntiersDansFichier(FILE* fichier);
// Fonction pour rechercher un nombre dans la file et afficher le résultat
void rechercherEtAfficherResultat(Element* file, int nombre) {
    if (rechercherDansFile(file, nombre)) {
        printf("Le nombre %d existe dans la file.\n", nombre);
    } else {
        printf("Le nombre %d n'existe pas dans la file.\n", nombre);
    }
}
// Fonction pour lire les entiers du fichier et les mettre dans une file
Element* lireEntiersDansFichier(FILE* fichier) {
Element* front = NULL;
Element* rear = NULL;
int nombre;
while (fscanf(fichier, "%d", &nombre) != EOF) {
enfiler(&rear, nombre);
if (front == NULL) {
front = rear;
}
}
return front;
}
int main() {
    FILE* fichier = fopen("entiers.txt", "r"); // Ouvrir le fichier en mode lecture
    if (fichier == NULL) {
        printf("Erreur : Impossible d'ouvrir le fichier.\n");
        return 1;
    }

    Element* file = lireEntiersDansFichier(fichier); // Lire les entiers du fichier et les mettre dans une file
    fclose(fichier); // Fermer le fichier après lecture

    int choix;
    int nombre;

    do {
        printf("1. Saisir un entier et rechercher dans la file\n");
        printf("2. Quitter\n");
        printf("Choix : ");
        scanf("%d", &choix);

        switch (choix) {
            case 1:
                printf("Entrez un entier : ");
                scanf("%d", &nombre);
                rechercherEtAfficherResultat(file, nombre);
                break;
            case 2:
                printf("Au revoir !\n");
                break;
            default:
                printf("Choix invalide. Veuillez entrer 1 ou 2.\n");
        }
    } while (choix != 2);

    libererFile(&file); // Libérer la mémoire allouée pour la file dynamique

    return 0;
}



