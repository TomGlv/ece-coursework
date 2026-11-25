//
// Created by tomga on 29/02/2024.
//

#include "pile.h"
#include <stdlib.h>
#include "pile.h"

// Fonction pour ajouter un élément au sommet de la pile
void push(Element** top, char data) {
    Element* newElement = (Element*)malloc(sizeof(Element));
    if (newElement == NULL) {
        exit(EXIT_FAILURE);
    }
    newElement->data = data;
    newElement->next = *top;
    *top = newElement;
}

// Fonction pour retirer et retourner l'élément du sommet de la pile
char pop(Element** top) {
    if (isEmpty(*top)) {
        exit(EXIT_FAILURE);
    }
    Element* temp = *top;
    char data = temp->data;
    *top = temp->next;
    free(temp);
    return data;
}

// Fonction pour vérifier si la pile est vide
int isEmpty(Element* top) {
    return top == NULL;
}
// Fonction pour consulter l'élément au sommet de la pile sans le retirer
char peek(Element* top) {
    if (isEmpty(top)) {
        exit(EXIT_FAILURE);
    }
    return top->data;
}
