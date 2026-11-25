#include <stdio.h>
#include <stdlib.h>
#include "pile.h"

void push(Element** top, int data) {
    Element* newElement = (Element*)malloc(sizeof(Element));
    if (newElement == NULL) {
        exit(EXIT_FAILURE);
    }
    newElement->data = data;
    newElement->next = *top;
    *top = newElement;
}
int pop(Element** top) {
    if (isEmpty(*top)) {
        exit(EXIT_FAILURE);
    }
    Element* temp = *top;
    int data = temp->data;
    *top = temp->next;
    free(temp);
    return data;
}

// Fonction pour vérifier si la pile est vide
int isEmpty(Element* top) {
    return top == NULL;
}
