#ifndef PILE_H
#define PILE_H

// Définition de la structure d'une cellule (maillon) de la pile
typedef struct Element {
    int data;  // Donnée de l'élément
    struct Element* next;  // Pointeur vers l'élément suivant dans la pile
} Element;

// Prototypes des fonctions utiles pour la gestion de la pile
void push(Element** top, int data);
int pop(Element** top);
int isEmpty(Element* top);

#endif /* PILE_H */
