#include <stdio.h>

int main() {
    int h,l,X,k,i,I,x;
    do {                                                                   ///blindage du code
        printf("Veuillez saisir une hauteur impaire entre 5 et 9 : ");
        scanf("%d", &h);                                          ///recuperation de la hauteur saisie au clavier par l'utilisateur

        if (h < 5 || h > 9 || h % 2 == 0) {
            printf("La hauteur doit etre impaire et comprise entre 5 et 9. Reessayez.\n"); ///blindage du code
        }
    } while (h < 5 || h > 9 || h % 2 == 0);

    printf("Vous avez saisi une hauteur valide : %d\n", h);     ///hauteur bien impaire
    l = h * 2 - 1;
    X = 0;
    x=0;
    for (i = 0; i < h; i++) {
        for (I = -1; I < (l / 2 - i); I++) {
            printf(" ");                   ///calcul du nombre d'espace et on les print
        };
        printf("%d",x);                     ///sommet du triangle
        for (k = 0; k < X-1; k++) {
            if (x%2==1)                         ///pour x paire
            printf(" ");
            else printf("_");            /// pour x impaire
        };
        if (x==0);
        else printf("%d",x);
        printf("\n");
        X += 2;
        x=x+1;
    };
    return 0;
}
