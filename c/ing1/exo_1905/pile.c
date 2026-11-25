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

// Fonction pour défiler un élément à l'avant de la file et le retourner
int defiler(Element** front) {
    if (isEmpty(*front)) {
        exit(EXIT_FAILURE);
    }
    Element* temp = *front;
    int data = temp->data;
    *front = (*front)->next;
    free(temp);
    return data;
}

// Fonction pour vérifier si la file est vide
int isEmpty(Element* front) {
    return front == NULL;
}
