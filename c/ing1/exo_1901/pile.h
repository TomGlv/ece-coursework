#ifndef PILE_H
#define PILE_H

// Définition de la structure d'un élément de la pile
typedef struct Element {
    char data;  // Caractère stocké dans l'élément
    struct Element* next;  // Pointeur vers l'élément suivant dans la pile
} Element;

// Prototypes des fonctions utiles pour la gestion de la pile
void push(Element** top, char data);
char pop(Element** top);
char peek(Element* top);
int isEmpty(Element* top);

#endif /* PILE_H */
