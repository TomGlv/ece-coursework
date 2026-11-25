
#ifndef EXO_1701_HEADER_H
#define EXO_1701_HEADER_H
#include <stdlib.h>
#include <stdio.h>
typedef struct maillon{
    float data;
    struct maillon * next;
}t_maillon;
t_maillon* creerM(float x);
void insererT(float x,t_maillon** pancre);
void afficherLC(t_maillon* ancre);
void insererF(float x,t_maillon** pancre);

#endif //EXO_1701_HEADER_H
