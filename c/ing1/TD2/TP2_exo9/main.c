#include <stdio.h>

int main() {
    int somme,x,y;
    float moy;
    printf("saisir les notes des eleves et taper une note negative afin d'arreter le programme:");
    y = 0;
    somme = 0;
    do {
        scanf("%d",&x);
        y = y + 1;
        somme = somme + x;
    }
    while (x>=0);

    printf("\n\t la somme est %d",somme-x);
    printf("\n\t le nombre de notes est %d",y-1);

    moy = (somme-x)/(y-1);
    printf("\n\t la moyenne est de %f",moy);
    return 0;
}
