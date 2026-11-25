#include <stdio.h>
#include <stdlib.h>
#include "pile.h"

// Fonction pour enfiler un élément à l'arrière de la file
void enfiler(Element** rear, int data) {
    Element* newElement = (Element*)malloc(sizeof(Element));
    if (newElement == NULL) {
        exit(EXIT_FAILURE);
    }
    newElement->data = data;
    newElement->next = NULL;

    if (*rear == NULL) {
        *rear = newElement;
    } else {
        (*rear)->next = newElement;
        *rear = newElement;
    }
}

// Fonction pour rechercher si un nombre existe dans la file
int rechercherDansFile(Element* front, int nombre) {
    while (front != NULL) {
        if (front->data == nombre) {
            return 1; // Le nombre existe dans la file
        }
        front = front->next;
    }
    return 0; // Le nombre n'existe pas dans la file
}

// Fonction pour libérer la mémoire allouée pour la file
void libererFile(Element** front) {
    while (*front != NULL) {
        Element* temp = *front;
        *front = (*front)->next;
        free(temp);
    }
}
