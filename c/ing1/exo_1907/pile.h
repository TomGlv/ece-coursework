#ifndef PILE_H
#define PILE_H

// Définition de la structure d'une cellule (maillon) de la file
typedef struct Element {
    int data;  // Donnée de l'élément
    struct Element* next;  // Pointeur vers l'élément suivant dans la file
} Element;

// Prototypes des fonctions utiles pour la gestion de la file
void enfiler(Element** rear, int data);
int rechercherDansFile(Element* front, int nombre);
void libererFile(Element** front);

#endif /* PILE_H */
