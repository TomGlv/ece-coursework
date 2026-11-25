#include <stdio.h>

int main() {
    int entier1,entier2,i,somme;
    printf("saisissez deux entiers\n");
    scanf("%d%d",&entier1,&entier2);
    somme  = 0;
    if (entier1<entier2) {
        for (i = entier1; i < entier2; i++) {
            somme = somme + entier1;
            entier1 = entier1 + 1;
        }
    }
    else {
        for (i = entier2;i<entier1;i++){
            somme = somme + entier2;
            entier2 = entier2 + 1;
        }
    }
    printf("la somme des reels entre ces deux entiers est %d", somme);
    return 0;
}
