#include <stdio.h>

int main() {
    int val1;
    ///affichage du menu
    printf("Pour dessiner une forme geometrique, saissisez un chiffre qui correspond a une forme : \t\n1:rectangle\t\n2:triangle\t\n3:losange\t\n4:sapin\t\n5:sablier");
    ///recuperation du choix
    scanf("%d",&val1);
    ///applique un code pour des cas specifiques
    switch (val1) {
        case 1 : //dans le cas ou la variable vaut 1
            printf("Dessiner un rectangle");
        break;
        case 2 :
            printf("Dessiner un triangle");
        break;
        case 3 :
            printf("Dessiner un losange");
        break;
        case 4 :
            printf("Dessiner un sapin");
        break;
        case 5 :
            printf("Dessiner un sablier");
        break;
        default : printf("Choisit une des options proposees !");
    }
    return 0;
}