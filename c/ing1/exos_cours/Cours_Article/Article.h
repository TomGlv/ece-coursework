//
// Created by tomga on 25/10/2023.
//

#ifndef COURS_ARTICLE_ARTICLE_H
#define COURS_ARTICLE_ARTICLE_H
#include <stdio.h>
#define N 1
///défintion d'un type structuré
typedef struct article{
    int code;
    float prix;
    char nom;
    int qStock;
} t_article;
///prototypes des sous-programmes
/* Sous prog de saisie des infos d'un sous prog */
/*Entrée : l'adresse de la structure à remplir
 * Sortie : Rien de spécial*/
void saisirArticle (t_article* pa);
void AffArticle(t_article* an);
#endif //COURS_ARTICLE_ARTICLE_H
